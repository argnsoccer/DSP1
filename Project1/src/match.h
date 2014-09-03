#ifndef MATCH_H
#define MATCH_H
#include <fstream>
#include <iostream>
#include <string>
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
};

#endif // MATCH_H
