class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = 0;
        long long zc1 = 0;
        long long s2 = 0;
        long long zc2 = 0;
        for(int i = 0 ; i < nums1.size() ; i++){
            s1 += nums1[i];
            if(nums1[i]==0){
                zc1++;
            }
        }
        for(int i = 0 ; i < nums2.size() ; i++){
            s2 += nums2[i];
            if(nums2[i]==0){
                zc2++;
            }
        }
        s1 += zc1;
        s2 += zc2;
        if( s1>s2 && zc2==0){
            return -1;
        }
        else if(s2>s1 && zc1==0){
            return -1;
        }
        return max(s1,s2);
    }
};