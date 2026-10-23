class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int last = n - 1;
        int mid = n - 2;

        // Step 1: Find the pivot
        while (mid >= 0) {
            if (nums[mid] < nums[last]) {
                break;
            } else {
                mid--;
                last--;
            }
        }

        // Step 2: Find and swap the correct element
        if (mid >= 0) {
            for (int j = n - 1; j > mid; j--) {
                if (nums[j] > nums[mid]) {
                    swap(nums[j], nums[mid]);
                    break;
                }
            }
        }

        // Step 3: Reverse the suffix
        reverse(nums.begin() + mid + 1, nums.end());
    }
};