#include "gtest/gtest.h"
#include "pretty_print.h"

#include <QJsonObject>
#include "common/Block.h"

void testTextureRead(const QString& s){
    Block b;
    QJsonObject json({
         {"texture", s}
    });
    b.read(json);
    QString textureName = b.getTexture();
    EXPECT_EQ(textureName, s);
}

void testTextureWrite(const QString& s){
    Block b(s);
    QJsonObject json;
    b.write(json);
    EXPECT_TRUE(json.contains("texture"));
    EXPECT_EQ(json["texture"].toString(), s);
}

void testTextureReadWrite(const QString& s){
    Block b;
    QJsonObject original({
         {"texture", s}
    });
    b.read(original);

    QJsonObject saved;
    b.write(saved);

    EXPECT_EQ(saved, original);
}


TEST(block, save) {
    testTextureWrite("block_#_grass.png");
}

TEST(block, load) {
    testTextureRead("block_#_grass.png");
}

TEST(block, consistency) {
    testTextureReadWrite("block_#_grass.png");
}
