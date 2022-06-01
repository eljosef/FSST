#include "widget.h"
// scanner.h includieren, damit man damit interagieren kann
// Dasselbe, wie auch eine private: scanner bei widget.h !!!
#include "scanner.h"
// Für Popup ausgabe
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    // Verbindung muss hergestellt werden
    // "this" Signal kommt von der Klasse Scanner und Ziel ist dieses Objekt
    connect(&m_scanner, &Scanner::scanFinished, this, &Widget::showResult);
}

// Wird ausgeführt wenn der Button gedrückt wird
void Widget::on_scanButton_clicked()
{
    // Stelle verbindung mit den Widget Values auf
    // -> sind Pointer
    QString host = hostEntry->text();
    // Man bekommt einen String als wert, dieser muss umgewandelt werden
    // toUShort = to unsigned short
    quint16 port = portEntry->text().toUShort();

    // Funktion für Scan wird ausgeführt
    m_scanner.scan(host, port);
}

// Gibt Ergebnis an Text Widget
// Muss als Slot in widget.h definiert sein
void Widget::showResult(quint16 port, bool status)
{
    // Shows result in Debug window
    qDebug() << port << status;

    // Bedingte Zuweisung, verändert 0 mit closed und 1 mit open
    QString message = (status == true) ? "open" : "closed";
    // status braucht kein QString:: weil der Datentyp es nicht zum vergleichen verlangt

    // Sends Text to Textwidget
    // message braucht kein QString:: weil es bereits ein QString ist
    QString result = QString::number(port) + "->" + message;
    // Old Message
    // QString result = QString::number(port) + "->" + QString::number(status);
    resultBrowser->append(result);
}
