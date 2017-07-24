#pragma once

class QJsonObject;

class Serializable {
public:
    virtual void read(const QJsonObject& json) = 0;
    virtual void write(QJsonObject& json) const = 0;

    virtual ~Serializable() = default;
};
