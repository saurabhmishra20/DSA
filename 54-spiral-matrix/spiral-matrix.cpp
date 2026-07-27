class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int>ans;
            int m=matrix.size();
            int n=matrix[0].size();
            int srow=0,scol=0;
            int erow=m-1, ecol=n-1;
    
            // condition for loop
            while(srow<=erow && scol<=ecol)
            {
                // top
                for(int j=scol; j<=ecol; j++)
                {
                    ans.push_back(matrix[srow][j]);
                }
                // Right
                for(int i=srow+1; i<=erow; i++)
                {
                    ans.push_back(matrix[i][ecol]);
                }
                // bottom
                for(int j=ecol-1; j>=scol; j--)
                {
                    if(srow==erow){//corner case
                        break;
                    }
                    ans.push_back(matrix[erow][j]);
                }
                // left
                for(int i=erow-1; i>=srow+1; i--)
                {
                    if(scol==ecol){ //corner case
                        break;
                    }
                    ans.push_back(matrix[i][scol]);
                }
                srow++;
                erow--;
                scol++;
                ecol--;
            }
        return ans;
    }
};