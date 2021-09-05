#include <iostream>
using namespace std;
int find(int);
int uni(int, int);
int parent[9];
int main()
{

    int i, j, k, a, b, u, v, n, ne = 1;
    int min, mincost = 0, cost[9][9];
    cout << "\n\n\tImplementation of Kruskal's algorithm\n\n";
    cout << "\nEnter the no. of vertices\n";
    cin >> n;
    cout << "\nEnter the cost adjacency matrix\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    cout << "\nThe edges of Minimum Cost Spanning Tree are\n\n";
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v))
        {
            cout << "\n"
                 << ne++ << " edge (" << a << "," << b << " =" << min << " )" << endl;
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    cout << "\n\tMinimum cost = " << mincost << endl;
    return 0;
}
int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}
int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}
