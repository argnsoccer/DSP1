#include "sortingcompetition.h"
#include <string>

int main(int argc, char *argv[])
{

    SortingCompetition sort("inputWords.txt");
    sort.readData();
    sort.sortData();

    return 0;
}
