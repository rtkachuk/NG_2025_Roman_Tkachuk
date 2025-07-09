#ifndef SHOWTIME_H
#define SHOWTIME_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class Showtime;
}
QT_END_NAMESPACE

class Showtime : public QMainWindow
{
    Q_OBJECT

public:
    Showtime(QWidget *parent = nullptr);
    ~Showtime();

private slots:
    void secondPassed();
    void moveObject();

private:
    Ui::Showtime *ui;
    QGraphicsScene *m_scene;
    QGraphicsPixmapItem *m_item;

    QTimer *m_timer;

    const int PIXELSIZE=40;
};
#endif // SHOWTIME_H
