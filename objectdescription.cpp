#include "objectdescription.h"

ObjectDescription::ObjectDescription(qreal x, qreal y, quint8 speedX, quint8 speedY, ObjectType type)
    :m_x(x), m_y(y), m_speedX(speedX), m_speedY(speedY), m_type(type)
{
}
