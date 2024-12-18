#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    connect(actionSave,SIGNAL(triggered(bool)),this,SLOT(saveFile()));
    connect(actionClose,SIGNAL(triggered(bool)),this,SLOT(close()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("儲存檔案"), "", tr("Text Files (*.txt);;All Files (*)"));


    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("錯誤"), tr("無法開啟檔案: %1").arg(file.errorString()));
        return;
    }

    QTextStream out(&file);
    out << textEdit->toPlainText(); // 假設你的 TextEdit 名稱是 textEdit
    file.close();

    QMessageBox::information(this, tr("成功"), tr("檔案儲存完成"));
}
