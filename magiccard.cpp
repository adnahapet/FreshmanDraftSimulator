#include "magiccard.h"


#include <string>
#include <iostream>
#include <stdlib.h>
#include <sstream>

magiccard::magiccard()
{
    //ctor
}

magiccard::~magiccard()
{
    //dtor
}

magiccard::magiccard(string a ,string b ,string c,string d,string e,string f,string g)
{
    magiccard::name = a;
    magiccard::type= b;
    magiccard::strengthtoughness = c;
    magiccard::castingcost = d;
    magiccard::rarity = e;
    magiccard::dominantcolor = f;
    magiccard::draftorder = g;
    istringstream (magiccard::draftorder) >> magiccard::value;
}


 string magiccard::getName(){
     return magiccard::name;
 }

  string magiccard::getType(){
      return magiccard::type;
 }

  string magiccard::getStrength(){
      return magiccard::strengthtoughness;
 }

 string magiccard::getCost(){
      return magiccard::castingcost;
 }

  string magiccard::getRare(){
      return magiccard::rarity;
 }

  string magiccard::getColor(){
      return magiccard::dominantcolor;
 }

  string magiccard::getOrder(){
      return magiccard::draftorder;
 }
