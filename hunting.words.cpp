#include<iostream>
#include<random>

using namespace std;

char gen_random() {

    char alphabet[] = "abcdefghijklmnopqrstuvxzkwy";
    for(int i = 0 ; i < 25; i++)
    {
        cout << "random: " << i << " - " << rand()%((26 - i) - rand()%26) << endl;
    };

    return alphabet[1+rand()%26];
}

int main(int argc, char *argv[])
{
    int board[10][10];

    cout << board[0] << endl;

    cout <<  gen_random() << " - fim" << endl;

    return 0; 
}