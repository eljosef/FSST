#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

const quint16 PORT = 5555;

class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(quint16 port, QObject *parent = nullptr);
    void start();

signals:

public slots:
    void myNewConnection();
    void myServerRead();

private:
    QTcpServer* m_webserver;
    QTcpSocket* m_socket;
    quint16 m_port;
};

#endif // MYSERVER_H
