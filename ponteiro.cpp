#include <iostream>

using namespace std;


void foo(int *n) 
{
    *n = 20;
}

void bar(int vector[]) 
{
    vector[0] = 100;
}

int main(int argc, char *argv[]) {

    int var = 10;
    int *pointerVar; // reserva um espaço de memória do tamanho int para gurdar um endereço
    pointerVar = &var; // guarda 0 endereço de var
    cout << "Conteudo do ponteiro: " << *pointerVar << endl; // imprime o valor do conteudo do ponteiro
    cout << "Endereco armazenado no ponteiro: " << pointerVar << endl; // imprime o endereço de memória de var

    foo(pointerVar);
    cout << "Mudando o valor da variavel por passagem de referencia: " << *pointerVar << endl;

    int *pointerVector = new int[10];
    *(pointerVector + 0) = 10;
    *(pointerVector + 1) = 20;
    *(pointerVector + 2) = 30;
    cout << "mudando o valor no array 0: " << *(pointerVector + 0) << endl;
    cout << "mudando o valor no array 1: " << *(pointerVector + 1) << endl;
    cout << "mudando o valor no array 2: " << *(pointerVector + 2) << endl;
    bar(pointerVector);
    cout << "mudando o valor no array 0 por passasgem de valor: " << pointerVector[0] << endl;

    for (int i = 0; i < (sizeof(pointerVector)/sizeof(int)); i++)
    {
        cout << "item: " << i << " - " << pointerVector[i] << endl;
    }

    cout << "Digite um numero: ";
    cin >> pointerVector[0];
    cout << "Voce digitou: " << pointerVector[0] << endl;
    cout << "digite outro numero: ";
    cin >> *(pointerVector + 2);
    cout << "Voce digitou: " << *(pointerVector + 2) << endl;

    delete[] pointerVector; // desalocar memória
    pointerVector = NULL; // null não é um endereço de memória


    int array[] {1, 2, 5, 4, 3};
    int *pointerArray = &array[0];
    int i = 0;

    while(i < 5) 
    {
        cout << "Item " << i << " - " << *pointerArray << endl;
        pointerArray = pointerArray + 1;
        i++;
    }

    i = 4;
    pointerArray = &array[4];

    while(i >= 0) 
    {
        cout << "Item reverso " << i << " - " << *pointerArray << endl;
        pointerArray--;
        i--;
    }

    return 0;
}