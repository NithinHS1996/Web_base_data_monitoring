#pragma once
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class File
{
    std::ifstream file;

public:
    File(std::string str)
    {
        file.open(str);
    }
    ~File() {}

    string readEverything()
    {
        if (file)
        {
            std::string str;
            ostringstream ss;
            ss << file.rdbuf(); // reading data
            str = ss.str();
            cout << str;
            return str;
        }
    }
};

class Readimg
{
    std::ifstream file;

public:
    Readimg(std::string str)
    {
        file.open(str, std::ios::binary);
    }
    ~Readimg() {}

    string readEverything()
    {
        if (file)
        {
            std::string str;
            ostringstream ss;
            ss << file.rdbuf(); // reading data
            str = ss.str();
            file.seekg(0, ios::end);
            int file_size = file.tellg();
            cout << "Size of the file is"
                 << " " << file_size << " "
                 << "bytes" << str.size();
            //char *ptr = new char[file_size];
            //cout << str;
            return str;
        }
    }

    char *readImg()
    {
        char *buffer = new char[100000];
        *buffer = {0};
        file.read(buffer, sizeof(char) * 100000);
        int size = (int)file.gcount();
        cout << "size read is: " << size << "\n";
        return buffer;
    }
};