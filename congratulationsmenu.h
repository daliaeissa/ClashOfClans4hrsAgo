#ifndef CONGRATULATIONSMENU_H
#define CONGRATULATIONSMENU_H

#include <QDialog>

namespace Ui {
class CongratulationsMenu;
}

class CongratulationsMenu : public QDialog
{
    Q_OBJECT

public:
    explicit CongratulationsMenu(QWidget *parent = nullptr);
    ~CongratulationsMenu();

private:
    Ui::CongratulationsMenu *ui;
};

#endif // CONGRATULATIONSMENU_H
