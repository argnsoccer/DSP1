#ifndef FILEREADER_H
#define FILEREADER_H
#include <iostream>
#include <fstream>

using namespace std;

class FileReader
{

public:
    FileReader();
    void run(char *input, char *output);

private:
    ifstream fileReader;
    int**pages;
    char**words;

};

#endif // FILEREADER_H
