class Solution {
public:

    void solve(int &n,vector<string> &ans,string temp,int open,int close){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }

        if(open==close){
            solve(n,ans,temp+'(',open-1,close);
        }

        else{
            solve(n,ans,temp+')',open,close-1);
            if(open>0){
                solve(n,ans,temp+'(',open-1,close);
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        int open=n,close=n;
        solve(n,ans,temp,open,close);
        return ans;
    }
};