class Solution {
public:
    vector<int> NSR(vector<int> heights){
        stack<pair<int,int>> s;
        vector<int> ans;
        int pr = heights.size();

        for(int j=heights.size()-1;j>=0;j--){
            if(s.empty()){
                ans.push_back(pr);
            }
            else if(heights[j]>s.top().first){
                ans.push_back(s.top().second);
            }
            else{
                while(s.size()!=0 && heights[j]<=s.top().first){
                    s.pop();
                }
                if(s.empty()){
                ans.push_back(pr);
            }
            else{
                ans.push_back(s.top().second);
            }
            }
            s.push({heights[j],j});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    vector<int> NSL(vector<int> heights){
        stack<pair<int,int>> s;
        vector<int> ans;
        int pl = -1;

        for(int j=0;j<heights.size();j++){
            if(s.empty()){
                ans.push_back(pl);
            }
            else if(heights[j]>s.top().first){
                ans.push_back(s.top().second);
            }
            else{
                while(s.size()!=0 && heights[j]<s.top().first){
                    s.pop();
                }
                if(s.empty()){
                ans.push_back(pl);
            }
            else{
                ans.push_back(s.top().second);
            }
            }
            s.push({heights[j],j});
        }
        return ans;
    }



    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsr = NSR(heights);
        vector<int> nsl = NSL(heights);
        int maxi = INT_MIN;

        for(int i=0;i<heights.size();i++){
            int curr = (nsr[i]-nsl[i]-1) * heights[i];
            maxi = max(curr,maxi);
        }
        return maxi;
    }
};