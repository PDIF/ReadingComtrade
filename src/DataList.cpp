#include "DataList.h"

namespace WAVETYPE
{

    //Перегрузка операторов
    BASE& operator++(BASE& input) {
        input = static_cast<BASE>(static_cast<size_t>(input) + 1);
        return input;
    };

    HIGH& operator++(HIGH& input) {
        input = static_cast<HIGH>(static_cast<size_t>(input) + 1);
        return input;
    }

    CALC& operator++(CALC& input) {
        input = static_cast<CALC>(static_cast<size_t>(input) + 1);
        return input;
    }
}
