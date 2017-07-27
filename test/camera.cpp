#include "gtest/gtest.h"
#include "pretty_print.h"

#include "common/Camera.h"

TEST(camera, conversion) {
    Camera cam;
    cam.setScale(2.7);
    cam.setTranslation(QPointF(17, 45));

    QPointF p(32, 11);
    EXPECT_EQ(p, cam.screenToWorld(cam.worldToScreen(p)));
    EXPECT_EQ(p, cam.worldToScreen(cam.screenToWorld(p)));
}
