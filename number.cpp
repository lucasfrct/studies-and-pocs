#include <iostream>

using namespace std;


int square(int num = 1)
{
    return num * num;
}

int main(int argc, const char** argv) {
    
    int n = 10;
    cout << "square ->  10^2: " << square(n) << endl;
    cout << "square ->  1^2: " << square() << endl;

    system("pause");

    return 0;
}