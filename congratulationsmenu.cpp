#include "congratulationsmenu.h"
#include "ui_congratulationsmenu.h"

CongratulationsMenu::CongratulationsMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CongratulationsMenu)
{
    ui->setupUi(this);
}

CongratulationsMenu::~CongratulationsMenu()
{
    delete ui;
}

void CongratulationsMenu::on_NextLevelButton_clicked()
{
    hide();
}

