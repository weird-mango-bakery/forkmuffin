#include "RenderManager.h"

#include "common/Renderable.h"

#include <QPainter>

void RenderManager::addRenderable(const Renderable& item) {
    renderables.insert(item.getZOrder(), &item);
}

void RenderManager::removeRenderable(const Renderable& item) {
    renderables.remove(item.getZOrder(), &item);
}

void RenderManager::updateZOrder(const Renderable& item, float oldZOrder, float newZOrder) {
    renderables.remove(oldZOrder, &item);
    renderables.insert(newZOrder, &item);
}

RenderManager& RenderManager::get() {
    static RenderManager manager;
    return manager;
}

void RenderManager::paint(QPainter& p) const {
    QMapIterator<float, const Renderable*> it(renderables);
    it.toBack();
    // walking from highest Z-order values to lowest
    // for same Z-order values walking from earliest added to latest
    while(it.hasPrevious()) {
        it.previous();
        p.save();
        it.value()->paint(p);
        p.restore();
    }
}
