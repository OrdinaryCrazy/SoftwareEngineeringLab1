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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_convertButton_clicked()
{
    QProcess* wordListCaller = new QProcess(this);
    bool everythingOK = true;
    QTextDocument* input = ui->InputText->document();
    QTextBlock textBlock;
    QFile tempInputFile("./tempInputFile.txt");
    tempInputFile.open(QIODevice::WriteOnly);
    QTextStream ts(&tempInputFile);
    for(textBlock = input->begin();textBlock != input->end();textBlock = textBlock.next()){
        ts<<textBlock.text()<<endl;
    }

    QStringList arguments = QStringList();
    // 检查选项设置的合法性
    if(ui->mostCharCheck->isChecked() == ui->mostWordCheck->isChecked() || \
            (ui->fixNumCheck->isChecked() && \
            (ui->fixHeadCheck->isChecked() || ui->fixTailCheck->isChecked() || ui->mostCharCheck->isChecked())))
    {
        QLabel* label = new QLabel();
        label->setWindowTitle("Wrong argument usage.");
        label->setText("<h2><font color=red>使用确定单词数量查询时请勿设置固定开头或结尾字母，且勿选择字母最长模式</font></h2>\r\n\
                        <h2><font color=red>请确定搜索模式：单词数量最多 / 字母数量最多</font></h2>");
        //label->resize(200,200);
        label->show();
        everythingOK = false;
    }
    // 依次设置命令行参数
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
        if(headline[0] < 'a' || headline[0] > 'z' || headline.length() < 1){
            QLabel* label = new QLabel();
            label->setWindowTitle("Wrong argument usage.");
            label->setText("<h2><font color=red>非法开头字母设置（必填 && 只接受小写英文字母）</font></h2>");
            everythingOK = false;
            label->show();
        }
        arguments<<"-h";
        arguments<<headline;
    }
    if(ui->fixTailCheck->isChecked()){
        QString tailline = ui->fixTail->text();
        if(tailline[0] < 'a' || tailline[0] > 'z' || tailline.length() < 1){
            QLabel* label = new QLabel();
            label->setWindowTitle("Wrong argument usage.");
            label->setText("<h2><font color=red>非法结尾字母设置（必填 && 只接受小写英文字母）</font></h2>");
            everythingOK = false;
            label->show();
        }
        arguments<<"-t";
        arguments<<tailline;
    }
    if(ui->fixNumCheck->isChecked()){
        arguments<<"-n";
        arguments<<QString((char)(ui->fixNumber->value() + 48));
    }
    arguments<<"./tempInputFile.txt";
    //满足条件后调用命令行程序
    if(everythingOK){
        wordListCaller->start("./WordlistCUI",arguments);
        wordListCaller->waitForFinished();
        // 删除可能的临时文件
        QStringList cleanarguments = QStringList();
        cleanarguments<<"./tempInputFile.txt";
        wordListCaller->start("rm",cleanarguments);
        // 将结果读取到输出区
        QFile resultFile("./solution.txt");
        resultFile.open(QIODevice::ReadOnly);
        ui->outputText->setText(resultFile.readAll());
    }
}

void MainWindow::on_loadFromFile_clicked()
{
    QString inputFileName = QFileDialog::getOpenFileName(this,"选择数据文件","./","文本文件(*txt)");
    QFile inputFile(inputFileName);
    inputFile.open(QIODevice::ReadOnly);
    ui->InputText->setPlainText(inputFile.readAll());
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
