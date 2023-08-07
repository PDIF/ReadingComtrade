#ifndef ORDERED_DATA_H
#define ORDERED_DATA_H


#include <vector>
#include <algorithm>
#include "DataList.h"


#include <iostream>

template <typename T>
class OrderedData
{
    using type_t     = std::vector<T>;
    using type_vec_t = std::vector<type_t>;

public:
    OrderedData()
    : data(std::move(defaultData()))
    {
        std::cout << "Here1\n";
    };


    OrderedData(type_vec_t&& input)
    : data(std::move(input))
    {
        std::cout << "Here2\n";
    };



    virtual ~OrderedData(){ };



    void addItem(const type_t& input, size_t index) {
        data[index] = input;
    }
    void addItem(type_t&& input, size_t index) {
        std::swap(data[index], input);
    }
    void addItem(type_vec_t&& input) {
        std::swap(data, input);
    }



    //
    std::vector<T>& operator[](size_t index) {
        return data[index];
    }

private:

    type_vec_t data;



    //Размер обычного вектора сигналов
    static constexpr size_t getDataSize() {
        return 2000;
    };

    //Размер вектора сигналов 6-й гармоники
    static constexpr size_t getHighSize() {
        return 6 * getDataSize();
    };



    //Дефолтное значение вектора
    type_vec_t defaultData() {

        using namespace WAVETYPE;

        type_vec_t output(static_cast<size_t>(CALC::LAST));

        for (BASE i = BASE::FIRST; i < BASE::LAST; ++i) {
            output[static_cast<size_t>(i)] = type_t(getDataSize(), 0);
        }

        for (HIGH i = HIGH::FIRST; i < HIGH::LAST; ++i) {
            output[static_cast<size_t>(i)] = type_t(getHighSize(), 0);
        }

        for (CALC i = CALC::FIRST; i < CALC::LAST; ++i) {
            output[static_cast<size_t>(i)] = type_t(getDataSize(), 0);
        }

        return output;

    };


};

#endif //ORDERED_DATA_H
