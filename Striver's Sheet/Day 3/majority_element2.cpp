#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;


// Linear Space. (Hashmap)
/* vector<int> majorityElement(vector<int>& a) {
    unordered_map<int,int> m;
    int n = a.size();
    for(int i = 0; i<n; i++){
        if(m.count(a[i]) > 0)
            m[a[i]] ++;
        else
            m[a[i]] = 1;


    }
    vector<int> ans;
    for(auto itr = m.begin(); itr != m.end(); itr++){
        if(itr->second > n/3)
            ans.push_back(itr->first);
     }
    return ans;
}*/

vector<int> majorityElement(vector<int>& a) {
    int n = a.size(), c1 = 0, c2 = 0;
    vector<int> ans;

    if (n == 1) {
        ans.push_back(a[0]);
        return ans;
    }

    int maj1 = -1, maj2 = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] == maj1)
            c1++;
        else if (a[i] == maj2)
            c2++;
        else if (c1 == 0) {
            maj1 = a[i];
            c1++;
        }
        else if (c2 == 0) {
            maj2 = a[i];
            c2++;
        }
        else {
            c1--;
            c2--;
        }

    }
    c1 = c2 = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == maj1)  c1++;
        else if (a[i] == maj2) c2++;
    }
    if (c1 > n / 3)    ans.push_back(maj1);
    if (c2 > n / 3)    ans.push_back(maj2);
    // if(maj1 == maj2)    ans.pop_back();
    return ans;
}
int main() {
    vector<int> arr = { 3,2,3 };
    vector<int> ans = majorityElement(arr);
    cout << "\n\n\n";
    for (int i = 0; i < ans.size();i++) {
        cout << arr[i] << " ";
    }
    return 0;
}