/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//#include <stdlib>
#include <iostream>

using namespace std;
int *H;
int size;
int hashf(int val)
{
    int i;
    i=val%size;
    return i;
}
void insert()
{
    int val;
    cout<<"Enter the element to be inserted";
    cin>>val;
    int i=hashf(val);
    H[i]=val;
}
void del()
{
    int val;
    cout<<"Enter the elemente dto be deleted";
    cin>>val;
    int i=hashf(val);
    if(H[i]==val)
    {
        H[i]=0;
        cout<<"Deleted successfully";
    }
}
void search()
{
    int val;
    cout<<"Enter the search element";
    cin>>val;
    int i=hashf(val);
    if(H[i]==val)
        cout<<"Found";
    else
        cout<<"NotFound";
}
int main()
{
    cout<<"Enter the size";
    cin>>size;
    H=(int *)calloc(size,sizeof(int));
    while(true)
    {
        cout<<"1.Insert\n 2.Delete\n 3.Search \n 4.Exit"<<endl;
        char ch;
        cin>>ch;
        switch(ch)
        {
            case'1':insert();
                        break;
            case'2':del(); 
                    break;
            case'3':search();
                    break;
            case'4':exit(0);
            default:cout<<"Invalid Input";
        }
    }

    return 0;
}


