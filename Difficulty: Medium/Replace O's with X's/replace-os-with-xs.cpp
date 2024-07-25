//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
void bfs(int i,int j,vector<vector<char>>mat,vector<vector<char>>&ans ,vector<vector<int>>&vis)
{
      
      vis[i][j]=1;
           queue<pair<int,int>>q;
         vector<pair<int,int>>ne={{-1,0},{0,-1},{1,0},{0,1}};
         q.push({i,j});
    
     while(!q.empty())
         {
           int row=q.front().first;
             int col=q.front().second;
             q.pop();
             for(int i=0;i<ne.size();i++)
             {
                 int nrow=row+ne[i].first; 
                 int ncol=col+ne[i].second;
                 if(nrow>=0&&nrow<mat.size()&&ncol>=0&&ncol<mat[0].size()&&!vis[nrow][ncol]&&mat[nrow][ncol]=='O')
                 {ans[nrow][ncol] = 'O';
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                 }
             }
              
       }
       
   
}

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>>vis(n,vector<int>(m,0));
         vector<vector<char>>ans = mat;
    
    // check if any of zero connected to boundary
        // first and last row
        for(int j = 0;j<m;j++){
            // first row
            if(!vis[0][j] &&mat[0][j] == 'O'){
                bfs(0,j,mat , ans , vis );
            }
            // last row 
            if(!vis[n-1][j]&& mat[n-1][j] == 'O'){
                bfs(n-1 , j,mat , ans , vis);
            }
        }
        
        // first and last col
        for(int i = 0;i<n;i++){
            if(!vis[i][0]&& mat[i][0] == 'O'){
                bfs(i , 0 ,mat , ans , vis);
            }
            // last column
            if(!vis[i][m-1] && mat[i][m-1] == 'O' ){
                bfs(i , m-1,mat , ans, vis);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++ )
            {
              if(!vis[i][j]&&mat[i][j]=='O')
              {
                  ans[i][j] = 'X';
              }
            }
           
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends