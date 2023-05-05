#include "DataManager.h"
#include <fstream>
#include <iostream>

const std::string CDataManager::ReadFile(const char* a_sFilePath)
{
    auto sContent = static_cast<std::string>("");

    auto stream = std::fstream{};
    stream.open(a_sFilePath, std::ios::in);

    if (!stream.is_open())
    {
        std::cout << "Err: Could not read file" << a_sFilePath << "File does not exist" << std::endl;

        return std::string();
    }

    auto sLine = static_cast<std::string>("");

    while (!stream.eof())
    {
        std::getline(stream, sLine);
        sContent.append(sLine + "\n");
    }

    stream.close();



    if (stream.is_open())
    {
        std::cout << "Err: Filestream is still open!" << std::endl;

        return std::string();
    }

    return sContent;
}
