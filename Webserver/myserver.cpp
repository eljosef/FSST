#include "myserver.h"
#include <QDebug>

MyServer::MyServer(quint16 port,QObject *parent) :
    QObject(parent), m_port(port)
{
    m_webserver = new QTcpServer(this);

    connect(m_webserver, &QTcpServer::newConnection,
            this, &MyServer::myNewConnection);
}

void MyServer::start()
{
    m_webserver->listen(QHostAddress::Any, m_port);
}

void MyServer::myNewConnection()
{
    qDebug() << "New connection to Server!";
    m_socket = m_webserver->nextPendingConnection();
    connect(m_socket, &QTcpSocket::readyRead,
            this, &MyServer::myServerRead);
}

void MyServer::myServerRead()
{
    while(m_socket->bytesAvailable()) {
        QString message = m_socket->readAll();
        qDebug() << message;
    }

    // 1) send HTTP/HTML answer to client

    // 2) Disconnect Socket
}
