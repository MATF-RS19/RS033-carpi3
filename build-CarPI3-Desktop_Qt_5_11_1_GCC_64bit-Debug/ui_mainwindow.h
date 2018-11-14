/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupboxMain;
    QFormLayout *formLayout;
    QPushButton *buttonEngine;
    QLabel *labelEngine;
    QLabel *infolabelSpeed;
    QProgressBar *progressbarSpeed;
    QPushButton *buttonReverse;
    QLabel *labelReverse;
    QLabel *infolabelDirection;
    QLabel *labelDirection;
    QPushButton *buttonHeadlights;
    QLabel *labelHeadlights;
    QPushButton *buttonPosition;
    QLabel *labelPosition;
    QPushButton *buttonHorn;
    QLabel *labelHorn;
    QPushButton *buttonCamera;
    QLabel *labelCamera;
    QSpacerItem *verticalSpacer;
    QFrame *frameCamera;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(731, 342);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QStringLiteral("background-color: grey"));
        gridLayout = new QGridLayout(MainWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupboxMain = new QGroupBox(MainWindow);
        groupboxMain->setObjectName(QStringLiteral("groupboxMain"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupboxMain->sizePolicy().hasHeightForWidth());
        groupboxMain->setSizePolicy(sizePolicy1);
        groupboxMain->setMaximumSize(QSize(16777215, 16777215));
        groupboxMain->setStyleSheet(QStringLiteral("background-color: white"));
        groupboxMain->setAlignment(Qt::AlignCenter);
        formLayout = new QFormLayout(groupboxMain);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        buttonEngine = new QPushButton(groupboxMain);
        buttonEngine->setObjectName(QStringLiteral("buttonEngine"));

        formLayout->setWidget(0, QFormLayout::LabelRole, buttonEngine);

        labelEngine = new QLabel(groupboxMain);
        labelEngine->setObjectName(QStringLiteral("labelEngine"));
        labelEngine->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, labelEngine);

        infolabelSpeed = new QLabel(groupboxMain);
        infolabelSpeed->setObjectName(QStringLiteral("infolabelSpeed"));
        infolabelSpeed->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, infolabelSpeed);

        progressbarSpeed = new QProgressBar(groupboxMain);
        progressbarSpeed->setObjectName(QStringLiteral("progressbarSpeed"));
        progressbarSpeed->setValue(0);

        formLayout->setWidget(1, QFormLayout::FieldRole, progressbarSpeed);

        buttonReverse = new QPushButton(groupboxMain);
        buttonReverse->setObjectName(QStringLiteral("buttonReverse"));

        formLayout->setWidget(2, QFormLayout::LabelRole, buttonReverse);

        labelReverse = new QLabel(groupboxMain);
        labelReverse->setObjectName(QStringLiteral("labelReverse"));
        labelReverse->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(2, QFormLayout::FieldRole, labelReverse);

        infolabelDirection = new QLabel(groupboxMain);
        infolabelDirection->setObjectName(QStringLiteral("infolabelDirection"));
        infolabelDirection->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(3, QFormLayout::LabelRole, infolabelDirection);

        labelDirection = new QLabel(groupboxMain);
        labelDirection->setObjectName(QStringLiteral("labelDirection"));
        labelDirection->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(3, QFormLayout::FieldRole, labelDirection);

        buttonHeadlights = new QPushButton(groupboxMain);
        buttonHeadlights->setObjectName(QStringLiteral("buttonHeadlights"));

        formLayout->setWidget(4, QFormLayout::LabelRole, buttonHeadlights);

        labelHeadlights = new QLabel(groupboxMain);
        labelHeadlights->setObjectName(QStringLiteral("labelHeadlights"));
        labelHeadlights->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(4, QFormLayout::FieldRole, labelHeadlights);

        buttonPosition = new QPushButton(groupboxMain);
        buttonPosition->setObjectName(QStringLiteral("buttonPosition"));

        formLayout->setWidget(5, QFormLayout::LabelRole, buttonPosition);

        labelPosition = new QLabel(groupboxMain);
        labelPosition->setObjectName(QStringLiteral("labelPosition"));
        labelPosition->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(5, QFormLayout::FieldRole, labelPosition);

        buttonHorn = new QPushButton(groupboxMain);
        buttonHorn->setObjectName(QStringLiteral("buttonHorn"));

        formLayout->setWidget(6, QFormLayout::LabelRole, buttonHorn);

        labelHorn = new QLabel(groupboxMain);
        labelHorn->setObjectName(QStringLiteral("labelHorn"));
        labelHorn->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(6, QFormLayout::FieldRole, labelHorn);

        buttonCamera = new QPushButton(groupboxMain);
        buttonCamera->setObjectName(QStringLiteral("buttonCamera"));

        formLayout->setWidget(7, QFormLayout::LabelRole, buttonCamera);

        labelCamera = new QLabel(groupboxMain);
        labelCamera->setObjectName(QStringLiteral("labelCamera"));
        labelCamera->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(7, QFormLayout::FieldRole, labelCamera);


        verticalLayout->addWidget(groupboxMain);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        frameCamera = new QFrame(MainWindow);
        frameCamera->setObjectName(QStringLiteral("frameCamera"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frameCamera->sizePolicy().hasHeightForWidth());
        frameCamera->setSizePolicy(sizePolicy2);
        frameCamera->setMinimumSize(QSize(505, 325));
        frameCamera->setStyleSheet(QLatin1String("background-color: white\n"
""));
        frameCamera->setFrameShape(QFrame::StyledPanel);
        frameCamera->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frameCamera, 0, 1, 1, 1);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupboxMain->setTitle(QApplication::translate("MainWindow", "Car PI 3", nullptr));
        buttonEngine->setText(QApplication::translate("MainWindow", "Engine", nullptr));
        labelEngine->setText(QApplication::translate("MainWindow", "OFF", nullptr));
        infolabelSpeed->setText(QApplication::translate("MainWindow", "Speed", nullptr));
        buttonReverse->setText(QApplication::translate("MainWindow", "Reverse", nullptr));
        labelReverse->setText(QApplication::translate("MainWindow", "OFF", nullptr));
        infolabelDirection->setText(QApplication::translate("MainWindow", "Direction", nullptr));
        labelDirection->setText(QApplication::translate("MainWindow", "-----", nullptr));
        buttonHeadlights->setText(QApplication::translate("MainWindow", "Headlights", nullptr));
        labelHeadlights->setText(QApplication::translate("MainWindow", "OFF", nullptr));
        buttonPosition->setText(QApplication::translate("MainWindow", "Position", nullptr));
        labelPosition->setText(QApplication::translate("MainWindow", "OFF", nullptr));
        buttonHorn->setText(QApplication::translate("MainWindow", "Horn", nullptr));
        labelHorn->setText(QApplication::translate("MainWindow", "OFF", nullptr));
        buttonCamera->setText(QApplication::translate("MainWindow", "Camera", nullptr));
        labelCamera->setText(QApplication::translate("MainWindow", "OFF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
