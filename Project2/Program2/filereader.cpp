#include "filereader.h"

FileReader::FileReader()
{

}

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
    if(fileReader.is_open())
    {
        while(fileReader.eof() == false)
        {
        int tempPage = 0;

            char temp = fileReader.get();//gets the first char of the file
            if(temp == 60)//if the char is a < then
            {
                char checkPage = fileReader.peek(); //checks if the next char is a hyphen without moving the iterator
                if(checkPage == 45)
                {
                    cout << "no more pages to read" << endl;
                }
                else
                {
                    fileReader >> pages[wordSizeCount][pageSizeCount];//puts the page number into the array
                    tempPage = pages[wordSizeCount][pageSizeCount];//stores the page number for allocation into the parallel array
                }
            }
            temp = fileReader.get();// gets the >
            temp = fileReader.get();//gets the \n to move the cursor to the first char
            for(int i = 0; i <= pageSizeCount; ++i)
            {
                cout << pages[wordSizeCount][i] << endl;
            }
            char checkWord = fileReader.peek(); //checks the next character to make sure it is not a white space
            cout << "checkword is " << checkWord << endl;
            int superCount = 0;
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
                        words[wordSizeCount][bufferSize] = fileReader.get();//puts each char into words
                        cout << words[wordSizeCount][bufferSize];
                        bufferSize++;//increments to put the next char in the corresponding place
                        cout << "count: " << count << endl;
                        if(count == 9)//check if the array is at 9 spots to resize it
                        {
                            cout << "in if" << endl;
                            resizeCharsinWords(words, bufferSize, wordSizeCount);
                        }
                        count++;

                        checkWord = fileReader.peek();//checks the next char to see if the while should break
                    }
                }
                else
                {
                    int count = 0;
                    while(checkWord != ' ')
                    {
                        cout << " in checkword space" << endl;
                        cout << "wordSizeCount in while: " << wordSizeCount << endl;
                        words[wordSizeCount][bufferSize] = fileReader.get();
                        cout << words[wordSizeCount][bufferSize] << endl;
                        bufferSize++;
                        cout << "count: " << count << endl;
                        if(count == 9)
                        {
                            cout << "in if" << endl;
                            resizeCharsinWords(words, bufferSize, wordSizeCount);
                        }
                        count++;

                        checkWord = fileReader.peek();
                        if(checkWord == '\n')//this break is put in because before, it would check the \n then the next iteration would read in the \n into temp and this broke the automatic reading in
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

                wordSizeCount++;
                superCount++;
                if(superCount == 8)
                {
                    resizeWords(words, wordSizeCount);
                    resizePages(pages, wordSizeCount);
                }

                temp = fileReader.get();
                cout << "temp is: " << temp << endl;

                checkWord = fileReader.peek();
                cout << "checkWord out of if else is: " << checkWord << endl;
            }
            cout << " out of while" << endl;


            for(int j = 0; j < wordSizeCount; ++j)
            {
                pages[j][pageSizeCount] = tempPage;
            }

            cout << endl;

        }
    }
}

void FileReader::resizeWords(char **&chararr, int oldSize)
{
    char ** temp = new char*[oldSize+10];
    for(int i = 0; i < oldSize; ++i)
    {
        temp[i] = chararr[i];
    }
    delete [] chararr;
    chararr = temp;
}

void FileReader::resizePages(int **&intarr, int &oldSize)
{
    int ** temp = new int*[oldSize+10];
    for(int i = 0; i < oldSize; ++i)
    {
        temp[i] = intarr[i];
    }
    delete [] intarr;
    intarr = temp;
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

void FileReader::resizeCharsinWords(char **&chararr, int &oldSize, int wordSizeCount)
{
    char * temp = new char[oldSize+10];
    cout << "wordSizeCount in resize: " << wordSizeCount << endl;
    for(int i = 0; i < oldSize; ++i)
    {
        temp[i] = chararr[wordSizeCount][i];
        cout << "temp[i]: " << temp[i];

    }
    chararr[wordSizeCount] = temp;
}

//FileReader::~FileReader()
//{
//    delete []words;
//    delete []pages;
//}

