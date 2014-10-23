#ifndef DIARY_H
#define DIARY_H

#include <QMainWindow>
#include <string>
#include <qdatetime.h>

namespace Ui {
class Diary;
}

class Diary : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Diary(QWidget *parent = 0);
    ~Diary();
    //void getFile(QString fileName);
    QString *currdate;
private slots:
    void on_calendarWidget_selectionChanged();

    void on_calendarWidget_clicked(const QDate &date);

    void on_pushButton_2_clicked();

    void on_actionExit_triggered();

    void on_plainTextEdit_textChanged();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_checkBox_3_clicked(bool checked);

    void on_actionSave_triggered();

private:
    Ui::Diary *ui;
};

#endif // DIARY_H
