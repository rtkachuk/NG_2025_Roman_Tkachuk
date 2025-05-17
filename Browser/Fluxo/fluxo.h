#ifndef FLUXO_H
#define FLUXO_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>

#include "tab.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Fluxo;
}
QT_END_NAMESPACE

class Fluxo : public QMainWindow
{
    Q_OBJECT

public:
    Fluxo(QWidget *parent = nullptr);
    ~Fluxo();

private slots:
    void createTab();
    void closeTab(int index);

private:
    QMap<QWidget *, Tab*> m_tabs;
    Ui::Fluxo *ui;

    QMenu *m_rootMenu;
    QAction *m_addTab;
};
#endif // FLUXO_H
