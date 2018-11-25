#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

QMap<QString, int> variableMap;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}

