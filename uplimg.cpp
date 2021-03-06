#include <QApplication>
#include <QTranslator>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QList>
#include "systemtrayicon.h"

#include <QHttpMultiPart>
#include <QHttpPart>
#include <QNetworkRequest>
#include <QUrl>
#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSignalMapper>


#include <fstream>

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setQuitOnLastWindowClosed(false);

    QCoreApplication::setOrganizationName("ImoteSystem");
    QCoreApplication::setApplicationName("Uplimg");

    QTranslator translator;

    const QString langSettingName("configuration/lang");
    QSettings settings;

    if(settings.value(langSettingName).toString() == "English")
        translator.load(":/lang/uplimg_en");
    else if(settings.value(langSettingName).toString() == "Français")
        translator.load(":/lang/uplimg_fr");
    else
        {
            QString locale = QLocale::system().name().section('_', 0, 0);
            translator.load(QString(":/lang/uplimg_") + locale);
        }

    app.installTranslator(&translator);

    SystemTrayIcon systemTray;
    systemTray.show();
    systemTray.setVisible(true);

    return app.exec();
}
