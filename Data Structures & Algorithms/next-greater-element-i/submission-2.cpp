class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums1idx;
        for(int i = 0; i < nums1.size(); i++){
            nums1idx[nums1[i]] = i;
        }

        vector<int> res(nums1.size(), -1);
        stack<int> st;

        for(int n : nums2){
            while (!st.empty() && n > st.top()){
                int val = st.top();
                st.pop();
                int index = nums1idx[val];
                res[index] = n;
            }
            if (nums1idx.find(n) != nums1idx.end()){
                st.push(n);
            }
        }

        return res;
    }
};