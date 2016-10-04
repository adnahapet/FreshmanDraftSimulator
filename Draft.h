#ifndef DRAFT_H
#define DRAFT_H

#include "magiccard.h"
#include "Player.h"

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <algorithm>

using namespace std;

class Draft
{
    private:
        vector <magiccard> setList;
        vector <magiccard> commonList;
        vector <magiccard> uncommonList;
        vector <magiccard> rareList;
        vector <Player> table;
        int round;
        int counter;

    public:

        vector <magiccard> temp;
        int temppick;

        Draft();

        void makeSet();
        void showSet();
        void makePlayers();
        void Pack();
        void makePacks();
        void showPack();
        void setPriority();
        int makePick(int);
        void sortPack();
        void consolidatePack(int,int);
        int userPick();
        void passLeft();
        void passRight();
        void showpool(int);
        virtual ~Draft();

};

#endif // DRAFT_H
