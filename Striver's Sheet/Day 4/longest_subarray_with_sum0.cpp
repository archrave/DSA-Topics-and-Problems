
/* Naive appoach to solve this question would be to go through every subarray and count their lengths if they give sum = 0,
    Maintain a max variable to find the max length.

    All subarrays can be accessed using two loops:
    for(int i = 0; i < n; i++){
        for(int j = i, j < n; j++){         // Parsing through every possible subarray
            //....
        }
    }

    T = O(n*n), S = O(1)
*/

/* Better Approach: (Using the following intution)

          S                0
   <--------------> <------------->
   [ * * * * * * * * * * * * * * * ]
   <------------------------------->
                    S

    If the prefix sum of a subarray (from 0  to i) = S, and the same prefix sum 'S' has already been found for a shorter subarray,
    that means the remaining subarray would have the sum 0.


    So we maintain a hashmap of prefixSums, and check the following conditions in the given order:

    1. if pSum = 0, (save the length and check if it exceeds the current maxm value)
    2. if pSum doesn't alredy exist in the map(hasnt been seen in a previous subarray), we simply store it along with the current index.
    3. If pSum already exists in map, then the abobe intution applies and we simply find the length of the 0 sum array by 'i - map[pSum]'., and check it with maxm.
    4. return the maxm length.


    T = O(N), S = O(N).  Hence time is optimise by compromising space.
*/
int LongestSubsetWithZeroSum(vector <int> arr) {
    unordered_map<int, int> prefixSums;
    int n = arr.size();
    int maxm = 0, psum = 0;
    for (int i = 0; i < n; i++) {
        psum += arr[i];
        if (psum == 0)
            maxm = max(maxm, i + 1);
        else if (!prefixSums.count(psum))
            prefixSums[psum] = i;
        else {
            int currLength = i - prefixSums[psum];
            maxm = max(maxm, currLength);
        }
    }
    return maxm;

}