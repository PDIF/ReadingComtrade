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


void OpenData::readRecord(std::ifstream& readFile,
                          type_matrix_t& result  ,
                          size_t    firstIndex   ,
                          size_t    lastIndex    ,
                          size_t    harmonic     ) {

    for (size_t trying = 0; trying < harmonic; ++trying) {

        for (size_t index = firstIndex; index < lastIndex; ++index) {

            //1. ������ ������� �����
            short symbol = 0;
            readFile.read(reinterpret_cast<char*>(&symbol), 1);

            //2. ���������� ������� ����� � ��������� ����������
            short processed = symbol << 8;

            //3. ������ ������� ����� � ����������� ���� ����
            readFile.read((char*)&symbol, 1);
            processed = processed | symbol;

            //4. ������ ����������� �������� � �������� ������
            type_t value   = static_cast<type_t>(processed);
            result[index].push_back(value);

        }
    }
};






type_matrix_t OpenData::openData(const std::string& openFile) {

    using namespace WAVETYPE;

    //���������� �������
    type_matrix_t result(static_cast<size_t>(LAST));

    for (auto i = BASE::FIRST; i < BASE::LAST; ++i) {
        result[static_cast<size_t>(i)].reserve(getRecordsNumber());
    }

    for (auto i = HIGH::FIRST; i < HIGH::LAST; ++i) {
        result[static_cast<size_t>(i)].reserve(getHarmonicalNumber());
    }

    for (auto i = CALC::FIRST; i < CALC::LAST; ++i) {
        result[static_cast<size_t>(i)].reserve(getRecordsNumber());
    }


    //�������� �����
    std::ifstream readFile(openFile, std::ios::binary | std::ios::in);

    //���������� �������
    for (size_t i = 0; i < getRecordsNumber(); ++i) {

        //��������� ��������� ������� ��� ���������� ����� ������
        readFile.seekg(getSkipSize() + i * getRecordsSize());

        //������ ���������� ������� ������� ������
        readRecord(readFile, result,
                   static_cast<size_t>(BASE::FIRST),
                   static_cast<size_t>(BASE::LAST) ,
                   1);

        //������ ������ ��������� ������� ������
        readRecord(readFile, result,
                   static_cast<size_t>(HIGH::FIRST),
                   static_cast<size_t>(HIGH::LAST),
                   6);
    }

    readFile.close();

    return result;

};
