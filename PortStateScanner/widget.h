#ifndef WIDGET_H
#define WIDGET_H

#include "ui_widget.h"
#include "scanner.h"

class Widget : public QWidget, private Ui::Widget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
private slots:
    void on_scanButton_clicked(); // from user
    void showResult(quint16 port, bool status); // from scanner

private:
    Scanner m_scanner;
};

#endif // WIDGET_H
