#include "setwindow.h"
#include "ui_setwindow.h"
#include <QFileDialog>
#include "set.h"

SetWindow::SetWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SetWindow)
{

    ui->setupUi(this);
}

SetWindow::~SetWindow()
{
    delete ui;
}

void SetWindow::on_btnD1_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(nullptr, tr("Выберите файл в котором содержется сеты!"),
                                                    "./", tr("Текстовый документ (*.txt)"));
    ui->lnEdt1->setText(filePath);
}

void SetWindow::on_btnD2_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(nullptr, tr("Выберите файл в котором содержется сеты!"),
                                                    "./", tr("Текстовый документ (*.txt)"));
    ui->lnEdt2->setText(filePath);
}

void SetWindow::on_btnStr_clicked()
{
    Set s1,s2;

    std::string current_locale_text = ui->lnEdt1->text().toLocal8Bit().constData();
    getFromFile(s1,current_locale_text);
    ui->outArea->append("Первое множество:");
    ui->outArea->append(s1.toString());
    current_locale_text = ui->lnEdt2->text().toLocal8Bit().constData();
    getFromFile(s2,current_locale_text);
    ui->outArea->append("Второе множество:");
    ui->outArea->append(s2.toString());
    ui->outArea->append("Их пересечения:");
    s1=s1&&s2;
    ui->outArea->append(s1.toString());

}
