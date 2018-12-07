#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCamera>
#include <QCameraViewfinder>
#include <QKeyEvent>
#include <QCoreApplication>
#include <QByteArray>
#include <QString>
#include <QDebug>

/* Commands */
#define ENGINE 1
#define SPEED 2
#define REVERSE 4
#define DIRECTION 8
#define HEADLIGHTS 16
#define POSITION 32
#define HORN 64

#define ON 1
#define OFF 0

#define LEFT 1
#define FORWARD 0
#define RIGHT -1

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    /* Setup Camera */
    mainCamera = new QCamera("/dev/video0", this);
    mainCameraViewFinder = new QCameraViewfinder(this);
    mainCameraLayout = new QVBoxLayout();
    mainCamera->setViewfinder(mainCameraViewFinder);
    mainCameraLayout->addWidget(mainCameraViewFinder);
    ui->frameCamera->setLayout(mainCameraLayout);

    /* Prepare map */
    variableMap.insert("Engine", 0);
    variableMap.insert("Reverse", 0);
    variableMap.insert("Headlights", 0);
    variableMap.insert("Position", 0);
    variableMap.insert("Horn", 0);
    variableMap.insert("Direction", 0); // 1(left), 0(forward), -1(right)
    variableMap.insert("Speed", 0);
}

MainWindow::~MainWindow() {
    delete ui;
}

/* Creating command string that contains command type and command value */
QString addNewCommand(int commandType,int commandValue){

    if (commandValue > 128) {
        qDebug() << "Error in addNewCommand function - commandValue! ";
        exit(1);
    }
    QByteArray bytearray(18,'0');
    bytearray[17] = '\n';
    switch (commandType) {
        case 512:
            bytearray[0] = '1';
            break;
        case 256:
            bytearray[1] = '1';
            break;
        case 128:
            bytearray[2] = '1';
            break;
        case 64:
            bytearray[3] = '1';
            break;
        case 32:
            bytearray[4] = '1';
            break;
        case 16:
            bytearray[5] = '1';
            break;
        case 8:
            bytearray[6] = '1';
            break;
        case 4:
            bytearray[7] = '1';;
            break;
        case 2:
            bytearray[8] = '1';
            break;
        case 1:
            bytearray[9] = '1';
            break;
    }
    int i = 16;
    while(commandValue){
        if(commandValue % 2)
                bytearray[i] = '1';
        else
                bytearray[i]='0';
        commandValue = commandValue / 2;
        i--;
    }
    QString string(bytearray);
    return string;
}


void MainWindow::on_buttonCamera_clicked() {
    if(ui->labelCamera->text() == "OFF") {
        ui->labelCamera->setText("ON");
        mainCamera->start();
        ui->labelCamera->setStyleSheet("color: green");
    }
    else {
        ui->labelCamera->setText("OFF");
        mainCamera->stop();
        ui->labelCamera->setStyleSheet("color: red");
    }
}

void MainWindow::on_progressbarSpeed_valueChanged(int value)
{
    if ( value < 70 )
        ui->progressbarSpeed->setStyleSheet("selection-background-color:green");
    else if ( value >= 70 && value < 90)
        ui->progressbarSpeed->setStyleSheet("selection-background-color:yellow");
    else
        ui->progressbarSpeed->setStyleSheet("selection-background-color:red");
}

/*Button HORN*/
void MainWindow::on_buttonHorn_clicked()
{
    if(variableMap.value("Horn")) {
        variableMap["Horn"] = OFF;
        queue.append(addNewCommand(HORN,OFF));
        ui->labelHorn->setText("OFF");
        ui->labelHorn->setStyleSheet("color:red");
    }
    else {
        variableMap["Horn"] = ON;
        queue.append(addNewCommand(HORN,ON));
        ui->labelHorn->setText("ON");
        ui->labelHorn->setStyleSheet("color:green");
    }
}

/*Button POSITION*/
void MainWindow::on_buttonPosition_clicked()
{
    if(variableMap.value("Position")) {
        variableMap["Position"] = OFF;
        queue.append(addNewCommand(POSITION,OFF));
        ui->labelPosition->setText("OFF");
        ui->labelPosition->setStyleSheet("color:red");
    }
    else {
        variableMap["Position"] = ON;
        queue.append(addNewCommand(POSITION,ON));
        ui->labelPosition->setText("ON");
        ui->labelPosition->setStyleSheet("color:green");
    }
}

/*Button HEADLIGHTS*/
void MainWindow::on_buttonHeadlights_clicked()
{
    if(variableMap.value("Headlights")) {
        variableMap["Headlights"] = OFF;
        queue.append(addNewCommand(HEADLIGHTS,OFF));
        ui->labelHeadlights->setText("OFF");
        ui->labelHeadlights->setStyleSheet("color:red");
    }
    else {
        variableMap["Headlights"] = ON;
        queue.append(addNewCommand(HEADLIGHTS,ON));
        ui->labelHeadlights->setText("ON");
        ui->labelHeadlights->setStyleSheet("color:green");
    }
}

/*Button REVERSE*/
void MainWindow::on_buttonReverse_clicked()
{
    if(variableMap.value("Reverse")) {
        variableMap["Reverse"] = OFF;
        queue.append(addNewCommand(REVERSE,OFF));
        ui->labelReverse->setText("OFF");
        ui->labelReverse->setStyleSheet("color:red");
    }
    else {
        variableMap["Reverse"] = ON;
        queue.append(addNewCommand(REVERSE,ON));
        ui->labelReverse->setText("ON");
        ui->labelReverse->setStyleSheet("color:green");
    }
}

/*Button ENGINE*/
void MainWindow::on_buttonEngine_clicked()
{
    if(variableMap.value("Engine")) {
        variableMap["Engine"] = OFF;
        queue.append(addNewCommand(ENGINE,OFF));
        ui->labelEngine->setText("OFF");
        ui->labelEngine->setStyleSheet("color:red");
    }
    else {
        variableMap["Engine"] = ON;
        queue.append(addNewCommand(ENGINE,ON));
        ui->labelEngine->setText("ON");
        ui->labelEngine->setStyleSheet("color:green");
    }
}

/* Setup speed and direction */
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())
        event->ignore();
    else
    {
        if(event->key() == Qt::Key_A)
            {
                variableMap["Direction"] = LEFT;
                ui->labelDirection->setText("<<<<<<");
                queue.prepend(addNewCommand(DIRECTION, variableMap["Direction"]));
            }
        if(event->key() == Qt::Key_D)
            {
                variableMap["Direction"] = RIGHT;
                ui->labelDirection->setText(">>>>>>");
                queue.prepend(addNewCommand(DIRECTION, variableMap["Direction"]));
            }
        // Check Speed boundaries - TODO
        if(event->key() == Qt::Key_W)
            {
                   variableMap["Speed"] += 5;
                   ui->progressbarSpeed->setValue(variableMap["Speed"]);
                   queue.append(addNewCommand(SPEED,variableMap["Speed"]));
            }
        if(event->key() == Qt::Key_S)
            {
                   variableMap["Speed"] -= 5;
                   ui->progressbarSpeed->setValue(variableMap["Speed"]);
                   queue.append(addNewCommand(SPEED,variableMap["Speed"]));
            }
        else
            QWidget::keyPressEvent(event);
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())
        event->ignore();
    else
    {
        if((event->key() == Qt::Key_A) || (event->key() == Qt::Key_D))
        {
            variableMap["Direction"] = FORWARD;
            ui->labelDirection->setText("---------");
            queue.prepend(addNewCommand(DIRECTION, variableMap["Direction"]));
        }
        else
            QWidget::keyReleaseEvent(event);
    }
}
