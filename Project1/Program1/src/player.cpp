#include "player.h"

Player::Player()
{

}

Player::Player(int code, string name, int tagAmt, int points, int codeTagged):
    code(code), name(name), tagAmt(tagAmt), points(points), codeTagged(codeTagged){

}

void Player::insertCode(int code, int teamAmt, int position){
    codeTagged.resize(teamAmt);
    if(position >= 0)
    {
        codeTagged.erase(codeTagged.begin()+position);
        codeTagged.insert(codeTagged.begin()+position, code);
    }
}

void Player::insertTags(int tagNum, int teamAmt, int position)
{
    tagAmtPerPerson.resize(teamAmt);
    if(position >= 0)
    {
        tagAmtPerPerson.erase(tagAmtPerPerson.begin()+position);
        tagAmtPerPerson.insert(tagAmtPerPerson.begin()+position, tagNum);
    }
}
