#include <iostream>
#include "linked.list.h"

using namespace std;


int main(int argc, char *argv[])
{

    Node<int>* newNode = new Node<int>(30);
    cout << "valor armazenado no no: (30) " << newNode->memory() << endl;

    List<string> l;

    l.insert_final("C++");
    l.insert_final("PHP");
    l.insert_final("GO");
    l.insert_final("JAVA");
    l.insert_init("Angular");

    l.show();

    cout << "has GO: " << l.has("GO") << endl;

    l.remove();
    l.show();

    cout << "quantidade " << l.length() << endl;

    return 0;
}
