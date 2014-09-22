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
    void resizeWords(char **&chararr, int oldSize);
    void resizePages(int **& intarr, int &oldSize);
    void resizeCharsinWords(char ** &chararr, int &oldSize, int wordSizeCount);
    void resizeIntsinPages(int **& intarr, int &oldSize, int wordSizeCount);


private:
    ifstream fileReader;
    int**pages;
    char**words;

};

#endif // FILEREADER_H
