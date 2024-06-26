#include <iostream>
using namespace std;

class  Node{
    public:
    Node *left;
    Node *right;
    int key;

    Node()
    {
        left = right = NULL;
    };
};

class BST{
    public:
    Node *root;

    BST(){
        root = NULL;
    }

    Node* insertRecursive(int inputKey, Node *currentRoot)
    {

        if(currentRoot == NULL)
        {
            Node *newNode = new Node();
            newNode->key = inputKey;
            return newNode;
        }
        if(inputKey < currentRoot->key){
            currentRoot->left = insertRecursive(inputKey, currentRoot->left);
        }
        else if(inputKey > currentRoot->key){
            currentRoot->right = insertRecursive(inputKey, currentRoot->right);
        }
        return currentRoot;
    }
    void insert(int inputKey)
    {
        root = insertRecursive(inputKey, root);
    }

    void *preOrderTravelsal(Node *currentNode)
    {
        if(currentNode != NULL)
        {
            cout << currentNode->key <<"";
            preOrderTravelsal(currentNode->left);
            preOrderTravelsal(currentNode->right);
        }
    }
    void preOrder()
    {
        cout <<"Pree Order Travelsar: ";
        preOrderTravelsal(root);
        cout << endl;
    }

    void *inOrderTravelsal(Node *currentNode)
    {
        if(currentNode != NULL)
        {
            preOrderTravelsal(currentNode->left);
            cout << currentNode->key <<"";
            preOrderTravelsal(currentNode->right);
        }
    }
     void inOrder()
     {
        cout <<"in Order Travelsar: ";
        inOrderTravelsal(root);
        cout << endl;
     }

     void *postOrderTravelsal(Node *currentNode)
    {
        if(currentNode != NULL)
        {
            postOrderTravelsal(currentNode->left);
            postOrderTravelsal(currentNode->right);
            cout << currentNode->key <<"";
           
         }
     }

    void postOrder()
    {
        cout <<"Post Order Travelsar: ";
        postOrderTravelsal(root);
        cout << endl;
    }

};

int main(int argc, char**argv) {

    BST *bin1 = new BST();

    bin1->insert(6);
    bin1->insert(7);
    bin1->insert(4);
    bin1->insert(8);
    bin1->insert(5);
    bin1->insert(3);

    bin1->preOrder();
    bin1->inOrder();
    bin1->postOrder();
    return 0;
};
