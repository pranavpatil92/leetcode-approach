class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> counts;

        // Part 1: count every number
        for (int x : nums) {
            if (counts.count(x) > 0) {
                counts[x] = counts[x] + 1;
            } else {
                counts[x] = 1;
            }
        }

        // Part 2: pick the biggest count, k times
        vector<int> result;

        for (int i = 0; i < k; i++) {
            int bestNum = 0;
            int bestCount = 0;

            for (auto p : counts) {
                if (p.second > bestCount) {
                    bestCount = p.second;
                    bestNum = p.first;
                }
            }

            result.push_back(bestNum);
            counts.erase(bestNum);
        }

        return result;
    }
};