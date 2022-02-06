#include <iostream>

using namespace std;

bool par(int num);

int main(int argc, char *argv[]) {
    
    int num;

    cout << "Digite um numero: " << ends;
    cin >> num;

    if(par(num)) {
        cout << "O numero " << num << " e par." << endl;
    } else  {
        cout << "o numero " << num << " e impar" << endl;
    }

    
    system("pause");
    return 0;
}

bool par(int num) {
    if(num % 2 == 0)
        return true;
    return false;
}

// Sobre caga de fuinc~so 
bool par(int num, bool operatorNum) {
    if(num % 2 == 0 && operatorNum == 1)
        return true;
    return false;
}


int sum(int n1, int n2) {
    return n1 + n2;
}

int sum(int n1, int n2, int n3) {
    return n1 + n2 + n3;
}

