#include "match.h"
#include "player.h"

Match::Match()
{

}

void Match::getJetTeamInfo()
{
   jetReader.open("c:/Users/argns_000/DataStructuresRepo/Project1/Program1/doc/Jets.txt");
   if(jetReader.is_open())
   {
       getline (jetReader, TeamName1);//gets the first line of the file and sets the line as a null terminated c-string
       jetReader >> teamAmt1;


       jetReader.close();
   }
   bearReader.open("C:/Users/argns_000/DataStructuresRepo/Project1/Program1/doc/Sunbears.txt");
   if(bearReader.is_open())
   {
       getline(bearReader, TeamName2);
       bearReader >> teamAmt2;
       bearTeam = new Player[teamAmt2];
       for(int i = 0; i < teamAmt2; ++i)
       {
            bearReader >> fileCodes;
            bearTeam[i].setCode(fileCodes);
            getline(bearReader, playerName);
            bearTeam[i].setName(playerName);

       }
       bearReader.close();
   }
   cout << TeamName1 << endl;
   cout << teamAmt1 << endl;
   cout << TeamName2 << endl;
   cout << teamAmt2 << endl;
   cout << bearTeam[0].getCode() << endl;
   cout << bearTeam[0].getName() << endl;
}


