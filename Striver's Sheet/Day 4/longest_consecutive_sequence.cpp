// T = NlogN (naive approach)
/* int longestConsecutive(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int count = 0, max = 0;
    if(nums.size() == 0) return 0;
    for(int i = 0; i<nums.size()-1; i++){
        if(nums[i+1] == nums[i]+1)
            count++;
        else if(nums[i]==nums[i+1])
            continue;
        else
            count = 0;
        if(count > max)
            max = count;
    }
    return max+1;
} */

// optimal striver's solution (shows TLE for some reason)
int longestConsecutive(vector<int>& nums) {
    set <int> hashSet;
    set<int>::iterator itr;

    for (int i = 0; i < nums.size(); i++) {
        hashSet.insert(nums[i]);
    }

    int longestStreak = 0;
    for (itr = hashSet.begin(); itr != hashSet.end(); itr++) {
        // If the current element is not the starting element of a sequence, do nothing. (i.e if a[i] - 1 exists)

        if (hashSet.count(*itr - 1)) continue;
        int currentNum = *itr;
        int currentStreak = 1;

        //Else keep checking if a[i]+1 exits or not to maintain a streak, use a max variable to return the longest streak
        while (hashSet.count(currentNum + 1)) {
            currentNum += 1;
            currentStreak += 1;
        }

        longestStreak = max(longestStreak, currentStreak);

    }

    return longestStreak;
}