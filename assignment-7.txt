#include <iostream>
using namespace std;

class Graph
{
    int n;
    int adj[20][20];
    bool visited[20];

    void dfsVisit(int v)
    {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && !visited[i])
                dfsVisit(i);
        }
    }

public:

    Graph() : n(0)
    {
        for (int i = 0; i < 20; i++)
        {
            visited[i] = false;

            for (int j = 0; j < 20; j++)
                adj[i][j] = 0;
        }
    }

    void createGraph()
    {
        cout << "Enter number of intersections (1-20): ";
        cin >> n;

        if (n < 1 || n > 20)
        {
            cout << "Invalid number of intersections.\n";
            n = 0;
            return;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                adj[i][j] = 0;
        }

        int roads;

        cout << "Enter number of roads: ";
        cin >> roads;

        if (roads < 0)
        {
            cout << "Invalid road count.\n";
            n = 0;
            return;
        }

        for (int k = 0; k < roads; k++)
        {
            int u, v;

            cout << "Enter road (intersection1 intersection2): ";
            cin >> u >> v;

            if (u < 0 || v < 0 || u >= n || v >= n)
            {
                cout << "Invalid intersection; enter again.\n";
                k--;
                continue;
            }

            adj[u][v] = adj[v][u] = 1;
        }
    }

    void displayGraph() const
    {
        if (n == 0)
        {
            cout << "Create graph first.\n";
            return;
        }

        cout << "Adjacency Matrix:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << adj[i][j] << " ";

            cout << "\n";
        }
    }

    void DFS(int start)
    {
        if (start < 0 || start >= n)
        {
            cout << "Invalid starting intersection.\n";
            return;
        }

        for (int i = 0; i < n; i++)
            visited[i] = false;

        cout << "DFS traversal: ";

        dfsVisit(start);

        cout << "\n";
    }
};

int main()
{
    Graph cityRoad;

    cityRoad.createGraph();

    cityRoad.displayGraph();

    int start;

    cout << "Enter starting intersection: ";
    cin >> start;

    cityRoad.DFS(start);

    return 0;
}
