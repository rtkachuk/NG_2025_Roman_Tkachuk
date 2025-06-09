#include "dbworker.h"

DbWorker::DbWorker(QObject *parent)
    : QObject{parent}
{
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("/Users/rtkachuk/users.sqlite");
}

bool DbWorker::connectToDatabase()
{
    bool ok = m_database.open();

    if (ok == false) {
        qDebug() << "Failed to connect to database!";
        return ok;
    }

    QSqlQuery query;
    QString msg = QString("CREATE TABLE IF NOT EXISTS users(%1, %2, %3, %4);")
                      .arg("id INTEGER PRIMARY KEY AUTOINCREMENT")
                      .arg("login TEXT")
                      .arg("password TEXT")
                      .arg("name TEXT");
    ok = query.exec(msg);
    if (ok == false) {
        qDebug() << "Failed to init table";
        qDebug() << query.lastError().text();
        m_database.close();
        return ok;
    }
    return ok;
}

bool DbWorker::createUser(User user)
{
    QSqlQuery query;
    QString msg = QString("INSERT INTO 'users'('login', 'password', 'name') VALUES('%1', '%2', '%3');")
                      .arg(user.login)
                      .arg(user.password)
                      .arg(user.name);

    bool ok = query.exec(msg);
    if (ok == false) qDebug() << "Create user: " << query.lastError().text();
    return ok;
}

bool DbWorker::updateUser(User user)
{
    QSqlQuery query;
    QString msg = QString ("UPDATE 'users' SET `login` = '%2', `name` = '%3' WHERE `id` = '%1';")
                      .arg(user.id)
                      .arg(user.login)
                      .arg(user.name);

    bool ok = query.exec(msg);
    if (ok == false) qDebug() << query.lastError().text();
    return ok;
}

QList<User> DbWorker::getUsers()
{
    QSqlQuery query;
    QString msg = "SELECT * FROM 'users';";
    QList<User> users;

    bool ok = query.exec(msg);
    if (ok == false) {
        qDebug() << query.lastError().text();
        return users;
    }

    while (query.next()) {
        User user;
        user.id = query.value("id").toInt();
        user.name = query.value("name").toString();
        user.login = query.value("login").toString();
        user.password = query.value("password").toString();

        users.append(user);
    }

    return users;
}
