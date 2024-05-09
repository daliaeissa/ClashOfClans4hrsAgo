// gameworker.h
#ifndef GAMEWORKER_H
#define GAMEWORKER_H

#include <QObject>

class GameWorker : public QObject
{
    Q_OBJECT

public:
    explicit GameWorker(QObject *parent = nullptr);

public slots:
    void startGame();
};

#endif // GAMEWORKER_H
