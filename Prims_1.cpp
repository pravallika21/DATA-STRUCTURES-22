#include <iostream>
using namespace std;
int main()
{

    int a, b, u, v, n, i, j, ne = 1, x;
    int visited[10] = {0}, min, mincost = 0, cost[10][10];
    cout << "\n Enter the number of nodes:" << endl;
    cin >> n;
    cout <<"\n Enter the adjacency matrix:\n";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> cost[i][j];
    cout <<"enter the starting vertex";
    cin >> x;
    visited[x] = 1;
    cout << endl;
    while (ne < n)
    {
        min = 999;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] && ((visited[i] && !visited[j]) || (visited[j] && !visited[i])))
                {
                    if (cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        cout << ne++ << " edge (" << a << "," << b << " =" << min << " )" << endl;
        mincost += min;
        visited[b] = visited[a] = 1;
    }
    cout << "\n Minimun cost=" << mincost << endl;
    return 0;
}
