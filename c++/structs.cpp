#include <iostream>
#include <string.h>
using namespace std;

typedef struct pessoa
{
    char nome[100];
    int idade;
    int ano;
} t_pessoa;

struct Person
{
public:
    char name;
    int age;

public:
    Person(int age)
    {
        this->age = age;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    int getAge()
    {
        return this->age;
    }
};

int main(int argc, char const *argv[])
{

    t_pessoa p;

    strcpy(p.nome, "Lucas");
    p.idade = 33;

    cout << "Nome: " << p.nome << endl;
    cout << "idade: " << p.idade << endl;

    t_pessoa p1[10];

    strcpy(p1[0].nome, "Lucas");
    p1[0].idade = 33;

    cout << "array - Nome: " << p1[0].nome << endl;
    cout << "array - idade: " << p1[0].idade << endl;

    t_pessoa p2;
    t_pessoa *p3;
    p3 = &p2;
    p3->idade = 33;
    cout << "ponteiro - idade: " << p3->idade << endl;

    Person p4(10);
    p4.age = 22;
    cout << "declaracao direta - age: " << p4.age << endl;

    p4.setAge(23);
    cout << "declaracao por metodo - age: " << p4.getAge() << endl;

    Person p5(30);
    cout << "declaracao por construtor - age: " << p5.getAge() << endl;

    system("pause");

    return 0;
}
