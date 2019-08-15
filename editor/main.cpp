#include "MainWindow.h"
#include "config.h"
#include <QSurfaceFormat>
#include <QApplication>

int main(int argc, char** argv)
{
    QApplication::setAttribute(Qt::AA_DisableWindowContextHelpButton);
    QApplication::setAttribute(Qt::AA_ShareOpenGLContexts);

    QSurfaceFormat defaultFormat;
    defaultFormat.setDepthBufferSize(0);
    defaultFormat.setStencilBufferSize(0);
    QSurfaceFormat::setDefaultFormat(defaultFormat);

    QApplication::setOrganizationName(QStringLiteral("Nikolay Zapolnov"));
    QApplication::setOrganizationDomain(QStringLiteral("zapolnov.com"));
    QApplication::setApplicationName(QStringLiteral("%1 Game Editor").arg(GAME_NAME));
    QApplication::setApplicationVersion(QStringLiteral("1.0"));

    QApplication app(argc, argv);

    MainWindow mainWindow(GAME_DIR);
    mainWindow.show();

    return app.exec();
}
