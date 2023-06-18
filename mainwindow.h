#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile> //Working with files
#include <QFileDialog> //File Dialogs that pops up to select a file
#include <QTextStream> //To read texts files
#include <QMessageBox> //Opens message box in case of errors
#include <QPrinter> //To print with a printer
#include <QPrintDialog> //Allows user to select which printer to use
#include <QTextEdit>
#include <QTextCursor>
#include <QTextCharFormat>
#include <QColorDialog>
#include <QFontDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT //each QObject operates on it's own thread

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_As_triggered();

    void on_actionSave_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_2_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionBold_triggered();

    void on_actionItalic_triggered();

    void on_actionUnderline_triggered();

    void on_actionStrike_through_triggered();

    void on_actionFont_Color_triggered();

    void on_actionFont_Family_triggered();

private:
    Ui::MainWindow *ui;
    QString currentFile = "";
};
#endif // MAINWINDOW_H
