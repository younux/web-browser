#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebEngineWidgets>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void AddTab(QString url=NULL);
    void CloseTab();


private:
    Ui::MainWindow *ui;

    void CreateActions();
    void CreateMenus();
    void CreateToolBar();
    void CreateStatusBar();

    QWidget* CreateNewTab(QString url=NULL);
    void About();
    QWebEngineView* CurrentPage();
    void LoadPage(QUrl url);
    void GoToPreviousPage();
    void GoToNextPage();
    void GoToHomePage();
    void StopLoading();
    void RefreshPage();

    QAction *actionNewTab;
    QAction *actionCloseTab;

};

#endif // MAINWINDOW_H
