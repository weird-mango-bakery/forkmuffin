#include "Player.h"

static const int SPEED = 200;

void Player::moveUp() {
    QPointF speed = muffin.getSpeed();
    speed.setY(-SPEED);
    muffin.setSpeed(speed);
}

void Player::moveDown() {
    QPointF speed = muffin.getSpeed();
    speed.setY(SPEED);
    muffin.setSpeed(speed);
}

void Player::moveLeft() {
    QPointF speed = muffin.getSpeed();
    speed.setX(-SPEED);
    muffin.setSpeed(speed);
}

void Player::moveRight() {
    QPointF speed = muffin.getSpeed();
    speed.setX(SPEED);
    muffin.setSpeed(speed);
}

Player::Player(const QPointF& pos): muffin(pos) {}

Muffin& Player::getMuffin() {
    return muffin;
}
