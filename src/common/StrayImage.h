#pragma once

#include <QPoint>
#include <QSize>
#include <QString>
#include "common/Renderable.h"
#include "common/Serializable.h"

//! Static image on the level with fixed position and Z-order.
class StrayImage : public Serializable, public Renderable {
private:
    //! Unique name of the image (used editor).
    QString name;
    //! The current image position in world coordinates.
    QPoint pos;
    //! The image size in world coordinates.
    QSize size;
    //! File name.
    QString texture;

public:
    //! Creates empty image with BACKGROUND Z-order.
    StrayImage();

    void paint(QPainter& p) const override;

    void read(const QJsonObject& json) override;
    void write(QJsonObject& json) const override;
};
