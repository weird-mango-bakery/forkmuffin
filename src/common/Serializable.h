#pragma once

class QJsonObject;

//! A base class for object that can be saved to/loaded from a json.
class Serializable {
public:
    //! Read the Serializable object from json.
    //! \param json json object.
    virtual void read(const QJsonObject& json) = 0;
    //! Write the Serializable object to json.
    //! \param json empty json object.
    virtual void write(QJsonObject& json) const = 0;

    virtual ~Serializable() = default;
};
