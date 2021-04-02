#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) 
{ 

    ifstream in("audio.cpp");
    string text;
    char c = in.get();
    text.push_back(c);

    cout << "\nMostando cada char" << endl;

    while (in.good())
    {
        cout << c;
        c = in.get();
        text.push_back(c);
    }
    
    cout << "\n\nMostando a string (text): " <<  text <<endl;
    
    
    /*=======================ESCREVENDO UM ARQUIVO ====================================================*/

    ofstream output("flow-io.txt");
    output << "FLOW OUTUPUT\n";
    output << "NEW LINE OUTPUT\n";
    /* ===============================================================*/


    ifstream in("flow-io.txt");
    while (true)
    {
        if(in.fail()) {
            break;
        } 

        cout << c;
    }
    



    
    system("pause");

    return 0;
}