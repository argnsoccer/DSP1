#include "match.h"
#include "player.h"

Match::Match()
{

}


void Match::run(char* teamName1, char* teamName2, char* matchFile, char* outputFile, string verbosityType)
{
    getJetTeamInfo(teamName1);
    getBearTeamInfo(teamName2);
    getMatchInfo(matchFile);
    setPlayerInfo();
    if(verbosityType == "vlow")
    {
        OutputVLow(outputFile);
    }
    else if(verbosityType == "vmed")
    {
        OutputVMed(outputFile);
    }
    else if(verbosityType == "vhigh")
    {
        OutputVHigh(outputFile);
    }

    delete [] jetTeam;
    delete [] bearTeam;
    delete [] tagged;
    delete [] taggers;
    delete [] timeTagged;
    delete [] placeTagged;
}

void Match::getJetTeamInfo(char* teamName1)
{
   fileReader.open(teamName1);
   if(fileReader.is_open())
   {
       getline (fileReader, TeamName1);//gets the first line of the file and sets the line as a null terminated c-string
       fileReader >> teamAmt1;
       jetTeam = new Player[teamAmt1];//creates the "Players" of each team
       for(int i = 0; i < teamAmt1; ++i)
       {
            jetTeam[i].setTagAmt(0);//initializing data that may not get overwritten just in case there is something in memory at those spots
            jetTeam[i].setPoints(0);
            fileReader >> fileCodes;//gathers the first int and sets that to the code for each specific player.
            jetTeam[i].setCode(fileCodes);
            getline(fileReader, playerName);//gathers the rest of the line to set name of the player
            jetTeam[i].setName(playerName);

       }
       fileReader.close();
   }
}

void Match::getBearTeamInfo(char* teamName2)//same as the other team method
{
   fileReader.open(teamName2);
   if(fileReader.is_open())
   {
       getline(fileReader, TeamName2);
       fileReader >> teamAmt2;
       bearTeam = new Player[teamAmt2];
       for(int i = 0; i < teamAmt2; ++i)
       {
            bearTeam[i].setTagAmt(0);
            bearTeam[i].setPoints(0);
            fileReader >> fileCodes;
            bearTeam[i].setCode(fileCodes);
            getline(fileReader, playerName);
            bearTeam[i].setName(playerName);

       }

       fileReader.close();
   }
}

void Match::getMatchInfo(char* matchFile)//used to gather the information from the match file and place them into unique arrays to then populate the players specific data
{
   fileReader.open(matchFile);
   if(fileReader.is_open())
   {
       fileReader >> tagAmt;//gathers the first character, the amount of tags made
       taggers = new int[tagAmt];//creates arrays for each unique aspect of data in the match file
       tagged = new int[tagAmt];
       timeTagged = new int[tagAmt];
       placeTagged = new int[tagAmt];

       for(int i = 0; i < tagAmt; ++i)
       {
           fileReader >> taggers[i];//inputs the data into the arrays from the match file
           fileReader >> tagged[i];
           fileReader >> timeTagged[i];
           fileReader >> placeTagged[i];
       }

       fileReader.close();
   }
}

void Match::setPlayerInfo()
{
    int count1 = 1;
    int count2 = 1;
    int * tagNum1 = new int [teamAmt1];//creates an array for the amount of tags one specific player has against another specific player
    int * tagNum2 = new int [teamAmt2];
    for(int a = 0; a < teamAmt1; ++a)
    {
        tagNum1[a] = 1;
    }
    for(int b = 0; b < teamAmt2; ++b)
    {
        tagNum2[b] = 1;
    }
    for(int i = 0; i < tagAmt; ++i)//iterates through the lines of information to set the necessary info for each object
    {
        for(int j = 0; j < teamAmt1; ++j)//iterates through first team to set the taggers
        {
            if(taggers[i] == jetTeam[j].getCode())
            {
               if(jetTeam[j].getTagAmt() == count1)//checks to make sure the amount of tags info for each player is incrementing correctly
               {
                   count1++;
               }
               jetTeam[j].setTagAmt(count1);
               if(placeTagged[i] == 1)//transfers code into points data
               {
                  points = 5;
               }
               else if(placeTagged[i] == 2)
               {
                  points = 8;
               }
               else if(placeTagged[i] == 3)
               {
                  points = 10;
               }
               else if(placeTagged[i] == 4)
               {
                  points = 15;
               }
                   points = jetTeam[j].getPoints() + points;//makes sure the points don't overwrite each other
                   jetTeam[j].setPoints(points);


               for(int k = 0; k < teamAmt2; ++k)//iterates through the other team's players
               {
                   if(tagged[i] == bearTeam[k].getCode())//if the code in the tagged array matches a code on the bear team's players
                   {
                       if(jetTeam[j].getCodeTagged(k) > 0)//checks to make sure that if someone has been tagged before that specific tag incremements properly
                       {
                           tagNum1[j]++;
                       }
                       jetTeam[j].insertCode(tagged[i], teamAmt2, k);//inserts that code into a vector of the size of the other team to determine who on the jet team tagged who on the bear team
                       jetTeam[j].insertTags(tagNum1[j], teamAmt2, k);//a separate vector that tracks the amount of tags on each person

                   }
               }
            }
            else
            {
                jetTeam[j].insertCode(0, teamAmt2, -1);//just in case no one is tagged
                jetTeam[j].insertTags(0, teamAmt2, -1);
            }
        }
        for(int x = 0; x < teamAmt2; ++x)
        {
            if(taggers[i] == bearTeam[x].getCode())
            {
                if(bearTeam[x].getTagAmt() == count2)
                {
                    count2++;
                }
                bearTeam[x].setTagAmt(count2);
                if(placeTagged[i] == 1)
                {
                   points = 5;
                }
                else if(placeTagged[i] == 2)
                {
                   points = 8;
                }
                else if(placeTagged[i] == 3)
                {
                   points = 10;
                }
                else if(placeTagged[i] == 4)
                {
                   points = 15;
                }
                    points = bearTeam[x].getPoints() + points;
                    bearTeam[x].setPoints(points);

                for(int f = 0; f < teamAmt1; ++f)
                {
                    if(tagged[i] == jetTeam[f].getCode())
                    {
                        bearTeam[x].insertCode(tagged[i], teamAmt1, f);
                        bearTeam[x].insertTags(tagNum2[x], teamAmt1, f);
                        tagNum2[x]++;
                    }
                }
            }
            else
            {
                bearTeam[x].insertCode(0, teamAmt1, -1);
                bearTeam[x].insertTags(0, teamAmt1, -1);
            }
        }
    }
    delete[] tagNum1;
    delete [] tagNum2;
}

void Match::teamTally()//adds up the scores of each team to then output in the files
{
    jetTeamPoints = 0;
    bearTeamPoints = 0;
    for(int i = 0; i < teamAmt1; ++i)
    {
        jetTeamPoints+=jetTeam[i].getPoints();
    }
    for(int j = 0; j < teamAmt2; ++j)
    {
        bearTeamPoints+=bearTeam[j].getPoints();
    }
}

void Match::OutputVLow(char* outputFile)
{

   fileOutput.open(outputFile);
   teamTally();
   fileOutput << TeamName1 << ": " << jetTeamPoints << " points" << endl;
   fileOutput << TeamName2 << ": " << bearTeamPoints << " points" << endl;
   if(jetTeamPoints > bearTeamPoints)
   {
       fileOutput << "Overall Winners: " << TeamName1 << endl;
   }
   else if(jetTeamPoints < bearTeamPoints)
   {
       fileOutput << "Overall Winners: " << TeamName2 << endl;
   }
   else
       fileOutput << TeamName1 << " have tied " << TeamName2 << endl;

   fileOutput.close();
}

void Match::OutputVMed(char* outputFile)
{
    teamTally();
    int bestScore1 = 0;
    string bestScore1Name ="";
    string bestScore2Name = "";
    int bestScore2 = 0;
    fileOutput.open(outputFile);
    fileOutput << TeamName1 << endl;
    bool min = false;
    int index = 0;
    for(int i = 0; i < teamAmt1-1; ++i)
    {
           if(jetTeam[i].getPoints() > jetTeam[i+1].getPoints())
           {
               bestScore1 = jetTeam[i].getPoints();
               bestScore1Name = jetTeam[i].getName();
           }
           else if(jetTeam[0].getPoints() > jetTeam[i+1].getPoints())//checks to make sure the first element is greater than the the rest, just in case bestScore values are changed away from it
           {
               bestScore1 = jetTeam[0].getPoints();
               bestScore1Name = jetTeam[0].getPoints();
           }
           else
           {
               bestScore1Name = jetTeam[i+1].getName();
               bestScore1 = jetTeam[i+1].getPoints();
           }
           if(jetTeam[i].getTagAmt() > jetTeam[i+1].getTagAmt())
           {
               fileOutput << "\t" << jetTeam[i].getName() << " had a total of " << jetTeam[i].getTagAmt() << " tags" << endl << endl;
           }
           else if(jetTeam[i+1].getTagAmt() > jetTeam[i].getTagAmt())
           {
               fileOutput << "\t" << jetTeam[i+1].getName() << " had a total of " << jetTeam[i+1].getTagAmt() << " tags" << endl << endl;
           }
           else if(jetTeam[i].getTagAmt() == jetTeam[i+1].getTagAmt())
               fileOutput << "\t" << jetTeam[i+1].getName() << " had a total of " << jetTeam[i+1].getTagAmt() << " tags" << endl << endl;


           if(i == teamAmt1-2)//checks to make sure the minimum value is still printed
           {
              for(int x = 0; x < teamAmt1-1; ++x)
              {
                 if(jetTeam[x].getTagAmt() < jetTeam[x+1].getTagAmt())
                 {
                     min = true;
                     index = x;
                 }
              }
              if(min == true)
              {

                  fileOutput << "\t" << jetTeam[index].getName() << " had a total of " << jetTeam[index].getTagAmt() << " tags" << endl << endl;
              }
           }

    }
    fileOutput << TeamName2 << endl;
    min = false;
    for(int j = 0; j < teamAmt2-1; ++j)
    {
        if(bearTeam[j].getPoints() > bearTeam[j+1].getPoints())
        {
            bestScore2 = bearTeam[j].getPoints();
            bestScore2Name = bearTeam[j].getName();
        }
        else if(bearTeam[0].getPoints() > bearTeam[j+1].getPoints())
        {
            bestScore2Name = bearTeam[0].getName();
            bestScore2 = bearTeam[0].getPoints();
        }
        else
        {
            bestScore2Name = bearTeam[j+1].getName();
            bestScore2 = bearTeam[j+1].getPoints();
        }
        if(bearTeam[j].getTagAmt() > bearTeam[j+1].getTagAmt())
        {
            fileOutput << "\t" << bearTeam[j].getName() << " had a total of " << bearTeam[j].getTagAmt() << " tags" << endl << endl;
        }
        else if(bearTeam[j+1].getTagAmt() > bearTeam[j].getTagAmt())
        {
            fileOutput << "\t" << bearTeam[j+1].getName() << " had a total of " << bearTeam[j+1].getTagAmt() << " tags" << endl << endl;
        }
        else if(bearTeam[j].getTagAmt() == bearTeam[j+1].getTagAmt())
            fileOutput << "\t" << bearTeam[j+1].getName() << " had a total of " << bearTeam[j+1].getTagAmt() << " tags" << endl << endl;

        if(j == teamAmt2-2)//checks to make sure the minimum value is still printed
        {
           for(int y = 0; y < teamAmt2-1; ++y)
           {
              if(bearTeam[y].getTagAmt() < bearTeam[y+1].getTagAmt())
              {
                  min = true;
                  index = y;
              }
           }
           if(min == true)
           {
               fileOutput << "\t" << bearTeam[index].getName() << " had a total of " << bearTeam[index].getTagAmt() << " tags" << endl << endl;
           }
        }


    }
    fileOutput << "Best score from " << TeamName1 << ":" << bestScore1Name << " (" << bestScore1 << " points)" << endl;
    fileOutput << "Best score from " << TeamName2 << ":" << bestScore2Name << " (" << bestScore2 << " points)" << endl;
    fileOutput << TeamName1 << ": " << jetTeamPoints << " points" << endl;
    fileOutput << TeamName2 << ": " << bearTeamPoints << " points" << endl;
    if(jetTeamPoints > bearTeamPoints)
    {
        fileOutput << "Overall Winners: " << TeamName1 << endl;
    }
    else if(jetTeamPoints < bearTeamPoints)
    {
        fileOutput << "Overall Winners: " << TeamName2 << endl;
    }
    else
        fileOutput << TeamName1 << " have tied " << TeamName2 << endl;

    fileOutput.close();


}

void Match::OutputVHigh(char* outputFile)
{
    teamTally();
    fileOutput.open(outputFile);
    fileOutput << TeamName1 << endl;
    for(int i = 0; i < teamAmt1; ++i)
    {
        for(int j = 0; j < teamAmt2; ++j)
        {
            fileOutput << "\t" << jetTeam[i].getName() << " tagged" << bearTeam[j].getName() << " " << jetTeam[i].getTagAmtperPerson(j) << " times" << endl;
        }
        fileOutput << "\t" << jetTeam[i].getName() << " had a total of " << jetTeam[i].getTagAmt() << " tags" << endl;
    }
    fileOutput << "\t " << TeamName1 << ": " << jetTeamPoints << " points" << endl << endl;

    fileOutput << TeamName2 << endl;
    for (int k = 0; k < teamAmt2; ++k)
    {
        for(int l = 0; l < teamAmt1; ++l)
        {
            fileOutput << "\t" << bearTeam[k].getName() << " tagged" << jetTeam[l].getName() << " " << bearTeam[k].getTagAmtperPerson(l) << " times" << endl;
        }
        fileOutput << "\t" << bearTeam[k].getName() << " had a total of " << bearTeam[k].getTagAmt() << " tags" << endl;
    }
    fileOutput << "\t " << TeamName2 << ": " << bearTeamPoints << " points" << endl << endl;

    if(jetTeamPoints > bearTeamPoints)
    {
        fileOutput << "Overall Winners: " << TeamName1 << endl;
    }
    else if(jetTeamPoints < bearTeamPoints)
    {
        fileOutput << "Overall Winners: " << TeamName2 << endl;
    }
    else
        fileOutput << TeamName1 << " have tied " << TeamName2 << endl;

    fileOutput.close();


}


