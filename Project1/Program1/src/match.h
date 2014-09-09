#ifndef MATCH_H
#define MATCH_H
#include <fstream>
#include <iostream>
#include <string>
#include "player.h"
using namespace std;

class Match
{
public:
    Match();

    void run(char *teamName1, char *teamName2, char *matchFile, char *outputFile, string verbosityType);
    void teamTally();
    void getJetTeamInfo(char* teamName1);
    void getBearTeamInfo(char* teamName2);
    void getMatchInfo(char* matchFile);
    void setPlayerInfo();
    void OutputVLow(char* outputFile);
    void OutputVMed(char* outputFile);
    void OutputVHigh(char* outputFile);

private:
    ifstream fileReader;
    ofstream fileOutput;
    string TeamName1, TeamName2;
    int teamAmt1, teamAmt2;
    int tagAmt, points;
    int fileCodes;
    int jetTeamPoints;
    int bearTeamPoints;
    string playerName;
    Player* bearTeam;
    Player* jetTeam;
    int* tagged;
    int* taggers;
    int* placeTagged;
    int* timeTagged;
};

#endif // MATCH_H
