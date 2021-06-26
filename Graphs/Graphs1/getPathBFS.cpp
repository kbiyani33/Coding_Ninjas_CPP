/*
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.

Note:
    1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
    2. E is the number of edges present in graph G.
    3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
    4. Save the input graph in Adjacency Matrix.

Input Format :
    The first line of input contains two integers, that denote the value of V and E.
    Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
    The following line contain two integers, that denote the value of v1 and v2.

Output Format :
    Print the path from v1 to v2 in reverse order.

Constraints :
    2 <= V <= 1000
    1 <= E <= (V * (V - 1)) / 2
    0 <= a <= V - 1
    0 <= b <= V - 1
    0 <= v1 <= 2^31 - 1
    0 <= v2 <= 2^31 - 1
    Time Limit: 1 second

Sample Input 1 :
    4 4
    0 1
    0 3
    1 2
    2 3
    1 3
Sample Output 1 :
    3 0 1
Sample Input 2 :
    6 3
    5 3
    0 1
    3 4
    0 3
Sample Output 2 :
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

void getPathBFS(int** edges, int n, int start, int end, bool* visited, unordered_map<int, int> &position){
    // visited[start] = true;
    queue<int> q;
    q.push(start);

    while(! q.empty()){
        int node = q.front(); // getting the front value an
        q.pop(); // removing the front value

        visited[node] = true;
        if(node == end)
            return;
        for(int i=0; i<n; i++){
            
            if(edges[node][i] == 1 && !visited[i]){
                q.push(i);
                if(position.count(i) == 0)
                    position[i] = node; 
            }
        }
    }
}

int main(){
    int V, E;
    cin >> V >> E;

    int** adjacency = new int*[V];
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

    unordered_map<int, int> positioning;
    bool* visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;
    
    int start, end;
    cin >> start >> end;
    
    getPathBFS(adjacency, V, start, end, visited, positioning);
    if(visited[end]){
        int t=end;
        while(t != start){
            cout << t << " ";
            t = positioning[t];
        }
        cout << t;
    }
    cout << endl;
    return 0;
}