#include "ProjectSettingsDialog.h"
#include "editor/Project.h"
#include "compiler/ProjectSettings.h"
#include "compiler/IO.h"
#include "util/ComboBox.h"
#include "ui_ProjectSettingsDialog.h"
#include <QMessageBox>
#include <QInputDialog>

static int lastSelectedTab;

ProjectSettingsDialog::ProjectSettingsDialog(Project* project, QWidget* parent)
    : QDialog(parent)
    , mUi(new Ui_ProjectSettingsDialog)
    , mProject(project)
{
    mUi->setupUi(this);
    mUi->tabWidget->setCurrentIndex(lastSelectedTab);

    mSettings = std::make_unique<ProjectSettings>();
    mSettings->load(project->file());

    mUi->standardCombo->addItem(QStringLiteral("C89"), int(CStandard::C89));
    mUi->standardCombo->addItem(QStringLiteral("C99"), int(CStandard::C99));
    mUi->standardCombo->addItem(QStringLiteral("C11"), int(CStandard::C11));
    comboSelectItem(mUi->standardCombo, QVariant(int(mSettings->standard)));

    bool first = true;
    for (const auto& it : mSettings->defines) {
        auto item = new QListWidgetItem(QString::fromLatin1(it.c_str()), mUi->definesList);
        if (first) {
            first = false;
            mUi->definesList->setCurrentItem(item);
        }
    }

    mUi->charUnsignedCheck->setChecked(mSettings->charIsUnsigned);

    updateUi();
}

ProjectSettingsDialog::~ProjectSettingsDialog()
{
}

void ProjectSettingsDialog::done(int r)
{
    if (r == QDialog::Accepted) {
        try {
            lastSelectedTab = mUi->tabWidget->currentIndex();

            mSettings->standard = CStandard(comboSelectedItem(mUi->standardCombo).toInt());
            mSettings->charIsUnsigned = mUi->charUnsignedCheck->isChecked();

            mSettings->defines.clear();
            int n = mUi->definesList->count();
            for (int i = 0; i < n; i++)
                mSettings->defines.emplace_back(mUi->definesList->item(i)->text().toLatin1().constData());

            mSettings->save(mProject->file());
        } catch (const IOException& e) {
            QMessageBox::critical(this, tr("Error"), e.message());
            return;
        }
    }

    QDialog::done(r);
}

void ProjectSettingsDialog::on_addDefineButton_clicked()
{
    QInputDialog dlg(this);
    dlg.setInputMode(QInputDialog::TextInput);
    dlg.setWindowTitle(tr("Add define"));
    dlg.setLabelText(tr("Define:"));
    dlg.setTextValue(tr("NEW_DEFINE"));
    if (dlg.exec() != QDialog::Accepted)
        return;

    QString name = dlg.textValue().trimmed();

    auto item = new QListWidgetItem(name, mUi->definesList);
    mUi->definesList->setCurrentItem(item);
}

void ProjectSettingsDialog::on_removeDefineButton_clicked()
{
    int index = mUi->definesList->currentRow();
    if (index >= 0)
        delete mUi->definesList->item(index);
}

void ProjectSettingsDialog::updateUi()
{
    mUi->removeDefineButton->setEnabled(mUi->definesList->currentRow() >= 0);
}
