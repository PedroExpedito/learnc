#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    char comma;
    int r1, c1, r2, c2, cards[4][4];
    srand((unsigned)time(NULL));
    //fill board
    for (int r=0; r<4; r++)
    {
        for (int c=0; c<4; c++)
        {
            cards[r][c]=rand()%8+1;
            cout<<cards[r][c];
        }
        cout<<endl;
    }
    //display board
    cout<<"    1 2 3 4\n";
    cout<<"  ";
    for (int i=0; i<=8; i++)
    {
        cout<<"-";
    }
    cout<<endl;
    for (int r=0; r<4; r++)
    {
        cout<<r+1<<" | ";
        for (int c=0; c<4; c++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    cout<<endl;
    //selection
    cout<<"Please insert the first card row and column seperated by a comma.\n";
    cin>>r1>>comma>>c1;
    cout<<"Please insert the second card row and column seperated by a comma.\n";
    cin>>r2>>comma>>c2;
    //fix
    r1--;
    c1--;
    r2--;
    c2--;
    //reveal
    cout<<"    1 2 3 4\n";
    cout<<"  ";
    for (int i=0; i<=8; i++)
    {
        cout<<"-";
    }
    cout<<endl;
    for (int r=0; r<4; r++)
    {
        cout<<r+1<<" | ";
        for (int c=0; c<4; c++)
        {
            if ((r==r1)&&(c==c1))
            {
                cout<<cards[r][c]<<" ";
            }
            else if((r==r2)&&(c==c2))
            {
                cout<<cards[r][c]<<" ";
            }
            else
            {
                cout<<"* ";
            }
        }
        cout<<endl;
    }
    //match?
    if (cards[r1][c1]==cards[r2][c2])
    {
    }
    else
    {
    }
    //this pushes the next board onto a blank screen
    for (int b=0; b<=20; b++)
        cout<<endl;
    //repeat
    return 0;
}

