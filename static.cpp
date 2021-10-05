#include <iostream>
#include <string>

using namespace std;

int generateID()
{
    static int ID = 0;
    return ID++;
}

int main(int argc, char *argv[])
{

    string name;

    while (1)
    {
        cout << "Digite um n0me" << endl;
        cin >> name;
        cout << "ID: " << generateID() << endl;
    }
    

    system("pause");
    return 0;
}
