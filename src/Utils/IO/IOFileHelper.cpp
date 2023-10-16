#include "IOFileHelper.h"
#include <iostream>
#include <fstream>
#include <sstream>

void IOFileHelper::writeIntoFile(const std::string fileName, const std::wstring& content)
{
    std::string prefix;
    std::wofstream outputFile(fileName);
    if (outputFile.is_open()) 
    {
        outputFile << content;
        outputFile.close();
    }
    else 
    {
        std::cerr << "Failed to open the output file for writing." << std::endl;
    }
}
