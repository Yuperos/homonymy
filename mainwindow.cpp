#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
   {
   ui->setupUi(this);
   homonyms = new QHash<QString, QStringList>;
   MapParser parser;
   parser.setHomonyms(homonyms);
   parser.startParsing(":/new/maps/map.txt", true);
   parser.startParsing(":/new/maps/test.txt", false);


//   qDebug() << homonyms->values();
   }

MainWindow::~MainWindow()
   {
   delete ui;
   }
