#ifndef DATALIST_H_INCLUDED
#define DATALIST_H_INCLUDED

#include <stdio.h>

/// Оператор префиксной суммы для представленных ниже перечислений



namespace WAVETYPE
{
    /// Основные параметры осциллограммы (BASE):
    /// блок данных, считываемых из осциллограммы без обработки
    enum class BASE : size_t {

        //Служебный блок
        FIRST,

        //Данные
        VOLTAGE_STATOR = FIRST,         // 0  - напряжение статора
        CURRENT_STATOR,                 // 1  - полный ток статора
        COS_VALUE,                      // 2  - косинус фи
        VOLTAGE_EXCITATION,             // 3  - напряжение возбуждения
        CURRENT_EXCITATION,             // 4  - ток возбуждения
        VOLTAGE_SYNCHRONICAL,           // 5  - напряжение синхронизации
        MODE_STATUS,                    // 6  - режим
        CURRENT_SUPPLY_A,               // 7  - ток питания фазы А
        CURRENT_RESIST,                 // 8  - ток через пусковое сопротивление
        CORNER_THYRISTOR,               // 9  - угол тиристора

        //Служебный блок
        LAST
    };
    BASE& operator++(BASE& input);


    /// Шестая гармоника осциллограммы (HIGH):
    /// блок данных, считываемых из осциллограммы с шестикратной частотой
    enum class HIGH : size_t {

        //Служебный блок
        FIRST = static_cast<size_t>(BASE::LAST),

        //Данные
        VOLTAGE_EXCITATION = FIRST,     // 10 - напряжение возбуждения 300 Гц
        CURRENT_EXCITATION,             // 11 - ток возбуждения 300 Гц
        CURRENT_RESIST,                 // 12 - ток через R пуск 300 Гц

        //Служебный блок
        LAST
    };
    HIGH& operator++(HIGH& input);


    /// Вычисляемые данные (CALC):
    /// данные, которых нет в осциллограмме,
    /// но которые вычисляются из других значений
    enum class CALC : size_t {

        //Служебный блок
        FIRST = static_cast<size_t>(HIGH::LAST),

        //Данные
        CALC_CURRENT_STATOR_RE = FIRST, // 13 - активная составляющая тока статора
        CALC_CURRENT_STATOR_IM,         // 14 - реактивная составляющая тока статора
        CALC_POWER_STATOR_FULL,         // 15 - полная мощность статора
        CALC_POWER_STATOR_RE,           // 16 - активная мощность статора
        CALC_POWER_STATOR_IM,           // 17 - реактивная мощность статора

        //Служебный блок
        LAST
    };
    CALC& operator++(CALC& input);

    static const size_t FIRST = 0;
    static const size_t LAST  = static_cast<size_t>(CALC::LAST);


};
#endif // DATALIST_H_INCLUDED
