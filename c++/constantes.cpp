#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
    int var = 10;
    int *p1, *p2;

    p1 = &var;
    p2 = &var;

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "var: " << &var << endl;

    const double PI = 3.1425;


    cout << PI << endl;

    system("pause");

    return 0;
}