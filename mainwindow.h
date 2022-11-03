#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonExit_clicked();

    void on_plainTextEdit_textChanged();

    void on_pushButtonHelp_clicked();

    void on_pushButtonOpen_clicked();

    void on_pushButtonSave_clicked();

private:
    Ui::MainWindow *ui;
    QString buffer;
};
#endif // MAINWINDOW_H
