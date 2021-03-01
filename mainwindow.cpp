#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionnew->setIcon(QIcon(":/image/timg.jpg"));
    connect(ui->actionnew,&QAction::triggered,[=](){
//        QDialog* dialog = new QDialog(this);
//        dialog->resize(200,100);
//        dialog->show();
//        dialog->setAttribute(Qt::WA_DeleteOnClose);
        QMessageBox::critical(this,"hello","错误",QMessageBox::Yes|QMessageBox::No|QMessageBox::Save,QMessageBox::Yes);


    });

    connect(ui->actionsave, &QAction::triggered,[=](){
        QString filename =  QFileDialog::getOpenFileName(this,"保存文件路径","D:\\","(*.*)");
    });

    connect(ui->actionfont, &QAction::triggered, [=](){
        bool flag = true;
        QFont font = QFontDialog::getFont(&flag,QFont("微软雅黑",12));
    });

    connect(ui->actioncolor, &QAction::triggered,[=](){
        QColor color = QColorDialog::getColor(QColor(255,255,255),this,"字体颜色");
    });

//    connect(this,&QMainWindow::close,[=](){
//       if(QMessageBox::Yes == QMessageBox::warning(this,"","是否保存？",QMessageBox::Yes|QMessageBox::Cancel|QMessageBox::No))
//       {
//           this->close();
//       }
//    });



}

MainWindow::~MainWindow()
{
    delete ui;
}

