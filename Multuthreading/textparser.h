#ifndef TEXTPARSER_H
#define TEXTPARSER_H

#include <QObject>
#include <QDebug>
#include <QThread>

class TextParser : public QThread
{
    Q_OBJECT
public:
    explicit TextParser(QThread *parent = nullptr);
    void setText(QString text) { m_text = text; }
    void setCharset(QString charset) {m_charset = charset; }

    int getCharsAmount() { return m_charsAmount; }


protected:
    virtual void run();

private:
    QString m_text;
    QString m_charset;
    int m_charsAmount = 0;

signals:
    void progress(int);
    void currentIndex(int);
};

#endif // TEXTPARSER_H
