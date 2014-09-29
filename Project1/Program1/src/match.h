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

    void run(const char* &teamName1, const char* &teamName2, const char* &matchFile, const char* &outputFile, const string &verbosityType);
        void teamTally();
        void getJetTeamInfo(const char *&teamName1);
        void getBearTeamInfo(const char *&teamName2);
        void getMatchInfo(const char*& matchFile);
        void setPlayerInfo();
        void OutputVLow(const char* &outputFile);
        void OutputVMed(const char* &outputFile);
        void OutputVHigh(const char* &outputFile);

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
