int merge(vector<int>& a, int s, int mid, int e)
{
    int n1 = mid + 1 - s, n2 = e - mid, curr = 0;
    int* a1 = new int[n1];
    int* a2 = new int[n2];
    int count = 0, j = mid + 1, i;
    for (i = s; i <= mid; i++) {

        while (j <= e && a[i] > 2LL * a[j]) {
            j++;
        }
        count += j - (mid + 1);
    }
    for (int i = s; i <= mid; i++) {
        a1[curr] = a[i];
        curr++;
    }
    curr = 0;
    for (int i = mid + 1; i <= e; i++) {
        a2[curr] = a[i];
        curr++;
    }
    curr = s;
    i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a1[i] <= a2[j]) {

            a[curr] = a1[i];
            i++;
        }
        else {
            a[curr] = a2[j];
            j++;
        }
        curr++;
    }
    while (i < n1) {
        a[curr] = a1[i];
        i++;
        curr++;
    }
    while (j < n2) {
        a[curr] = a2[j];
        j++;
        curr++;
    }
    delete[] a1;
    delete[] a2;
    return count;
}

int mergeSort(vector<int>& a, int s, int e)
{
    if (s >= e)
    {
        return 0;
    }
    int mid = s + (e - s) / 2;

    int a1 = mergeSort(a, s, mid);
    int b1 = mergeSort(a, mid + 1, e);
    int count = a1 + b1 + merge(a, s, mid, e);
    // cout<<"mS: s = "<<s<<", e = "<<e<<"; count =  "<<count<<endl;
    return count;
}
int reversePairs(vector<int>& nums) {
    int s = 0, e = nums.size() - 1;
    return mergeSort(nums, s, e);

}