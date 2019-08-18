#include "MainWindow.h"
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
    QApplication::setApplicationName(QStringLiteral("ZX Spectrum IDE"));
    QApplication::setApplicationVersion(QStringLiteral("1.0"));

    QApplication app(argc, argv);
    MainWindow mainWindow;

    auto args = app.arguments();
    if (args.length() > 1)
        mainWindow.openProject(args[1], false);
    else
        mainWindow.openLastProject();

    mainWindow.show();
    return app.exec();
}
