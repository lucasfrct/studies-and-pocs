#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {


    map<int, string> mapper;

    mapper[1] = "pedro";

    cout << mapper[1] << endl;


    return 0;
}