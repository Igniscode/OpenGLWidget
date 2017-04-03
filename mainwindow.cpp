#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowStaysOnTopHint|
                   Qt::FramelessWindowHint|
                   Qt::WindowFlags());

//  ***** this code is for removing background *****
    setAttribute(Qt::WA_TranslucentBackground);
//  ***** this code is for using EventFilter *****
//    qApp->installEventFilter(this);

	createActions();
	createTrayIcon();
	
	QIcon icon = QIcon("kist.png");
	trayIcon->setIcon(icon);
	setWindowIcon(icon);
	
	trayIcon->show();
    
	this->move(_hwidth/2,_hheight/2);
    this->setFixedSize(_hwidth,_hheight);
    
//	QLabel* _label = ui->BlankLabel ;
// _label->move((_hwidth-_label->width())/2,(_hheight-_label->height())/2);
//	GLWidget* _opengl = ui->MainGL;
	GLWidget* _opengl = new GLWidget(&helper, this);
	_opengl->move(0, 0);
	_opengl->resize(_hwidth, _hheight);

	QTimer *timer = new QTimer(this);
	connect(timer, &QTimer::timeout, _opengl, &GLWidget::animate);
	timer->start(50);
}

void MainWindow::setVisible(bool visible) {
	restoreAction->setEnabled(isMaximized() | !visible);
	QWidget::setVisible(visible);
}

void MainWindow::closeEvent(QCloseEvent *e) {
	if (trayIcon->isVisible()) {
		QMessageBox::information(this, 
            tr("Caution!"),
            tr("This process will keep running in tray"));
		hide();
		e->ignore();
	}
}

void MainWindow::createActions() {

	restoreAction = new QAction(tr("Show"), this);
	connect(restoreAction, &QAction::triggered, this, &QWidget::showNormal);

	quitAction = new QAction(tr("Quit"), this);
	connect(quitAction, &QAction::triggered, this, &QCoreApplication::quit);
}

void MainWindow::createTrayIcon() {
	trayIconMenu = new QMenu(this);
	trayIconMenu->addActions({ restoreAction, quitAction });
	trayIcon = new QSystemTrayIcon(this);
	trayIcon->setContextMenu(trayIconMenu);
}

void MainWindow::getDataEvent(QEvent *e, bool hide_or_show, string s) {
	//hide_or_show is true : hide , hide_or_show is false : show
	if (hide_or_show&&QWidget::isVisible()) QWidget::hide();
	else QWidget::show();
	
	e->ignore();
	//Input some code ... 
	
}

void MainWindow::moveEvent(QMoveEvent *e){
    if (e->oldPos() != e->pos()){
            this->move(_hwidth/2,_hheight/2);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

