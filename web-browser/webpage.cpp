#include "webpage.h"

WebPage::WebPage(QWidget *parent) : QWebEngineView(parent)
{
    this->load(QUrl(QString("https://www.youtube.com/")));

}


QSize WebPage::minimumSizeHint() const{
    return QSize(800, 400);
}

QSize WebPage::sizeHint() const{
    return QSize(1200, 700);
}
