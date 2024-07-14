#include "customer.h"
#include "ui_customer.h"

#include <QMessageBox>
#include <QDebug>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>

customer::customer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::customer)
{
    ui->setupUi(this);

    koneksi = QSqlDatabase::addDatabase("QODBC");
    koneksi.setDatabaseName("reza");
    koneksi.setUserName("root");
    koneksi.setPassword("");

    if(koneksi.open()){
        qDebug()<<"Database terkoneksi";
    }else{
        qDebug()<<koneksi.lastError().text();
    }

    customer::loadDataCustomer();
    QSqlQuery sql;
    sql.prepare("SELECT * FROM customer");
    sql.exec();
}

customer::~customer()
{
    delete ui;
}

customer::customer(QString nmCust, QString siupCust, QString alamatCust, QString email1, QString telp1,
                   QString fax1, QString cpCust, QString email2, QString telp2, int idUser)
{
    this->nmCust = nmCust;
    this->siupCust = siupCust;
    this->alamatCust = alamatCust;
    this->email1 = email1;
    this->telp1 = telp1;
    this->fax1 = fax1;
    this->cpCust = cpCust;
    this->email2 = email2;
    this->telp2 = telp2;
    this->idUser = idUser;
}

void customer::setNmCust(QString nmCust)
{
    this->nmCust = nmCust;
}

QString customer::getNmCust()
{
    return this->nmCust;
}

void customer::setSiupCust(QString siupCust)
{
    this->siupCust = siupCust;
}

QString customer::getSiupCust()
{
    return this->siupCust;
}

void customer::setAlamatCust(QString alamatCust)
{
    this->alamatCust = alamatCust;
}

QString customer::getAlamatCust()
{
    return this->alamatCust;
}

void customer::setEmaill1(QString email1)
{
    this->email1 = email1;
}

QString customer::getEmaill1()
{
    return this->email1;
}

void customer::setTelp1(QString telp1)
{
    this->telp1 = telp1;
}

QString customer::getTelp1()
{
    return this->telp1;
}

void customer::setFax1(QString fax1)
{
    this->fax1 = fax1;
}

QString customer::getFax1()
{
    return this->fax1;
}

void customer::setCpCust(QString cpCust)
{
    this->cpCust = cpCust;
}

QString customer::getCpCust()
{
    return this->cpCust;
}

void customer::setEmail2(QString email2)
{
    this->email2 = email2;
}

QString customer::getEmail2()
{
    return this->email2;
}

void customer::setTelp2(QString telp2)
{
    this->telp2 = telp2;
}

QString customer::getTelp2()
{
    return this->telp2;
}

void customer::setIdUser(int idUser)
{
    this->idUser = idUser;
}

int customer::getIdUser()
{
    return this->idUser;
}

void customer::loadDataCustomer()
{
    crudcust = new QSqlQueryModel(this);
    crudcust->setQuery("SELECT * FROM customer");
    crudcust->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    crudcust->setHeaderData(1, Qt::Horizontal, QObject::tr("NAMA CUSTOMER"));
    crudcust->setHeaderData(2, Qt::Horizontal, QObject::tr("SIUP CUSTOMER"));
    crudcust->setHeaderData(3, Qt::Horizontal, QObject::tr("ALAMAT CUSTOMER"));
    crudcust->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL 1"));
    crudcust->setHeaderData(5, Qt::Horizontal, QObject::tr("TELP 1"));
    crudcust->setHeaderData(6, Qt::Horizontal, QObject::tr("FAX 1"));
    crudcust->setHeaderData(7, Qt::Horizontal, QObject::tr("CP CUSTOMER"));
    crudcust->setHeaderData(8, Qt::Horizontal, QObject::tr("EMAIL 2"));
    crudcust->setHeaderData(9, Qt::Horizontal, QObject::tr("TELP 2"));
    crudcust->setHeaderData(10, Qt::Horizontal, QObject::tr("ID USER"));

    ui->tableView->setModel(crudcust);
    ui->tableView->setColumnWidth(0,50);
    ui->tableView->setColumnWidth(1,50);
    ui->tableView->setColumnWidth(2,50);
    ui->tableView->setColumnWidth(3,50);
    ui->tableView->setColumnWidth(4,50);
    ui->tableView->setColumnWidth(5,50);
    ui->tableView->setColumnWidth(6,50);
    ui->tableView->setColumnWidth(7,50);
    ui->tableView->setColumnWidth(8,50);
    ui->tableView->setColumnWidth(9,50);
    ui->tableView->setColumnWidth(10,50);
    ui->tableView->show();
}

void customer::on_pushButton_clicked()
{
    customer c;

    c.setNmCust(ui->namaCustLineEdit->text());
    c.setSiupCust(ui->siupCustLineEdit->text());
    c.setAlamatCust(ui->alamatCustLineEdit->text());
    c.setEmaill1(ui->email1LineEdit->text());
    c.setTelp1(ui->telp1LineEdit->text());
    c.setFax1(ui->fax1LineEdit->text());
    c.setCpCust(ui->cPCustLineEdit->text());
    c.setEmail2(ui->email2LineEdit->text());
    c.setTelp2(ui->telp2LineEdit->text());
    c.setIdUser(ui->iDUserLineEdit->text().toInt());

    /*qDebug()<<"Nama Customer : "<<c.getNmCust()<<"\n";
    qDebug()<<"SIUP Customer : "<<c.getSiupCust()<<"\n";
    qDebug()<<"Alamat : "<<c.getAlamatCust()<<"\n";
    qDebug()<<"Email 1 : "<<c.getEmaill1()<<"\n";
    qDebug()<<"No Telp 1 : "<<c.getTelp1()<<"\n";
    qDebug()<<"Fax 1 : "<<c.getFax1()<<"\n";
    qDebug()<<"CP Customer : "<<c.getCpCust()<<"\n";
    qDebug()<<"Email 2 : "<<c.getEmail2()<<"\n";
    qDebug()<<"No Telp 2 : "<<c.getTelp2()<<"\n";
    qDebug()<<"ID User : "<<c.getIdUser()<<"\n";*/

    QSqlQuery sql;
    sql.prepare("INSERT INTO customer (NmCust, SiupCust, AlamatCust, Email1, Telp1, Fax1, CpCust, Email2, Telp2, IdUser) "
                "VALUES (:NmCust, :SiupCust, :AlamatCust, :Email1, :Telp1, :Fax1, :CpCust, :Email2, :Telp2, :IdUser)");
    sql.bindValue(":NmCust", c.getNmCust());
    sql.bindValue(":SiupCust", c.getSiupCust());
    sql.bindValue(":AlamatCust", c.getAlamatCust());
    sql.bindValue(":Email1", c.getEmaill1());
    sql.bindValue(":Telp1", c.getTelp1());
    sql.bindValue(":Fax1", c.getFax1());
    sql.bindValue(":CpCust", c.getCpCust());
    sql.bindValue(":Email2", c.getEmail2());
    sql.bindValue(":Telp2", c.getTelp2());
    sql.bindValue(":IdUser", c.getIdUser());

    if(sql.exec()){
        qDebug()<<"Data berhasil disimpan";
        customer::loadDataCustomer();
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void customer::on_pushButton_2_clicked()
{
    int baris = ui->tableView->selectionModel()->currentIndex().row();

    QSqlQuery sql;
    sql.prepare("UPDATE customer SET "
                "NmCust=:NmCust, SiupCust=:SiupCust, AlamatCust=:AlamatCust, Email1=:Email1, "
                "Telp1=:Telp1, Fax1=:Fax1, CpCust=:CpCust, Email2=:Email2, Telp2=:Telp2,"
                "IdUser=:IdUser WHERE IdCust=:IdCust");

    sql.bindValue(":IdCust", ui->tableView->model()->index(baris,0).data().toString());

    sql.bindValue(":NmCust", ui->namaCustLineEdit->text());
    sql.bindValue(":SiupCust", ui->siupCustLineEdit->text());
    sql.bindValue(":AlamatCust", ui->alamatCustLineEdit->text());
    sql.bindValue(":Email1", ui->email1LineEdit->text());
    sql.bindValue(":Telp1", ui->telp1LineEdit->text());
    sql.bindValue(":Fax1", ui->fax1LineEdit->text());
    sql.bindValue(":CpCust", ui->cPCustLineEdit->text());
    sql.bindValue(":Email2", ui->email2LineEdit->text());
    sql.bindValue(":Telp2", ui->telp2LineEdit->text());
    sql.bindValue(":IdUser", ui->iDUserLineEdit->text().toInt());

    /*customer c;
    c.setNmCust(ui->namaCustLineEdit->text());
    c.setSiupCust(ui->siupCustLineEdit->text());
    c.setAlamatCust(ui->alamatCustLineEdit->text());
    c.setEmaill1(ui->email1LineEdit->text());
    c.setTelp1(ui->telp1LineEdit->text());
    c.setFax1(ui->fax1LineEdit->text());
    c.setCpCust(ui->cPCustLineEdit->text());
    c.setEmail2(ui->email2LineEdit->text());
    c.setTelp2(ui->telp2LineEdit->text());
    c.setIdUser(ui->iDUserLineEdit->text().toInt());

    sql.bindValue(":NmCust", c.getNmCust());
    sql.bindValue(":SiupCust", c.getSiupCust());
    sql.bindValue(":AlamatCust", c.getAlamatCust());
    sql.bindValue(":Email1", c.getEmaill1());
    sql.bindValue(":Telp1", c.getTelp1());
    sql.bindValue(":Fax1", c.getFax1());
    sql.bindValue(":CpCust", c.getCpCust());
    sql.bindValue(":Email2", c.getEmail2());
    sql.bindValue(":Telp2", c.getTelp2());
    sql.bindValue(":IdUser", c.getIdUser());*/

    if(sql.exec()){
        qDebug()<<"Data berhasil diubah";
        customer::loadDataCustomer();
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void customer::on_tableView_activated(const QModelIndex &index)
{
    int baris = ui->tableView->selectionModel()->currentIndex().row();
    ui->namaCustLineEdit->setText(ui->tableView->model()->index(baris,1).data().toString());
    ui->siupCustLineEdit->setText(ui->tableView->model()->index(baris,2).data().toString());
    ui->alamatCustLineEdit->setText(ui->tableView->model()->index(baris,3).data().toString());
    ui->email1LineEdit->setText(ui->tableView->model()->index(baris,4).data().toString());
    ui->telp1LineEdit->setText(ui->tableView->model()->index(baris,5).data().toString());
    ui->fax1LineEdit->setText(ui->tableView->model()->index(baris,6).data().toString());
    ui->cPCustLineEdit->setText(ui->tableView->model()->index(baris,7).data().toString());
    ui->email2LineEdit->setText(ui->tableView->model()->index(baris,8).data().toString());
    ui->telp2LineEdit->setText(ui->tableView->model()->index(baris,9).data().toString());
    ui->iDUserLineEdit->setText(ui->tableView->model()->index(baris,10).data().toString());
}


void customer::on_pushButton_3_clicked()
{
    int baris = ui->tableView->selectionModel()->currentIndex().row();

    QSqlQuery sql;
    sql.prepare("DELETE FROM customer WHERE IdCust=:IdCust");
    sql.bindValue(":IdCust", ui->tableView->model()->index(baris,0).data().toString());

    if(sql.exec()){
        qDebug()<<"Data berhasil dihapus";
        customer::loadDataCustomer();
    }else{
        qDebug()<<sql.lastError().text();
    }
}

