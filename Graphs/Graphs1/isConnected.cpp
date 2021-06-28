/*
Given an undirected graph G(V,E), check if the graph G is connected graph or not.

Note:
    1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
    2. E is the number of edges present in graph G.

Input Format :
    The first line of input contains two integers, that denote the value of V and E.
    Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.

Output Format :
    The first and only line of output contains "true" if the given graph is connected or "false", otherwise.

Constraints :
    0 <= V <= 1000
    0 <= E <= (V * (V - 1)) / 2
    0 <= a <= V - 1
    0 <= b <= V - 1
    Time Limit: 1 second

Sample Input 1:
    4 4
    0 1
    0 3
    1 2
    2 3
Sample Output 1:
    true
Sample Input 2:
    4 3
    0 1
    1 3 
    0 3
Sample Output 2:
    false 
    Sample Output 2 Explanation
        The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
*/

#include<iostream>
#include<queue>
using namespace std;


void BFS(int** edges, int n, int start, bool* visited, int* count){
    queue<int> q;
    q.push(start);
    *(count) += 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        visited[node] = true;

        for(int i=0; i<n; i++){
                
            if(edges[node][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
                *(count) += 1;
            }
        }
    }
}

bool isConnected(int** edges, int n){
    
    if(n == 0)
        return true;
    
    bool* visited = new bool[n];
    int count = 0;

    BFS(edges, n, 0, visited, &count);
    //DFS(edges, n, 0, visited, count);
    if(count == n)
        return true;
    
    return false;
}

int main(){
    int V, E;
    cin >> V >> E;

    int **adjacency = new int*[V];
    for(int i=0; i<V; i++){
        adjacency[i] = new int[V];
        for(int j=0; j<V; j++){
            adjacency[i][j] = 0;
        }
    }

    for(int i=0; i<E; i++){
        int src, tgt;

        cin >> src >> tgt;

        adjacency[src][tgt] = 1;
        adjacency[tgt][src] = 1;
    }

    cout << boolalpha << isConnected(adjacency, V);
}