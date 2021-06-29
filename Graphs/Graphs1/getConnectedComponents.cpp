/*

Given an undirected graph G(V,E), find and print all the connected components of the given graph G.

Note:
    1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
    2. E is the number of edges present in graph G.
    3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
    Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.

Input Format :
    The first line of input contains two integers, that denote the value of V and E.
    Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.

Output Format :
    Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order of different components doesn't matter.

Constraints :
    0 <= V <= 1000
    0 <= E <= (V * (V - 1)) / 2
    0 <= a <= V - 1
    0 <= b <= V - 1

Sample Input 1:
    4 2
    0 1
    2 3
Sample Output 1:
    0 1 
    2 3 
Sample Input 2:
    4 3
    0 1
    1 3 
    0 3
Sample Output 2:
    0 1 3 
    2
    
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> BFS(int** edges, int n, int start, bool* visited){
    vector<int> output;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int node = q.front();
        output.push_back(node);
        q.pop();
        for(int i=0; i<n; i++){
            if(i == node)
                continue;
            if(edges[node][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return output;
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
    for(int i=0; i<V; i++){
        visited[i] = false;
    }

    for(int i=0; i<V; i++){
        if(! visited[i]){
            vector<int> connected = BFS(adj, V, i, visited);
            sort(connected.begin(), connected.end());
            for(int i=0; i<connected.size(); i++)
                cout << connected.at(i) << " ";
            cout << endl;
        }
    }

    // Deletion
    for(int i=0; i<V; i++){
        delete[] adj[i];
    }
    delete[] adj;
    delete[] visited;
    return 0;
}