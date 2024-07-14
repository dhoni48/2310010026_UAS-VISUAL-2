/********************************************************************************
** Form generated from reading UI file 'customer.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMER_H
#define UI_CUSTOMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_customer
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *namaCustLabel;
    QLineEdit *namaCustLineEdit;
    QLabel *siupCustLabel;
    QLineEdit *siupCustLineEdit;
    QLabel *alamatCustLabel;
    QLineEdit *alamatCustLineEdit;
    QLabel *email1Label;
    QLineEdit *email1LineEdit;
    QLabel *telp1Label;
    QLineEdit *telp1LineEdit;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *fax1Label;
    QLineEdit *fax1LineEdit;
    QLabel *cPCustLabel;
    QLineEdit *cPCustLineEdit;
    QLabel *email2Label;
    QLineEdit *email2LineEdit;
    QLabel *telp2Label;
    QLineEdit *telp2LineEdit;
    QLabel *iDUserLabel;
    QLineEdit *iDUserLineEdit;
    QPushButton *pushButton_2;
    QTableView *tableView;
    QPushButton *pushButton_3;

    void setupUi(QDialog *customer)
    {
        if (customer->objectName().isEmpty())
            customer->setObjectName("customer");
        customer->resize(371, 345);
        pushButton = new QPushButton(customer);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 180, 91, 21));
        label = new QLabel(customer);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 111, 16));
        formLayoutWidget = new QWidget(customer);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(20, 40, 160, 128));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        namaCustLabel = new QLabel(formLayoutWidget);
        namaCustLabel->setObjectName("namaCustLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, namaCustLabel);

        namaCustLineEdit = new QLineEdit(formLayoutWidget);
        namaCustLineEdit->setObjectName("namaCustLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, namaCustLineEdit);

        siupCustLabel = new QLabel(formLayoutWidget);
        siupCustLabel->setObjectName("siupCustLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, siupCustLabel);

        siupCustLineEdit = new QLineEdit(formLayoutWidget);
        siupCustLineEdit->setObjectName("siupCustLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, siupCustLineEdit);

        alamatCustLabel = new QLabel(formLayoutWidget);
        alamatCustLabel->setObjectName("alamatCustLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, alamatCustLabel);

        alamatCustLineEdit = new QLineEdit(formLayoutWidget);
        alamatCustLineEdit->setObjectName("alamatCustLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, alamatCustLineEdit);

        email1Label = new QLabel(formLayoutWidget);
        email1Label->setObjectName("email1Label");

        formLayout->setWidget(3, QFormLayout::LabelRole, email1Label);

        email1LineEdit = new QLineEdit(formLayoutWidget);
        email1LineEdit->setObjectName("email1LineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, email1LineEdit);

        telp1Label = new QLabel(formLayoutWidget);
        telp1Label->setObjectName("telp1Label");

        formLayout->setWidget(4, QFormLayout::LabelRole, telp1Label);

        telp1LineEdit = new QLineEdit(formLayoutWidget);
        telp1LineEdit->setObjectName("telp1LineEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, telp1LineEdit);

        formLayoutWidget_2 = new QWidget(customer);
        formLayoutWidget_2->setObjectName("formLayoutWidget_2");
        formLayoutWidget_2->setGeometry(QRect(190, 40, 160, 128));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        fax1Label = new QLabel(formLayoutWidget_2);
        fax1Label->setObjectName("fax1Label");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, fax1Label);

        fax1LineEdit = new QLineEdit(formLayoutWidget_2);
        fax1LineEdit->setObjectName("fax1LineEdit");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, fax1LineEdit);

        cPCustLabel = new QLabel(formLayoutWidget_2);
        cPCustLabel->setObjectName("cPCustLabel");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, cPCustLabel);

        cPCustLineEdit = new QLineEdit(formLayoutWidget_2);
        cPCustLineEdit->setObjectName("cPCustLineEdit");

        formLayout_2->setWidget(1, QFormLayout::FieldRole, cPCustLineEdit);

        email2Label = new QLabel(formLayoutWidget_2);
        email2Label->setObjectName("email2Label");

        formLayout_2->setWidget(2, QFormLayout::LabelRole, email2Label);

        email2LineEdit = new QLineEdit(formLayoutWidget_2);
        email2LineEdit->setObjectName("email2LineEdit");

        formLayout_2->setWidget(2, QFormLayout::FieldRole, email2LineEdit);

        telp2Label = new QLabel(formLayoutWidget_2);
        telp2Label->setObjectName("telp2Label");

        formLayout_2->setWidget(3, QFormLayout::LabelRole, telp2Label);

        telp2LineEdit = new QLineEdit(formLayoutWidget_2);
        telp2LineEdit->setObjectName("telp2LineEdit");

        formLayout_2->setWidget(3, QFormLayout::FieldRole, telp2LineEdit);

        iDUserLabel = new QLabel(formLayoutWidget_2);
        iDUserLabel->setObjectName("iDUserLabel");

        formLayout_2->setWidget(4, QFormLayout::LabelRole, iDUserLabel);

        iDUserLineEdit = new QLineEdit(formLayoutWidget_2);
        iDUserLineEdit->setObjectName("iDUserLineEdit");

        formLayout_2->setWidget(4, QFormLayout::FieldRole, iDUserLineEdit);

        pushButton_2 = new QPushButton(customer);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(140, 180, 91, 21));
        tableView = new QTableView(customer);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 210, 331, 131));
        pushButton_3 = new QPushButton(customer);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(240, 180, 91, 21));

        retranslateUi(customer);

        QMetaObject::connectSlotsByName(customer);
    } // setupUi

    void retranslateUi(QDialog *customer)
    {
        customer->setWindowTitle(QCoreApplication::translate("customer", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("customer", "Tambah", nullptr));
        label->setText(QCoreApplication::translate("customer", "DATA CUSTOMER", nullptr));
        namaCustLabel->setText(QCoreApplication::translate("customer", "Nama Cust", nullptr));
        siupCustLabel->setText(QCoreApplication::translate("customer", "Siup Cust", nullptr));
        alamatCustLabel->setText(QCoreApplication::translate("customer", "Alamat Cust", nullptr));
        email1Label->setText(QCoreApplication::translate("customer", "Email 1", nullptr));
        telp1Label->setText(QCoreApplication::translate("customer", "Telp 1", nullptr));
        fax1Label->setText(QCoreApplication::translate("customer", "Fax 1", nullptr));
        cPCustLabel->setText(QCoreApplication::translate("customer", "CP Cust", nullptr));
        email2Label->setText(QCoreApplication::translate("customer", "Email 2", nullptr));
        telp2Label->setText(QCoreApplication::translate("customer", "Telp 2", nullptr));
        iDUserLabel->setText(QCoreApplication::translate("customer", "ID User", nullptr));
        pushButton_2->setText(QCoreApplication::translate("customer", "Edit", nullptr));
        pushButton_3->setText(QCoreApplication::translate("customer", "Hapus", nullptr));
    } // retranslateUi

};

namespace Ui {
    class customer: public Ui_customer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMER_H
