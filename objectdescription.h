#ifndef OBJECTDESCRIPTION_H
#define OBJECTDESCRIPTION_H

#include "objecttype.h"

#include <QObject>

struct ObjectDescription
{
public:
    qreal m_x;
    qreal m_y;
    qint8 m_speedX;
    qint8 m_speedY;
    ObjectType m_type;

    ObjectDescription(qreal x, qreal y, quint8 speedX, quint8 speedY, ObjectType type);
};

#endif // OBJECTDESCRIPTION_H
