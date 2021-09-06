#define MAX 15
#include <iostream>
using namespace std;

class Hashtable
{
    private:
        int *ht;
        int size;
    public:
        Hashtable()
        {
            cout<<"Enter size:";
            cin>>size;
            ht=(int *)calloc(size,sizeof(int));
        }
    int hashkey(int val)
    {
        int i=val%size;
        return i;
    }
    int insert(int val)
    {
        int i=hashkey(val);
        for(int j=0;j<size;j++)
        {
            if(ht[(i+j)%size]==0)
                ht[(i+j)%size]=val;
            break;    
        }
    }
    int search(int val)
    {
        int i=hashkey(val);
        for(int j=0;j<size;j++)
        {
        if (ht[(i+j)%size]==val)
            return ht[(i+j)%size];
        else
            cout<<"Element not found";
            return -1;
        }
    }
    void remove(int val)
    {
        int key=search(val);
        if (key==-1)
            cout<<"Element not present in table";
        else
            ht[key]=0;
            cout<<"Element deleted";
    }
    void display()
    {
        for (int i=0;i<size;i++)
        {
            cout<<i<<"\t"<<ht[i]<<"\n";
        }
    }
};
int main()
{
    Hashtable obj;
    int a[10]={56,25,54,20,22,21,51,89,36,45};
    for(int i=0;i<10;i++)
        obj.insert(a[i]);
    obj.display();
}
