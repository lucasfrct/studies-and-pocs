#include <iostream>
#include <stack>

using namespace std;

int main(int arg, char *argv[]) {
    
    stack<int> pilha;

    pilha.push(10);
    pilha.push(20);
    pilha.push(30);
    pilha.push(40);

    while(!pilha.empty()) {
        int e = pilha.top();

        cout << e << endl;
        pilha.pop();
    }
    
    return 0;

}