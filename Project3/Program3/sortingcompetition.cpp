#include "sortingcompetition.h"

//Chris Perez and Andre Gras
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
        while(!fileReader.eof())
        {
            string wordTemp;
            fileReader >> wordTemp;
            char*temp = new char [wordTemp.length()+2];
            char*length = new char[2];
//            itoa(wordTemp.length(),length,10);
            sprintf(length,"%d", wordTemp.length());
            if(length[1] == 0)//single digit check
            {
                int tmp = length[0];
                length[0] = 48;
                length[1] = tmp;
            }
            temp[0] = length[0];
            temp[1] = length[1];

            temp = StringCopy(temp, wordTemp);

            words.push_back(temp);
\
            //delete []temp;
            //delete []length;
        }


    }
    fileReader.close();
    return true;
}

void SortingCompetition::sortData()
{
    cout << words.size() << endl;
    QuickSort(0, (words.size())-1);
    //Bubble();

}

void SortingCompetition::outputData(const string &outputFileName)
{
    fileOut.open(outputFileName.c_str());
    char*strlen = new char[2];
    for(int i = 0; i < words.size()-1; ++i)
    {
        strlen[0] = words[i][0];
        strlen[1] = words[i][1];
        int len = atoi(strlen);
        for(int j = 0; j < len; ++j)
        {
            fileOut << words[i][j+2];
        }
        fileOut << endl;
    }
    delete [] strlen;
    fileOut.close();
}

char* SortingCompetition::StringCopy(char* temp, string& wordTemp)
{
    int len = wordTemp.length();
    for(int i = 0; i < len; ++i)
    {
        temp[i+2] = wordTemp[i];
    }
    return temp;
}

bool SortingCompetition::swap(int spot1, int spot2)
{
    char*temp = words[spot1];
    words[spot1] = words[spot2];
    words[spot2] = temp;
    return true;
}

int SortingCompetition::partition(int from, int to)
{
    char*pivot = words[from];
    int i = from - 1;
    int j = to + 1;
    while(i < j)
    {
        i++;
        while (strcmp(words[i], pivot) < 0) //works like a do while
        {
            i++;
        }
        j--;
        while (strcmp(words[j], pivot) > 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(i, j);
        }
    }
    return(j);
}

void SortingCompetition::QuickSort(int from, int to)
{
    if(from >= to) return;
    int p = partition(from, to);
    QuickSort(from, p);
    QuickSort(p + 1, to);
}

void SortingCompetition::Bubble()
{
    bool swapped = false;
    for (int x = words.size()-1; x > 0; x--)
    {
        swapped = false;
        for (int y = 0; y < x; y++)
        {
            if(strcmp(words[y],words[y+1]) > 0)
            {
                swapped = swap(y, y+1);
            }
        }
        if (!swapped) break;
    }
}
