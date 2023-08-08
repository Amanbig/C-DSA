#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, int current, vector<bool>& visited) {

     // Mark the current node as visited
    visited[current] = true;
    // Print the node 
    cout << current << " ";   

    // Visit all adjacent nodes of the current node that have not been visited
    for (int i = 0; i < graph[current].size(); i++) {
        int adjacentNode = graph[current][i];
        if (!visited[adjacentNode]) {
            // Recursive call to visit the adjacent node
            dfs(graph, adjacentNode, visited);  
        }
    }
}

void dfsTraversal(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    // Keep track of visited nodes
    vector<bool> visited(n, false);  

    // Start DFS from the given starting node
    dfs(graph, start, visited);
}

 void toString(int numVertices, vector<vector<int>>& adjMatrix) {
     for (int i = 0; i < numVertices; i++) {
       cout << i << " : ";
       for (int j = 0; j < numVertices; j++)
         cout << adjMatrix[i][j] << " ";
       cout << "\n";
     }
   }

int main() {
    system("cls");
    int n, e;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> graph(n);

st:
    cout << "\nIs the graph: \n1.Directed\n2.Undirected\n";
    int b;
    cin >> b;
    switch (b)
        {
        case 1:
            cout << "\nEnter the edges: \n";
            for (int i = 0; i < e; i++) {
                int src, dest;
                cin >> src >> dest;
                graph[src].push_back(dest);
            }
            break;
        case 2:
            cout << "\nEnter the edges: \n";
            for (int i = 0; i < e; i++) {
                int src, dest;
                cin >> src >> dest;
                graph[src].push_back(dest);
                graph[dest].push_back(src);
            }
            break;
        default :
            cout << "\nInvalid Input\n";
            goto st;
        }

    cout << "\nRepresentation of the graph:\n";
    // Generate ASCII representation of the graph
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j];
            if (j < graph[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    int startNode;
    cout << "\nEnter the starting node: ";
    cin >> startNode;

    cout << "\nDFS traversal starting from node " << startNode << ": ";
    dfsTraversal(graph, startNode);
    cout << "\n";
    return 0;
}