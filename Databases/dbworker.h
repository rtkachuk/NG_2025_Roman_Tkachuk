#ifndef DBWORKER_H
#define DBWORKER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

struct User {
    int id;
    QString login;
    QString password;
    QString name;
};

class DbWorker : public QObject
{
    Q_OBJECT
public:
    explicit DbWorker(QObject *parent = nullptr);
    bool connectToDatabase();
    bool createUser(User user);
    bool updateUser(User user);
    QList<User> getUsers();

signals:

private:
    QSqlDatabase m_database;
};

#endif // DBWORKER_H
