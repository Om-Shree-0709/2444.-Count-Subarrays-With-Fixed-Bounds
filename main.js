var countSubarrays = function(nums, minK, maxK) {
    let ans = 0;
    let minPos = -1, maxPos = -1, lastInvalidIndex = -1;

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] < minK || nums[i] > maxK) {
            lastInvalidIndex = i;
        }
        if (nums[i] === minK) {
            minPos = i;
        }
        if (nums[i] === maxK) {
            maxPos = i;
        }

        let validStart = Math.min(minPos, maxPos);
        let count = validStart - lastInvalidIndex;
        ans += (count > 0) ? count : 0;
    }

    return ans;
};
