#ifndef MAGICCARD_H
#define MAGICCARD_H

#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class magiccard
{
    private:
        string name;
        string type;
        string strengthtoughness;
        string castingcost;
        string rarity;
        string dominantcolor;
        string draftorder;

    public:
        magiccard();
        magiccard(string,string,string,string,string,string,string);
        string getName();
        string getType();
        string getStrength();
        string getCost();
        string getRare();
        string getColor();
        string getOrder();
        int value;
        virtual ~magiccard();


};

#endif // MAGICCARD_H
