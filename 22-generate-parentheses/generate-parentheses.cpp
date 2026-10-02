class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, n, 0,0,"");
        return ans;
    }
    void solve(vector<string> &ans, int n, int o, int c, string cur)
    {
        if(o==n && c==n){
            ans.push_back(cur);
            return;
        }
        if(o<n) solve(ans, n, o+1, c, cur+"(");
        if(c<o) solve(ans, n, o, c+1, cur+")");
    } 
};