#include<algorithm>
#include <iostream>
#include <vector>
#include <list>
using namespace std;
class Graph
{
public:
    int V;
    int E;
    vector<pair<int, pair<char, char> > > edges;
    int *parent;
    

    Graph(int V, int E)
    {
        this->E = E;
        this->V = V;
        parent = new int[V + 1];
        for (int i = 0; i <= V; i++)
        {
            parent[i] = i+65;
        }
    }
    int find(char u)
    {
        if (u != parent[u-65])
            parent[u-65] = find(parent[u-65]);
        return parent[u-65];
    }

    void simpleUnion(int u, int v){
        u = find(u);
        v = find(v);
        parent[u-65] = v;
    }
    void addEdge(int w, char u, char v)
    {
        edges.push_back(make_pair(w, make_pair(u, v)));     

    }
    void display(){
        vector<pair<int, pair<char ,char > > >::iterator it;
        for (it = edges.begin(); it != edges.end(); it++)
        {
            cout << it->first << " : " << it->second.first << " - " << it->second.second << endl;
        }
    }
    int minimalSpanningTree();
};

Graph initializeGraph(Graph myGraph, int E)
{
    char u, v;
    int w;
    for (int j = 0; j < E; j++)
    {
        cout << "Enter weight, starting vertex and ending vertex" << endl;
        cin >> w >> u >> v;
        myGraph.addEdge(w, u, v);
    }
    return myGraph;
}
int Graph::minimalSpanningTree()
    {
        int totalCost = 0;
        sort(edges.begin(), edges.end());
        vector<pair<int, pair<char ,char > > >::iterator it;
        for (it = edges.begin(); it != edges.end(); it++)
        {            
            char  u = it->second.first;
            char  v = it->second.second;
            int  u1 = find(u);
            int  v1 = find(v);
            if (u1 != v1)
            {
                cout << u << " - " << v << endl;
                totalCost += it->first;
                simpleUnion(u1, v1);
            }
        }
        return totalCost;
    }
int main()
{
    int V, E;
    cout << "Enter number of vertices and edges in graph " <<endl;
    cin >> V >> E;
    Graph myGraph(V, E);
    myGraph = initializeGraph(myGraph, E);
    myGraph.display();
    int cost = myGraph.minimalSpanningTree();
    cout << "Minimal Cost is :" << cost << endl;
    return 0;
}
