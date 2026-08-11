class Solution {
public:
void dfs(int node, vector<vector<int>>&adj, vector<int>&vis,vector<int>&quiet,int &miniq,int &person){
    vis[node]++;
    if(quiet[node]<miniq)
    {
        miniq=quiet[node];
        person=node;
    }
    for(auto &neigh:adj[node])
    {
        if(vis[neigh]==0) dfs(neigh,adj,vis,quiet,miniq,person);
    }
}
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
      int n =quiet.size();
      vector<vector<int>>adj(n);
      for(auto &i:richer)
      {
        int rich=i[0], poor=i[1];
        adj[poor].push_back(rich);
      }  
      vector<int>ans(n);
      for(int i=0; i<n; i++)
      {
        vector<int>vis(n);
        int miniq=INT_MAX,person;
        dfs(i,adj,vis,quiet,miniq,person);
        ans[i]=person;
      }
      return ans;
    }
};