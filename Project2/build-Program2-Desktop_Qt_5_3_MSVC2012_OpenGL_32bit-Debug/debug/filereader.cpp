#include "filereader.h"

FileReader::FileReader()
{

}

void FileReader::run(char*input, char*output)
{
    fileReader.open(input);
    if(fileReader.is_open())
    {
        cout << "kill me" << endl;
    }
}
