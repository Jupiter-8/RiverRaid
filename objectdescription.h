#ifndef OBJECTDESCRIPTION_H
#define OBJECTDESCRIPTION_H

#include "objecttype.h"

#include <QObject>

struct ObjectDescription
{
public:
    qreal x;
    qreal y;
    qint8 speedX;
    qint8 speedY;
    ObjectType type;

    ObjectDescription(qreal x, qreal y, quint8 speedX, quint8 speedY, ObjectType type);
};

#endif // OBJECTDESCRIPTION_H
