#ifndef OPENDATA_H
#define OPENDATA_H

#include <string>
#include <fstream>
#include <vector>

#include "DataList.h"

class OpenData
{

    using type_t        = int;
    using type_vec_t    = std::vector<int>;
    using type_matrix_t = std::vector<type_vec_t>;

public:

    OpenData(const std::string& openFile);

    virtual ~OpenData();

    type_matrix_t& getData();

    type_matrix_t openData(const std::string& openFile);


private:

    type_matrix_t data;


    ///������, ������������� � ������ ����� ������ � ������� ��������
    void readRecord(std::ifstream&, type_matrix_t&, size_t, size_t, size_t);


    ///���������� ������� � ����� �������������
    size_t getRecordsNumber() {
        return 2000;
    };

    ///������ ����� ������ � �������������
    size_t getRecordsSize() {
        return 56;
    };

    ///���������� ����������� ���� � ������ ������
    size_t getSkipSize() {
        return 8;
    };

    ///����� ��������������� ���������
    size_t getHarmonicalNumber() {
        return 6;
    };


};

#endif // OPENDATA_H
