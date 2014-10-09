#include "sortingcompetition.h"
#include <string>
#include <chrono>
#include <ctime>

//Chris Perez and Andre Gras
int main(int argc, char *argv[])
{

    SortingCompetition sort("inputWords.txt");
    std::chrono::time_point<std::chrono::system_clock> start, end;
    sort.readData();
    start = std::chrono::system_clock::now();
    sort.sortData();
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished computation at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";
    sort.outputData("outputWords.txt");


    return 0;
}
