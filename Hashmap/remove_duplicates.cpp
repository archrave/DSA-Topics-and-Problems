#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates(vector<int> arr)
{
    unordered_map<int, int> umap;
    vector<int> v;
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (umap.count(arr[i]) == 0)
        {
            umap[arr[i]] = 1;
            v.push_back(arr[i]); // Pushing in the vector right away to maintain the same order as the orignal one
        }
        else
        {
            umap[arr[i]]++;
        }
    }
    return v;
}

int main()
{
    vector<int> arr = {1, 2, 3, 2, 1, 5, 4, 1, 3};
    vector<int> newArr = removeDuplicates(arr);
    cout << endl;
    for (int i = 0; i < newArr.size(); i++)
    {
        cout << newArr[i] << " ";
    }
    return 0;
}