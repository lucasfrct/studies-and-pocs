#include <iostream>

using namespace std;

int main(int argc, char * argv[]) 
{
    int n = 1;

    while(n <= 100) {

        if(n > 50) {
            break;
        }

        if(n  % 2 != 0) {
            n++;
            continue;
        }

        if(n < 10) {
            int i = 0;
            while(i < 3) {
                cout << "0" << ends;
                i++;
            }
        }

        cout << n << endl;
        
        n++;
    }

    system("pause");
    return 0;
}