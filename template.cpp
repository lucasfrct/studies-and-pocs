#include <iostream>
#include <list>

using namespace std;

template<class T>
class Queue
{
private:
    list<T> queue;
public:
    void insert(const T &q)
    {
        this.queue.push_back(q);
    }

    bool emptied()
    {
        return this.queue.empty();
    }

    T remove()
    {
        if(!this.emptied()) {
            T q = this.queue.front();
            this.queue.pop_front();
            return q;
        }
    }

    T front()
    {
        if(!this.emptied()) {
            return this.queue.front();
        }
        throw "fila vazia";
    }

    T final()
    {
        if(!this.emptied()) {
            return this.queue.back();
        }
        throw "fila vazia";
    }

    T size()
    {
        return this.queue.size();
    }
};

template<typename T> T sum(T number1, T number2)
{
    return number1 + number2;
}

int main(int argc, char *argv[])
{
    
    cout << "SUM 1 + 2 : " << sum(1, 2) << endl;
    cout << "SUM 3.8 + 5.2 : " << sum(3.8, 5.2) << endl;

    cout << "Antes de inserir elementos " << endl;

    Queue<int> Q1;


    system("pause");

    return 0;
}
