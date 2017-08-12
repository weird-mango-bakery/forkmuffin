#include "gtest/gtest.h"
#include "pretty_print.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#include "common/Level.h"

TEST(level, save) {
    // TODO: construct level and check it saves correctly
}

TEST(level, load) {
    Level lvl;
    QJsonObject json{
        {"blocks",  QJsonObject{
            {"#", QJsonObject{
                {"texture", "block_#_grass.png"}
            }}
        }},
        {"map", QJsonArray{
            "#  ",
            "###",
        }},
        {"version", 1}
    };
    lvl.read(json);
    // TODO: check everything got correctly loaded in level
}

TEST(level, consistency) {
    QByteArray originalData = R"({
    "blocks": {
        "#": {
            "texture": "block_#_grass.png"
        }
    },
    "map": [
        " ############## ",
        "#              #",
        "#   #      #   #",
        "#   ##    ##   #",
        "#              #",
        "#  ##########  #",
        "#              #",
        " ############## "
    ],
    "version": 1
}
)";
    QJsonObject original = QJsonDocument::fromJson(originalData).object();

    Level lvl;
    lvl.read(original);

    QJsonObject saved;
    lvl.write(saved);

    EXPECT_EQ(original, saved);
    EXPECT_EQ(originalData, QJsonDocument(saved).toJson());
}
