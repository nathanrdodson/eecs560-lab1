#include <iostream>
#include <fstream>
#include "Executive.h"

int main(int argc, char *argv[])
{
    std::ifstream inputFile;

    if(argc != 2)
    {
        std::cout << "Invalid number of arguments.\nUsage: ./Lab1 <input filename>\n";
    } else {
        inputFile.open(argv[1]);
        if(inputFile.is_open())
        {
            Executive executive(argv[1]);
            executive.run();
        } else {
            std::cout << "Invalid filename. Check spelling...\nUsage: ./Lab1 <input filename>\n";
        }
    }
    return 0;
}
