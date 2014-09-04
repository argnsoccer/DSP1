#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player
{
public:
    Player();
    Player(int code, string name);

    void setCode(int code);
    int getCode();

    void setName(string name);
    string getName();

private:
    int code;
    string name;
};

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

#endif // PLAYER_H
