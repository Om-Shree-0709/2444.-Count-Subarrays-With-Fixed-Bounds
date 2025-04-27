class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minPos = -1, maxPos = -1, lastInvalidIndex = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                lastInvalidIndex = i;
            }
            if (nums[i] == minK) {
                minPos = i;
            }
            if (nums[i] == maxK) {
                maxPos = i;
            }

            long long validStart = min(minPos, maxPos);
            long long count = validStart - lastInvalidIndex;
            ans += (count > 0) ? count : 0;
        }

        return ans;
    }
};
