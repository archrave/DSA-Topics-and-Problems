int lengthOfLongestSubstring(string s) {
    vector<int> visited(256, -1);
    int maxm = 0, count = 0, l = 0;
    for (int r = 0; r < s.length(); r++) {
        if (visited[s[r]] < l) {
            visited[s[r]] = r;
            count++;
        }
        else {
            l = visited[s[r]] + 1;
            visited[s[r]] = r;
            count = r - l + 1;
        }
        maxm = max(count, maxm);
    }
    return maxm;
}