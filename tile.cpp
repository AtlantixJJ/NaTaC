#include "const.h"
#include "tile.h"

#include <QDebug>

Tile::Tile()
{

}

Tile::Tile(double x, double y, double size) :
    m_center(x, y), m_size(size)
{
    buildPolygon();
}

Tile::Tile(const QPointF& center, double size) :
    m_center(center), m_size(size)
{
    buildPolygon();
}

void Tile::SetGeometry(const QPointF &center, double size)
{
    m_size = size;
    m_center = center;
    buildPolygon();
}

void Tile::buildPolygon()
{
    m_color = Qt::red;
    m_polygon.clear();
    m_polygon << m_center + QPointF(0, -m_size)
              << m_center + QPointF(-m_size * Const::SQRT3/ 2, -m_size / 2)
              << m_center + QPointF(-m_size * Const::SQRT3/ 2,  m_size / 2)
              << m_center + QPointF(0,  m_size)
              << m_center + QPointF( m_size * Const::SQRT3/ 2,  m_size / 2)
              << m_center + QPointF( m_size * Const::SQRT3/ 2, -m_size / 2);

    //qDebug()<<center<<' '<<m_size<<' '<<' '<<m_polygon;
}
