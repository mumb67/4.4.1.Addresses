// 4.4.1.Addresses.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
//#include <clocale>
#include <Windows.h>
#include <fstream>

class Addresses {
public:
    void get_addresses(std::string *addressesArray) {
        this->inputFile.open("in.txt");

        if (inputFile.is_open()) {

            outputFile.open("out.txt");
            std::string addressStr;

            inputFile >> addressesCount;
            outputFile << addressesCount << std::endl;

            for (int i = 0; i < addressesCount; i++) {
                for (int j = 0; j < 4; j++)
                {
                    inputFile >> addressStr;
                    if (j == 0) {
                        addressesArray[i] = addressStr;
                    }
                    else {
                        addressesArray[i] += ", ";
                        addressesArray[i] += addressStr;
                    }
                }
            }

            for (int i = addressesCount-1; i > -1; i--) {
                outputFile << addressesArray[i] << std::endl;
                
            }
            
            if (inputFile.eof())
            {
                inputFile.close();
                outputFile.close();
            }
        }
        else {
            std::cout << "Файл не открыт!" << std::endl;
        } 
    }
private:
    std::ifstream inputFile;
    std::ofstream outputFile;
    unsigned int addressesCount = 0;
};

std::string* addressesArray = new std::string[3];

int main()
{
    setlocale(LC_ALL, "Russian");

    Addresses A;
    A.get_addresses(addressesArray);
    delete[] addressesArray;
}