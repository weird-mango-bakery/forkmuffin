#pragma once

#include <initializer_list>
#include <QList>

template<typename T>
class ValuesSelector {
private:
    const QList<T> values;
    int index;

public:
    ValuesSelector(std::initializer_list<T> list): values(list), index(0) {}

    int size() const {
        return values.size();
    }

    T get() const {
        return values[index];
    }

    void set(const T& value) {
        int idx = values.indexOf(value);
        if (idx != -1) {
            index = idx;
        }
    }

    void next() {
        if (index < size() - 1) {
            ++index;
        }
    }

    void prev() {
        if (index > 0) {
            --index;
        }
    }
};
