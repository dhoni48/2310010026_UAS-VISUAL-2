#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QDialog>
#include <QString>

#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QDate>

namespace Ui {
class customer;
}

class customer : public QDialog
{
    Q_OBJECT

public:
    explicit customer(QWidget *parent = nullptr);
    ~customer();

    customer(QString nmCust, QString siupCust, QString alamatCust, QString email1, QString telp1,
             QString fax1, QString cpCust, QString email2, QString telp2, int idUser);

    void setNmCust(QString nmCust);
    QString getNmCust();

    void setSiupCust(QString siupCust);
    QString getSiupCust();

    void setAlamatCust(QString alamatCust);
    QString getAlamatCust();

    void setEmaill1(QString email1);
    QString getEmaill1();

    void setTelp1(QString telp1);
    QString getTelp1();

    void setFax1(QString fax1);
    QString getFax1();

    void setCpCust(QString cpCust);
    QString getCpCust();

    void setEmail2(QString email2);
    QString getEmail2();

    void setTelp2(QString telp2);
    QString getTelp2();

    void setIdUser(int idUser);
    int getIdUser();

    void loadDataCustomer();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

private:
    Ui::customer *ui;

    QString nmCust, siupCust, alamatCust, email1, telp1, fax1, cpCust, email2, telp2;
    int idUser;

    QSqlDatabase koneksi;
    QSqlQueryModel *crudcust;
};

#endif // CUSTOMER_H
