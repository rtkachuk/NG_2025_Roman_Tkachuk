#include "fluxo.h"
#include "ui_fluxo.h"

Fluxo::Fluxo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Fluxo)
{
    ui->setupUi(this);

    // Menu
    //

    m_rootMenu = new QMenu("File");
    m_addTab = new QAction("Add tab");

    m_rootMenu->addAction(m_addTab);
    ui->menubar->addMenu(m_rootMenu);

    // Init Tabs

    ui->tabWidget->removeTab(0);
    ui->tabWidget->setTabsClosable(true);

    createTab();

    connect (m_addTab, &QAction::triggered, this, &Fluxo::createTab);
    connect (ui->tabWidget, &QTabWidget::tabCloseRequested, this, &Fluxo::closeTab);
}

Fluxo::~Fluxo()
{
    delete ui;
}

void Fluxo::createTab()
{
    int index = ui->tabWidget->addTab(new QWidget(), "New Tab");
    ui->tabWidget->setCurrentIndex(index);

    QWidget *tab = ui->tabWidget->currentWidget();
    m_tabs[tab] = new Tab();
    tab->setLayout(m_tabs[tab]->getTabView());
}

void Fluxo::closeTab(int index)
{
    QWidget *tab = ui->tabWidget->widget(index);
    Tab *bufferTab = m_tabs[tab];
    m_tabs.remove(tab);
    ui->tabWidget->removeTab(index);
    delete bufferTab;

    if (ui->tabWidget->count() == 0)
        createTab();
}
