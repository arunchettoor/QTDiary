#include "diary.h"
#include "ui_diary.h"
#include <iostream>
#include <fstream>
#include <string>
#include <qdatetime.h>

#include <QTextStream>

#include <QFileDialog>

#define folder "files"

Diary::Diary(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Diary)
{
    currdate = new QString();
    ui->setupUi(this);
    ui->checkBox_3->setCheckable(1);
    if(~QDir(folder).exists())
        QDir().mkdir(folder);
}

Diary::~Diary()
{
    delete ui;
}


void Diary::on_calendarWidget_selectionChanged()
{

}

void Diary::on_calendarWidget_clicked(const QDate &date)
{
    *currdate = date.toString("yyyy.MM.dd");
    //QTextStream out(stdout);
    //out << QString(date.toString("yyyy.MM.dd"));
    ui->checkBox_3->setChecked(0);
    QString fname = "files/"+*currdate;
    //out << fname;
    QFile file(fname);

    file.open(QFile::ReadOnly | QFile::Text);

    QTextStream ReadFile(&file);
    ui->plainTextEdit->setReadOnly(true);
    ui->plainTextEdit->setPlainText(ReadFile.readAll());
    file.close();

}

void Diary::on_pushButton_2_clicked()
{
     QCoreApplication::exit();
}

void Diary::on_actionExit_triggered()
{
    QCoreApplication::exit();
}

void Diary::on_plainTextEdit_textChanged()
{

}

void Diary::on_pushButton_clicked()
{
    QString fname = "files/"+*currdate;
    QFile file(fname);

    file.open(QFile::ReadWrite | QFile::Text);

    QTextStream OutFile(&file);
    QString text = ui->plainTextEdit->toPlainText();
    OutFile << text;

    file.close();
}



void Diary::on_checkBox_3_clicked(bool checked)
{
    if(checked)
        ui->plainTextEdit->setReadOnly(false);
    else
        ui->plainTextEdit->setReadOnly(true);
}

void Diary::on_actionSave_triggered()
{
    QString fname = "files/"+*currdate;
    QFile file(fname);

    file.open(QFile::ReadWrite | QFile::Text);

    QTextStream OutFile(&file);
    QString text = ui->plainTextEdit->toPlainText();
    OutFile << text;

    file.close();
}
