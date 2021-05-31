#include <iostream>
#include <vector>
#include <cassert>
 
#pragma GCC diagnostic error "-std=c++11"
 
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        assert(board.size()==9 && board[0].size()==9);
        if(isSolved(board)){
            return;
        } else{
            throw invalid_argument("no solution.");
        }
 
 
    }
private:
    bool judgeNums(int i,int j,vector<vector<char>>&board){
        int row=board.size();
        int column=board[0].size();
        //row no duplicate
        for(int k=0;k<column;k++){
            if((k!=j) && (board[i][k]==board[i][j])){
                return false;
            }
        }
        //column no duplicate
        for(int k=0;k<row;k++){
            //k!=i should not  k<row && k!=i if k=i, false k+1 won't do
            if((k!=i) && (board[k][j]==board[i][j])){
                return false;
            }
        }
        //grid no duplicate
        for(int r=3*(i/3);r<=3*(i/3)+2;r++){
            for(int d=3*(j/3);d<=3*(j/3)+2;d++){
                if((r!=i || d!=j) && board[r][d]==board[i][j]){
                    return false;
                }
            }
        }
 
        return true;
 
    }
 
    bool isSolved(vector<vector<char> >&board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(int k=0;k<9;k++){
                        board[i][j]=k+'1';
                        if(judgeNums(i,j,board)){
                            if(isSolved(board)){
                                return true;
                            }
                        }
                        board[i][j]='.';
 
                    }
                    return false;
                }
            }
        }
        return true;
    }
};
 
int main(){
    char board[9][9]={{'5','3','.','.','7','.','.','.','.'},
                      {'6','.','.','1','9','5','.','.','.'},
                      {'.','9','8','.','.','.','.','6','.'},
                      {'8','.','.','.','6','.','.','.','3'},
                      {'4','.','.','8','.','3','.','.','1'},
                      {'7','.','.','.','2','.','.','.','6'},
                      {'.','6','.','.','.','.','2','8','.'},
                      {'.','.','.','4','1','9','.','.','5'},
                      {'.','.','.','.','8','.','.','7','9'}};
    vector<vector<char>> vec(9,vector<char>(9));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            vec[i][j]=board[i][j];
        }
    }
 
    Solution().solveSudoku(vec);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}