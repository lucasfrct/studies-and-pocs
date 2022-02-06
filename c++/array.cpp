#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int vector1 [10];
    int vetcor2[4] = { 1,2,3,4 }; 

    for(int i = 0; i < 10; i++) {
        cout << "Vector 1 - pos: " << i << "-->  " << vector1[i] << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        cout << "Vector 2 - pos: " << i << " --> " << vetcor2[i] << endl;
    }
    
    cout << "tamanho do Vector1 [10]: " << sizeof(vector1) << "cada espacode de memoria tem 4 bytes" << endl;
    cout << "tamanho do vector2 [4]: " << sizeof(vetcor2) << "cada espacode de memoria tem 4 bytes" << endl; 

    char vector3[] = {'l', 'u', 'c', 'a', 's', '\0'};

    //*varendo o vetor
    int i = 0;
    while (vector3[i])
    {
        cout << "varredura " << i << " | char:  " << vector3[i++] << endl;
    }

    cout << "Vector3: " << vector3 << endl;

    char vector4[] = "LUCAS";
    cout << "vector4: " << vector4 << endl;

    system("pause");

    return 0;
}

