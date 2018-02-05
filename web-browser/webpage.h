#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <QWidget>
#include <QtWebEngineWidgets>

class WebPage : public QWebEngineView
{
    Q_OBJECT
public:
    explicit WebPage(QWidget *parent = nullptr);

    QSize  minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

signals:

public slots:


};

#endif // WEBPAGE_H
