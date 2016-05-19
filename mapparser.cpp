#include <QTextStream>
#include <QDebug>

#include "mapparser.h"

void MapParser::setHomonyms(QHash<QString, QStringList> *value)
   {
   homonyms = value;
   }

void MapParser::startParsing(QString filePath, bool isMap)
   {
   QFile file(filePath);
   if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      return;

   QTextStream in(&file);
   in.setLocale(QLocale::Turkish);
   while (!in.atEnd()) {
      QString line = in.readLine();
      if(isMap)
         parseMapLine(line);
      else
         parseTextLine(line);
      }
   }



void MapParser::parseMapLine(QString line)
   {
   QStringList a = line.split("-", QString::SkipEmptyParts);
   if (a.length()<2) return;


   QStringList b = homonyms->value(a.at(0).toLower());
   if ( b.isEmpty() )
      homonyms->insert(a.at(0).toLower(), QStringList(a.at(1)));
   else
      {
      b.append(a.at(1));
      homonyms->insert(a.at(0).toLower(),b);
      }
   }

void MapParser::parseTextLine(QString line)
   {
   QStringList a = line.split(QRegExp("\\W"),QString::SkipEmptyParts);
   int i=0;
   for(auto b : a) {
      if (!homonyms->value(b.toLower()).isEmpty()) i++;
      }
   qDebug() << "found" << i << "/" << a.length();
   }
