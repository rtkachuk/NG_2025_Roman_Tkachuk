#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_multiThreadedManager = new Manager();
    m_multiThreadedManagerThread = new QThread();
    m_multiThreadedManager->moveToThread(m_multiThreadedManagerThread);
    m_multiThreadedManagerThread->start();

    m_multiThreadedManager->setThreadsAmount(5);
    ui->gb_multiThread->setLayout(m_multiThreadedManager->getLayout());

    m_singleThreadedManager = new Manager();
    m_singleThreadedManagerThread = new QThread();
    m_singleThreadedManager->moveToThread(m_singleThreadedManagerThread);
    m_singleThreadedManagerThread->start();

    m_singleThreadedManager->setThreadsAmount(1);
    ui->gb_singleThread->setLayout(m_singleThreadedManager->getLayout());

    connect (ui->b_select, &QPushButton::clicked, this, &MainWindow::selectFile);
    connect (ui->b_start, &QPushButton::clicked, this, &MainWindow::start);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectFile()
{
    m_filePath = QFileDialog::getOpenFileName(this, "Select File to use", QDir::homePath(), "*.txt");
    ui->l_fileSelect->setText(m_filePath);
    QFile file = QFile(m_filePath);
    ui->statusbar->showMessage("Approximate file size: " + QString::number(file.size() / 1024 / 1024) + " MB");

    if (file.open(QIODevice::ReadOnly)) {
        QString text = file.readAll();
        QString charset = "eyuioa";

        m_singleThreadedManager->setText(text);
        m_singleThreadedManager->setCharset(charset);
        m_multiThreadedManager->setText(text);
        m_multiThreadedManager->setCharset(charset);
    }
}

void MainWindow::start()
{
    // Start single-threaded calculation

    m_singleThreadedManager->start();

    // Start multi-threaded calculation

    m_multiThreadedManager->start();
}
