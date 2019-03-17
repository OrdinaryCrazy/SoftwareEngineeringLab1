#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void on_convertButton_clicked();
    void on_loadFromFile_clicked();
    void on_saveOutputFile_clicked();
    void Result(int a);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
