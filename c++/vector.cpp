#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{

    vector<int> v;

    v.push_back(10);
    v.push_back(100);
    v.push_back(1000);

    for (int i = 0; i < v.size(); i++)
    {
        cout << "vector item: " << v[i] << endl;
    }

    vector<int>::iterator it = v.begin();

    cout << *it << endl;

    for (it = v.begin(); it < v.end(); it++)
    {
        cout << "item: " << *it << endl;
    }

    cout << "ultimo elemento: " << *(--v.end()) << endl;

    while (!v.empty())
    {
        //v.pop_back(); // desempilhando
    }

    if (v.empty())
    {
        cout << "vector empty" << endl;
    }

    cout << "primeiro: " << v.front() << endl;
    cout << "ultimo: " << v.back() << endl;
    cout << "position 1: " << v.at(1) << endl;
    //cout << "erase: " << v.erase(1) << endl;
    //cout << "clear: " << v.clear() << endl;

    system("pause");

    return 0;
}