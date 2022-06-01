#include "config.h"
#include "widget.h"
#include <QGridLayout>
#include <QDebug>
#include <QLCDNumber>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{   
    // Widget s &QTimer::timeouttructure
    setWindowTitle("ButtonMonitor");
    resize(300, 100);
    QGridLayout* grid = new QGridLayout(this);
    setLayout(grid);

    // Labels for input pins / buttons
    int column = 0;

    QLabel* Down = new QLabel("Down", this);
    QLabel* Up = new QLabel("Up", this);
    QLabel* Reset = new QLabel("Reset", this);
    Down->setAlignment(Qt::AlignCenter);
    Up->setAlignment(Qt::AlignCenter);
    Reset->setAlignment(Qt::AlignCenter);
    grid->addWidget(Down, 0, column + 2);
    grid->addWidget(Up, 0, column);
    grid->addWidget(Reset, 0, column + 1);

    QLabel* Counterl = new QLabel("Counter:", this);
    Counterl->setAlignment(Qt::AlignCenter);
    grid->addWidget(Counterl,3,column);

    QString counterstring = QString::number(this->counter);
    //QLabel* wcounter = new QLabel(counterstring,this);
    //wcounter->setAlignment(Qt::AlignCenter);
    counterLcd->setSegmentStyle(QLCDNumber::Flat);
    counterLcd->setFrameStyle(0);
    grid->addWidget(counterLcd,3,column+1);
    for (auto pin : BUTTONS) {

        // pin numbers
        QLabel* label = new QLabel("GPIO " + QString::number(pin), this);
        label->setAlignment(Qt::AlignCenter);
        grid->addWidget(label, 1, column); // links oben (1. Zeile / 1. - 3. Spalte)

        // pin states
        QLabel* state = new QLabel("0", this);
        state->setAlignment(Qt::AlignCenter);
        grid->addWidget(state, 2, column++); // links oben (2. Zeile / 1. - 3. Spalte)
        m_input_display.push_back(state);
    }

    //m_input_display.push_back(wcounter);

    // initialize hardware
    m_gpio = new gpio();

    m_timer = new QTimer(this);
    // Connect QTimer (Signal) with GUI function (Slot) "update display"
    connect(m_timer, &QTimer::timeout, this, &Widget::updateButtonState);
    m_timer->start(T_UPDATE/10);
}

Widget::~Widget()
{

}

void Widget::updateButtonState()
{
    int n = 0;
    for (auto pin : BUTTONS){
        int state = !m_gpio->get(pin);
        m_input_display[n++]->setText(QString::number(state));

        if(prestate[n] != state)
        {
            able = true;
            prestate[n] = 0;

        }
        else {
            able = false;
        }


        if(state == 1 && n == 2 && able)
        {
            this->counter = 0;
            //m_input_display[3]->setText(QString::number(this->counter));
            counterLcd->display(counter);
            prestate[n] = 1;
        }

        if(state == 1 && n == 1 && able)
        {
            if(this->counter < 99)
            {
            this->counter++;
            }else{
                this->counter = 0;
            }
            //m_input_display[3]->setText(QString::number(this->counter));
            counterLcd->display(counter);
            prestate[n] = 1;
        }

        if(state == 1 && n == 3 && able)
        {
            if(this->counter > 0)
            {
            this->counter--;
            }else{
                this->counter = 99;
            }
            //m_input_display[3]->setText(QString::number(this->counter));
            counterLcd->display(counter);
            prestate[n] = 1;
        }
    }
}
