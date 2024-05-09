#include "startmenu.h"
#include "ui_startmenu.h"
#include "game.h"


StartMenu::StartMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StartMenu)
{

    ui->setupUi(this);
    gameManager = new game();
}

StartMenu::~StartMenu()
{

    delete ui;
}

void StartMenu::on_pushButton_clicked()
{
    hide();
    gameManager->runGame();
}

