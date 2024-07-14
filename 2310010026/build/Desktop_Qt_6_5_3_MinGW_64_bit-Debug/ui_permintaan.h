/********************************************************************************
** Form generated from reading UI file 'permintaan.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERMINTAAN_H
#define UI_PERMINTAAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_permintaan
{
public:
    QLabel *label;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *tanggalMintaLabel;
    QDateEdit *tanggalMintaDateEdit;
    QLabel *tanggalKirimLabel;
    QDateEdit *tanggalKirimDateEdit;
    QLabel *deskripsiLabel;
    QLineEdit *deskripsiLineEdit;
    QLabel *statusLabel;
    QLineEdit *statusLineEdit;
    QLabel *idCustomerLabel;
    QLineEdit *idCustomerLineEdit;
    QPushButton *pushButton;
    QTableView *tableView;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *permintaan)
    {
        if (permintaan->objectName().isEmpty())
            permintaan->setObjectName("permintaan");
        permintaan->resize(250, 330);
        label = new QLabel(permintaan);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 121, 16));
        formLayoutWidget = new QWidget(permintaan);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(20, 30, 211, 126));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        tanggalMintaLabel = new QLabel(formLayoutWidget);
        tanggalMintaLabel->setObjectName("tanggalMintaLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, tanggalMintaLabel);

        tanggalMintaDateEdit = new QDateEdit(formLayoutWidget);
        tanggalMintaDateEdit->setObjectName("tanggalMintaDateEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, tanggalMintaDateEdit);

        tanggalKirimLabel = new QLabel(formLayoutWidget);
        tanggalKirimLabel->setObjectName("tanggalKirimLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, tanggalKirimLabel);

        tanggalKirimDateEdit = new QDateEdit(formLayoutWidget);
        tanggalKirimDateEdit->setObjectName("tanggalKirimDateEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, tanggalKirimDateEdit);

        deskripsiLabel = new QLabel(formLayoutWidget);
        deskripsiLabel->setObjectName("deskripsiLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, deskripsiLabel);

        deskripsiLineEdit = new QLineEdit(formLayoutWidget);
        deskripsiLineEdit->setObjectName("deskripsiLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, deskripsiLineEdit);

        statusLabel = new QLabel(formLayoutWidget);
        statusLabel->setObjectName("statusLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, statusLabel);

        statusLineEdit = new QLineEdit(formLayoutWidget);
        statusLineEdit->setObjectName("statusLineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, statusLineEdit);

        idCustomerLabel = new QLabel(formLayoutWidget);
        idCustomerLabel->setObjectName("idCustomerLabel");

        formLayout->setWidget(4, QFormLayout::LabelRole, idCustomerLabel);

        idCustomerLineEdit = new QLineEdit(formLayoutWidget);
        idCustomerLineEdit->setObjectName("idCustomerLineEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, idCustomerLineEdit);

        pushButton = new QPushButton(permintaan);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 170, 71, 21));
        tableView = new QTableView(permintaan);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 200, 231, 121));
        pushButton_2 = new QPushButton(permintaan);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(90, 170, 71, 21));
        pushButton_3 = new QPushButton(permintaan);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(170, 170, 71, 21));

        retranslateUi(permintaan);

        QMetaObject::connectSlotsByName(permintaan);
    } // setupUi

    void retranslateUi(QDialog *permintaan)
    {
        permintaan->setWindowTitle(QCoreApplication::translate("permintaan", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("permintaan", "DATA PERMINTAAN", nullptr));
        tanggalMintaLabel->setText(QCoreApplication::translate("permintaan", "Tanggal Minta", nullptr));
        tanggalKirimLabel->setText(QCoreApplication::translate("permintaan", "Tanggal Kirim", nullptr));
        deskripsiLabel->setText(QCoreApplication::translate("permintaan", "Deskripsi", nullptr));
        statusLabel->setText(QCoreApplication::translate("permintaan", "Status", nullptr));
        idCustomerLabel->setText(QCoreApplication::translate("permintaan", "ID Customer", nullptr));
        pushButton->setText(QCoreApplication::translate("permintaan", "Tambah", nullptr));
        pushButton_2->setText(QCoreApplication::translate("permintaan", "Edit", nullptr));
        pushButton_3->setText(QCoreApplication::translate("permintaan", "Hapus", nullptr));
    } // retranslateUi

};

namespace Ui {
    class permintaan: public Ui_permintaan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERMINTAAN_H
