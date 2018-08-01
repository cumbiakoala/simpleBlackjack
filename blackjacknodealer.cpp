// Name: Millan Figueroa
// Course: CIS 006 Intro to Programming
// CRN: 44574
// Date: 7/3/2018
// Assignment: Blackjack

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int card1, card2, card3, card4, card5, card6, h, H, s, S, y, Y, n, N, total;
    char stayOrhit, playAgain='y';

    do{
        cout<<"Blackjack rules: Get as close as you can to 21 without going over!\n";
        cout<<endl;
        cout<<"Here are your first cards: \n";

        //1. Player: Generates two cards adds to total
        const int MIN_VALUE = 2;
        const int MAX_VALUE = 10;
        unsigned seed = time(0);
        srand (seed);
        card1=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
        card2=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
        cout<<card1<<endl;
        cout<<card2<<endl;
        total=card1+card2;
        cout<<endl;
        cout<<"Your Total: "<<total<<endl; //Print total #1
        //HIT OR STAY #1
        do //Problem is this loop keeps starting from here, so when the option to "stay" is chosen, cannot get it to switch to "Play again" loop
        {cout<<endl;
         cout<<"Do you want to [h]it or [s]tay?"<<endl;
         cin>>stayOrhit;

            if(stayOrhit=='h') //If Hit, generate another card, add to to total #1
            {unsigned seed = time(0);
            srand (seed);
            card3=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
            cout<<endl;
            cout<<"Here's another card: "<<card3<<endl;
            total=total+card3;
            cout<<endl;
            cout<<"Your Total: "<<total<<endl; //total #2
            }
    }
    while(total<18);

            if(stayOrhit=='s'&&total<18)

            {
                cout<<"Sorry! Dealer's closer to 21 than you. You lose!"<<endl;
                cin.ignore();

                if (total==18){ //If total = 18, PUSH. WORKS.
                    cout<<endl;
                    cout<<"PUSH. Nobody wins!\n"<<endl;
                    cin.ignore();
                    }

                if (total==21){ //If total #2 equals 21, WIN.
                    cout<<endl;
                    cout<<"BLACKJACK! You got 21, you win!\n"<<endl; //equals 21, win. WORKS.
                    cin.ignore();
                    }

                if (total>18&&total<21){ //If total #2 is more than 18 and less than 21, WIN. WORKS.
                    cout<<endl;
                    cout<<"Congratulations! You beat the dealer without going over! You win!"<<endl;
                    cin.ignore();
                    }
                if (total>21){ //If total #2 is greater than 21, BUST.
                    cout<<endl;
                    cout<<"BUST. You lose.\n"<<endl; //over 21, bust.
                    cin.ignore();
                    }

    cout<<endl;
    cout<<"Woud you like to go again? y/n\n"<<endl;
    cin>>playAgain;
    cout<<endl;
    }
    while (playAgain == 'y');

}
