#include "start.h"
#include "ui_start.h"
#include <QPixmap>


startwindow::startwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::start)
{
    ui->setupUi(this);


}

startWindow::~startWindow()
{
    delete ui;
}



void WelcomeWindow::on_pushButton_clicked()
{
    hide();

}
