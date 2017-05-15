#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <aboutdialog.h>
#include <QFontDialog>
#include <QFont>
#include <QKeySequence>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->plainTextEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionZ_awijanie_wierszy_toggled(bool arg1)
{
    if(arg1==true)
    {
        ui->plainTextEdit->setLineWrapMode(QPlainTextEdit::WidgetWidth);
    }
    else
    {
        ui->plainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
    }
}

void MainWindow::on_actionOtw_rz_triggered()
{
    QString filter = "Wszystkie pliki (*.*) ;; Dokument tekstowy (*.txt)";
    QString file_path = QFileDialog::getOpenFileName(this, "Otwórz plik", QDir::homePath(),filter);
    QFile file(file_path);
    filename=file_path;
    if(file.open(QFile::ReadWrite | QFile::Text))
    {
        QTextStream in(&file);
        ui->plainTextEdit->setPlainText(in.readAll());
    }
    file.close();
}

void MainWindow::on_actionZapisz_jako_triggered()
{
    QString filter = "Wszystkie pliki (*.*) ;; Dokument tekstowy (*.txt)";
    QString file_path = QFileDialog::getSaveFileName(this, "Zapisz jako...", QDir::homePath(),filter);
    QFile file(file_path);
    if(file_path!="") filename=file_path;
    if(file.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&file);
        QString text = ui->plainTextEdit->toPlainText();
        out << text;
    }
    file.flush();
    file.close();
}

void MainWindow::on_actionZapisz_triggered()
{
    if(filename=="")
    {
        on_actionZapisz_jako_triggered();
    }
    else
    {
        QFile file(filename);
        if(file.open(QFile::WriteOnly | QFile::Text))
        {
            QTextStream out(&file);
            QString text = ui->plainTextEdit->toPlainText();
            out << text;
        }
        file.flush();
        file.close();
    }
}


void MainWindow::on_actionNowy_triggered()
{
    filename="";
    ui->plainTextEdit->setPlainText("");
}

void MainWindow::on_actionZako_cz_triggered()
{
    exit(EXIT_SUCCESS);
}

void MainWindow::on_actionWytnij_triggered()
{
    ui->plainTextEdit->cut();
}

void MainWindow::on_actionKopiuj_triggered()
{
    ui->plainTextEdit->copy();
}

void MainWindow::on_actionWklej_triggered()
{
    ui->plainTextEdit->paste();
}

void MainWindow::on_action_Czcionka_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok,this);
    if(ok)
    {
        QTextCursor cursor = ui->plainTextEdit->textCursor();
        QTextCharFormat format = cursor.charFormat();
        if(cursor.selectedText()=="")
        {
            ui->plainTextEdit->setFont(font);
        }
        else
        {
        format.setFont(font);
        cursor.setCharFormat(format);
        }
    }else return;
}

void MainWindow::on_actionCofnij_triggered()
{
    ui->plainTextEdit->undo();
}

void MainWindow::on_actionPrzywr_triggered()
{
    ui->plainTextEdit->redo();
}

void MainWindow::on_actionO_programie_triggered()
{
    AboutDialog *about = new AboutDialog(this);
    about->show();
}

