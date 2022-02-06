#include <iostream>
#include <set>

using namespace std;

int main(int argc, char *argv[]) {

    int vet[] = { 70, 10, 20, 10, 30, 40 };
    set<int> myset(vet, vet + 5);

    set<int>::iterator it = myset.begin();
    // myset.erase(it);
    while (it != myset.end()) {
        cout << *it << " ";
        it++;
    }

    cout << endl;

    // myset.clear();
    if(myset.empty()) {
        cout << "conjunto vazio";
    }

    return 0;
}