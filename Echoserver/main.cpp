#include <QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Apllication wird gestarten
    Server server;
    server.start();

    return a.exec();
}
