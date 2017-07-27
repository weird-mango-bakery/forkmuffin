#include "gtest/gtest.h"
#include "pretty_print.h"

#include <QJsonObject>
#include "common/Block.h"

void testColorRead(const QString& s, const QColor& c){
    Block b;
    QJsonObject json({
         {"color", s}
    });
    b.read(json);
    QColor color = b.getColor();
    EXPECT_TRUE(color.isValid());
    EXPECT_EQ(color, c);
}

void testColorWrite(const QString& s, const QColor& c){
    Block b(c);
    QJsonObject json;
    b.write(json);
    EXPECT_TRUE(json.contains("color"));
    EXPECT_EQ(json["color"].toString(), s);
}

void testColorReadWrite(const QString& s){
    Block b;
    QJsonObject original({
         {"color", s}
    });
    b.read(original);

    QJsonObject saved;
    b.write(saved);

    EXPECT_EQ(saved, original);
}


TEST(block, save) {
    testColorWrite("000000", {0, 0, 0});
    testColorWrite("ff0080", {255, 0, 128});
    testColorWrite("012345", {1, 35, 69});
}

TEST(block, load) {
    testColorRead("000000", {0, 0, 0});
    testColorRead("ff0080", {255, 0, 128});
    testColorRead("012345", {1, 35, 69});
}

TEST(block, consistency) {
    testColorReadWrite("000000");
    testColorReadWrite("ff0080");
    testColorReadWrite("012345");
}
