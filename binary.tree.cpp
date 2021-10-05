#include <iostream>

using namespace std;

class Node
{
private:
    Node *left, *right;
    int key;
public:
    Node(int key) 
    {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }

    int getKey()
    {
        return this->key;
    }

    Node* getLeft()
    {
        return this->left;
    }

    Node* getRight()
    {
        return this->right;
    }

    void setLeft(Node* node)
    {
        this->left = node;
    }

    void setRight(Node* node)
    {
        this->right = node;
    }

};

class Tree
{
private:
    Node* root;
public:
    Tree()
    {
        this->root = NULL;
    }
    void insert(int key)
    {
        if(this->root == NULL) {
            this->root = new Node(key);
        } else {
            this->insertAux(this->root, key);
        }
    }

    void insertAux(Node* node, int key)
    {
        if(key < node->getKey()) {

            if(node->getLeft() == NULL) {
                Node* n = new Node(key);
                node->setLeft(n);
            } else {
                this->insertAux(node->getLeft(), key);
            }

        } else if(key > node->getKey()) {
            
            if(node->getRight() == NULL) {
                Node* n = new Node(key);
                node->setRight(n);
            } else {
                this->insertAux(node->getRight(), key);
            }

        }
    }

    Node* getRoot()
    {
        return this->root;
    }

    void ordered(Node* node)
    {
        if(node != NULL) {
            this->ordered(node->getLeft());
            cout << node->getKey() << " ";
            this->ordered(node->getRight());
        }
    }

};

int main(int argc, char const *argv[])
{

    Tree tree;

    tree.insert(8);
    tree.insert(10);
    tree.insert(14);
    tree.insert(13);
    tree.insert(3);
    tree.insert(1);
    tree.insert(6);
    tree.insert(4);
    tree.insert(7);

    tree.ordered(tree.getRoot());
    
    cout << endl;
    cout << endl;

    system("pause");
    return 0;

}