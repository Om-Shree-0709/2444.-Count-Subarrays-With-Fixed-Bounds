# 🧠 How to Solve: "Count Subarrays With Fixed Bounds" (LeetCode 2444)

> **Problem Rating:** Hard  
> **Topics:** Arrays, Sliding Window, Greedy

Hello, amazing developers! 👋  
Today, I’m excited to walk you through a detailed, beginner-friendly guide to solving an interesting problem:  
**"Count Subarrays With Fixed Bounds"** (LeetCode 2444).

I’ll break it down **step-by-step**, **slowly**, and **clearly**, so even if you're new to problem-solving, you'll come out stronger at the end of this post. 💪

---

## 🧩 Problem Statement (Simplified)

You are given:
- An array `nums`
- Two integers: `minK` and `maxK`

We have to **count** how many **contiguous subarrays** satisfy **both**:
- The minimum element is exactly `minK`
- The maximum element is exactly `maxK`

> **Key Reminder:** A subarray is a continuous slice of the array — you cannot skip elements.

---

# 🛠️ Step-by-Step Thought Process

---

## Step 1: Naive Brute Force (and Why It Fails)

First thought:  
- Try all possible subarrays.
- For each subarray, check if the minimum is `minK` and maximum is `maxK`.
- Count it if yes.

**Problem?**  
- Checking every subarray → O(n²)
- Checking min and max in each → O(n)
- **Total:** O(n³) — **way too slow** for big arrays.

💬 *We need something smarter.*

---

## Step 2: Key Observations

While scanning the array:
1. If we see an element that’s **less than minK** or **greater than maxK**, we know:
   - ❌ No valid subarray can include this element.
   - So, we **reset** our tracking.
   
2. We must keep track of:
   - The **latest index** where we saw a number equal to `minK` → (`minPos`)
   - The **latest index** where we saw a number equal to `maxK` → (`maxPos`)

3. At each position `i`, if both `minK` and `maxK` have been seen:
   - The earliest (`min(minPos, maxPos)`) marks the beginning of a valid subarray ending at `i`.

4. However, if an invalid number appeared after the last valid `minK` or `maxK`, we must ignore it.

---

## Step 3: Visual Walkthrough

Let's imagine:

```
nums = [1, 3, 5, 2, 7, 5], minK = 1, maxK = 5
```

- `i = 0`: nums[0] = 1 → matches minK
- `i = 1`: nums[1] = 3 → between minK and maxK
- `i = 2`: nums[2] = 5 → matches maxK

Now, from `i=0` to `i=2`, we have both 1 and 5 — a valid subarray! 🎯

We can also have subarrays:
- `[1,3,5]`
- `[3,5]` (starting from 1 no longer, but still valid)

Thus, at each index, **we can count** how many valid subarrays end there.

---

## Step 4: Code Strategy (Summary)

- Loop through the array.
- Keep updating:
  - `minPos`: where was last `minK`
  - `maxPos`: where was last `maxK`
  - `lastInvalidIndex`: last index where element was out of range
- At each step:
  - Calculate `validStart = min(minPos, maxPos)`
  - Add `validStart - lastInvalidIndex` to the answer, if positive.

---

# 📈 Time and Space Complexity

| Aspect | Complexity |
|:-------|:-----------|
| Time | **O(n)** — Single pass through the array |
| Space | **O(1)** — No extra array or data structure |

---

# ✨ Full Working Solutions (C++, JavaScript, Python)

---

## 🧪 C++ Solution

```cpp
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
```

---

## 🧪 JavaScript Solution

```javascript
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
```

---

## 🧪 Python Solution

```python
class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        ans = 0
        min_pos = -1
        max_pos = -1
        last_invalid_index = -1

        for i, num in enumerate(nums):
            if num < minK or num > maxK:
                last_invalid_index = i
            if num == minK:
                min_pos = i
            if num == maxK:
                max_pos = i

            valid_start = min(min_pos, max_pos)
            count = valid_start - last_invalid_index
            ans += count if count > 0 else 0

        return ans
```

---

# 🎯 Final Takeaways

- Be cautious when an element goes **out of bounds** — immediately reset.
- Always **track the latest occurrences** of `minK` and `maxK`.
- **Single pass** solutions often hide behind clever **index tracking**.

This problem teaches you **pattern recognition**, **window management**, and **greedy optimizations** — all crucial for advanced coding interviews! 🚀

---

# 📢 Conclusion

If you found this article helpful:
- ⭐ Please react to it
- 💬 Share your thoughts in the comments
- 🔁 Share it with your study group or coding buddies!

**Follow me** for more beginner-friendly, clear breakdowns of algorithms, frontend tech, and career growth strategies! 🚀  
Let's **grow and win** together! 🎯

---

# 🙏 Thank You!

