#ifndef FILEREADER_H
#define FILEREADER_H
#include <iostream>
#include <fstream>

using namespace std;

class FileReader
{

public:
    FileReader();
    void input(char *input, char *output);
    void resizeWords(int oldSize);
    void resizePages(int &oldSize);
    void resizeCharsinWords(int &oldSize, int wordSizeCount);
    void resizeIntsinPages(int **& intarr, int &oldSize, int wordSizeCount);


private:
    ifstream fileReader;
    int**pages;
    char**words;

};

#endif // FILEREADER_H
