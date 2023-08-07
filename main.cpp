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


    short x = 0; //X ����� ��������� �� �����
    short y = 0;
    short z = 0;


    for(int i = 0; i < 112000 / RECORD_SIZE; ++i) {

		//int i = j/56;

        readFile.seekg((8 + i * RECORD_SIZE));

        size_t number = 4;
        readFile.seekg((8 + i * RECORD_SIZE + number * 2));
        //�������� ��������
        //0. U�� - ���������� �������
        //1. I�� ���� - ������ ��� �������
        //2. cos f - ������� ��
        //3. U �����������
        //4. I����- ��� ����������� .
        //5. U����� - ���������� �������������
        //6. �����
        //7. I ������� �. �
        //8. I ����� R ���� - ��� ����� �������� ��������������
        //9. ���� ���������
        //10. U�����������300
        //11. I�����������300
        //12. I ����� R ���� 300


        for (size_t j = number; j < number + 1 ; ++j) {

            //������ ���� ������ ������� �� ���� ����
            //1. ������ ������� �����
            short symbol = 0;
            readFile.read(reinterpret_cast<char*>(&symbol), 1);

            //2. ���������� ������� ����� � ��������� ����������
            short processed = symbol << 8;

            //3. ������ ������� ����� � ����������� ����� ����
            readFile.read((char*)&symbol, 1);
            processed = processed | symbol;

            outfile << processed << ";";

        }

        outfile << '\n';

        /*
		readFile.read((char*)&x,1); //������ ������ ���������� � ���������� � � X
        readFile.read((char*)&y,1); //������ ������ ���������� � ���������� � � X
        z = (x << 8) | y;

        //std::cout << z << " ";
        outfile << z << '\n';
        */
	}
    outfile.close();

    /*
    for (size_t i = 0; i < 10; ++i) {
        readFile.read((char*)&x,1); //������ ������ ���������� � ���������� � � X
        readFile.read((char*)&y,1); //������ ������ ���������� � ���������� � � X
        z = (x << 8) | y;
    }
*/

/*
    for (size_t i = 0; i < 10; ++i) {
        readFile.read((char*)&x,1); //������ ������ ���������� � ���������� � � X
        readFile.read((char*)&y,1); //������ ������ ���������� � ���������� � � X
        z = (x << 8) | y;
    }

    for (size_t i = 0; i < 18; ++i) {

        readFile.read((char*)&x,1); //������ ������ ���������� � ���������� � � X
        readFile.read((char*)&y,1); //������ ������ ���������� � ���������� � � X
        z = (x << 8) | y;
    }


*/
//    readFile.read((char*)&x,sizeof x); //������ ������ ���������� � ���������� � � X



    readFile.close();
    return 0;
}
