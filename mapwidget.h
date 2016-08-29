#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include "tile.h"

#include <QWidget>

class MapWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MapWidget(QWidget *parent = 0);

public slots:

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    Tile tile[19];
    double m_size;
    QPointF m_center;

    void buildTile();
};

#endif // MAPWIDGET_H
