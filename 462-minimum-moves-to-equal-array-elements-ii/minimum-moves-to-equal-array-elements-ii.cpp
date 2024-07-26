class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long int ans = 0,n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        int a = nums[0],b=nums[n-1];
        int mid = a + (b-a)/2;
        for(int i=0;i<n;i++){
            ans+=abs(nums[i]-mid);
            mp[nums[i]]++;
        }
        long long int res = INT_MAX;
        for(auto i:mp){
            int a = i.first;
            long long int count=0;
            for(auto j:mp){
                count+=(j.second*abs(j.first-a));
            }
            res = min(res,count);
        }
        return min(ans,res);
    }
};