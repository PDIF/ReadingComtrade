#ifndef DATALIST_H_INCLUDED
#define DATALIST_H_INCLUDED

#include <stdio.h>

/// �������� ���������� ����� ��� �������������� ���� ������������



namespace WAVETYPE
{
    /// �������� ��������� ������������� (BASE):
    /// ���� ������, ����������� �� ������������� ��� ���������
    enum class BASE : size_t {

        //��������� ����
        FIRST,

        //������
        VOLTAGE_STATOR = FIRST,         // 0  - ���������� �������
        CURRENT_STATOR,                 // 1  - ������ ��� �������
        COS_VALUE,                      // 2  - ������� ��
        VOLTAGE_EXCITATION,             // 3  - ���������� �����������
        CURRENT_EXCITATION,             // 4  - ��� �����������
        VOLTAGE_SYNCHRONICAL,           // 5  - ���������� �������������
        MODE_STATUS,                    // 6  - �����
        CURRENT_SUPPLY_A,               // 7  - ��� ������� ���� �
        CURRENT_RESIST,                 // 8  - ��� ����� �������� �������������
        CORNER_THYRISTOR,               // 9  - ���� ���������

        //��������� ����
        LAST
    };
    BASE& operator++(BASE& input);


    /// ������ ��������� ������������� (HIGH):
    /// ���� ������, ����������� �� ������������� � ������������ ��������
    enum class HIGH : size_t {

        //��������� ����
        FIRST = static_cast<size_t>(BASE::LAST),

        //������
        VOLTAGE_EXCITATION = FIRST,     // 10 - ���������� ����������� 300 ��
        CURRENT_EXCITATION,             // 11 - ��� ����������� 300 ��
        CURRENT_RESIST,                 // 12 - ��� ����� R ���� 300 ��

        //��������� ����
        LAST
    };
    HIGH& operator++(HIGH& input);


    /// ����������� ������ (CALC):
    /// ������, ������� ��� � �������������,
    /// �� ������� ����������� �� ������ ��������
    enum class CALC : size_t {

        //��������� ����
        FIRST = static_cast<size_t>(HIGH::LAST),

        //������
        CALC_CURRENT_STATOR_RE = FIRST, // 13 - �������� ������������ ���� �������
        CALC_CURRENT_STATOR_IM,         // 14 - ���������� ������������ ���� �������
        CALC_POWER_STATOR_FULL,         // 15 - ������ �������� �������
        CALC_POWER_STATOR_RE,           // 16 - �������� �������� �������
        CALC_POWER_STATOR_IM,           // 17 - ���������� �������� �������

        //��������� ����
        LAST
    };
    CALC& operator++(CALC& input);

    static const size_t FIRST = 0;
    static const size_t LAST  = static_cast<size_t>(CALC::LAST);


};
#endif // DATALIST_H_INCLUDED
