#include "dbdemo.h"
#include "ui_dbdemo.h"

DbDemo::DbDemo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DbDemo)
{
    ui->setupUi(this);

    m_dbWorker = new DbWorker(this);
    m_dbWorker->connectToDatabase();

    connect (this, &DbDemo::refresh, this, &DbDemo::updateTable);
    connect (ui->b_create, &QPushButton::clicked, this, &DbDemo::createUser);
    connect (ui->b_update, &QPushButton::clicked, this, &DbDemo::updateUser);
    connect (ui->m_tableUsers, &QTableWidget::itemSelectionChanged, this, &DbDemo::userSelected);

    updateTable();
}

DbDemo::~DbDemo()
{
    delete ui;
}

void DbDemo::createUser()
{
    User user;

    user.login = ui->le_login->text();
    user.name = ui->le_name->text();
    user.password = ui->le_password->text();

    if (user.login.isEmpty() || user.password.isEmpty() || user.name.isEmpty())
        return;

    if (m_dbWorker->createUser(user) == false)
        QMessageBox::critical(this, "Uhhhh....", "Can't create user");
    emit refresh();
}

void DbDemo::updateUser()
{
    User user;

    user.login = ui->le_login->text();
    user.name = ui->le_name->text();
    user.id = ui->l_id->text().toInt();

    if (user.login.isEmpty() || user.name.isEmpty())
        return;

    if (m_dbWorker->updateUser(user) == false)
        QMessageBox::critical(this, "Uhhhh....", "Can't update user");


    emit refresh();
}

void DbDemo::updateTable()
{
    QStringList headers;
    headers.append("id");
    headers.append("login");
    headers.append("password");
    headers.append("name");

    ui->m_tableUsers->clear();
    ui->m_tableUsers->setColumnCount(4);
    ui->m_tableUsers->setHorizontalHeaderLabels(headers);

    QList<User> users = m_dbWorker->getUsers();
    ui->m_tableUsers->setRowCount(users.size());

    qDebug () << "Amount of users: " << users.size();

    int row = 0;

    for (User user : users) {
        ui->m_tableUsers->setItem(row, cId, new QTableWidgetItem(QString::number(user.id)));
        ui->m_tableUsers->setItem(row, cLogin, new QTableWidgetItem(user.login));
        ui->m_tableUsers->setItem(row, cPassword, new QTableWidgetItem(user.password));
        ui->m_tableUsers->setItem(row, cName, new QTableWidgetItem(user.name));
        row++;
    }
}

void DbDemo::userSelected()
{
    int row = ui->m_tableUsers->currentRow();
    ui->l_id->setText(ui->m_tableUsers->item(row, cId)->text());
    ui->le_login->setText(ui->m_tableUsers->item(row, cLogin)->text());
    ui->le_password->setText(ui->m_tableUsers->item(row, cPassword)->text());
    ui->le_name->setText(ui->m_tableUsers->item(row, cName)->text());
}
