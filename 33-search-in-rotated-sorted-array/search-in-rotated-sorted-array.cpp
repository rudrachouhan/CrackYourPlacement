class Solution {
public:

    int bSearch(vector<int> nums,int s, int e,int target){
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]==target)
            return mid;
            else if(nums[mid]>target){
                e= mid-1;
            }
            else
            s= mid +1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int s =0;
        int n = nums.size();
        int e = n-1;
        int l = 0;
        if(n==2)
        l = 1; 
        while(s<=e){
            int mid = s + (e-s)/2;
            int next = (mid+1) % n;
            int prev = (mid+n-1) % n; 
            if(nums[mid]<nums[next] && nums[mid]<nums[prev]){
                l = mid;
                if(nums[mid]==target)
                return mid;
                break;
            }
            else if(nums[0]<=nums[mid]){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
    cout<<l;
    int a = bSearch(nums,0,l-1,target);
    int b = bSearch(nums,l,n-1,target);

    if(a!=-1){
        return a;
    }
    if(b!=-1){
        return b;
    }
    return -1;
    }
};