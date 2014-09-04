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

private:
    ifstream jetReader;
    ifstream bearReader;
    string TeamName1, TeamName2;
    int teamAmt1, teamAmt2;
    int fileCodes;
    string playerName;
    Player* bearTeam;
    Player* jetTeam;
};

#endif // MATCH_H
