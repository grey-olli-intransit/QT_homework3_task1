#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCoreApplication>
#include <QPlainTextEdit>
#include <QDebug>
#include <QFile>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonExit_clicked()
{
    QCoreApplication::exit(0);
}


void MainWindow::on_plainTextEdit_textChanged()
{
    buffer = ui->plainTextEdit->document()->toPlainText();

    //qDebug() << buffer;
}


void MainWindow::on_pushButtonHelp_clicked()
{
    QFile helpfile(":/help/helpfile.txt");
    helpfile.open(QIODevice::ReadOnly);
    QByteArray ba = helpfile.readAll();
    QString helptext(ba);
    ui->plainTextEdit->document()->setPlainText(helptext);
}


void MainWindow::on_pushButtonOpen_clicked()
{
    QString path = QFileDialog::getOpenFileName();
    if (path.isEmpty()) return; // user pressed Escape or Cancel in dialogue.
    QFile userfile(path);
    userfile.open(QIODevice::ReadOnly); // Для записи есть отдельная кнопка, так что пусть будет r/o.
    QByteArray ba = userfile.readAll();
    QString filecontent(ba);
    ui->plainTextEdit->document()->setPlainText(filecontent);
}


void MainWindow::on_pushButtonSave_clicked()
{
    QString path = QFileDialog::getSaveFileName();
    if (path.isEmpty()) return; // user pressed Escape or Cancel in dialogue.
    QFile userfile(path);
    userfile.open(QIODevice::Append); // пусть добавляет в конец
    buffer = ui->plainTextEdit->document()->toPlainText();
    QByteArray ba = buffer.toUtf8();
    userfile.write(ba);
    userfile.flush();
    userfile.close();
}

