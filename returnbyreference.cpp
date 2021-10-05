#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

typedef struct Person 
{
    string name;
    int age;
    double weight;
    double height;
} t_person;

 double& calcIMC(t_person &person)
 {
    double result = person.weight / pow(person.height, 2);
    double& imc = result;
    return imc;
 };


int main(int argc, char *argv[])
{
    
    t_person person = { "Jhon", 20, 92.45, 1.75 };

    cout << calcIMC(person) << endl;
    
    system("pause");
    return 0;
}
