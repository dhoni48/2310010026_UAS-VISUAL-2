#ifndef USER_H
#define USER_H

#include <QDialog>
#include <QString>

#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlQueryModel>

namespace Ui {
class user;
}

class user : public QDialog
{
    Q_OBJECT

public:
    explicit user(QWidget *parent = nullptr);
    ~user();

    user(QString nmUser, QString jab, QString telp, QString pass, int hak);

    void setNmUser(QString nmUser);
    QString getNmUser();

    void setJab(QString jab);
    QString getJab();

    void setTelp(QString telp);
    QString getTelp();

    void setPass(QString pass);
    QString getPass();

    void setHak(int hak);
    int getHak();

    void loadDataUser();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

private:
    Ui::user *ui;

    QString nmUser, jab, telp, pass;
    int hak;

    QSqlDatabase koneksi;
    QSqlQueryModel *cruduser;
};

#endif // USER_H
