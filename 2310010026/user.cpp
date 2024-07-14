#include "user.h"
#include "ui_user.h"

#include <QMessageBox>
#include <QDebug>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>

user::user(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::user)
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

    user::loadDataUser();
    QSqlQuery sql;
    sql.prepare("SELECT * FROM user");
    sql.exec();
}

user::~user()
{
    delete ui;
}

user::user(QString nmUser, QString jab, QString telp, QString pass, int hak)
{
    this->nmUser = nmUser;
    this->jab = jab;
    this->telp = telp;
    this->pass = pass;
    this->hak = hak;
}

void user::setNmUser(QString nmUser)
{
    this->nmUser = nmUser;
}

QString user::getNmUser()
{
    return this->nmUser;
}

void user::setJab(QString jab)
{
    this->jab = jab;
}

QString user::getJab()
{
    return this->jab;
}

void user::setTelp(QString telp)
{
    this->telp = telp;
}

QString user::getTelp()
{
    return this->telp;
}

void user::setPass(QString pass)
{
    this->pass = pass;
}

QString user::getPass()
{
    return this->pass;
}

void user::setHak(int hak)
{
    this->hak = hak;
}

int user::getHak()
{
    return this->hak;
}

void user::loadDataUser()
{
    cruduser = new QSqlQueryModel(this);
    cruduser->setQuery("SELECT * FROM user");
    cruduser->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    cruduser->setHeaderData(1, Qt::Horizontal, QObject::tr("NAMA USER"));
    cruduser->setHeaderData(2, Qt::Horizontal, QObject::tr("JAB"));
    cruduser->setHeaderData(3, Qt::Horizontal, QObject::tr("TELP"));
    cruduser->setHeaderData(4, Qt::Horizontal, QObject::tr("PASS"));
    cruduser->setHeaderData(5, Qt::Horizontal, QObject::tr("HAK AKSES"));

    ui->tableView->setModel(cruduser);
    ui->tableView->setColumnWidth(0,50);
    ui->tableView->setColumnWidth(1,50);
    ui->tableView->setColumnWidth(2,50);
    ui->tableView->setColumnWidth(3,50);
    ui->tableView->setColumnWidth(4,50);
    ui->tableView->setColumnWidth(5,50);
    ui->tableView->show();
}

void user::on_pushButton_clicked()
{
    user u;

    u.setNmUser(ui->namaUserLineEdit->text());
    u.setJab(ui->jabatanLineEdit->text());
    u.setTelp(ui->teleponLineEdit->text());
    u.setPass(ui->passwordLineEdit->text());
    u.setHak(ui->hakAksesLineEdit->text().toInt());

    /*qDebug()<<"Nama User : "<<u.getNmUser()<<"\n";
    qDebug()<<"No Telepon : "<<u.getTelp()<<"\n";
    qDebug()<<"Jabatan : "<<u.getJab()<<"\n";
    qDebug()<<"Password : "<<u.getPass()<<"\n";
    qDebug()<<"Hak Akses : "<<u.getHak()<<"\n";*/

    QSqlQuery sql;
    sql.prepare("INSERT INTO user (NmUser, Jab, Telp, Pass, HakAkses) "
                "VALUES (:NmUser, :Jab, :Telp, :Pass, :HakAkses)");
    sql.bindValue(":NmUser", u.getNmUser());
    sql.bindValue(":Jab", u.getJab());
    sql.bindValue(":Telp", u.getTelp());
    sql.bindValue(":Pass", u.getPass());
    sql.bindValue(":HakAkses", u.getHak());

    if(sql.exec()){
        qDebug()<<"Data berhasil disimpan";
        user::loadDataUser();
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void user::on_pushButton_2_clicked()
{
    int baris = ui->tableView->selectionModel()->currentIndex().row();

    QSqlQuery sql;
    sql.prepare("UPDATE user SET "
                "NmUser=:NmUser, Jab=:Jab, Telp=:Telp, Pass=:Pass, "
                "HakAkses=:HakAkses WHERE IdUser=:IdUser");

    sql.bindValue(":IdUser", ui->tableView->model()->index(baris,0).data().toString());

    sql.bindValue(":NmUser", ui->namaUserLineEdit->text());
    sql.bindValue(":Jab", ui->jabatanLineEdit->text());
    sql.bindValue(":Telp", ui->teleponLineEdit->text());
    sql.bindValue(":Pass", ui->passwordLineEdit->text());
    sql.bindValue(":HakAkses", ui->hakAksesLineEdit->text().toInt());

    if(sql.exec()){
        qDebug()<<"Data berhasil diubah";
        user::loadDataUser();
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void user::on_tableView_activated(const QModelIndex &index)
{
    int baris = ui->tableView->selectionModel()->currentIndex().row();
    ui->namaUserLineEdit->setText(ui->tableView->model()->index(baris,1).data().toString());
    ui->jabatanLineEdit->setText(ui->tableView->model()->index(baris,2).data().toString());
    ui->teleponLineEdit->setText(ui->tableView->model()->index(baris,3).data().toString());
    ui->passwordLineEdit->setText(ui->tableView->model()->index(baris,4).data().toString());
    ui->hakAksesLineEdit->setText(ui->tableView->model()->index(baris,5).data().toString());
}


void user::on_pushButton_3_clicked()
{
    int baris = ui->tableView->selectionModel()->currentIndex().row();

    QSqlQuery sql;
    sql.prepare("DELETE FROM user WHERE IdUser=:IdUser");
    sql.bindValue(":IdUser", ui->tableView->model()->index(baris,0).data().toString());

    if(sql.exec()){
        qDebug()<<"Data berhasil dihapus";
        user::loadDataUser();
    }else{
        qDebug()<<sql.lastError().text();
    }
}

