class Solution {
public:
    //和为 K 的子数组
    //前缀和加两数差
    /**
     * 时间复杂度：遍历一遍数组，O(n)
     * 空间复杂度：前缀和数组加哈希表，O(n)
     */
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1);
        sum[0] = 0;
        unordered_map<int, int> hash;   //哈希表键为前缀和，值为下标
        hash[0] = 1;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            sum[i] += sum[i - 1] + nums[i - 1]; //计算前缀和
            if (hash.find(sum[i] - k) != hash.end()) {  //查找是否有差为k的前缀和
                ans += hash[sum[i] - k];
            }
            hash[sum[i]]++;     //记录
        }
        return ans;
    }
};