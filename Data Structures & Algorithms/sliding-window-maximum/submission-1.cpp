class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;

        int l = 0;
        int r = k - 1;
        while(r < nums.size()){
            int max = INT_MIN;
            for(int i = l; i <= r; i++){
                if (nums[i] > max){
                    max = nums[i];
                }
            }
            res.push_back(max);
            l++;
            r++;
        }

        return res;
    }
};
