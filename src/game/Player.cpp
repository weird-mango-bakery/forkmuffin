#include "Player.h"
#include <QPainter>

void Player::paint(QPainter& p) const {
    p.fillRect(QRect(pos, QSize(30, 50)), QColor(0, 255, 128));
}

float Player::getZOrder() const {
    return Z_MIDDLE;
}

void Player::moveUp() {
    pos += QPoint(0, -1);
}

void Player::moveDown() {
    pos += QPoint(0, 1);
}

void Player::moveLeft() {
    pos += QPoint(-1, 0);
}

void Player::moveRight() {
    pos += QPoint(1, 0);
}
