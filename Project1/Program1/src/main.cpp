#include <QCoreApplication>
#include "match.h"

int main(int argc, char *argv[])
{
    Match m;
    char* teamName1 = argv[1];
    char* teamName2 = argv[2];
    char* matchFile = argv[3];
    char* outputFile = argv[4];
    string verbosityType = argv[5];
    m.run(teamName1, teamName2, matchFile, outputFile, verbosityType);
    return 0;
}
