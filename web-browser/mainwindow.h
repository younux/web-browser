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
    void NewTab(QString url=NULL);
    void CloseTab();
    void GoToPage();
    void GoToPreviousPage();
    void GoToNextPage();
    void GoToHomePage();
    void StopLoading();
    void RefreshPage();
    void About();

    void LoadingStarted();
    void LoadingInProgress(int pourcentage);
    void LoadingFinished(bool ok);

    void ChangeTitle(const QString & title);
    void ChangeUrl(const QUrl & url);

    // this last one is created using qt creator, I do not need to configure connection
    void on_tabWidget_currentChanged(int index);

private:
    Ui::MainWindow *ui;

    QLineEdit *urlField;
    QProgressBar *progressBar;

    QAction *actionNewTab;
    QAction *actionCloseTab;
    QAction *actionPreviousPage;
    QAction *actionNextPage;
    QAction *actionHomePage;
    QAction *actionStopLoading;
    QAction *actionRefreshPage;
    QAction *actionGoToPage;
    QAction *actionAbout;

    void CreateActions();
    void CreateMenus();
    void CreateToolBar();
    void CreateStatusBar();

    QWebEngineView* CurrentPage();


};

#endif // MAINWINDOW_H
