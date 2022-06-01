#include "scanner.h"

Scanner::Scanner(QObject *parent) : QObject(parent)
{

}

void Scanner::scan(QString& host, quint16 port)
{
    bool status = false; // Default immer auf 0
    // bool = 0 oder 1

    // Verbindung wird hergestellt
    m_socket.connectToHost(host, port);

    // Prüft obverbindung hergestellt werden kann
    // TIMEOUT: globale Variable
    if (m_socket.waitForConnected(TIMEOUT)) {
        // Trennt verbindung
        m_socket.disconnectFromHost();
        // Meldet, dass verbindung hergestellt worden ist
        status = true;
    }

    emit scanFinished(port, status);
}
