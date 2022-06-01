#include "httpclient.h"

HttpClient::HttpClient(QObject *parent) : QObject(parent)
{
    m_socket = new QTcpSocket(this);

    connect(m_socket, &QTcpSocket::connected, this, &HttpClient::connected);
    connect(m_socket, &QTcpSocket::readyRead, this, &HttpClient::readyRead);
}

void HttpClient::getHTTP(QString& host)
{
    m_socket->connectToHost(host, PORT);
    if (m_socket->waitForConnected(TIMEOUT) == 0) {
        // Trennt verbindung
        m_socket->disconnectFromHost();

        // Meldet, dass verbindung nicht hergestellt werden konnte
        m_signal = "connect failed!";
        emit sendData(m_signal);
    }
}


void HttpClient::connected()
{
    // normgerechter HTTP Request zum Server
    m_socket->write("GET / HTTP/1.1\r\nHost:" + m_host + "\r\n\r\n");
}

void HttpClient::readyRead()
{
    // HTTP-Antwort vom Server
    m_signal = m_socket->readAll();
    emit sendData(m_signal);
    m_socket->disconnectFromHost();
}

