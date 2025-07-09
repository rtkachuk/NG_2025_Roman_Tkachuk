#include "showtime.h"
#include "ui_showtime.h"

Showtime::Showtime(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Showtime)
{
    ui->setupUi(this);

    m_scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(m_scene);

    int columnsAmount = 20;
    int rowsAmount = 20;



    for (int row=0; row<rowsAmount; row++) {
        for (int column=0; column < columnsAmount; column++){
            m_scene->addPixmap(QPixmap(":/textures/floor.png"))->setPos(column*PIXELSIZE, row*PIXELSIZE);
        }
    }
    m_item = m_scene->addPixmap(QPixmap(":/textures/player.png"));

    m_timer = new QTimer();

    m_timer->setInterval(1000);
    m_timer->start();

    connect (m_timer, &QTimer::timeout, this, &Showtime::secondPassed);

    connect (ui->b_up, &QPushButton::clicked, this, &Showtime::moveObject);
    connect (ui->b_down, &QPushButton::clicked, this, &Showtime::moveObject);
    connect (ui->b_left, &QPushButton::clicked, this, &Showtime::moveObject);
    connect (ui->b_right, &QPushButton::clicked, this, &Showtime::moveObject);
}

Showtime::~Showtime()
{
    delete ui;
}

void Showtime::secondPassed()
{
    //m_item->moveBy(10, 10);
}

void Showtime::moveObject()
{
    QPushButton *button = (QPushButton *)sender();

    if (button == ui->b_up) m_item->moveBy(0, PIXELSIZE * -1);
    if (button == ui->b_down) m_item->moveBy(0, PIXELSIZE);
    if (button == ui->b_left) m_item->moveBy(PIXELSIZE * -1,0);
    if (button == ui->b_right) m_item->moveBy(PIXELSIZE, 0);
}
