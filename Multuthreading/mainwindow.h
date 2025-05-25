#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "manager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void selectFile();

    void start();

private:
    Ui::MainWindow *ui;

    QThread *m_multiThreadedManagerThread;
    QThread *m_singleThreadedManagerThread;
    Manager *m_multiThreadedManager;
    Manager *m_singleThreadedManager;

    QString m_filePath;
};
#endif // MAINWINDOW_H
