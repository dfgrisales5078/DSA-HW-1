// COP 3530 - Homework 1
// 02/27/2022
// Diego Grisales
// Ragy Costa De Jesus

#include <iostream>
#include "DynamicQueue.h"
#include <string>
#include <fstream>

int main() {

    DynamicQueue queueArray[N];

    // if stream used to read info from data.txt file
    std::ifstream myFile;
    myFile.open("data.txt");

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

            std::cout << "Read key " << key << " for queue " << index << ". ";
            queueArray[std::stoi(&index)].queueCheck(key);
            std::cout << "Q" << index << ": ";
            queueArray[std::stoi(&index)].print();
        }

    }

    myFile.close();


    std::cout << "\n..Final Queues.." << std::endl;
    std::cout << "Q0: ";
    queueArray[0].print();
    std::cout << "Q1: ";
    queueArray[1].print();
    std::cout << "Q2: ";
    queueArray[2].print();
    std::cout << "Q3: ";
    queueArray[3].print();


    return 0;
}







