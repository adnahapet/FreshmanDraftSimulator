#include "Player.h"


#include <vector>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;



Player::Player()
{
    name="Darwin";

}

Player::~Player()
{
    //dtor
}

Player::Player(string tname)
{
    name=tname;
}

void Player::setColor(string clr)
{
    Player::color=clr;
}
