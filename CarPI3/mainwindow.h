#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

extern QMap<QString, int> variableMap;
extern QList<QString> queue;

namespace Ui {
class MainWindow;
}

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QSerialPort;
class QString;
class QTimer;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private slots:
    void on_buttonCamera_clicked();
    void on_progressbarSpeed_valueChanged(int value);
    void on_buttonHorn_clicked();
    void on_buttonPosition_clicked();
    void on_buttonHeadlights_clicked();
    void on_buttonReverse_clicked();
    void on_buttonEngine_clicked();
    void on_Timer();

private:
    Ui::MainWindow *ui;

    /* Camera members */
    QCamera *mainCamera;
    QCameraViewfinder *mainCameraViewFinder;
    QVBoxLayout *mainCameraLayout;
    QSerialPort *serialOutput;
    QTimer *timer;
};

#endif // MAINWINDOW_H
