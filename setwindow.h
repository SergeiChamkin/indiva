#ifndef SETWINDOW_H
#define SETWINDOW_H

#include <QMainWindow>

namespace Ui {
class SetWindow;
}

class SetWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SetWindow(QWidget *parent = nullptr);
    ~SetWindow();

private slots:
    void on_btnD1_clicked();

    void on_btnD2_clicked();

    void on_btnStr_clicked();

private:
    Ui::SetWindow *ui;
};

#endif // SETWINDOW_H
