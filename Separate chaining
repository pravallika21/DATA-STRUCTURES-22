#include <cstddef>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
typedef struct node Node;
class DoubleLL
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    DoubleLL()
    {
        head = tail = NULL;
        size = 0;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void insert(int val)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = val;
        newNode->prev = newNode->next = NULL;
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }
    // This function will return the address of the element in list or else NULL
    Node *search(int value)
    {
        Node *temp = head;
        for (size_t i = 0; i < size; i++)
        {
            if (temp->data == value)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

    void del(int value)
    {
        Node *t = search(value);
        //cout << t << endl;
        if (t != NULL)
        {
            Node *prevNode = t->prev;
            Node *nextNode = t->next;
            //Node * nextNode = t->next->next;
            if (nextNode != NULL)
                nextNode->prev = prevNode;
            else{
                tail = prevNode;
            }
            if (prevNode != NULL)
                prevNode->next = nextNode;
            else{
                head = nextNode;
            }
            free(t);
        }
    }
};
void display(DoubleLL list[],int size){
    for(int i=0;i<size;i++){
        cout<< i << "-->";
        list[i].display();
       
    }
}
int main(int argc, char const *argv[])
{
    int size;
    cout<<"Enter the size of the HashTable"<<endl;
    cin >> size;
    DoubleLL list[size];
    cout << "1.Insert \n 2. Remove \n 3. Search \n 4. Any other to Quit" << endl;
    while (1)
    {
        int choice;
        cout<<"Choose from menu: ";
        cin >> choice;
        int element;
        cout<<"Enter the Key"<<endl;
        cin >> element;
        int hashIndex = element % size;
        switch (choice)
        {
        case 1:
            list[hashIndex].insert(element);
            display(list,size);
            break;
        case 2:
            list[hashIndex].del(element);
            display(list,size);
            break;
        case 3:
            if (list[hashIndex].search(element) != NULL)
                cout << "Found" << endl;
            else
                cout << "Not Found <<endl";
            break;
        default:
            exit(0);
        }
    }    
    return 0;
}
