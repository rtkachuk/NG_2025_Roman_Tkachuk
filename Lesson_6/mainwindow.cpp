#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(
    QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->sb_charsAmount->setReadOnly(true);

    connect (ui->pushButton, &QPushButton::clicked, this, &MainWindow::increaseNumber);
    connect (ui->b_summ, &QPushButton::clicked, this, &MainWindow::findSumm);
    connect (ui->le_string, &QLineEdit::textChanged, this, &MainWindow::calculateCharsAmount);

    connect (ui->dial, &QDial::valueChanged, ui->verticalSlider, &QSlider::setValue);
    connect (ui->dial, &QDial::valueChanged, ui->horizontalSlider, &QSlider::setValue);
    connect (ui->dial, &QDial::valueChanged, ui->progressBar, &QProgressBar::setValue);

    connect (ui->verticalSlider, &QSlider::valueChanged, ui->dial, &QDial::setValue);
    connect (ui->verticalSlider, &QSlider::valueChanged, ui->horizontalSlider, &QSlider::setValue);
    connect (ui->verticalSlider, &QSlider::valueChanged, ui->progressBar, &QProgressBar::setValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::increaseNumber()
{
    ui->lcdNumber->display(5);
}

void MainWindow::findSumm()
{
    ui->l_result->setText("Result: " + QString::number(ui->value_1->value() + ui->value_2->value()));
}

void MainWindow::calculateCharsAmount(QString text)
{
    ui->sb_charsAmount->setValue(text.size());
}
