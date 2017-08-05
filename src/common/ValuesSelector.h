#pragma once

#include <initializer_list>
#include <QList>

//! A list of items with one of them "selected" and returned by get().
//! Can select next item, previous item or an item by value.
//! \tparam T type of items.
template<typename T>
class ValuesSelector {
private:
    //! A list of items.
    const QList<T> values;
    //! Index of the selected item.
    int index;

public:
    //! Constructs selector from brace-enclosed list of values and selects the first one.
    //! \param list brace-enclosed list of values.
    ValuesSelector(std::initializer_list<T> list): values(list), index(0) {}

    //! Returns count of items.
    int size() const {
        return values.size();
    }

    //! Returns selected item.
    const T& get() const {
        return values[index];
    }

    //! Selects item by value. Does nothing if there isn't an item with this value.
    //! \param value to select.
    void set(const T& value) {
        int idx = values.indexOf(value);
        if (idx != -1) {
            index = idx;
        }
    }

    //! Selects next item. Does nothing if the last item is already selected.
    void next() {
        if (index < size() - 1) {
            ++index;
        }
    }

    //! Selects previous item. Does nothing if the first item is already selected.
    void prev() {
        if (index > 0) {
            --index;
        }
    }
};
