#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        bool isUnsorted = false;
        for (int j = 0; j < arr.size() - 1; j++)
        {
            if (arr[j] == arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isUnsorted = true;
            }
        }
        if (!isUnsorted)
        {
            break;
        }
    }
}

int removeElement(vector<int> &nums, int val)
{
    bubbleSort(nums);
    int i = 0, flag = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (flag == 0 && nums[j] == val)
        {
            i = j;
            flag = 1;
        }

        else if (flag == 1 && nums[j] != val)
        {
            nums[i] = nums[j];
            i++;
        }
    }
    if (!flag)
    {
        i = nums.size();
    }
    return i;
}

int main()
{
    vector<int> num = {0, 1, 2, 2, 3, 0, 4, 2, 2, 2};
    int k = removeElement(num, 2);
    cout << k << endl;
    for (int i = 0; i < k; i++)
    {
        cout << num[i] << " ";
    }
    return 0;
}