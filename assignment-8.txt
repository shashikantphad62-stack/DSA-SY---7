#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    vector<vector<int>> adj;

public:

    void createGraph()
    {
        int n, edges;

        cout << "Enter number of users: ";
        cin >> n;

        if (n <= 0)
        {
            cout << "Invalid number of users.\n";
            return;
        }

        adj.assign(n, {});

        cout << "Enter number of friendships: ";
        cin >> edges;

        if (edges < 0)
        {
            cout << "Invalid count.\n";
            adj.clear();
            return;
        }

        for (int i = 0; i < edges; ++i)
        {
            int u, v;

            cout << "Enter friendship (user1 user2): ";
            cin >> u >> v;

            if (u < 0 || v < 0 || u >= n || v >= n)
            {
                cout << "Invalid user ID; try again.\n";
                --i;
                continue;
            }

            adj[u].push_back(v);

            if (u != v)
                adj[v].push_back(u);
        }
    }

    void displayGraph() const
    {
        if (adj.empty())
        {
            cout << "Create a graph first.\n";
            return;
        }

        cout << "Adjacency list:\n";

        for (int i = 0; i < (int)adj.size(); ++i)
        {
            cout << i << " -> ";

            for (int friendId : adj[i])
                cout << friendId << " ";

            cout << "\n";
        }
    }

    void BFS(int start) const
    {
        int n = (int)adj.size();

        if (start < 0 || start >= n)
        {
            cout << "Invalid starting user.\n";
            return;
        }

        vector<bool> visited(n, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS traversal: ";

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int next : adj[current])
            {
                if (!visited[next])
                {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }

        cout << "\n";
    }
};

int main()
{
    Graph socialNetwork;
    int choice = 0;

    do
    {
        cout << "\n===== SOCIAL NETWORK =====\n"
             << "1. Create Graph\n"
             << "2. Display Adjacency List\n"
             << "3. Perform BFS\n"
             << "4. Exit\n"
             << "Enter choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            socialNetwork.createGraph();
            break;

        case 2:
            socialNetwork.displayGraph();
            break;

        case 3:
        {
            int start;

            cout << "Enter starting user: ";
            cin >> start;

            socialNetwork.BFS(start);
            break;
        }

        case 4:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
