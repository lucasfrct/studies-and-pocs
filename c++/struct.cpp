#include <iostream>
#include <string.h>
#include <string>

using namespace std;

typedef struct University
{
private:
    string name;
public:
    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return this->name;
    }

} t_university, University;

typedef struct Curse
{
private:
    string name;
    double price;
public:
    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return this->name;
    }

    void setPrice(double price)
    {
        this->price = price;
    }

    double getPrice()
    {
        return this->price;
    }

} t_curse, Curse;

typedef struct Studendt
{
private:
    string name;
    t_university university;
    Curse curse;
public: 
    string getUniversity()
    {
        return this->university.getName();
    }

    string getName()
    {
        return this->name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setUniversity(string name)
    {
        this->university.setName(name);
    }

    void setCurse(string name)
    {
        this->curse.setName(name);
    }

    string getCurse()
    {
        return this->curse.getName();
    }

    void setPrice(double price)
    {
        this->curse.setPrice(price);
    }

    double getPrice()
    {
        return this->curse.getPrice();
    }

} t_student, Student;

void BuiderStudent(Student& student, string name, string university, string curse, double price)
{
    student.setName(name);
    student.setUniversity(university);
    student.setCurse(curse);
    student.setPrice(price);
}

void DisplayStudent(Student &student)
{
    cout << "\nNome: " <<  student.getName() << endl;
    cout << "Universidade: " <<  student.getUniversity() << endl;
    cout << "Curso: " <<  student.getCurse() << endl;
    cout << "Preco: " <<  student.getPrice() << endl;
}

int main(int argc, char *argv[])
{
    Studendt e;
    e.setName( "Lucas" );
    e.setCurse("C++");
    e.setPrice(10);

    University u;
    u.setName("UFA");

    cout << e.getName() << " | " << e.getCurse() << " | " << e.getPrice() << endl;
    cout << "Universidade: " << u.getName() << endl;

    Studendt c;
    BuiderStudent(c, "Costa", "Uninter", "Eng da Computacao", 800.0);
    DisplayStudent(c);

    system("pause");

    return 0;
}


