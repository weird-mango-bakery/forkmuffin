#include "Player.h"
#include <QPainter>

void Player::paint(QPainter& p) const {
    p.fillRect(QRect(pos, QSize(30, 50)), QColor(0, 255, 128));
}

float Player::getZOrder() const {
    return Z_MIDDLE;
}
