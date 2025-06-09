#ifndef DBDEMO_H
#define DBDEMO_H

#include <QMainWindow>
#include <QMessageBox>
#include "dbworker.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class DbDemo;
}
QT_END_NAMESPACE

class DbDemo : public QMainWindow
{
    Q_OBJECT

public:
    DbDemo(QWidget *parent = nullptr);
    ~DbDemo();

private slots:
    void createUser();
    void updateUser();
    void updateTable();
    void userSelected();

signals:
    void refresh();

private:
    Ui::DbDemo *ui;
    DbWorker *m_dbWorker;

    enum {
        cId,
        cLogin,
        cPassword,
        cName
    };
};
#endif // DBDEMO_H

// CREATE
// UPDATE
// SELECT
// DELETE
