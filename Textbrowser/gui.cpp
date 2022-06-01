#include "gui.h"

Gui::Gui(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    connect(&client, &HttpClient::sendData, this, &Gui::showResult);
}

void Gui::on_goButton_clicked()
{
    // Stellt verbindung mit dem Server her, indem er die Adresse von Widget hostEntry liest
    QString host = hostEntry->text();
    // Sendet host an die Funktion getHTTP im httpclient.cpp
    client.getHTTP(host);
}

void Gui::showResult(QString& httpprintback)
{
    resultBrowser->append(httpprintback);
}
