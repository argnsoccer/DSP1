#include "filereader.h"

FileReader::FileReader()
{

}


//FileReader::~FileReader() wouldn't work for some reason. Tried and tried
//{
//    delete []words;
//    delete []pages;
//}

void FileReader::input(char*input, char*output)
{

    fileReader.open(input);
    pages = new int*[10];
    words = new char*[10];
    for(int y = 0; y < 10; y++)
    {
        pages[y] = new int[10];
        words[y] = new char[10];
    }
    int pageSizeCount=0;
    int wordSizeCount=0;
    int bufferSize = 0;
    int superCount = 0;
    if(fileReader.is_open())
    {

        while(fileReader.eof() == false)
        {

        int tempPage = 0;

            char temp = fileReader.get();//gets the first char of the file
            if(temp == 60)//if the char is a < then
            {
                char checkPage = fileReader.peek(); //checks if the next char is a hyphen
                if(checkPage == 45)
                {
                    cout << "no more pages to read" << endl;
                }
                else
                {
                    fileReader >> pages[wordSizeCount][pageSizeCount];//puts the page number into the array
                    tempPage = pages[wordSizeCount][pageSizeCount];//stores the page number into the parallel array
                }
            }
            temp = fileReader.get();// gets the >
            temp = fileReader.get();//gets the \n
            for(int i = 0; i <= pageSizeCount; ++i)
            {
                cout << pages[wordSizeCount][i] << endl;
            }
            char checkWord = fileReader.peek(); //checks white space
            cout << "checkword is " << checkWord << endl;

            while(checkWord != '<')
            {
                bufferSize = 0;
                cout << "in while" << endl;
                if(checkWord == '[')
                {
                    int count = 0;
                    cout << "in checkword [" << endl;
                    temp = fileReader.get();//gets the opening bracket
                    while(checkWord != ']')
                    {
                        cout << " in checkword ]" << endl;
                        checkWord = fileReader.peek();
                        if(checkWord != ']')
                        {
                            words[wordSizeCount][bufferSize] = fileReader.get();//puts each char into words
                            cout << words[wordSizeCount][bufferSize];
                            bufferSize++;//increments to place next char
                            cout << "count: " << count << endl;
                            if(count == 10)//checks resize it
                            {
                                cout << "in if" << endl;
                                resizeCharsinWords(bufferSize, wordSizeCount);
                            }
                            count++;
                        }

                        checkWord = fileReader.peek();//break check
                    }
                }
                else
                {
                    int count = 0;
                    while(checkWord != ' ')
                    {
                        cout << " in checkword space" << endl;
                        cout << "wordSizeCount in while: " << wordSizeCount << endl;
                        words[wordSizeCount][bufferSize] = fileReader.get();//breaks here on the 11th word, meaning the resize is not working correctly
                        cout << words[wordSizeCount][bufferSize] << endl;//I am stuck here because I cannot figure out how to fix the resize so I can proceed to sort and output
                        bufferSize++;
                        cout << "count: " << count << endl;
                        if(count == 10)
                        {
                            cout << "in if" << endl;
                            resizeCharsinWords(bufferSize, wordSizeCount);
                        }
                        count++;

                        checkWord = fileReader.peek();
                        if(checkWord == '\n')//break case to reset new page
                        {
                            break;
                        }
                        cout << "checkword in space is: " << checkWord << endl;
                    }
                }
                cout << "wordSizeCount: " << wordSizeCount << endl;
                for(int b = 0; b < wordSizeCount; ++b)
                {
                    for(int a = 0; a < 20; ++a)
                    {
                        cout << words[b][a];
                    }
                }

                wordSizeCount++;//a word has just been added so go to the next place in the words array
                superCount++;//increments capacity
                cout << "superCount is: " << superCount << endl;
                if(superCount == 10)
                {
                    resizeWords(wordSizeCount);
                    resizePages(wordSizeCount);
                    superCount = 0;//resets (tracking capacity)
                }

                temp = fileReader.get();
                cout << "temp is: " << temp << endl;

                checkWord = fileReader.peek();
                cout << "checkWord out of if else is: " << checkWord << endl;
            }
            cout << " out of while" << endl;


            for(int j = 0; j < wordSizeCount; ++j)
            {
                pages[j][pageSizeCount] = tempPage; // updates pages for words
            }
            cout << endl;
        }
    }
}

void FileReader::resizeWords(int oldSize)//no clue why this is not working have stared at it for 3 hours (and counting)
{
    char ** temp = new char*[oldSize+10];
    for(int i = 0; i < oldSize; ++i)
    {
        temp[i] = words[i];
        cout << "in resize for " << endl;
        //delete [] chararr[i];
    }
    delete [] words;
    words = temp;
}

void FileReader::resizePages(int &oldSize)
{
    int ** temp = new int*[oldSize+10];
    for(int i = 0; i < oldSize; ++i)
    {
        temp[i] = pages[i];
        //delete [] intarr[i];
    }
    //delete [] intarr;
    pages = temp;
}

void FileReader::resizeIntsinPages(int **&intarr, int &oldSize, int wordSizeCount)
{
    int * temp = new int[oldSize+10];
    for(int i = 0; i < oldSize; ++i)
    {
        temp[i] = intarr[wordSizeCount][i];
    }
    delete [] intarr;
    intarr[wordSizeCount] = temp;
}

void FileReader::resizeCharsinWords(int &oldSize, int wordSizeCount)
{
    char * temp = new char[oldSize+10];
    cout << "wordSizeCount in resize: " << wordSizeCount << endl;
    for(int i = 0; i < oldSize; ++i)
    {
        temp[i] = words[wordSizeCount][i];
        cout << "temp[i]: " << temp[i];

    }
    words[wordSizeCount] = temp;
}


