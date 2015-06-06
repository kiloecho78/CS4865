#include "gamewindow.h"
#include "rulesdialog.h"
#include "gameclient.h"
#include "gameserver.h"
#include <QApplication>
#include <QtCore/QSettings>
#include <QtNetwork/QNetworkConfigurationManager>
#include <QtNetwork/QNetworkSession>

RulesDialog *Rules;
GameClient *Client;
GameServer *Server;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
        // Get saved network configuration
        QSettings settings(QSettings::UserScope, QLatin1String("YahtzeeProject"));
        settings.beginGroup(QLatin1String("YahtzeeNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // If the saved network configuration is not currently discovered use the system default
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
            QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }

        QNetworkSession *networkSession = new QNetworkSession(config, &a);
        networkSession->open();
        networkSession->waitForOpened();

        if (networkSession->isOpen()) {
            // Save the used configuration
            QNetworkConfiguration config = networkSession->configuration();
            QString id;
            if (config.type() == QNetworkConfiguration::UserChoice) {
                id = networkSession->sessionProperty(
                        QLatin1String("UserChoiceConfiguration")).toString();
            } else {
                id = config.identifier();
            }

            QSettings settings(QSettings::UserScope, QLatin1String("YahtzeeProject"));
            settings.beginGroup(QLatin1String("YahtzeeNetwork"));
            settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
            settings.endGroup();
        }
    }

    GameWindow w;
    RulesDialog rd;
    GameClient c;
    GameServer s;
    w.show();
    Rules = &rd;
    Client = &c;
    Server = &s;
    return a.exec();
}
