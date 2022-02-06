#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, const char** argv) {
    
    char str[] = "Lucas Costa";
    string str1 = "lucas Costa 01";

    cout << "char: " << str << endl; 
    cout << "string: " << str1 << " size: " << str1.size() << " len: " << str1.length() << endl;
    cout << "string: select charactere - " << str1.at(1) << endl;
    cout << "string: first character - " << str1.front() << endl;
    cout << "string: last character - " << str1.back() << endl;
    cout << "string: concat - " << str1.append(" concat ") << endl;    
    cout << "string: last character " << str1.back() << endl;
    cout << "string: insert - " << str1.insert(0, " --user ") << endl;
    cout << "string: erase - " << str1.erase(20, str1.size()).erase(0, 8) << endl;
    cout << "string: empty - " << str1.empty() << endl;
    //cout << "string: clear - " << str1.clear() << endl;

    cout << "string: find - " << str1.find('cas') << endl;

    str1.replace(0 , 5, "LUCAS ");
    cout << "string: replace - " << str1 << endl;

    string str2 = "";
    getline(cin, str2);
    cout << "string com espacos: " << str2 << endl;


    system("pause");
    
    return 0;
}