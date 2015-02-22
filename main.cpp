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
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
