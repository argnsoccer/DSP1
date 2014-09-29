#include <QCoreApplication>
#include "match.h"

int main(int argc, char *argv[])
{
    Match m;
    const char* teamName1 = argv[1];
    const char* teamName2 = argv[2];
    const char* matchFile = argv[3];
    const char* outputFile = argv[4];
    const string verbosityType = argv[5];
    m.run(teamName1, teamName2, matchFile, outputFile, verbosityType);
    return 0;
}
