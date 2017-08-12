#include "Renderable.h"

#include "common/RenderManager.h"

Renderable::Renderable(float zOrder): zOrder(zOrder) {
    RenderManager::get().addRenderable(*this);
}

Renderable::~Renderable() {
    RenderManager::get().removeRenderable(*this);
}

float Renderable::getZOrder() const {
    return zOrder;
}

void Renderable::setZOrder(float newZOrder) {
    RenderManager::get().updateZOrder(*this, zOrder, newZOrder);
    zOrder = newZOrder;
}
