#include "const.h"
#include "mapwidget.h"

#include <QPainter>
#include <QResizeEvent>
#include <QDebug>

using namespace std;

MapWidget::MapWidget(QWidget *parent) : QWidget(parent)
{
    m_size = min(this->height() / 5 / Const::SQRT3, this->width() / 8.0);
    buildTile();
}

void MapWidget::resizeEvent(QResizeEvent* event)
{
    //qDebug()<<' '<<this->visibleRegion();
    m_center = QPointF(this->width() / 2, this->height() / 2);
    m_size = min(this->height() / 8.0, this->width() / 5 / Const::SQRT3) * 0.85;
    buildTile();
    QWidget::resizeEvent(event);
}

void MapWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    qDebug()<<this->rect();
    painter.setBrush(QColor(0, 132, 255));
    painter.drawRect(0, 0, this->width()-1, this->height()-1);
    for (int i = 0; i < 19; i++)
    {
        painter.setBrush(tile[i].Color());
        //qDebug()<<tile.ToPolygon();
        painter.drawPolygon(tile[i].ToPolygon());
    }
    QWidget::paintEvent(event);
}

void MapWidget::buildTile()
{
    tile[0].Rebuild(m_center + QPointF(-1 * Const::SQRT3 * m_size, -3 * m_size), m_size);
    tile[1].Rebuild(m_center + QPointF( 0 * Const::SQRT3 * m_size, -3 * m_size), m_size);
    tile[2].Rebuild(m_center + QPointF( 1 * Const::SQRT3 * m_size, -3 * m_size), m_size);

    tile[3].Rebuild(m_center + QPointF(-1.5 * Const::SQRT3 * m_size, -1.5 * m_size), m_size);
    tile[4].Rebuild(m_center + QPointF(-0.5 * Const::SQRT3 * m_size, -1.5 * m_size), m_size);
    tile[5].Rebuild(m_center + QPointF( 0.5 * Const::SQRT3 * m_size, -1.5 * m_size), m_size);
    tile[6].Rebuild(m_center + QPointF( 1.5 * Const::SQRT3 * m_size, -1.5 * m_size), m_size);

    tile[7].Rebuild( m_center + QPointF(-2 * Const::SQRT3 * m_size, 0), m_size);
    tile[8].Rebuild( m_center + QPointF(-1 * Const::SQRT3 * m_size, 0), m_size);
    tile[9].Rebuild( m_center + QPointF( 0 * Const::SQRT3 * m_size, 0), m_size);
    tile[10].Rebuild(m_center + QPointF( 1 * Const::SQRT3 * m_size, 0), m_size);
    tile[11].Rebuild(m_center + QPointF( 2 * Const::SQRT3 * m_size, 0), m_size);

    tile[12].Rebuild(m_center + QPointF(-1.5 * Const::SQRT3 * m_size, 1.5 * m_size), m_size);
    tile[13].Rebuild(m_center + QPointF(-0.5 * Const::SQRT3 * m_size, 1.5 * m_size), m_size);
    tile[14].Rebuild(m_center + QPointF( 0.5 * Const::SQRT3 * m_size, 1.5 * m_size), m_size);
    tile[15].Rebuild(m_center + QPointF( 1.5 * Const::SQRT3 * m_size, 1.5 * m_size), m_size);

    tile[16].Rebuild(m_center + QPointF(-1 * Const::SQRT3 * m_size, 3 * m_size), m_size);
    tile[17].Rebuild(m_center + QPointF( 0 * Const::SQRT3 * m_size, 3 * m_size), m_size);
    tile[18].Rebuild(m_center + QPointF( 1 * Const::SQRT3 * m_size, 3 * m_size), m_size);
}
