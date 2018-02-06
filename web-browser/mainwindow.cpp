#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "definitions.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("./icons/web.png"));
    setWindowTitle(WINDOW_TITLE);
    AddTab();
    CreateActions();
    CreateMenus();
    CreateToolBar();
    CreateStatusBar();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::CreateActions(){
    actionNewTab = new QAction("&New Tab", this);
    actionNewTab->setShortcut(QKeySequence::New);
    connect(actionNewTab, SIGNAL(triggered()), this, SLOT(AddTab()));

    actionCloseTab = new QAction("&Close Tab", this);
    actionCloseTab->setShortcut(QKeySequence::Close);
    connect(actionCloseTab,SIGNAL(triggered()), this, SLOT(CloseTab()));
}

void MainWindow::CreateMenus(){
    QMenu *fileMenu = ui->menuBar->addMenu("&File Menu");
    fileMenu->addAction(actionNewTab);
    fileMenu->addSeparator();
    fileMenu->addAction(actionCloseTab);

}

void MainWindow::CreateToolBar(){

}

void MainWindow::CreateStatusBar(){

}


QWidget* MainWindow::CreateNewTab(QString url){
    // create the layout that will contain the web page
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    // create the web page and adding it to the layout
    QWebEngineView *page = new QWebEngineView();
    page->load(QUrl(url));
    layout->addWidget(page);
    // create a widget with the constructed layout
    QWidget *tab = new QWidget();
    tab->setLayout(layout);
    return tab;
}

void MainWindow::AddTab(QString url){
    if(url.isEmpty()){
        url = HOME_PAGE_URL;
    }
    if(url.left(7)!="http://" && url.left(8)!="https://"){
        url = "http://" + url;
    }
    int index = ui->tabWidget->addTab(CreateNewTab(url), "New tab");
    ui->tabWidget->setCurrentIndex(index);
}

void MainWindow::CloseTab(){
    if(ui->tabWidget->count() > 1){
        ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
    } else {
        QMessageBox::critical(this, "Error", "There is only one tab !");

    }
}

void MainWindow::About(){
    QMessageBox::information(this, "About ...", "This is my Web Browser ! <br /> By Younux");
}

QWebEngineView* MainWindow::CurrentPage(){
    return ui->tabWidget->currentWidget()->findChild<QWebEngineView *>();
}

void MainWindow::LoadPage(QUrl url){
    CurrentPage()->load(url);
}

void MainWindow::GoToPreviousPage(){
    CurrentPage()->back();
}

void MainWindow::GoToNextPage(){
    CurrentPage()->forward();
}

void MainWindow::GoToHomePage(){
    CurrentPage()->load(QUrl(HOME_PAGE_URL));
}

void MainWindow::StopLoading(){
    CurrentPage()->stop();
}

void MainWindow::RefreshPage(){
    CurrentPage()->reload();
}
