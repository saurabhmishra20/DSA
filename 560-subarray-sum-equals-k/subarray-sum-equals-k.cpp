class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int>pre(n+1);
    for(int i=1; i<=n; i++) pre[i]=pre[i-1]+nums[i-1]; 
    int count=0;
    map<int , int > freq;
    freq[0]++;
    for(int i=1; i<=n; i++)
    {
        int p1=pre[i]-k;
        count+=freq[p1];
        freq[pre[i]]++;
    }  
    return count;
    }
};