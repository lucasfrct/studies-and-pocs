#include <iostream>

using namespace std;

#define MAX 100

int main(int argc, char *argv[])
{
    char name[MAX];

    cout << "Digiete o seu nome" << endl;
    cin.get(name, MAX);
    cout << "Oi, " << name << endl;


    system("pause");
    return 0;
}
