class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int i=n-2;
        int j=n-1;
        return (nums[i]-1)*(nums[j]-1);
    }
};