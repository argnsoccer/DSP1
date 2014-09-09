#include "player.h"

Player::Player()
{

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
