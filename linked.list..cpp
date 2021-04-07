#include <iostream>

using namespace std;

class Node
{
private:
    int spaceMemory;
    Node* next;
public:
    Node(int spacaMemory)
    {
        this->spaceMemory = spaceMemory;
        this->next = NULL;
    }

    int memory()
    {
        return this->spaceMemory;
    }

    Node* get()
    {
        return this->next;
    }

    Node* set(Node* next)
    {
        this->next = next;
    }

};


class List
{
private:
    Node* head;
    Node* tail;
public:
    List()
    {
        this->head = NULL;
        this->tail = NULL;
    }

     List(int spaceMemory)
    {
        this->head = new Node(spaceMemory);
        this->tail = this->head;
    }

    virtual ~List()
    {
        delete this->head;
    }

    void show()
    {
        Node* h = this->head;

        if(this->empty()) {
            cout << "LIst void" << endl;
        } else {

            while (h)
            {
                cout << "item: " << h->memory() << endl;
                h = h->get();
            }
            

        }
        
        cout << "" << endl;
    }

    bool empty()
    {
        return (this->head == NULL);
    }

    void insert_init(int spaceMemory)
    {
        Node* newNode = new Node(spaceMemory);
        newNode->set(this->head);
        this->head = newNode;
    }

    void insert_final(int spaceMemory)
    {
        Node* newNode = new Node(spaceMemory);

        if(this->empty()) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            this->tail->set(newNode);
            this->tail = newNode;
        }
    }

    int length()
    {
        if(this->empty())
        {
            return 0;
        }

        Node* h = this->head;

        int len = 0;

        do {

            h = h->get();
            len++;

        } while(h);

    }

    bool has(int spaceMemory)
    {
        Node* h = this->head;
        while(h)
        {
            if(h->memory() == spaceMemory) {
               return true; 
            } else {
                h = h->get();
            }
        }
    }

    void remove()
    {
        if(!this->empty()) 
        {
            if(this->head->get() == NULL) {
                this->head = NULL;
            } else if(this->head->get()->get() == NULL) {
                this->head->set(NULL);
            } else {

                Node* ant_ant = this->head;
                Node* ant = this->head->get();
                Node* current  = this->head->get()->get();

                while(current) {
                    Node* aux = ant;
                    ant = current;
                    ant_ant = aux;
                    current = current->get();
                }

                delete ant_ant->get();
                ant_ant->set(NULL);
                this->tail = ant_ant;

            }
        }
    }


};

int main(int argc, char *argv[])
{
    


    return 0;
}
