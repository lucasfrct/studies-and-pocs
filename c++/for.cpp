#include <iostream>

using namespace std;

int main(int argc, char *argv []) 
{
    int i,j;
    for(i = 1, j = 1; i <= 10; i++, j++) {
        cout << "i: " << i << endl;
        cout << "j: " << j << endl;
    }

    // Calc fatorial

    int num, fat = 1;

    cout << "Digite um numero: ";
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        fat = fat * (i + 1);
    }

    cout << "O fatotial e: " << fat << endl;
    
    system("pause");
    return 0;
}