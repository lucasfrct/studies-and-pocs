#include <iostream>
#include <exception>
#include <string.h>

using namespace std;

class ExceptionCustom : public exception
{
protected:
    char msg[100];
public:
    ExceptionCustom (const char *e)
    {
        strcpy(msg, e);
    }

    virtual const char *what()
    {
        return msg;
    }
};

int fatorial(int number)
{
    if (number < 0)
    {
        //throw "Numero negativo";
        throw ExceptionCustom("Cuastom: numero negativo");
    }

    if (number == 0 || number == 1)
    {
        return 1;
    }
    return number * fatorial(number - 1);
}

double divider(double number1, double number2)
{
    if(number2 == 0) {
        //throw "Divisão impossível";
        throw ExceptionCustom("Cuastom: divisao impossivel");
    }

    return number1 / number2;
};

int main(int argc, char *argv[])
{
    int result;
    try
    {
        cout << "fotirla 9: " << fatorial(9) << endl;

        cout << "fotirla -9: " << fatorial(-9) << endl;

        cout << "divider 11/13: " << divider(11,13) << endl;

        cout << "divider 11/0: " << divider(11,0) << endl;

    }
    catch (ExceptionCustom e)
    {
        cerr << "\nErro: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "Erro inesperado" << endl;
    };

    system("pause");

    return 0;
}