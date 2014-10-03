#include "sortingcompetition.h"


SortingCompetition::SortingCompetition()
{

}

SortingCompetition::SortingCompetition(const string &inputFileName)
{
    setFileName(inputFileName);
}

void SortingCompetition::setFileName(const string &inputFileName)
{
    fileReader.open(inputFileName.c_str());
}

bool SortingCompetition::readData()
{
    if(fileReader.is_open())
    {
        while(fileReader.eof() == false)
        {
            string wordsTemp;
            fileReader >> wordsTemp;
            char*word = new char[wordsTemp.length()];
            strcpy(word, wordsTemp.c_str());

            words.push_back(word);
        }
    }
    fileReader.close();
    return true;
}

void SortingCompetition::sortData()
{

}
