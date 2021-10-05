#include <iostream>
#include <string.h>

using namespace std;

class Person
{
public:
    char name[100];
    char cpf[20];
    int age;
};

class Conta
{
public:
    int numero;
    double saldo;

    double depositar(double quantidade)
    {
        if(quantidade > 0) {
            this->saldo += quantidade;
        }
         
         return this->saldo;
    }

    double retirar(double quantidade)
    {
        if(quantidade > 0 && saldo >= quantidade) {
            this->saldo -= quantidade;
        }
        return this->saldo;
    }

    double getSaldo()
    {
        return this->saldo;
    }

    int getNumero()
    {
        return this->numero;
    }
};

Conta *novaConta(int numero)
{
    Conta *c = new Conta;
    c->numero = numero;
    c->saldo = 0.0;
    return c;
}

int main(int argc, char const *argv[])
{

    Person p1;
    strcpy(p1.name, "lucas");

    cout << "nome: " << p1.name << endl;

    Conta cont;

    cont.numero = 1;
    cont.saldo = 100.75;

    cout << "saldo: " << cont.getSaldo() << endl;
    
    cont.depositar(100);
    cout << "Saldo atual: " << cont.getSaldo() << endl;

    cont.retirar(50);
    cout << "Saldo depois do saque: " << cont.getSaldo() << endl;

    Conta *c1 = novaConta(100);
    cout << "Saldo numero: " << c1->getNumero() << endl;
    cout << "Saldo atual: " << c1->getSaldo() << endl;
    
    system("pause");
    return 0;
}
