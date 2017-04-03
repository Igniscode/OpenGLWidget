#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <QMainWindow>
#include <QMoveEvent>
#include <QAction>
#include <Qmenu>
#include <QCloseEvent>
#include <QMessagebox>
#include <qopengl.h>
#include <Qsystemtrayicon>
#include "glwidget.h"

#ifndef QT_NO_SYSTEMTRAYICON
using namespace std;
#pragma comment(lib, "user32.lib")

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

	void setVisible(bool visible) override;

protected:
	void closeEvent(QCloseEvent *e) override;
    void moveEvent(QMoveEvent *e);
	void getDataEvent(QEvent *e, bool hide_or_show, string s);

private:
	void createActions();
	void createTrayIcon();
	
	QAction *restoreAction;
	QAction *quitAction;

	QSystemTrayIcon *trayIcon;
	QMenu *trayIconMenu;

	int _hwidth = GetSystemMetrics(SM_CXSCREEN)/2;
    int _hheight = GetSystemMetrics(SM_CYSCREEN)/2;

	Helper helper;

    Ui::MainWindow *ui;
};
#endif // QT_NO_SYSTEMTRAYICON
#endif // MAINWINDOW_H
