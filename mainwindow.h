#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHash>
#include <QStringList>

#include "mapparser.h"

namespace Ui {
   class MainWindow;
   }

class MainWindow : public QMainWindow
{
   Q_OBJECT


public:
   QHash<QString, QStringList>* homonyms;
   explicit MainWindow(QWidget *parent = 0);
   ~MainWindow();

private:
   Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
