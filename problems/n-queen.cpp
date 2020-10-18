struct pos { 
    int row;
    int col;
};
class Solution {
public:
    
    
    
    vector<vector<string>> ans;
    void solve(int n,int row, vector<pos> &positions){
        if(n == row) {
            vector<string> s;
            
            
            
            for(int i = 0; i < n;i++){
                pos x = positions[i];
                string temp = "";
                for(int j = 0; j < n;j++){
                    if(x.row == i && x.col == j) temp += "Q";
                    else temp += ".";
                }
                s.push_back(temp);
            }
            ans.push_back(s);
            
            return;
        }
        
        for(int col = 0; col < n; col++){
            bool isSafe = true;
            
            for(int j = 0; j < row;j++){
                pos i = positions[j];
                if(i.col == col || i.row == row ||
                  ((i.col + i.row) == (row + col)) ||
                  ((i.col - i.row) == (col - row))){
                    isSafe = false;
                    break;
                }
            }
            
            if(isSafe){
                positions[row] = {row, col};
                solve(n, row + 1, positions);
            }
        }
        
        //return false;
    }
   
    vector<vector<string>> solveNQueens(int n) {
        vector<pos> positions(n);
        
        solve(n, 0, positions);
        
        
        
        
        return ans;
        
    }
};