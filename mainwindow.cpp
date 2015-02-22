/*
 * diff-pdf GUI
 * ************
 *
 * Licence:     GNU GENERAL PUBLIC LICENSE
 * Author:      Sylvain MARIEL <sylvain.mariel@otmax.fr>
 *
 * Original app "diff-pdf"
 * http://vslavik.github.io/diff-pdf/
 * by Vaclav Slavik <vslavik@fastmail.fm>
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QFileDialog"
#include "QMessageBox"
#include "QProcess"
#include "QDesktopServices"

#ifdef QT_DEBUG
    #define DIFFPDF_PATH "../diff-pdf/diff-pdf.exe"
#else
    #define DIFFPDF_PATH "diff-pdf.exe"
#endif


// MainWindow constructor, on launch...
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    if(!QFile().exists(DIFFPDF_PATH))
    {
        QMessageBox::warning(this,"Error","Can not find diff-pdf.exe");
        QCoreApplication::exit();
    }

    QDir().mkdir("tmp");
    ui->setupUi(this);
    ui->compare_checkbox->setChecked(true);
}

// MainWindow destructor, on exit...
MainWindow::~MainWindow()
{
    delete ui;
    clean_tmp();
    QDir().rmdir("tmp");
}


// Browse BT clieked, open file dialog and fill the textbox
void MainWindow::on_file1_button_clicked()
{
   QString file_path = QFileDialog::getOpenFileName(this, tr("Open PDF file 1"), "", tr("PDF Filee (*.pdf)"));
   if(!file_path.isNull())
   {
       ui->file1_text->setText(file_path);
   }
}
void MainWindow::on_file2_button_clicked()
{
    QString file_path = QFileDialog::getOpenFileName(this, tr("Open PDF file 2"), "", tr("PDF Filee (*.pdf)"));
    if(!file_path.isNull())
    {
        ui->file2_text->setText(file_path);
    }
}
void MainWindow::on_output_button_clicked()
{
    QString file_path = QFileDialog::getSaveFileName(this, tr("Save output PDF file"), "", tr("PDF Filee (*.pdf)"));
    if(!file_path.isNull())
    {
        ui->output_text->setText(file_path);
    }
}

// Compare button clicked
void MainWindow::on_compar_button_clicked()
{
    QFile file1(ui->file1_text->text());
    QFile file2(ui->file2_text->text());
    QFile output(ui->output_text->text());

    QFile file1_tmp("tmp/file1.pdf");
    QFile file2_tmp("tmp/file2.pdf");
    QFile output_tmp("tmp/output.pdf");

    // check if specified files exist
    if(!file1.exists())
    {
        QMessageBox::warning(this, "Error", "File1 does not exist");
    }
    else if(!file2.exists())
    {
        QMessageBox::warning(this, "Error", "File2 does not exist");
    }
    else if(ui->output_text->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Output file is empty");
    }
    else
    {
        // Delete old temporary files
        clean_tmp();

        // Copy file to work in local (diff-pdf does not like network)
        QFile::copy(file1.fileName(), file1_tmp.fileName());
        QFile::copy(file2.fileName(), file2_tmp.fileName());

        // Process...
        QProcess diffpdf_process;
        diffpdf_process.start(DIFFPDF_PATH, QStringList() << "--output-diff" << output_tmp.fileName() << file1_tmp.fileName() << file2_tmp.fileName());
        if(!diffpdf_process.waitForFinished(-1))
        {
            QMessageBox::warning(this, "Error", "Error occured on diff-pdf execution");
        }

        // Copy the result file
        QFile::copy(output_tmp.fileName(), output.fileName());

        // Optionaly, open the new file
        if(ui->compare_checkbox->isChecked())
        {
            QDesktopServices::openUrl(QUrl(output.fileName()));
        }
    }
}

// Clean temproray files
void clean_tmp()
{
    QFile::remove("tmp/file1.pdf");
    QFile::remove("tmp/file2.pdf");
    QFile::remove("tmp/output.pdf");
}
