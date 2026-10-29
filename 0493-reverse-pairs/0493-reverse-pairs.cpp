class Solution {
public:
    int merge(vector<int>& nums, int st, int mid, int end) {
        int count = 0;
        int j = mid + 1;

        // Count reverse pairs across the two sorted halves
        for (int i = st; i <= mid; i++) {
            while (j <= end &&
                   (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += j - (mid + 1);
        }

        // Merge the two sorted halves
        vector<int> temp;
        int i = st;
        j = mid + 1;

        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i++]);
        }

        while (j <= end) {
            temp.push_back(nums[j++]);
        }

        for (int k = 0; k < (int)temp.size(); k++) {
            nums[st + k] = temp[k];
        }

        return count;
    }

    int mergeSort(vector<int>& nums, int st, int end) {
        if (st >= end) return 0;

        int mid = st + (end - st) / 2;

        int count = mergeSort(nums, st, mid);
        count += mergeSort(nums, mid + 1, end);
        count += merge(nums, st, mid, end);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, (int)nums.size() - 1);
    }
};