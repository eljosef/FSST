#ifndef SCANNER_H
#define SCANNER_H

#include <QObject>
// include needed libraries
#include <QAbstractSocket>
#include <QTcpSocket>

const int TIMEOUT = 5000; // 5s, verwendet in scanner.cpp

class Scanner : public QObject
{
    Q_OBJECT
public:
    explicit Scanner(QObject *parent = nullptr);
    // scan funktion
    // port muss quint16 sein weil das verlangt wird
    void scan(QString& host, quint16 port);

signals:
    void scanFinished(quint16 port, bool status);

public slots:

// Erstelle Private Klasse
private:
    QTcpSocket m_socket;
};

#endif // SCANNER_H
