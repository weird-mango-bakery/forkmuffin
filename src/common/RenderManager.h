#pragma once

#include <QMultiMap>

class Renderable;
class QPainter;

//! Class that holds all renderables and paints them in the correct order.
class RenderManager {
private:
    //! Only Renderable can call our private methods.
    friend class Renderable;
    //! Render queue.
    QMultiMap<float, const Renderable*> renderables;

    //! Private constructor so the render manager can be created inside get() only.
    RenderManager() = default;

    //! Adds a renderable to the render queue.
    //! Called automatically by all Renderables in their constructor.
    //! \param item the new renderable.
    void addRenderable(const Renderable& item);

    //! Removes a renderable from the render queue.
    //! Called automatically by all Renderables in their destructor.
    //! \param item the renderable to remove.
    void removeRenderable(const Renderable& item);

    //! Updates Z-order of a renderable in the render queue.
    //! Called automatically by all Renderables when their Z-order changes.
    void updateZOrder(const Renderable& item, float oldZOrder, float newZOrder);

public:
    //! The static function to get or create the render manager.
    static RenderManager& get();

    //! Paints all renderables on the specified painter.
    void paint(QPainter& p) const;
};
