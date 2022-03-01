#include <iostream>
#include "DynamicQueue.h"
#include <string>
#include <fstream>

int main() {

    DynamicQueue queueArray[N];

    // if stream used to read info from data.txt file
    std::ifstream myFile;
    myFile.open(R"(C:\Users\diego\OneDrive - Florida Gulf Coast University\CLion\Hw1\data.txt)");

    if (!myFile){
        // Print an error and exit
        std::cerr << "data.txt could not be opened.\n";
        exit(1);
    }

    char key, index;
    // loop to read all lines from the file until the end of file
    while (myFile) {
        std::string line;
        std::getline(myFile, line);

        if(!line.empty()){
            key = line[0];
            index = line[2];
            std::cout << key << " " << index << std::endl;

            queueArray[std::stoi(&index)].queueCheck(key);

        }

    }

    myFile.close();

    std::cout << "Queue 1: ";
    queueArray[0].print();
    std::cout << "Queue 2: ";
    queueArray[1].print();
    std::cout << "Queue 3: ";
    queueArray[2].print();
    std::cout << "Queue 4: ";
    queueArray[3].print();

    return 0;
}







