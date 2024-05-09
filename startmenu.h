#ifndef STARTMENU_H
#define STARTMENU_H
#include"game.h"
#include <QDialog>

namespace Ui {
class StartMenu;
}

class StartMenu : public QDialog
{
    Q_OBJECT

public:
    explicit StartMenu(QWidget *parent = nullptr);
    game *gameManager;
    ~StartMenu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::StartMenu *ui;
};

#endif // STARTMENU_H
