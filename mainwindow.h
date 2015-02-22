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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_file1_button_clicked();

    void on_file2_button_clicked();

    void on_output_button_clicked();

    void on_compar_button_clicked();

private:
    Ui::MainWindow *ui;
};

void clean_tmp();

#endif // MAINWINDOW_H
