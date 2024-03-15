#include <iostream>
#include <vector>
using namespace std;

void printSolution(vector<vector<char>>& board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(int row, int col, vector<vector<char>>& board, int n){

    //this function has a T.C of O(n) as of now 
    //but can be reduced to O(1) with the use of hashmap
    //Mapping - data insertion and retrieval in O(1) times 

    //check left sides if queens placed 
    int i = row;
    int j = col;

    //left row
    while(j>=0){
        if (board[i][j]=='Q'){
            return false;
        }
        j--;
    }
    j=col;
    //upper left diagonal
    while(i>=0 && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }
    i=row;
    j=col;
    //bottom left diagonal
    while(i<n && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void solve(vector<vector<char>>& board, int col, int n){
    //base case
    if(col >= n){
        printSolution(board, n);
        return;
    }

    //solve 1 case and recursion handles the rest
    for(int row = 0; row < n ; row++ ){
        if(isSafe(row,col,board,n)){
            //queen placed
            board[row][col]='Q';
            //recursion
            solve(board,col+1,n);
            //backtracking
            board[row][col]='.';
        }
    }
}

int main(){
    int n = 9;
    vector<vector<char>> board(n,vector<char>(n,'.'));
    int col = 0;
    solve(board, col, n);
    return 0;
}