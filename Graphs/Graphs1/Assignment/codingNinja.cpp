/*
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.

Input Format :
    The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
    Each of the following N lines contain M characters. Please note that characters are not space separated.

Output Format :
    Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.

Constraints :
    1 <= N <= 1000
    1 <= M <= 1000
    Time Limit: 1 second

Sample Input 1:
    2 11
    CXDXNXNXNXA
    XOXIXGXIXJX
Sample Output 1:
    1
*/
#include <iostream>
#include <vector>
using namespace std;

bool validPoint(int x, int y, int n, int m){
    return (x>=0 && x <n && y>=0 && y<m);
}

bool DFS(vector< vector<char> > &board, vector< vector<bool> > &used, string &word, int x, int y, int nextIndex, int n, int m){
    if(nextIndex == 1) return true;
    used[x][y] = true; // Marking as visited

    bool found = false;

    int dxdy[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    for(int i=0; i<8; i++){
        int newX = x + dxdy[i][0];
        int newY = y + dxdy[i][1];

        if(validPoint(newX, newY, n, m) && board[newX][newY] == word[nextIndex] && !used[newX][newY])
            found = found | DFS(board, used, word, newX, newY, nextIndex+1, n, m);
    }

    used[x][y] = false;
    return found;

}

bool hasPath(vector< vector<char> > board, int n, int m){
    // This function will return if we have a coding ninja path of not.
    string word = "CODINGNINJA";
    bool foundPath = false;
    vector< vector<bool> > used(n, vector<bool> (m, false)); // This will create a n*m vector
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == word[0]){
                foundPath = DFS(board, used, word, i, j, 1, n, m);
                if(foundPath)
                    break;
            }
        }
        if(foundPath) break;
    }
    return foundPath;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector< vector<char> > board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
    return 0;
}