//Chris Perez and Andre Gras
//38357479        42064208

#include "SortingCompetition.h"



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
            wordsCopy.push_back(wordTemp);//create a copy to store the unsorted vector
        }
    }
    fileReader.close();
    return true;
}

bool SortingCompetition::prepareData()
{
    words.clear();//clears out words and stores the unsorted back into the sorted
    for(int i = 0; i < wordsCopy.size(); ++i)
    {
        char*temp = new char [wordsCopy[i].length()+2];//length prefixed c-strings
        char*length = new char[2];
        sprintf(length,"%d", wordsCopy[i].length());
        if(length[1] == 0)//single digit check
        {
            int tmp = length[0];
            length[0] = 48;
            length[1] = tmp;
        }
        temp[0] = length[0];
        temp[1] = length[1];

        StringCopy(temp, wordsCopy[i]);

        words.push_back(temp);
    }
    return true;
}

void SortingCompetition::sortData()
{
    int size = words.size();
    cout << size << endl;
    QuickSort(0, size-1);
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

void SortingCompetition::StringCopy(char* temp, string& wordTemp)
{
    for(int i = 0; i < wordTemp.length(); ++i)
    {
        temp[i+2] = wordTemp[i];
    }
}

bool SortingCompetition::swap(int spot1, int spot2)//swaps to elements in vector
{
    char*temp = words[spot1];
    words[spot1] = words[spot2];
    words[spot2] = temp;
    return true;
}

int SortingCompetition::partition(int from, int to)
{

    char*first = words[rand()%(to-from+1)+from];//random variable as first pivot to increase chances of true median
    char* mid=words[(to-from)/2];
    char* last=words[to];
    int i = from-1;
    int j = to+1;
    if (((strcmp(mid,first) > 0) && (strcmp(mid,last) < 0)) || ((strcmp(mid,last) > 0) && (strcmp(mid,first) <  0)))//if mid is median
    {
        first = mid;
    }
    else if (((strcmp(last,first) > 0) && (strcmp(last,mid) < 0)) || ((strcmp(last,mid) > 0) && (strcmp(last,first) < 0)) )// if last was median
    {
        first = last;
    }
    //^^finds the threes median and uses it as the pivot
    while(i < j)
    {
        j--;
        while ((strcmp(words[j], first)) > 0)
        {
            j--;
        }
        i++;
        while ((strcmp(words[i], first)) < 0) //works like a do while
        {
            i++;
        }

        if (i < j)
        {
            swap(i, j);
        }
    }
    return (j);//returns the index of the 3's median

}

void SortingCompetition::QuickSort(int from, int to)
{
    if(from >= to) return;
    int p = partition(from, to);
    QuickSort(from, p);
    QuickSort(p+1, to);
}

void SortingCompetition::Bubble()// basic bubble sort, not used in final sorting, disregard
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


//g++ main.cpp SortingCompetition.cpp -std=c++11
