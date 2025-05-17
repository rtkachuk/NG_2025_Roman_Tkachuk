#ifndef TAB_H
#define TAB_H

#include <QObject>
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>
#include <QWebEngineView>
#include <QProgressBar>

class Tab : public QObject
{
    Q_OBJECT
public:
    explicit Tab(QObject *parent = nullptr);
    ~Tab();

    QLayout* getTabView() { return tabLayout; }

public slots:
    void updateUrl(QUrl url);
    void goToWebsite();
    void updateProgressBar(int value);

private:
    QPushButton *b_go;
    QLineEdit *le_url;
    QWebEngineView *view;
    QLayout *addressLayout;
    QLayout *tabLayout;
    QProgressBar *progressBar;

signals:
};

#endif // TAB_H
