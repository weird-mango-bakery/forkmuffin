#include "Player.h"
#include <QPainter>

void Player::paint(QPainter& p) const {
    p.fillRect(QRectF(getPos(), getSize()), QColor(0, 255, 128));
}

float Player::getZOrder() const {
    return Z_MIDDLE;
}

void Player::moveUp() {
    QPointF speed = getSpeed();
    speed.setY(-1);
    setSpeed(speed);
}

void Player::moveDown() {
    QPointF speed = getSpeed();
    speed.setY(1);
    setSpeed(speed);
}

void Player::moveLeft() {
    QPointF speed = getSpeed();
    speed.setX(-1);
    setSpeed(speed);
}

void Player::moveRight() {
    QPointF speed = getSpeed();
    speed.setX(1);
    setSpeed(speed);
}

QSizeF Player::getSize() const {
    return QSizeF(30, 50);
}

Player::Player(const QPointF& pos): PhysicsObject(pos) {}
