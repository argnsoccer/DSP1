#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
using namespace std;

class Player
{
public:
    Player();
    Player(int code, string name, int tagAmt, int points, int codeTagged);

    void setCode(int code);
    int getCode();

    void setName(string name);
    string getName();

    void setTagAmt(int tagAmt);
    int getTagAmt();

    void setPoints(int points);
    int getPoints();

    void insertCode(int code, int teamAmt, int position);
    int getCodeTagged(int position);
    int getCodeTaggedSize();

    int getTagAmtperPerson(int position);
    void insertTags(int tagNum, int teamAmt, int position);
    int getTagAmtSize();

private:
    int code;
    string name;
    int tagAmt;
    int points;
    vector<int> codeTagged;
    vector<int> tagAmtPerPerson;
};

inline int Player::getTagAmtperPerson(int position)
{
    return tagAmtPerPerson.at(position);
}

inline int Player::getTagAmtSize()
{
    return tagAmtPerPerson.size();
}

inline int Player::getCodeTagged(int position)
{
   return codeTagged.at(position);
}

inline int Player::getCodeTaggedSize()
{
    return codeTagged.size();
}

inline void Player::setCode(int code)
{
    this->code = code;
}

inline int Player::getCode()
{
    return code;
}

inline void Player::setName(string name)
{
    this->name = name;
}

inline string Player::getName()
{
    return name;
}

inline void Player::setTagAmt(int tagAmt)
{
    this->tagAmt = tagAmt;
}

inline int Player::getTagAmt()
{
    return tagAmt;
}

inline void Player::setPoints(int points)
{
    this->points = points;
}

inline int Player::getPoints()
{
    return points;
}
#endif // PLAYER_H
