class Solution {
public:
    int findMin(vector<int> &nums) {
        //assume last digit is smallest

        int l = 0;
        int r = nums.size() - 1;
        int v = nums[r];

        while (l <= r){
            int m = (l + r) / 2;

            if (nums[m] > v){
                l = m + 1;
            }
            else{
                v = min(nums[m], v);
                r = m - 1;
            }
        }
        return v;
    }
};
