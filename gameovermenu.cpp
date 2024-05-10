#include "gameovermenu.h"
#include "ui_gameovermenu.h"

GameOverMenu::GameOverMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GameOverMenu)
{
    ui->setupUi(this);
}

GameOverMenu::~GameOverMenu()
{
    delete ui;
}
