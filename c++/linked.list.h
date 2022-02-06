#define _LIST_H

using namespace std;


template<class T>
class Node
{
private:
    T spaceMemory;
    Node* next;
public:
    Node(T spacaMemory)
    {   
        this->spaceMemory = spacaMemory;
        this->next = NULL;
    }

    T memory()
    {
        return this->spaceMemory;
    }

    Node* get()
    {
        return this->next;
    }

    Node* set(Node* next)
    {
        return this->next = next;
    }
};


template <class T>
class List
{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    List()
    {
        this->head = NULL;
        this->tail = NULL;
    }

     List(T spaceMemory)
    {
        this->head = new Node<T>(spaceMemory);
        this->tail = this->head;
    }

    virtual ~List()
    {
        delete this->head;
    }

    void show()
    {
        Node<T>* h = this->head;

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

    void insert_init(T spaceMemory)
    {
        Node<T>* newNode = new Node<T>(spaceMemory);
        newNode->set(this->head);
        this->head = newNode;
    }

    void insert_final(T spaceMemory)
    {
        Node<T>* newNode = new Node<T>(spaceMemory);

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

        Node<T>* h = this->head;

        int len = 0;

        do {

            h = h->get();
            len++;

        } while(h);

        return len;

    }

    bool has(T spaceMemory)
    {
        Node<T>* h = this->head;
        while(h)
        {
            if(h->memory() == spaceMemory) {
               return true; 
            } else {
                h = h->get();
            }
        };
        return false;
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

                Node<T>* ant_ant = this->head;
                Node<T>* ant = this->head->get();
                Node<T>* current  = this->head->get()->get();

                while(current) {
                    Node<T>* aux = ant;
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