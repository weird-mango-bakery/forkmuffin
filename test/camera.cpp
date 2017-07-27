#include "gtest/gtest.h"
#include "pretty_print.h"

#include "common/Camera.h"
#include "common/Level.h"

TEST(camera, consistency) {
    Camera cam;
    cam.setScale(2.7);
    cam.setTranslation(QPointF(17, 45));

    QPointF p(32, 11);
    EXPECT_EQ(p, cam.screenToWorld(cam.worldToScreen(p)));
    EXPECT_EQ(p, cam.worldToScreen(cam.screenToWorld(p)));
}

TEST(camera, worldToLevel) {
    int d = 10;
    int block = Level::BLOCK_SIZE;
    ASSERT_LT(d, block) << "this constant should be made less than grid size";

    EXPECT_EQ(QPoint(0, 0), Camera::worldToLevel(QPointF(0, 0)));
    EXPECT_EQ(QPoint(0, 0), Camera::worldToLevel(QPointF(d, d)));
    EXPECT_EQ(QPoint(1, 1), Camera::worldToLevel(QPointF(d + block, d + block)));
    EXPECT_EQ(QPoint(-1, -1), Camera::worldToLevel(QPointF(-d, -d)));
    EXPECT_EQ(QPoint(-2, -2), Camera::worldToLevel(QPointF(-d - block, -d - block)));
}

TEST(camera, levelToWorld) {
    int block = Level::BLOCK_SIZE;

    EXPECT_EQ(QPointF(0, 0), Camera::levelToWorld(QPoint(0, 0)));
    EXPECT_EQ(QPointF( block,  block), Camera::levelToWorld(QPoint( 1,  1)));
    EXPECT_EQ(QPointF(-block, -block), Camera::levelToWorld(QPoint(-1, -1)));
}
