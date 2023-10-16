#pragma once
#include <string>

class IOFileHelper
{
public:
    IOFileHelper() {};

    void writeIntoFile(const std::string fileName, const std::wstring& content);
};