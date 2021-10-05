#include <iostream>
#include <deque>

using namespace std;

int main(int argc, char *argv[]) {

    deque<int> queue;

    cout << "Antes de inserir os elementos" << endl;

    if (queue.empty()) {
        cout << "Fila vazia" << endl;
    } else {
        cout << "fila não vazia" << endl;
    }
    

    queue.push_back(10);
    queue.push_back(20);
    queue.push_front(30);

    cout << "depois de inseridos" << endl;

    deque<int>::iterator it = queue.begin();

    while (it != queue.end())
    {
        cout << *it++ << " " << endl;
    }
    
    cout << "\n" << endl;

    queue.erase(queue.begin() + 1);

    it = queue.begin();

    while (it != queue.end())
    {
        cout << *it++ << " " << endl;
    }


    cout << "primeiro: " << queue.front() << endl;
    cout << "ultimo: " << queue.back() << endl;

    it = queue.begin() + 1;

    queue.insert(it, 10);
    
    it = queue.begin();

    while (it != queue.end())
    {
        cout << *it++ << " " << endl;
    }

    queue.pop_front();
    queue.pop_back();

    it = queue.begin();

    while (it != queue.end())
    {
        cout << *it++ << " tamanho: " << queue.size() << endl;
    }


    queue.clear();

    return 0;
}