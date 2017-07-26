#include "Player.h"
#include <QPainter>

void Player::paint(QPainter& p) const {
    p.fillRect(QRectF(getPos(), getSize()), QColor(0, 255, 128));
}

float Player::getZOrder() const {
    return Z_MIDDLE;
}

void Player::moveUp() {
    setPos(getPos() + QPointF(0, -1));
}

void Player::moveDown() {
    setPos(getPos() + QPointF(0, 1));
}

void Player::moveLeft() {
    setPos(getPos() + QPointF(-1, 0));
}

void Player::moveRight() {
    setPos(getPos() + QPointF(1, 0));
}

QSizeF Player::getSize() const {
    return QSizeF(30, 50);
}

Player::Player(const QPointF& pos): PhysicsObject(pos) {}
