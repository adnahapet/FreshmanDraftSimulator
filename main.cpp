#include <iostream>
#include "Draft.h"
#include "magiccard.h"
#include "Player.h"

using namespace std;


//main function outside of containing while loop mostly calls Draft() object which creates and controls each instance of draft entirely
//Draft.cpp contains a more thorough explanation of how the program works
int main()
{
    cout << "This program simulates an eight person draft of the original Magic: The Gathering card set, now called Alpha though it can be used for almost any set." << endl;
    cout << "Your 7 computer opponents will make their selections based on quality of card and color, attempting to draft with relatively smart strategy. " << endl;
    cout << "For educational purpose only. Magic: The Gathering is owned by Wizards of the Coast"<<endl;
    bool keepgoing=true;
    while(keepgoing==true){
        Draft();
        int selection;
        cout<<"Would you like to draft again?"<<endl;
        cout<<"1) Yes"<<endl;
        cout<<"2) No"<<endl;
        cin>>selection;
        while (!(selection >= 1 && selection <=2)){
            if (!(selection >= 1 && selection <=2)){
                cout << "invalid selection!" << endl;
                cout << "selection: ";
                cin>>selection;
            }
        }
    if(selection==2)
        keepgoing=false;
    }
    cout<<"Thanks for playing."<<endl;
    return 0;
}

