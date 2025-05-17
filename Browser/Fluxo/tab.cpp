#include "tab.h"

Tab::Tab(QObject *parent)
    : QObject{parent}
{
    b_go = new QPushButton();
    b_go->setText("GO");
    le_url = new QLineEdit();

    view = new QWebEngineView();
    progressBar = new QProgressBar();
    progressBar->setVisible(false);

    addressLayout = new QHBoxLayout();
    addressLayout->addWidget(le_url);
    addressLayout->addWidget(b_go);

    tabLayout = new QVBoxLayout();
    tabLayout->addItem(addressLayout);
    tabLayout->addWidget(view);
    tabLayout->addWidget(progressBar);

    connect(b_go, &QPushButton::clicked, this, &Tab::goToWebsite);
    connect(view, &QWebEngineView::urlChanged, this, &Tab::updateUrl);
    connect(view, &QWebEngineView::loadProgress, this, &Tab::updateProgressBar);
}

Tab::~Tab()
{
    disconnect(b_go, &QPushButton::clicked, this, &Tab::goToWebsite);
    disconnect(view, &QWebEngineView::urlChanged, this, &Tab::updateUrl);
    disconnect(view, &QWebEngineView::loadProgress, this, &Tab::updateProgressBar);

    tabLayout->removeWidget(view);
    tabLayout->removeWidget(progressBar);
    tabLayout->removeItem(addressLayout);

    addressLayout->removeWidget(le_url);
    addressLayout->removeWidget(b_go);

    delete tabLayout;
    delete addressLayout;
    delete progressBar;
    delete view;
    delete le_url;
    delete b_go;
}

void Tab::updateUrl(QUrl url)
{
    le_url->setText(url.toString());
}

void Tab::goToWebsite()
{
    QString url = le_url->text();

    if (url.indexOf("https://") != 0)
        url = "https://" + url;

    view->load(url);
}

void Tab::updateProgressBar(int value)
{
    if (value == 100)
        progressBar->setVisible(false);
    else
        progressBar->setVisible(true);

    progressBar->setValue(value);
}
