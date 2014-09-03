#include "match.h"


Match::Match()
{

}

void Match::getJetTeamInfo()
{
   jetReader.open("Jets.txt");
   if(jetReader.is_open())
   {
       getline (jetReader, TeamName1);
       teamAmt1 = jetReader.get();


       jetReader.close();
   }
   cout << TeamName1 << endl;
   cout << teamAmt1 << endl;
   cout << "Unable to open file";
}


