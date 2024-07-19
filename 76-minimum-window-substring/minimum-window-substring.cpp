class Solution {
public:
    string minWindow(string s, string t) {
        int len = INT_MAX,i=0,j=0;
        unordered_map<char,int> mp;
        for(auto i:t){
            mp[i]++;
        }
        int count = mp.size();
        int n = s.length();
        int start = i;
        while(j<n){
            if(mp.count(s[j])){
                mp[s[j]]--;
                if(mp[s[j]]==0)
                count--;
            }
            if(count==0){
                while(count==0){
                    if(len>j-i+1){
                    start=i;
                    len=j-i+1;
                    }
                    if(mp.count(s[i])){
                        mp[s[i]]++;
                        if(mp[s[i]]==1)
                        count++;
                    }
                    i++;
                }
            }
            j++;
        }
        if(len==INT_MAX)
        return "";
        string ans = s.substr(start,len);
        return ans;
    }
};