#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCamera>
#include <QCameraViewfinder>

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
}



void MainWindow::on_buttonHorn_clicked()
{
}

void MainWindow::on_buttonPosition_clicked()
{
}

void MainWindow::on_buttonHeadlights_clicked()
{
}

void MainWindow::on_buttonReverse_clicked()
{
}

void MainWindow::on_buttonEngine_clicked()
{
}
