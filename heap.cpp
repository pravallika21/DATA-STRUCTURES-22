#include <iostream>
using namespace std;
class Heap
{
private:
    int *heap;
    int size;

public:
    Heap(int size = 20)
    {
        this->size = 0;
        heap = (int *)calloc(size, sizeof(int));
    }
    void insert(int val)
    {
        int child, parent, temp;
        child = ++size;
        heap[child] = val;
        parent = child / 2;
        printf(" %d :%d ", parent, heap[parent]);
        while (parent > 0)
        {
            if (heap[parent] > heap[child])
            {
                temp = heap[parent];
                heap[parent] = heap[child];
                heap[child] = temp;
            }
            else
            {
                break;
            }
            child = parent;
            parent = child / 2;
        }
        display();
    }
    void reHeapify()
    {
        int parent, child;
        parent = 1;
        if (size == 1)
            return;
        else if (size == 2)
            child = 2 * parent;
        else
        {
            if (heap[2 * parent] < heap[2 * parent + 1])
                child = 2 * parent;
            else
                child = 2 * parent + 1;
        }
        while (child <= size)
        {
            if (heap[parent] > heap[child])
            {
                int t;
                t = heap[parent];
                heap[parent] = heap[child];
                heap[child] = t;
            }
            parent = child;
            child = 2 * parent;
            if (child < size && heap[child] > heap[child + 1])
                child += 1;
        }
    }
    int deleteHeap()
    {
        if (size > 0)
        {
            heap[1] = heap[size--];
            reHeapify();
        }
        else
            printf("Cannot be deleted\n");
        return size;
    }
    void display()
    {
        cout << "The contents of heap are :" << endl;
        for (int i = 1; i <= size; i++)
        {
            cout << " " << heap[i];
        }
        cout << endl;
    }
    int extractMin()
    {
        if (size > 0)
            return heap[0];
        else
            return -1;
    }
};
int main(int argc, char const *argv[])
{
    Heap myHeap;
    cout << "1.Insert \n 2. Remove \n 3. FindMin \n 4. Any other to Quit" << endl;
    while (1)
    {
        int choice,temp;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int ele;
            cin >> ele;
            myHeap.insert(ele);
            break;
        case 2:
            myHeap.deleteHeap();
            break;
        case 3:
            temp = myHeap.extractMin();
            if (temp != -1)
                cout << "Minimum element is "<< temp << endl;
            else
                cout << "Heap is empty " <<endl;
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
