#include <iostream>
#include <fstream>
#include <cstddef>
//using namespace std;

#include "DataList.h"
#include "OrderedData.h"
#include "OpenData.h"

const size_t RECORD_SIZE = 56;

int main()
{
    //cout << "Hello world!" << endl;


    OrderedData<int> orderedData;//{};

    orderedData[0][0] = 3;

    std::cout << orderedData[0][0] << "\n";

    std::vector<int> && a = {10, 15, 11};

    orderedData.addItem(std::move(a), 0);

    std::cout << orderedData[0][0] << "\t" << a.size() << "\n";

    OpenData qqq("START.BSO");

    OrderedData<int> aaa(std::move(qqq.getData()));



    std::cout << "TEST\n" << aaa[0][0] << "\t" << aaa[0][500] << "\n";



    std::ifstream readFile("START.BSO", std::ios::binary | std::ios::in);

    std::ofstream outfile("result.csv");

    //readFile.seekg(4);


    short x = 0; //X будем считывать из файла
    short y = 0;
    short z = 0;


    for(int i = 0; i < 112000 / RECORD_SIZE; ++i) {

		//int i = j/56;

        readFile.seekg((8 + i * RECORD_SIZE));

        size_t number = 4;
        readFile.seekg((8 + i * RECORD_SIZE + number * 2));
        //Перечень сигналов
        //0. Uст - напряжение статора
        //1. Iст полн - полный ток статора
        //2. cos f - косинус фи
        //3. U возбуждения
        //4. Iвозб- ток возбуждения .
        //5. Uсинхр - напряжение синхронизации
        //6. Режим
        //7. I питания ф. А
        //8. I через R пуск - ток через пусковое сопростивление
        //9. Угол тиристора
        //10. Uвозбуждения300
        //11. Iвозбуждения300
        //12. I через R пуск 300


        for (size_t j = number; j < number + 1 ; ++j) {

            //Каждый блок данных состоит из двух байт
            //1. Чтение первого байта
            short symbol = 0;
            readFile.read(reinterpret_cast<char*>(&symbol), 1);

            //2. Сохранение первого байта в отдельной переменной
            short processed = symbol << 8;

            //3. Чтение второго байта и объединение обоих байт
            readFile.read((char*)&symbol, 1);
            processed = processed | symbol;

            outfile << processed << ";";

        }

        outfile << '\n';

        /*
		readFile.read((char*)&x,1); //Читаем оттуда информацию и запоминаем её в X
        readFile.read((char*)&y,1); //Читаем оттуда информацию и запоминаем её в X
        z = (x << 8) | y;

        //std::cout << z << " ";
        outfile << z << '\n';
        */
	}
    outfile.close();

    /*
    for (size_t i = 0; i < 10; ++i) {
        readFile.read((char*)&x,1); //Читаем оттуда информацию и запоминаем её в X
        readFile.read((char*)&y,1); //Читаем оттуда информацию и запоминаем её в X
        z = (x << 8) | y;
    }
*/

/*
    for (size_t i = 0; i < 10; ++i) {
        readFile.read((char*)&x,1); //Читаем оттуда информацию и запоминаем её в X
        readFile.read((char*)&y,1); //Читаем оттуда информацию и запоминаем её в X
        z = (x << 8) | y;
    }

    for (size_t i = 0; i < 18; ++i) {

        readFile.read((char*)&x,1); //Читаем оттуда информацию и запоминаем её в X
        readFile.read((char*)&y,1); //Читаем оттуда информацию и запоминаем её в X
        z = (x << 8) | y;
    }


*/
//    readFile.read((char*)&x,sizeof x); //Читаем оттуда информацию и запоминаем её в X



    readFile.close();
    return 0;
}
