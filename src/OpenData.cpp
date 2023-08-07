#include "OpenData.h"

using type_t        = int;
using type_vec_t    = std::vector<type_t>;
using type_matrix_t = std::vector<type_vec_t>;

OpenData::OpenData(const std::string& openFile)
: data(std::move(openData(openFile)))
{
    //ctor
};


OpenData::~OpenData()
{
    //dtor
}


type_matrix_t& OpenData::getData() {

    return data;
};


type_matrix_t OpenData::openData(const std::string& openFile) {

    std::ifstream readFile(openFile, std::ios::binary | std::ios::in);

    //Размер базовой части осциллограммы
    size_t startBase = static_cast<size_t>(WAVETYPE::BASE::FIRST);
    size_t lastBase  = static_cast<size_t>(WAVETYPE::BASE::LAST);

    //Чтение высокочастотной частоты в пределах одной записи
    size_t startHigh = static_cast<size_t>(WAVETYPE::HIGH::FIRST);
    size_t lastHigh  = static_cast<size_t>(WAVETYPE::HIGH::LAST);


    type_matrix_t result;

    result.resize(getRecordsNumber());



    for (size_t i = 0; i < )






    for (size_t i = 0; i < getRecordsNumber(); ++i) {

        //Установка начальной позиции для считывания новой записи
        readFile.seekg(getSkipSize() + i * getRecordsSize());


        size_t startBase = static_cast<size_t>(WAVETYPE::BASE::FIRST);
        size_t lastBase  = static_cast<size_t>(WAVETYPE::BASE::LAST);

        size_t startHigh = static_cast<size_t>(WAVETYPE::HIGH::FIRST);
        size_t lastHigh  = static_cast<size_t>(WAVETYPE::HIGH::LAST);
        //for (size_t j = startBase; j < lastBase; ++j) {

        using namespace WAVETYPE;

        //Чтение данных нормальной частоты в пределах одной записи
        for (auto j = BASE::FIRST; j < BASE::LAST; ++j) {
            //1. Чтение первого байта
            short symbol = 0;
            readFile.read(reinterpret_cast<char*>(&symbol), 1);

            //2. Сохранение первого байта в отдельной переменной
            short processed = symbol << 8;

            //3. Чтение второго байта и объединение обоих байт
            readFile.read((char*)&symbol, 1);
            processed = processed | symbol;

            //4. Запись полученного значения в итоговый массив
            size_t channel = static_cast<size_t>(i);
            type_t value   = static_cast<type_t>(processed);
            result[channel].push_back(value);
        }

        //Чтение данных высокой частоты в пределах одной записи
        for (size_t k = 0; k < getHarmonicalNumber(); ++k) {

            for (auto j = HIGH::FIRST; j < HIGH::LAST; ++j) {

                //1. Чтение первого байта
                short symbol = 0;
                readFile.read(reinterpret_cast<char*>(&symbol), 1);

                //2. Сохранение первого байта в отдельной переменной
                short processed = symbol << 8;

                //3. Чтение второго байта и объединение обоих байт
                readFile.read((char*)&symbol, 1);
                processed = processed | symbol;


                result[j].push_back(static_cast<type_t>(processed));
            }
        }
    }

    readFile.close();

    return result;

}
