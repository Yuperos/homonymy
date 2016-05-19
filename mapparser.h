#ifndef MAPPARSER_H
#define MAPPARSER_H

#include <QFile>
#include <QString>
#include <QStringList>

#include "mapparser.h"

class MapParser
{
   QHash<QString,QStringList> *homonyms;
   void parseMapLine(QString line);
   void parseTextLine(QString line);
public:
   MapParser(){}
   void startParsing(QString filePath, bool isMap);
   void setHomonyms(QHash<QString, QStringList> *value);
};

#endif // MAPPARSER_H
