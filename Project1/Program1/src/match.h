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
    void getJetTeamInfo();
    void getBearTeamInfo();
    void printTest();
    void getMatchInfo();
    void setPlayerInfo();
    void teamTally();
    void OutputVLow();
    void run();
    void OutputVMed();
    void OutputVHigh();

private:
    ifstream fileReader;
    ofstream fileOutput;
    string TeamName1, TeamName2;
    int teamAmt1, teamAmt2;
    int tagAmt, points, jetTeamPoints, bearTeamPoints;
    int fileCodes;
    string playerName;
    Player* bearTeam;
    Player* jetTeam;
    int* tagged;
    int* taggers;
    int* placeTagged;
    int* timeTagged;
};

#endif // MATCH_H
