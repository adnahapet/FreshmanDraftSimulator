#include "Draft.h"
#include "magiccard.h"
#include "Player.h"

#include <vector>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Draft Object. Calls methods to import cards,create players, and make packs of cards. Controls flow of the draft.
Draft::Draft()
{
    srand (time(NULL));
    Draft::round=0;
    Draft::makeSet();
    Draft::makePlayers();
    Draft::makePacks();
    while(Draft::round<3){
        Draft::counter=1;
        for(int x=0;x<15;x++){
            Draft::showPack();
            Draft::consolidatePack(Draft::userPick(),0);
            Draft::sortPack();
            for(int i=1;i<8;i++){
                Draft::temppick = Draft::makePick(i);
                Draft::consolidatePack(Draft::temppick,i);
            }
            Draft::counter++;
            if(round==1){
                Draft::setPriority();
                Draft::passRight();
            }
            else
                Draft::passLeft();
        }
        Draft::setPriority();
        Draft::round++;
    }
    Draft::showpool(0);
    cout<<"Thanks for drafting."<<endl;

}

Draft::~Draft()
{
    //dtor
}

//Uses stringstream to import card data from text file. Could be changed to accommodate a different set.
//Also creates sorted lists of cards by rarity.
void Draft::makeSet()
{
    cout<<"Making the set..."<<endl;
    vector <string> datalist(7);
    string data;
    string token;
    ifstream infile;
    int card = 0;

    setList.resize(292);
    rareList.resize(0);
    commonList.resize(0);
    uncommonList.resize(0);

    infile.open("alphasetlist.txt");

    while(infile.good())
    {

      getline(infile,data);
      istringstream ss(data);
      for (int x = 0; x<7; x++)
      {
        getline(ss, token, ',');
        datalist[x] = token;
      }
      Draft::setList[card]=magiccard(datalist[0],datalist[1],datalist[2],datalist[3],datalist[4],datalist[5],datalist[6]);
      if (datalist[4] == "Rare"){
          int z = Draft::rareList.size();
          Draft::rareList.resize(z+1);
          Draft::rareList[z]=setList[card];
        card++;
        }
      if (datalist[4] == "Common"){
          int z = Draft::commonList.size();
          Draft::commonList.resize(z+1);
          Draft::commonList[z]=setList[card];
        card++;
        }
      if (datalist[4] == "Uncommon"){
          int z = Draft::uncommonList.size();
          Draft::uncommonList.resize(z+1);
          Draft::uncommonList[z]=setList[card];
        card++;
        }
    }
}

//Method for testing data import success.
void Draft::showSet()
{
    for(int i=0;i++;i<Draft::setList.size()){
        cout<<Draft::setList[i].getName()<<endl;
    }
}

//Creates the computer controlled drafters. Names are arbitrary and not needed for program.
void Draft::makePlayers()
{
    Draft::table.resize(8);
    Draft::table[0]=Player("User");
    Draft::table[1]=Player("Jason");
    Draft::table[2]=Player("Nick");
    Draft::table[3]=Player("Ann");
    Draft::table[4]=Player("Ami");
    Draft::table[5]=Player("Jarred");
    Draft::table[6]=Player("Charlie");
    Draft::table[7]=Player("Joe");
}

//A typical Magic booster pack contains 1 Rare, 3 Uncommons, and 11 Commons
//This method utilizes the different rarity lists created in Draft::makeSet()
//to create a vector of Magic cards of the appropriate composition
void Draft::Pack(){
    Draft::temp.resize(15);
    int number = rand() % Draft::rareList.size();
    Draft::temp[0]=rareList[number];
    number = rand() % Draft::uncommonList.size();
    Draft::temp[1]=uncommonList[number];
    number = rand() % Draft::uncommonList.size();
    Draft::temp[2]=uncommonList[number];
    number = rand() % Draft::uncommonList.size();
    Draft::temp[3]=uncommonList[number];
    number = rand() % Draft::commonList.size();
    Draft::temp[4]=commonList[number];
    number = rand() % Draft::commonList.size();
    Draft::temp[5]=commonList[number];
    number = rand() % Draft::commonList.size();
    Draft::temp[6]=commonList[number];
    number = rand() % Draft::commonList.size();
    Draft::temp[7]=commonList[number];
    number = rand() % Draft::commonList.size();
    Draft::temp[8]=commonList[number];
    number = rand() % Draft::commonList.size();
    Draft::temp[9]=commonList[number];
    number = rand() % Draft::commonList.size();
    Draft::temp[10]=commonList[number];
    number = rand() % Draft::commonList.size();
    Draft::temp[11]=commonList[number];
    number = rand() % Draft::commonList.size();
    Draft::temp[12]=commonList[number];
    number = rand() % Draft::commonList.size();
    Draft::temp[13]=commonList[number];
    number = rand() % Draft::commonList.size();
    Draft::temp[14]=commonList[number];
}

//Method that calls Pack() 3 times for each player
//and assigns their packs to their pack1 pack2 and pack3 members
void Draft::makePacks(){
   for(int i=0;i<8;i++){
        Draft::temp.clear();
        Draft::Pack();
        Draft::table[i].pack1=Draft::temp;
        Draft::temp.clear();
        Draft::Pack();
        Draft::table[i].pack2=Draft::temp;
        Draft::temp.clear();
        Draft::Pack();
        Draft::table[i].pack3=Draft::temp;
    }
}

//method for showing the contents of a pack
//primarily used for displaying info to the user about their current pack
void Draft::showPack(){
    cout<<endl;
    cout<<endl;
    cout<<endl;
   if (Draft::round==0){
        cout<<"Pack 1"<<"   "<<"Pick:"<<Draft::counter<<endl;
        cout<<"Card Name --- Card Type --- S/T --- Casting Cost --- Rarity"<<endl;
      for(int i=0;i<table[0].pack1.size();i++){
         cout<<i<<")";
         cout<<table[0].pack1[i].getName()<<",";
         cout<<table[0].pack1[i].getType()<<",";
         cout<<table[0].pack1[i].getStrength()<<",";
         cout<<table[0].pack1[i].getCost()<<",";
         cout<<table[0].pack1[i].getRare()<<",";
         cout<<endl;
        }
    }
    if (Draft::round==1){
        cout<<"Pack 2"<<"   "<<"Pick:"<<Draft::counter<<endl;
        cout<<"Card Name --- Card Type --- S/T --- Casting Cost --- Rarity"<<endl;
      for(int i=0;i<table[0].pack2.size();i++){
         cout<<i<<")";
         cout<<table[0].pack2[i].getName()<<",";
         cout<<table[0].pack2[i].getType()<<",";
         cout<<table[0].pack2[i].getStrength()<<",";
         cout<<table[0].pack2[i].getCost()<<",";
         cout<<table[0].pack2[i].getRare()<<",";
         cout<<endl;
        }
    }
    if (Draft::round==2){
        cout<<"Pack 3"<<"   "<<"Pick:"<<Draft::counter<<endl;
        cout<<"Card Name --- Card Type --- S/T --- Casting Cost --- Rarity"<<endl;
        for(int i=0;i<table[0].pack3.size();i++){
         cout<<i<<")";
         cout<<table[0].pack3[i].getName()<<",";
         cout<<table[0].pack3[i].getType()<<",";
         cout<<table[0].pack3[i].getStrength()<<",";
         cout<<table[0].pack3[i].getCost()<<",";
         cout<<table[0].pack3[i].getRare()<<",";
         cout<<endl;
        }
    }
}

//Controls the picking "decision" of the non-user players and adds their selection to their card pool
//A sorted pack will have the lowest (best) valued card in the [0] position in the pack vector
//If round==1 the computer will simply take the best card. This is often called "rare drafting"
//In subsequent rounds the computer will take into account the color composition of the players current pool
//The computer will pick a card in the current players color granted it is under a maximum value
//Or take the best card available regardless of color
int Draft::makePick(int whoseturn){
    Draft::sortPack();
    magiccard selection;
    int thepick;
    if(Draft::round==0){
        thepick=0;
        selection = table[whoseturn].pack1[0];
    }
    if(Draft::round==1){
        for(int i=0;i<table[whoseturn].pack2.size();i++){
        if (table[whoseturn].pack2[i].getColor()==table[whoseturn].color && table[whoseturn].pack2[i].value<4){
            thepick=i;
            selection=table[whoseturn].pack2[thepick];
        }
        else{
            thepick=0;
            selection=table[whoseturn].pack2[0];
        }
        }
    }
    if(Draft::round==2){
        for(int i=0;i<table[whoseturn].pack3.size();i++){
          if (table[whoseturn].pack3[i].getColor()==table[whoseturn].color && table[whoseturn].pack3[i].value<12){
            thepick=i;
            selection=table[whoseturn].pack3[thepick];
        }
        else{
            thepick=0;
            selection=table[whoseturn].pack3[0];
        }
    }
    }
    int current = table[whoseturn].pool.size();
    table[whoseturn].pool.resize(current+1);
    table[whoseturn].pool[current]=selection;
    return thepick;
}


//Method to sort pack based on value. Frequently doesn't move the cards much because they are already sorted by rarity at creation
//and rare cards are often best
void Draft::sortPack(){
    magiccard buffer;
        for(int i=1;i<8;i++){
            int q=0;
            while(q<table[i].pack1.size()){
                for(int z=0;z<table[i].pack1.size()-1;z++){
                    if (table[i].pack1[z].value>table[i].pack1[z+1].value){
                        buffer= table[i].pack1[z];
                        table[i].pack1[z]=table[i].pack1[z+1];
                        table[i].pack1[z+1]=buffer;
                    }
                }
            q++;
            }
        }
        for(int i=1;i<8;i++){
            int q=0;
            while(q<table[i].pack1.size()){
                for(int z=0;z<table[i].pack2.size()-1;z++){
                    if (table[i].pack2[z].value>table[i].pack2[z+1].value){
                        buffer= table[i].pack2[z];
                        table[i].pack2[z]=table[i].pack2[z+1];
                        table[i].pack2[z+1]=buffer;
                    }
                }
            q++;
            }
        }
        for(int i=1;i<8;i++){
            int q=0;
            while(q<table[i].pack1.size()){
                for(int z=0;z<table[i].pack3.size()-1;z++){
                    if (table[i].pack3[z].value>table[i].pack3[z+1].value){
                        buffer= table[i].pack3[z];
                        table[i].pack3[z]=table[i].pack3[z+1];
                        table[i].pack3[z+1]=buffer;
                    }
                }
            q++;
            }
        }
}

//Method to take in the selection of the user or computer player and eliminate that card object from the pack before passing
void Draft::consolidatePack(int num,int whoseturn){
    vector <magiccard> holder;
    int q=0;


    if(Draft::round==0){
        if(table[whoseturn].pack1.size()!=0)
            holder.resize(table[whoseturn].pack1.size()-1);
        for(int i=0;i<table[whoseturn].pack1.size();i++){
        if(i!=num){
            holder[q]=table[whoseturn].pack1[i];
            q++;
        }
    }
    table[whoseturn].pack1.resize(holder.size());
    table[whoseturn].pack1=holder;
    }

    if(Draft::round==1){
        if(table[whoseturn].pack2.size()!=0)
            holder.resize(table[whoseturn].pack2.size()-1);
        for(int i=0;i<table[whoseturn].pack2.size();i++){
        if(i!=num){
            holder[q]=table[whoseturn].pack2[i];
            q++;
        }
    }
    table[whoseturn].pack2.resize(holder.size());
    table[whoseturn].pack2=holder;
    }

    if(Draft::round==2){
        if(table[whoseturn].pack3.size()!=0)
            holder.resize(table[whoseturn].pack3.size()-1);
        for(int i=0;i<table[whoseturn].pack3.size();i++){
        if(i!=num){
            holder[q]=table[whoseturn].pack3[i];
            q++;
        }
    }
    table[whoseturn].pack3.resize(holder.size());
    table[whoseturn].pack3=holder;
    }
}


//Controls the interaction with the user and allows them to pick a card.
int Draft::userPick(){
    int i;
    if(round==0)
        i=table[0].pack1.size();
    if(round==1)
        i=table[0].pack2.size();
    if(round==2)
        i=table[0].pack3.size();
    int number;
    cout<<endl;
    cout<<"Please enter the number of the card you'd like to pick:"<<endl;
    cin>>number;
    while (!(number >= 0 && number <=i-1))
    {
        cout << "Sorry, you can't do that!" << endl;
        cout << "Pick again: ";
        cin>>number;
	}
    magiccard selection;
    if(Draft::round==0){
        selection = table[0].pack1[number];
    }
    if(Draft::round==1){
            selection=table[0].pack2[number];
        }
    if(Draft::round==2){
            selection=table[0].pack3[number];
    }
    int current = table[0].pool.size();
    table[0].pool.resize(current+1);
    table[0].pool[current]=selection;
    return number;
}


//Passes the pack objects between players
void Draft::passLeft(){
    vector <magiccard> holder;
    if(Draft::round==0){
        holder=table[0].pack1;
        for (int i=0;i<7;i++){
            table[i].pack1=table[i+1].pack1;
            }

    table[7].pack1=holder;
    }
    if(Draft::round==1){
        holder=table[0].pack2;
        for (int i=0;i<7;i++){
            table[i].pack2=table[i+1].pack2;
            }

    table[7].pack2=holder;
    }
    if(Draft::round==2){
        holder=table[0].pack3;
        for (int i=0;i<7;i++){
            table[i].pack3=table[i+1].pack3;
            }

    table[7].pack3=holder;
    }
}


//Passes the pack objects between players
void Draft::passRight(){
    vector <magiccard> holder;
    if(Draft::round==0){
        holder=table[7].pack1;
        for (int i=0;i<7;i++){
            table[i+1].pack1=table[i].pack1;
            }

    table[0].pack1=holder;
    }
    if(Draft::round==1){
        holder=table[7].pack2;
        for (int i=0;i<7;i++){
            table[i+1].pack2=table[1].pack2;
            }

    table[0].pack2=holder;
    }
    if(Draft::round==2){
        holder=table[7].pack3;
        for (int i=0;i<7;i++){
            table[i+1].pack3=table[i].pack3;
            }

    table[0].pack3=holder;
    }
}

//method to display the contents of a players pool
void Draft::showpool(int z){
    int x = table[z].pool.size();
    cout<<x<<" cards:"<<endl;
    for(int i=0;i<x;i++){
        cout<<table[z].pool[i].getName()<<" "<<table[z].pool[i].getColor()<<endl;
    }

}

//method to count the cards of each color in a players pool and set the players .color member to the corresponding color
void Draft::setPriority(){
     for(int i=1;i<8;i++){
            int temp=0;
            int whichcolor;
            int counter[5]={0,0,0,0,0};
            for(int z=0;z<15;z++){
                if (table[i].pool[z].getColor()=="Red")
                    counter[0]++;
                if (table[i].pool[z].getColor()=="Green")
                    counter[1]++;
                if (table[i].pool[z].getColor()=="Blue")
                    counter[2]++;
                if (table[i].pool[z].getColor()=="White")
                    counter[3]++;
                if (table[i].pool[z].getColor()=="Black")
                    counter[4]++;
            }
            for(int z=0;z<5;z++){
                if(counter[z]>temp){
                    temp=counter[z];
                    whichcolor=z;
                }
            }
            if(whichcolor==0)
                table[i].setColor("Red");
            if(whichcolor==1)
                table[i].setColor("Green");
            if(whichcolor==2)
                table[i].setColor("Blue");
            if(whichcolor==3)
                table[i].setColor("White");
            if(whichcolor==4)
                table[i].setColor("Black");
    }
}
