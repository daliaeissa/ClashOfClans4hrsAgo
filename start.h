#ifndef START_H
#define START_H
#include <QDialog>

namespace Ui
{
class startwindow;
}

class startwindow: public QDialog
{
    Q_OBJECT;

public:
    explicit startwindow(QWidget *parent = nullptr);
    ~startwindow();



private slots:
    void on_pushButton_clicked();

private:
    Ui::startwindow *ui;
};

#endif // START_H
