#include "Player.h"

void Player::moveUp() {
    QPointF speed = muffin.getSpeed();
    speed.setY(-1);
    muffin.setSpeed(speed);
}

void Player::moveDown() {
    QPointF speed = muffin.getSpeed();
    speed.setY(1);
    muffin.setSpeed(speed);
}

void Player::moveLeft() {
    QPointF speed = muffin.getSpeed();
    speed.setX(-1);
    muffin.setSpeed(speed);
}

void Player::moveRight() {
    QPointF speed = muffin.getSpeed();
    speed.setX(1);
    muffin.setSpeed(speed);
}

Player::Player(const QPointF& pos): muffin(pos) {}

Muffin& Player::getMuffin() {
    return muffin;
}
