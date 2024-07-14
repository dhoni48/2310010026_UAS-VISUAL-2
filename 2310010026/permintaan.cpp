#include "permintaan.h"
#include "ui_permintaan.h"

#include <QMessageBox>
#include <QDebug>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>

permintaan::permintaan(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::permintaan)
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

    permintaan::loadDataPermintaan();
    QSqlQuery sql;
    sql.prepare("SELECT * FROM permintaan");
    sql.exec();
}

permintaan::~permintaan()
{
    delete ui;
}

permintaan::permintaan(QDate tglMinta, QDate tglKirim, QString desc, QString status, int idCust)
{
    this->tglMinta = tglMinta;
    this->tglKirim = tglKirim;
    this->desc = desc;
    this->status = status;
    this->idCust = idCust;
}

void permintaan::setTglMinta(QDate tglMinta)
{
    this->tglMinta = tglMinta;
}

QDate permintaan::getTglMinta()
{
    return this->tglMinta;
}

void permintaan::setTglKirim(QDate tglKirim)
{
    this->tglKirim = tglKirim;
}

QDate permintaan::getTglKirim()
{
    return this->tglKirim;
}

void permintaan::setDesc(QString desc)
{
    this->desc = desc;
}

QString permintaan::getDesc()
{
    return this->desc;
}

void permintaan::setStatus(QString status)
{
    this->status = status;
}

QString permintaan::getStatus()
{
    return this->status;
}

void permintaan::setIdCust(int idCust)
{
    this->idCust = idCust;
}

int permintaan::getIdCust()
{
    return this->idCust;
}

void permintaan::loadDataPermintaan()
{
    crudpermintaan = new QSqlQueryModel(this);
    crudpermintaan->setQuery("SELECT * FROM permintaan");
    crudpermintaan->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    crudpermintaan->setHeaderData(1, Qt::Horizontal, QObject::tr("TGL MINTA"));
    crudpermintaan->setHeaderData(2, Qt::Horizontal, QObject::tr("TGL KIRIM"));
    crudpermintaan->setHeaderData(3, Qt::Horizontal, QObject::tr("DESC"));
    crudpermintaan->setHeaderData(4, Qt::Horizontal, QObject::tr("STATUS"));
    crudpermintaan->setHeaderData(5, Qt::Horizontal, QObject::tr("ID CUST"));

    ui->tableView->setModel(crudpermintaan);
    ui->tableView->setColumnWidth(0,50);
    ui->tableView->setColumnWidth(1,50);
    ui->tableView->setColumnWidth(2,50);
    ui->tableView->setColumnWidth(3,50);
    ui->tableView->setColumnWidth(4,50);
    ui->tableView->setColumnWidth(5,50);
    ui->tableView->show();
}

void permintaan::on_pushButton_clicked()
{
    permintaan p;

    p.setTglMinta(ui->tanggalMintaDateEdit->date());
    p.setTglKirim(ui->tanggalKirimDateEdit->date());
    p.setDesc(ui->deskripsiLineEdit->text());
    p.setStatus(ui->statusLineEdit->text());
    p.setIdCust(ui->idCustomerLineEdit->text().toInt());

    /*qDebug()<<"Tanggal Minta : "<<p.getTglMinta()<<"\n";
    qDebug()<<"Tanggal Kirim : "<<p.getTglKirim()<<"\n";
    qDebug()<<"Deskripsi : "<<p.getDesc()<<"\n";
    qDebug()<<"Status : "<<p.getStatus()<<"\n";
    qDebug()<<"ID Customer : "<<p.getIdCust()<<"\n";*/

    QSqlQuery sql;
    sql.prepare("INSERT INTO permintaan (TglMinta, TglKirim, DesMinta, StatusProses1, IdCust) "
                "VALUES (:TglMinta, :TglKirim, :DesMinta, :StatusProses1, :IdCust)");
    sql.bindValue(":TglMinta", p.getTglMinta());
    sql.bindValue(":TglKirim", p.getTglKirim());
    sql.bindValue(":DesMinta", p.getDesc());
    sql.bindValue(":StatusProses1", p.getStatus());
    sql.bindValue(":IdCust", p.getIdCust());

    if(sql.exec()){
        qDebug()<<"Data berhasil disimpan";
        permintaan::loadDataPermintaan();
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void permintaan::on_tableView_activated(const QModelIndex &index)
{
    int baris = ui->tableView->selectionModel()->currentIndex().row();
    ui->tanggalMintaDateEdit->setDate(ui->tableView->model()->index(baris,1).data().toDate());
    ui->tanggalKirimDateEdit->setDate(ui->tableView->model()->index(baris,2).data().toDate());
    ui->deskripsiLineEdit->setText(ui->tableView->model()->index(baris,3).data().toString());
    ui->statusLineEdit->setText(ui->tableView->model()->index(baris,4).data().toString());
    ui->idCustomerLineEdit->setText(ui->tableView->model()->index(baris,5).data().toString());
}


void permintaan::on_pushButton_2_clicked()
{
    int baris = ui->tableView->selectionModel()->currentIndex().row();

    QSqlQuery sql;
    sql.prepare("UPDATE permintaan SET "
                "TglMinta=:TglMinta, TglKirim=:TglKirim, DesMinta=:DesMinta, StatusProses1=:StatusProses1, "
                "IdCust=:IdCust WHERE NoMinta=:NoMinta");

    sql.bindValue(":NoMinta", ui->tableView->model()->index(baris,0).data().toString());

    sql.bindValue(":TglMinta", ui->tanggalMintaDateEdit->date());
    sql.bindValue(":TglKirim", ui->tanggalKirimDateEdit->date());
    sql.bindValue(":DesMinta", ui->deskripsiLineEdit->text());
    sql.bindValue(":StatusProses1", ui->statusLineEdit->text());
    sql.bindValue(":IdCust", ui->idCustomerLineEdit->text().toInt());

    if(sql.exec()){
        qDebug()<<"Data berhasil diubah";
        permintaan::loadDataPermintaan();
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void permintaan::on_pushButton_3_clicked()
{
    int baris = ui->tableView->selectionModel()->currentIndex().row();

    QSqlQuery sql;
    sql.prepare("DELETE FROM permintaan WHERE NoMinta=:NoMinta");
    sql.bindValue(":NoMinta", ui->tableView->model()->index(baris,0).data().toString());

    if(sql.exec()){
        qDebug()<<"Data berhasil dihapus";
        permintaan::loadDataPermintaan();
    }else{
        qDebug()<<sql.lastError().text();
    }
}
