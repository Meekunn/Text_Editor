#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);// to take up the whole screen.
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString()); //Clear the textEdit widget
}


void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(filename);
    currentFile = filename;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot Open File: " + file.errorString());
        return;
    }
    setWindowTitle("File Path: " + filename);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSave_As_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(filename);
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot Save File: " + file.errorString());
        return;
    }
    currentFile = filename;
    setWindowTitle("File Path: " + filename);
    QTextStream out(&file);
    QString text = ui->textEdit->toHtml(); //copy text in the textEdit
    out << text; //write copied text to the file
    file.close();
}

void MainWindow::on_actionSave_triggered()
{
    QFile file(currentFile);
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Unable to Save Changes");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toHtml();
    out << text;
    file.close();
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer; //allows interaction with any printer on the network
    printer.setPrinterName("Printer Name");
    QPrintDialog pDialog(&printer, this);
    if(pDialog.exec() == QDialog::Rejected) {
        QMessageBox::warning(this, "Warning", "Cannot Access Printer");
        return;
    }
    ui->textEdit->print(&printer); //send texts to printer
}


void MainWindow::on_actionExit_2_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionBold_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    if(!cursor.hasSelection()) return;

    QTextCharFormat format;
    format.setFontWeight(cursor.charFormat().fontWeight() == QFont::Bold ? QFont::Normal : QFont::Bold);

    cursor.mergeCharFormat(format);
    ui->textEdit->mergeCurrentCharFormat(format);
}


void MainWindow::on_actionItalic_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    if(!cursor.hasSelection()) return;

    QTextCharFormat format;
    format.setFontItalic(!(cursor.charFormat().fontItalic()));

    cursor.mergeCharFormat(format);
    ui->textEdit->mergeCurrentCharFormat(format);
}


void MainWindow::on_actionUnderline_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    if(!cursor.hasSelection()) return;

    QTextCharFormat format;
    format.setFontUnderline(!(cursor.charFormat().fontUnderline()));

    cursor.mergeCharFormat(format);
    ui->textEdit->mergeCurrentCharFormat(format);
}


void MainWindow::on_actionStrike_through_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    if(!cursor.hasSelection()) return;

    QTextCharFormat format;
    format.setFontStrikeOut(!(cursor.charFormat().fontStrikeOut()));

    cursor.mergeCharFormat(format);
    ui->textEdit->mergeCurrentCharFormat(format);
}


void MainWindow::on_actionFont_Color_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    if(!cursor.hasSelection()) return;

    QColor color = QColorDialog::getColor(Qt::black, this, "Select Font Color");
    if(!color.isValid()) return;

    QTextCharFormat format;
    format.setForeground(color);

    cursor.mergeCharFormat(format);
    ui->textEdit->mergeCurrentCharFormat(format);
}


void MainWindow::on_actionFont_Family_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    if(!cursor.hasSelection()) return;

    bool ok;

    QFont font = QFontDialog::getFont(&ok, this);
    if(!ok) return;

    QTextCharFormat format;
    format.setFont(font);

    cursor.mergeCharFormat(format);
    ui->textEdit->mergeCurrentCharFormat(format);
}
