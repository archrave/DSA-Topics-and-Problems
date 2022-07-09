vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> umap;
    vector<int> ans(2);

    int n = nums.size();
    for (int i = 0; i < n; i++) {
        umap[nums[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        if (umap.count(target - nums[i]) > 0 && umap[target - nums[i]] != i) {
            ans[0] = i;
            ans[1] = umap[target - nums[i]];
            break;
        }
    }
    return ans;

}