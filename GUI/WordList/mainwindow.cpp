#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>
#include <stdlib.h>
#include <QtDebug>
#include <QProcess>
#include <QTextBlock>
#include <QTextDocument>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // connect(ui->convertButton,SIGNAL(clicked()),this,SLOT(convertButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_convertButton_clicked()
{
    // accept();
    QProcess* wordListCaller = new QProcess(this);

    QTextDocument* input = ui->InputText->document();
    QTextBlock textBlock;
    QFile tempInputFile("./tempInputFile.txt");
    tempInputFile.open(QIODevice::WriteOnly);
    QTextStream ts(&tempInputFile);
    for(textBlock = input->begin();textBlock != input->end();textBlock = textBlock.next()){
        ts<<textBlock.text()<<endl;
    }

    QStringList arguments = QStringList();
    //arguments<<"../../Wordlist";
    //这里需要一个约束
    if(ui->mostWordCheck->isChecked()){
        arguments<<"-w";
    }
    if(ui->mostCharCheck->isChecked()){
        arguments<<"-c";
    }
    //这里需要一个约束
    if(ui->fixHeadCheck->isChecked()){
        QString headline = ui->fixHead->text();
        //std::string headLineStd = headline.toStdString();
        if(headline[0] <= 'a' || headline[0] >= 'z' || headline.length() < 1){

        }
        arguments<<"-h";
        arguments<<headline;
    }
    if(ui->fixTailCheck->isChecked()){
        QString tailline = ui->fixTail->text();
        //std::string headLineStd = headline.toStdString();
        if(tailline[0] <= 'a' || tailline[0] >= 'z' || tailline.length() < 1){

        }
        arguments<<"-t";
        arguments<<tailline;
    }
    if(ui->fixNumCheck->isChecked()){
        arguments<<"-n";
        arguments<<QString((char)(ui->fixNumber->value() + 48));
    }
    arguments<<"./tempInputFile.txt";

    wordListCaller->start("./WordlistCUI",arguments);
    wordListCaller->waitForFinished();
    //qDebug()<<arguments;

    QStringList cleanarguments = QStringList();
    cleanarguments<<"./tempInputFile.txt";
    wordListCaller->start("rm",cleanarguments);
    QFile resultFile("./solution.txt");
    resultFile.open(QIODevice::ReadOnly);
    ui->outputText->setText(resultFile.readAll());
}

void MainWindow::on_loadFromFile_clicked()
{
    QString inputFileName = QFileDialog::getOpenFileName(this,"选择数据文件","./","文本文件(*txt)");
    QFile inputFile(inputFileName);
    inputFile.open(QIODevice::ReadOnly);
    ui->InputText->setPlainText(inputFile.readAll());
    // qDebug() <<inputFileName;

}

void MainWindow::on_saveOutputFile_clicked()
{
    QString outputFileName = QFileDialog::getSaveFileName(this,"选择保存文件","./","文本文件(*txt)");
    QProcess* wordListCaller = new QProcess(this);
    QStringList saveArguments = QStringList();
    saveArguments<<"./solution.txt";
    saveArguments<<outputFileName;
    wordListCaller->start("mv",saveArguments);
}
