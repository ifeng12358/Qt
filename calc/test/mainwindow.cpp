#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->my_label->setStyleSheet("border:0.5px solid gray;");
    ui->my_label->setText("");
    _Flag = false;

    connect(this,SIGNAL(input(QString)),this,SLOT(displayInput(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayInput(QString str)
{
    ui->my_label->setText(ui->my_label->text() + str);
}

void MainWindow::on_pushButton_clicked() //num 1
{
    emit input(ui->pushButton->text());
}

void MainWindow::on_pushButton_2_clicked() //num 2
{
    emit input(ui->pushButton_2->text());
}

void MainWindow::on_pushButton_3_clicked() //num 3
{
    emit input(ui->pushButton_3->text());
}

void MainWindow::on_pushButton_4_clicked() //num 4
{
    emit input(ui->pushButton_4->text());
}

void MainWindow::on_pushButton_5_clicked() //num 5
{
    emit input(ui->pushButton_5->text());
}

void MainWindow::on_pushButton_6_clicked() //num 6
{
    emit input(ui->pushButton_6->text());
}

void MainWindow::on_pushButton_7_clicked() //num 7
{
    emit input(ui->pushButton_7->text());
}

void MainWindow::on_pushButton_8_clicked() //num 8
{
    emit input(ui->pushButton_8->text());
}

void MainWindow::on_pushButton_9_clicked() //num 9
{
    emit input(ui->pushButton_9->text());
}

void MainWindow::on_pushButton_10_clicked() //num 0
{
    emit input(ui->pushButton_10->text());
}

void MainWindow::on_pushButton_12_clicked() //num +
{
    if(_Flag == false)
    {
        emit input(ui->pushButton_12->text());
        _Flag = true;
    }else{
        on_pushButton_11_clicked();
        ui->my_label->setText(ui->my_label->text()+"+");
    }
}

void MainWindow::on_pushButton_13_clicked() //num -
{
    if(_Flag == false)
    {
    emit input(ui->pushButton_13->text());
    _Flag = true;
    }else{
        on_pushButton_11_clicked();
        ui->my_label->setText(ui->my_label->text()+"-");
    }
}

void MainWindow::on_pushButton_14_clicked() //num *
{
    if(_Flag == false)
    {
    emit input(ui->pushButton_14->text());
    _Flag = true;
    }else{
        on_pushButton_11_clicked();
        ui->my_label->setText(ui->my_label->text()+"*");
    }

}

void MainWindow::on_pushButton_15_clicked() //num /
{
    if(_Flag == false)
    {
    emit input(ui->pushButton_15->text());
    _Flag = true;
    }else{
        on_pushButton_11_clicked();
        ui->my_label->setText(ui->my_label->text()+"/");
    }
}

void MainWindow::on_pushButton_11_clicked() //num =
{
    //no checking the +-*/,please rewrite yourself.
    QString str1 = ui->my_label->text();

    if(str1.contains('+',Qt::CaseSensitive))
    {
        int iPos = str1.indexOf('+',Qt::CaseSensitive);
        QString nValue = "";
        int iValue = (str1.left(iPos)).toInt()+(str1.right(iPos)).toInt();
        nValue = QString("%1").arg(iValue);
        ui->my_label->setText(nValue);
        _Flag = false;
    }else if(str1.contains('-',Qt::CaseSensitive))
    {
        int iPos = str1.indexOf('-',Qt::CaseSensitive);
        QString nValue = "";
        int iValue = (str1.left(iPos)).toInt()-(str1.right(iPos)).toInt();
        nValue = QString("%1").arg(iValue);
        ui->my_label->setText(nValue);
        _Flag = false;
    }else if(str1.contains('*',Qt::CaseSensitive))
    {
        int iPos = str1.indexOf('*',Qt::CaseSensitive);
        QString nValue = "";
        int iValue = (str1.left(iPos)).toInt()*(str1.right(iPos)).toInt();
        nValue = QString("%1").arg(iValue);
        ui->my_label->setText(nValue);
        _Flag = false;
    }else if(str1.contains('/',Qt::CaseSensitive))
    {

        int iPos = str1.indexOf('/',Qt::CaseSensitive);
        if((str1.right(iPos))!="0")
        {
            QString nValue = "";
            double iValue = (str1.left(iPos)).toDouble()/(str1.right(iPos)).toDouble();
            nValue = QString("%1").arg(iValue);
            ui->my_label->setText(nValue);
        }else{
            ui->my_label->setText("0");
        }
        _Flag = false;
    }
}

void MainWindow::on_pushButton_16_clicked()
{
    _Flag = false;
    ui->my_label->setText("");
}
