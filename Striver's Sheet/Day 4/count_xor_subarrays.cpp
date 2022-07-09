int Solution::solve(vector<int>& A, int B) {
    unordered_map<int, int> pXors;
    int count = 0, prefix = 0;
    for (int i = 0; i < A.size(); i++) {

        prefix = prefix ^ A[i];

        if (prefix == B)
        {
            count++;
        }
        if (pXors.count(B ^ prefix))
            count += pXors[B ^ prefix];

        pXors[prefix]++;

        // cout<<"\nPrefix: "<<prefix<<", Count: "<<count<<endl;
    }
    return count;
}
// Extremely tricky, can't even bother to explain this shit.

