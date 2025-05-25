#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QLayout>
#include <QLabel>
#include <QProgressBar>
#include <QSpacerItem>
#include <QDebug>

#include "textparser.h"

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);
    void setThreadsAmount(int amount);

    void setText(QString text) { m_text = text; }
    void setCharset(QString charset) {m_charset = charset; }

    QLayout* getLayout() { return m_layout; }

    void start();
signals:

private:
    QVector<TextParser*> m_threads;
    QString m_text;
    QString m_charset;
    QLayout *m_layout;
};

#endif // MANAGER_H
