class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> s;
        vector<int> ans;

        int m = nums1.size();
        int n = nums2.size();

        int i = n-1;
        while(i>=0){
            if(s.size()==0){
                mp[nums2[i]] = -1;
            }
            else{
                if(s.top()>nums2[i]){
                    mp[nums2[i]] = s.top();
                }
                else{
                    while(s.size()>0 && s.top()<nums2[i]){
                        s.pop();
                    }
                    if(s.size()==0)
                    mp[nums2[i]] = -1;
                    else
                    mp[nums2[i]] = s.top();
                }
            }
            s.push(nums2[i]);
            i--;
        }

        for(int j=0;j<m;j++){
            ans.push_back(mp[nums1[j]]);
        }
        return ans;
    }
};