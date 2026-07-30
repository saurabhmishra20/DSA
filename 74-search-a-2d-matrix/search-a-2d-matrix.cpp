class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty()) return false;
       int m=matrix.size();
        int n=matrix[0].size();
        int low=0;
        int high=n*m-1;// n*m matrix ke liye high ki value aise find kiya..
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int row = mid/n;// 1D ko 2D me convert kiya
            int col= mid % n;
            if (matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) low=mid+1;
            else if(matrix[row][col] > target) high=mid-1;
        }
        return false;
    }
};