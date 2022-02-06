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
        this->queue.push_back(q);
    }

    bool emptied()
    {
        return this->queue.empty();
    }

    T remove()
    {
        if(!this->emptied()) {
            T q = this->queue.front();
            this->queue.pop_front();
            return q;
        }
        throw "fila Vazia";
    }

    T front()
    {
        if(!this->emptied()) {
            return this->queue.front();
        }
        throw "fila vazia";
    }

    T final()
    {
        if(!this->emptied()) {
            return this->queue.back();
        }
        throw "fila vazia";
    }

    T size()
    {
        return this->queue.size();
    }
};

template<typename T> T sum(T number1, T number2)
{
    return number1 + number2;
}

template<typename T> void print(T msg) {
    cout << msg << endl;
};

int main(int argc, char *argv[])
{
    
    cout << "SUM 1 + 2 : " << sum(1, 2) << endl;
    cout << "SUM 3.8 + 5.2 : " << sum(3.8, 5.2) << endl;

    cout << "Antes de inserir elementos " << endl;
    Queue<double> Q1;

    if(Q1.emptied()) {
        print("Fila vazia");
    }

    try
    {
        double e = Q1.remove();
        print("Elemento removido");
    }
    catch(const char *msg)
    {
        cerr << "Error: " << msg << endl;
    }

    Q1.insert(1.2);
    Q1.insert(2.3);
    Q1.insert(3.4);
    Q1.insert(4.5);

    print("depois de inserir elementos");

    if(!Q1.emptied()) {
        print("fila Cheia");
    }

    cout << "front: " << Q1.front() << endl;
    cout << "front: " << Q1.final() << endl;

    try
    {
        cout << "elemento reomovido " << Q1.remove() << "  tamanho: " << Q1.size() << endl;
    }
    catch(const char *msg)
    {
        cerr << "Erro: " << msg << endl;;
    }


    Queue<string> Q2;

    Q2.insert("c++");
    Q2.insert("php");
    Q2.insert("javascript");
    Q2.insert("Java");
    Q2.insert("angular");
    
    try { 
        cout << "Frente: " << Q2.front() << endl;
    } catch(const char *msg) {
        cerr << "Error: " << msg << endl;
    }


    system("pause");

    return 0;
}
