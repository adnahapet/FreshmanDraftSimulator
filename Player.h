#ifndef PLAYER_H
#define PLAYER_H

#include "magiccard.h"

#include <vector>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class Player
{
    public:
        Player();
        Player(string);
        string color;
        vector <magiccard> pack1;
        vector <magiccard> pack2;
        vector <magiccard> pack3;
        vector <magiccard> pool;
        void setColor(string);
        virtual ~Player();
    private:
        string name;



};

#endif // PLAYER_H
