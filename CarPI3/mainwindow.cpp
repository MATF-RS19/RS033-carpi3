#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCamera>
#include <QCameraViewfinder>
#include <QKeyEvent>

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
    variableMap.insert("Direction", 0);
    variableMap.insert("Speed", 0);
}

MainWindow::~MainWindow() {
    delete ui;
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



void MainWindow::on_buttonHorn_clicked()
{
    if(variableMap.value("Horn")) {
        variableMap["Horn"] = 0;
        ui->labelHorn->setText("OFF");
        ui->labelHorn->setStyleSheet("color:red");
    }
    else {
        variableMap["Horn"] = 1;
        ui->labelHorn->setText("ON");
        ui->labelHorn->setStyleSheet("color:green");
    }
}

void MainWindow::on_buttonPosition_clicked()
{
    if(variableMap.value("Position")) {
        variableMap["Position"] = 0;
        ui->labelPosition->setText("OFF");
        ui->labelPosition->setStyleSheet("color:red");
    }
    else {
        variableMap["Position"] = 1;
        ui->labelPosition->setText("ON");
        ui->labelPosition->setStyleSheet("color:green");
    }
}

void MainWindow::on_buttonHeadlights_clicked()
{
    if(variableMap.value("Headlights")) {
        variableMap["Headlights"] = 0;
        ui->labelHeadlights->setText("OFF");
        ui->labelHeadlights->setStyleSheet("color:red");
    }
    else {
        variableMap["Headlights"] = 1;
        ui->labelHeadlights->setText("ON");
        ui->labelHeadlights->setStyleSheet("color:green");
    }
}

void MainWindow::on_buttonReverse_clicked()
{
    if(variableMap.value("Reverse")) {
        variableMap["Reverse"] = 0;
        ui->labelReverse->setText("OFF");
        ui->labelReverse->setStyleSheet("color:red");
    }
    else {
        variableMap["Reverse"] = 1;
        ui->labelReverse->setText("ON");
        ui->labelReverse->setStyleSheet("color:green");
    }
}

void MainWindow::on_buttonEngine_clicked()
{
    if(variableMap.value("Engine")) {
        variableMap["Engine"] = 0;
        ui->labelEngine->setText("OFF");
        ui->labelEngine->setStyleSheet("color:red");
    }
    else {
        variableMap["Engine"] = 1;
        ui->labelEngine->setText("ON");
        ui->labelEngine->setStyleSheet("color:green");
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())
        event->ignore();
    else
    {
        if(event->key() == Qt::Key_A)
            {
                ui->labelDirection->setText("<<<<<<");
            }
        if(event->key() == Qt::Key_D)
            {
                ui->labelDirection->setText(">>>>>>");
            }
        if(event->key() == Qt::Key_W)
            {
                   variableMap["Speed"] += 5;
                   ui->progressbarSpeed->setValue(variableMap["Speed"]);
            }
        if(event->key() == Qt::Key_S)
            {
                   variableMap["Speed"] -= 5;
                   ui->progressbarSpeed->setValue(variableMap["Speed"]);
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
            ui->labelDirection->setText("---------");
        }
        else
            QWidget::keyReleaseEvent(event);
    }
}
