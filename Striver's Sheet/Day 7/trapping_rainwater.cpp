// O(1): Space, O(N): Time
int trap(vector<int>& height) {
    int n = height.size(), lmax = 0, rmax = 0, res = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        if (height[l] <= height[r]) {
            if (height[l] >= lmax)
                lmax = height[l];
            else
                res += lmax - height[l];
            l++;
        }
        else {
            if (height[r] >= rmax)
                rmax = height[r];
            else
                res += rmax - height[r];
            r--;
        }
    }
    return res;
}

// Time: O(3N), Space: O(2N)
/*
int trap(vector<int>& height) {
    int n = height.size(), maxm = 0;
    vector<int> pre(n), suf(n);
    for(int i = 0; i < n; i++){
        maxm = max(maxm, height[i]);
        pre[i] = maxm;
    }
    maxm = 0;
    for(int i = n-1; i>=0; i--){
        maxm = max(maxm, height[i]);
        suf[i] = maxm;
    }

    long long int water = 0;
    for(int i = 0; i<n; i++){
        water += min(pre[i],suf[i]) - height[i];
    }
    return water;
}
*/