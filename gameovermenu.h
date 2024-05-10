#ifndef GAMEOVERMENU_H
#define GAMEOVERMENU_H

#include <QDialog>

namespace Ui {
class GameOverMenu;
}

class GameOverMenu : public QDialog
{
    Q_OBJECT

public:
    explicit GameOverMenu(QWidget *parent = nullptr);
    ~GameOverMenu();

private:
    Ui::GameOverMenu *ui;
};

#endif // GAMEOVERMENU_H
