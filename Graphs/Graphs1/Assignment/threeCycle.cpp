/*
Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.


Input Format :
    The first line of input contains two space separated integers, that denotes the value of N and M.
    Each of the following M lines contain two integers, that denote the vertices which have an undirected edge between them. Let us denote the two vertices with the symbol u and v. 


Output Format :
    Print the count the number of 3-cycles in the given graph


Constraints :
    0 <= N <= 100
    0 <= M <= (N*(N-1))/2
    0 <= u <= N - 1
    0 <= v <= N - 1
    Time Limit: 1 sec


Sample Input 1:
    3 3
    0 1
    1 2
    2 0

    
Sample Output 1:
    1
*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void getCount3Cycles(int** edges, int n, int startVertex, int currentVertex, int &count){
    for(int i=0; i<n; i++){
        if(i == startVertex)
            continue;
        else{
            if(edges[currentVertex][i] == 1 && edges[i][startVertex] == 1)
                count += 1;
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;

    int **edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }

    for(int i=0; i<m; i++){
        int s, f;
        cin >> s >> f;
        edges[s][f] = 1;
        edges[f][s] = 1;
    }
    int count = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int start = i;
            if(edges[start][j] == 1){
                getCount3Cycles(edges, n, start, j, count);
            }
        }
    }
    cout << count/6 << endl;
    return 0;
}