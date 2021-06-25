
#include <stdlib.h>
#include <stdio.h>

#include <iostream>
using namespace std;
#define new_node (struct node*)malloc(sizeof(struct node))
struct node
{
    int vertex;
    struct node *next;
};
 
int main()
{
    int option;
    
    do
    {
        cout<<"\n A Program to represent a Graph by using an Adjacency List \n ";
        cout<<"\n 1. Directed Graph ";
        cout<<"\n 2. Un-Directed Graph ";
        cout<<"\n 3. Exit ";
        cout<<"\n\n Select a proper option : ";
        cin>>option;
        switch(option)
        {
            case 1 : dir_graph();
                     break;
            case 2 : undir_graph();
                     break;
            case 3 : exit(0);
        }
    }while(1);
    return 0;
}

int dir_graph()
{
    struct node *adj_list[10], *p;
    int n;
    int in_deg, out_deg, i, j;
 
    cout<<"\n How Many Vertices ? : ";
    cin>>n;
 
    for( i = 1 ; i <= n ; i++ )
        adj_list[i] = NULL;
 
    read_graph (adj_list, n);
 
    cout<<"\n Vertex \t In_Degree \t Out_Degree \t Total_Degree ";
 
    for (i = 1; i <= n ; i++ )
    {
        in_deg = out_deg = 0;
        p = adj_list[i];
 
        while( p != NULL )
        {
            out_deg++;
            p = p -> next;
        }
 
        for ( j = 1 ; j <= n ; j++ )
        {
            p = adj_list[j];
 
            while( p != NULL ) 
            {
                if ( p -> vertex == i )
                   in_deg++;
                p = p -> next;
            }
        }
             cout<<"\n\n "<<i<<"\t\t\t"<<in_deg<<"\t\t"<<out_deg<<"\t\t"<<(in_deg+out_deg)<<"\n\n";
    } 
    return;
}
int undir_graph()
{
    struct node *adj_list[10], *p;
    int deg, i, j, n;
    cout<<"\n How Many Vertices ? : ";
    cin>>n;
    
	for ( i = 1 ; i <= n ; i++ )
        adj_list[i] = NULL;
    
	read_graph(adj_list, n);
    
	cout<<"\n Vertex \t Degree ";
	for ( i = 1 ; i <= n ; i++ )
    {
        deg = 0;
        p = adj_list[i];
        while( p != NULL )
	{
            deg++;
            p = p -> next;
        }
        cout<<"\n\n"<<i<<"\t\t "<<deg<<"\n\n";
    }
    return;
} 
int read_graph ( struct node *adj_list[10], int n )
{
    int i, j;
    char reply;
    struct node *p, *c;
    for ( i = 1 ; i <= n ; i++ )
    {
        for ( j = 1 ; j <= n ; j++ )
        {
            if ( i == j )
                continue;
            printf("\n Vertices %d & %d are Adjacent ? (Y/N) :", i, j);
            scanf("%c", &reply);
            if ( reply == 'y' || reply == 'Y' )
            {
                c = new_node;
                c -> vertex = j;
                c -> next = NULL;
                if ( adj_list[i] == NULL )
                    adj_list[i] = c;
                else
                {
                    p = adj_list[i];
                    while ( p -> next != NULL )
                        p = p -> next;
                    p -> next = c;
		} 
            }
        } 
    }
    return;
}
