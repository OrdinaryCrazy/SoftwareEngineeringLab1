/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *inputLabel;
    QPlainTextEdit *InputText;
    QVBoxLayout *verticalLayout;
    QRadioButton *mostWordCheck;
    QRadioButton *mostCharCheck;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *fixHeadCheck;
    QLineEdit *fixHead;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *fixTailCheck;
    QLineEdit *fixTail;
    QHBoxLayout *horizontalLayout;
    QCheckBox *fixNumCheck;
    QSpinBox *fixNumber;
    QPushButton *convertButton;
    QPushButton *loadFromFile;
    QPushButton *saveOutputFile;
    QVBoxLayout *verticalLayout_3;
    QLabel *outputLabel;
    QTextBrowser *outputText;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1062, 538);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("AR PL UKai CN"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 1041, 441));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("AR PL UKai CN"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        verticalLayout_4->addWidget(label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        inputLabel = new QLabel(widget);
        inputLabel->setObjectName(QString::fromUtf8("inputLabel"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("AR PL UKai CN"));
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setWeight(75);
        font2.setKerning(true);
        inputLabel->setFont(font2);
        inputLabel->setTextFormat(Qt::PlainText);
        inputLabel->setScaledContents(false);
        inputLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(inputLabel);

        InputText = new QPlainTextEdit(widget);
        InputText->setObjectName(QString::fromUtf8("InputText"));

        verticalLayout_2->addWidget(InputText);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mostWordCheck = new QRadioButton(widget);
        mostWordCheck->setObjectName(QString::fromUtf8("mostWordCheck"));
        mostWordCheck->setFont(font);

        verticalLayout->addWidget(mostWordCheck);

        mostCharCheck = new QRadioButton(widget);
        mostCharCheck->setObjectName(QString::fromUtf8("mostCharCheck"));
        mostCharCheck->setFont(font);

        verticalLayout->addWidget(mostCharCheck);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        fixHeadCheck = new QCheckBox(widget);
        fixHeadCheck->setObjectName(QString::fromUtf8("fixHeadCheck"));

        horizontalLayout_2->addWidget(fixHeadCheck);

        fixHead = new QLineEdit(widget);
        fixHead->setObjectName(QString::fromUtf8("fixHead"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fixHead->sizePolicy().hasHeightForWidth());
        fixHead->setSizePolicy(sizePolicy1);
        fixHead->setMaxLength(1);

        horizontalLayout_2->addWidget(fixHead);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        fixTailCheck = new QCheckBox(widget);
        fixTailCheck->setObjectName(QString::fromUtf8("fixTailCheck"));

        horizontalLayout_3->addWidget(fixTailCheck);

        fixTail = new QLineEdit(widget);
        fixTail->setObjectName(QString::fromUtf8("fixTail"));
        sizePolicy1.setHeightForWidth(fixTail->sizePolicy().hasHeightForWidth());
        fixTail->setSizePolicy(sizePolicy1);
        fixTail->setMaxLength(1);

        horizontalLayout_3->addWidget(fixTail);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        fixNumCheck = new QCheckBox(widget);
        fixNumCheck->setObjectName(QString::fromUtf8("fixNumCheck"));

        horizontalLayout->addWidget(fixNumCheck);

        fixNumber = new QSpinBox(widget);
        fixNumber->setObjectName(QString::fromUtf8("fixNumber"));

        horizontalLayout->addWidget(fixNumber);


        verticalLayout->addLayout(horizontalLayout);

        convertButton = new QPushButton(widget);
        convertButton->setObjectName(QString::fromUtf8("convertButton"));
        convertButton->setEnabled(true);
        sizePolicy1.setHeightForWidth(convertButton->sizePolicy().hasHeightForWidth());
        convertButton->setSizePolicy(sizePolicy1);
        convertButton->setAutoRepeatDelay(296);

        verticalLayout->addWidget(convertButton);

        loadFromFile = new QPushButton(widget);
        loadFromFile->setObjectName(QString::fromUtf8("loadFromFile"));

        verticalLayout->addWidget(loadFromFile);

        saveOutputFile = new QPushButton(widget);
        saveOutputFile->setObjectName(QString::fromUtf8("saveOutputFile"));

        verticalLayout->addWidget(saveOutputFile);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        outputLabel = new QLabel(widget);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));
        outputLabel->setFont(font1);
        outputLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(outputLabel);

        outputText = new QTextBrowser(widget);
        outputText->setObjectName(QString::fromUtf8("outputText"));

        verticalLayout_3->addWidget(outputText);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1062, 28));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "WordList", nullptr));
        label->setText(QApplication::translate("MainWindow", "WordList \347\250\213\345\272\217\350\257\264\346\230\216\357\274\232", nullptr));
        inputLabel->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245\345\214\272", nullptr));
        mostWordCheck->setText(QApplication::translate("MainWindow", "\346\234\200\345\244\232\345\215\225\350\257\215\346\225\260\351\207\217", nullptr));
        mostCharCheck->setText(QApplication::translate("MainWindow", "\346\234\200\345\244\232\345\255\227\346\257\215\346\225\260\351\207\217", nullptr));
        fixHeadCheck->setText(QApplication::translate("MainWindow", "\345\233\272\345\256\232\345\274\200\345\244\264", nullptr));
        fixTailCheck->setText(QApplication::translate("MainWindow", "\345\233\272\345\256\232\347\273\223\345\260\276", nullptr));
        fixNumCheck->setText(QApplication::translate("MainWindow", "\345\233\272\345\256\232\345\215\225\350\257\215\344\270\252\346\225\260", nullptr));
        convertButton->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242\345\215\225\350\257\215\351\223\276", nullptr));
        loadFromFile->setText(QApplication::translate("MainWindow", "\344\273\216\346\226\207\344\273\266\345\212\240\350\275\275\350\276\223\345\205\245", nullptr));
        saveOutputFile->setText(QApplication::translate("MainWindow", "\345\260\206\347\273\223\346\236\234\345\257\274\345\207\272\345\210\260\346\226\207\344\273\266", nullptr));
        outputLabel->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\345\214\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
