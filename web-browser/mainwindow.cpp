#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "definitions.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setting icon and title
    setWindowIcon(QIcon("./icons/web.png"));
    setWindowTitle(WINDOW_TITLE);
    // Creating actions, menus, tool bar and status bar
    CreateActions();
    CreateMenus();
    CreateToolBar();
    CreateStatusBar();
    // creating a new tab
    NewTab();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CreateActions(){
    actionNewTab = new QAction("&New tab", this);
    actionNewTab->setShortcut(QKeySequence::New);
    connect(actionNewTab, SIGNAL(triggered()), this, SLOT(NewTab()));

    actionCloseTab = new QAction("&Close tab", this);
    actionCloseTab->setShortcut(QKeySequence::Close);
    connect(actionCloseTab,SIGNAL(triggered()), this, SLOT(CloseTab()));

    actionPreviousPage = new QAction(QIcon("./icons/prev.png"), "&Go to previous page", this);
    actionPreviousPage->setShortcut(QKeySequence::Back);
    connect(actionPreviousPage, SIGNAL(triggered()), this, SLOT(GoToPreviousPage()));

    actionNextPage = new QAction(QIcon("./icons/next.png"), "&Go to next page", this);
    actionNextPage->setShortcut(QKeySequence::Forward);
    connect(actionNextPage, SIGNAL(triggered()), this, SLOT(GoToNextPage()));

    actionHomePage = new QAction(QIcon("./icons/home.png"), "&Go to home page", this);
    connect(actionHomePage, SIGNAL(triggered()), this, SLOT(GoToHomePage()));

    actionStopLoading = new QAction(QIcon("./icons/stop.png"), "&Stop loading page", this);
    connect(actionStopLoading, SIGNAL(triggered()), this, SLOT(StopLoading()));

    actionRefreshPage = new QAction(QIcon("./icons/refresh.png"), "&Refresh page", this);;
    actionRefreshPage->setShortcut(QKeySequence::Refresh);
    connect(actionRefreshPage, SIGNAL(triggered()), this, SLOT(RefreshPage()));

    actionGoToPage = new QAction(QIcon("./icons/go.png"), "&Go", this);
    connect(actionGoToPage, SIGNAL(triggered()), this, SLOT(GoToPage()));

    actionAbout = new QAction("&About", this);
    actionAbout->setShortcut(QKeySequence::HelpContents);
    connect(actionAbout, SIGNAL(triggered()), this, SLOT(About()));

}

void MainWindow::CreateMenus(){
    QMenu *fileMenu = ui->menuBar->addMenu("&File");
    fileMenu->addAction(actionNewTab);
    fileMenu->addAction(actionCloseTab);

    QMenu *editMenu = ui->menuBar->addMenu("&Edit");
    editMenu->addAction(actionPreviousPage);
    editMenu->addAction(actionNextPage);
    editMenu->addSeparator();
    editMenu->addAction(actionGoToPage);
    editMenu->addSeparator();
    editMenu->addAction(actionHomePage);
    editMenu->addSeparator();
    editMenu->addAction(actionStopLoading);
    editMenu->addAction(actionRefreshPage);

    QMenu *aboutMenu = ui->menuBar->addMenu("&About");
    aboutMenu->addAction(actionAbout);


}

void MainWindow::CreateToolBar(){
    urlField = new QLineEdit(this);
    connect(urlField, SIGNAL(returnPressed()), this, SLOT(GoToPage()));

    ui->mainToolBar->addAction(actionHomePage);
    ui->mainToolBar->addAction(actionPreviousPage);
    ui->mainToolBar->addAction(actionNextPage);
    ui->mainToolBar->addAction(actionStopLoading);
    ui->mainToolBar->addAction(actionRefreshPage);
    ui->mainToolBar->addWidget(urlField);
    ui->mainToolBar->addAction(actionGoToPage);
}

void MainWindow::CreateStatusBar(){
    progressBar = new QProgressBar(this);
    progressBar->setVisible(false);
    progressBar->setMaximumHeight(14);
    ui->statusBar->addWidget(progressBar, 1);

}

void MainWindow::NewTab(QString url){
    // create the layout that will contain the web page
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    // create the web page and adding it to the layout
    QWebEngineView *webPage = new QWebEngineView();
    webPage->load(QUrl(url));
    layout->addWidget(webPage);
    // create a widget with the constructed layout
    QWidget *tab = new QWidget();
    tab->setLayout(layout);
    // checking url
    if(url.isEmpty()){
        url = HOME_PAGE_URL;
    }
    if(url.left(7)!="http://" && url.left(8)!="https://"){
        url = "http://" + url;
    }
    // adding tab
    int index = ui->tabWidget->addTab(tab, "New tab");
    ui->tabWidget->setCurrentIndex(index);

    // connecting web page signals to created slots
    connect(webPage, SIGNAL(titleChanged(QString)), this, SLOT(ChangeTitle(QString)));
    connect(webPage, SIGNAL(urlChanged(QUrl)), this, SLOT(ChangeUrl(QUrl)));
    connect(webPage, SIGNAL(loadStarted()), this, SLOT(LoadingStarted()));
    connect(webPage, SIGNAL(loadProgress(int)), this, SLOT(LoadingInProgress(int)));
    connect(webPage, SIGNAL(loadFinished(bool)), this, SLOT(LoadingFinished(bool)));
}

void MainWindow::CloseTab(){
    if(ui->tabWidget->count() > 1){
        ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
    } else {
        QMessageBox::critical(this, "Error", "There is only one tab !");
    }
}

QWebEngineView* MainWindow::CurrentPage(){
    return ui->tabWidget->currentWidget()->findChild<QWebEngineView *>();
}

void MainWindow::GoToPage(){
    QString url = urlField->text();
    if(url.isEmpty()){
        url = HOME_PAGE_URL;
    }
    if(url.left(7)!="http://" && url.left(8)!="https://"){
        url = "http://" + url;
    }
    CurrentPage()->load(QUrl(url));
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

void MainWindow::About(){
    QMessageBox::information(this, "About ...", "This is my Web Browser ! <br /> By Younux");
}

void MainWindow::LoadingStarted()
{
    progressBar->setVisible(true);
}

void MainWindow::LoadingInProgress(int pourcentage)
{
    progressBar->setValue(pourcentage);
}

void MainWindow::LoadingFinished(bool ok)
{
    progressBar->setVisible(false);
    statusBar()->showMessage("Ready", 2000);
}

void MainWindow::ChangeTitle(const QString & title)
{
    QString shortTitle = title;
    if (title.size() > 40)
    {
        shortTitle = title.left(40) + "...";
    }
    setWindowTitle(shortTitle + " - " + "Younux Web Browser");
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), shortTitle);
}

void MainWindow::ChangeUrl(const QUrl & url)
{
    urlField->setText(url.toString());
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    ChangeTitle(CurrentPage()->title());
    ChangeUrl(CurrentPage()->url());
}
