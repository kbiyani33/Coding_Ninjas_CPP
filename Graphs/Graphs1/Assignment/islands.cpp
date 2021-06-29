/*

An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.

Input Format :
    The first line of input contains two integers, that denote the value of V and E.
    Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 

Output Format :
    Print the count the number of connected groups of islands

Constraints :
    0 <= V <= 1000
    0 <= E <= (V * (V-1)) / 2
    0 <= a <= V - 1
    0 <= b <= V - 1
    Time Limit: 1 second

Sample Input 1:
    5 8
    0 1
    0 4
    1 2
    2 0
    2 4
    3 0
    3 2
    4 3
Sample Output 1:
    1 
    
*/
#include<iostream>
#include<queue>

using namespace std;

void BFS(int** edges, int n, int start, bool* visited){
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(! q.empty()){
        int node = q.front();
        q.pop();

        for(int i=0; i<n; i++){
            if(edges[node][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    int V, E;
    cin >> V >> E;

    int **adj = new int*[V];
    for(int i=0; i<V; i++){
        adj[i] = new int[V];
        for(int j=0; j<V; j++){
            adj[i][j] = 0;
        }
    }

    for(int i=0; i<E; i++){
        int s, f;
        cin >> s >> f;
        adj[s][f] = 1;
        adj[f][s] = 1; 
    }

    bool* visited = new bool[V];

    for(int i=0; i<V; i++)
        visited[i] = false;
    
    int count = 0;
    for(int i=0; i<V; i++){
        if(! visited[i]){
            count += 1;
            BFS(adj, V, i, visited);
        }
    }

    cout << count << endl;

    for(int i=0; i<V; i++){
        delete[] adj[i];
    }
    delete[] adj;
    delete[] visited;

    return 0;

}
