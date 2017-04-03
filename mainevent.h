#ifndef MAINEVENT_H
#define MAINEVENT_H

#include <QEvent>
#include "mainwindow.h"
class MainEvent : public QEvent
{
    Q_OBJECT
public:
    MainEvent();
protected:
    void move(QEvent *);
    void Resize(QEvent );
};




#endif // MAINEVENT_H
