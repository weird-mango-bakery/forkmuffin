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

    //! Creates image from the given params with BACKGROUND Z-order.
    StrayImage(const QString& name, const QPoint& pos, const QSize& size, const QString& texture);

    void paint(QPainter& p) const override;

    //! Returns the image name.
    const QString& getName() const;
    //! Returns the image position.
    const QPoint& getPos() const;
    //! Returns the image size.
    const QSize& getSize() const;
    //! Returns the image texture name.
    const QString& getTexture() const;

    //! Sets the image position to the new position.
    //! \param pos The new position.
    void setPos(const QPoint& pos);
    //! Sets the image size to the new size.
    //! \param size The new size.
    void setSize(const QSize& size);
    //! Sets the image name to the new name.
    //! \param name The new name.
    void setName(const QString& name);
    //! Sets the image texture name to the new texture name.
    //! \param tex The new texture name.
    void setTexture(const QString& tex);

    void read(const QJsonObject& json) override;
    void write(QJsonObject& json) const override;
};
