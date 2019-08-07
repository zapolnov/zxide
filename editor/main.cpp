#include "MainWindow.h"
#include "config.h"
#include <QApplication>

int main(int argc, char** argv)
{
    QApplication::setAttribute(Qt::AA_DisableWindowContextHelpButton);
    QApplication::setOrganizationName(QStringLiteral("Nikolay Zapolnov"));
    QApplication::setOrganizationDomain(QStringLiteral("zapolnov.com"));
    QApplication::setApplicationName(QStringLiteral("%1 Game Editor").arg(GAME_NAME));
    QApplication::setApplicationVersion(QStringLiteral("1.0"));

    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
