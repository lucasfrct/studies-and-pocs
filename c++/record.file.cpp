#include <iostream>
#include <fstream>

using namespace std;

class Pessoa {
private:
    string name;
    int age;
public:
    string& getName() { return name; }
    int getAge() { return age; }
    void setName(string& name) { this->name = name; }
    void setAge(int age) { this->age = age; }
};

char menu(){
    char resp;

    cout << "Digite 1 para inserir pessoas";
    cout << "Digite 2 para listar as pessoas";
    cout << "Digite 0 para sair";

    cin >> resp;
    return resp;
}

int main(int argc, char const *argv[])
{
    char resp;

    while(true) {
        resp = menu();

        if(resp ==  1) {
            cout << "inserindo pessoas" << endl;
        } else if(resp == 2) {
            cout << "listando pessoas" << endl;
        } else if(resp == 0) {
            cout << "Visite o menu";
            break;
        }
    };

    return 0;
}
