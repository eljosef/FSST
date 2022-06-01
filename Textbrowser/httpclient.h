#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QCoreApplication>

const int PORT = 80;
const int TIMEOUT = 5000; // Nach 5 sekunden Anfrage beenden

class HttpClient : public QObject
{
    Q_OBJECT
public:
    explicit HttpClient(QObject *parent = nullptr);
    void getHTTP(QString& host);
    void connected();
    void readyRead();

signals:
    void sendData(QString& Message);

public slots:

private:
    QTcpSocket *m_socket;
    QByteArray m_host;
    QString m_signal;
};

#endif // HTTPCLIENT_H
