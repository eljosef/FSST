#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    m_gpio = new Gpio(this);
    m_server = new QTcpServer(this);

    // 2 Paare
    connect(m_server, &QTcpServer::newConnection, this, &Server::myNewConnection);

}

void Server::start()
{
    m_server->listen(QHostAddress::Any, PORT);
    qDebug() << "Server lauscht auf: " << PORT;
}

void Server::myNewConnection()
{
    // Verbindung zum Client über m_socket
    m_socket = m_server->nextPendingConnection();
    qDebug() << "Verbindung zum server hergestellt";
    connect(m_socket, &QTcpSocket::disconnected, this, &Server::myClientDisconnect);
    connect(m_socket, &QTcpSocket::readyRead, this, &Server::myServerRead);
    m_gpio->set(18, 1);
}

void Server::myClientDisconnect()
{
    m_socket->disconnect();
    qDebug() << "Verbindung zum Client getrennt";
    m_gpio->set(18, 0);
}

void Server::myServerRead()
{
    // qDebug() << "Daten vom Client eingelangt: ";
    QByteArray message = m_socket->readAll();
    qDebug() << "Daten vom Client eingelangt: " << message;

    // Nachrich invertieren
    std::reverse(message.begin(), message.end());
    // entfernt ungedrehtes \n
    message = message.trimmed() + "\n";
    qDebug() << "Daten zum Client eingelangt: " << message;
    m_socket->write("From Server: " + message);
}
