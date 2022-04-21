#include <iostream>
#include <vector>
using namespace std;
int majorityElement(vector<int> &nums)
{
    int count = 0;
    int majority = nums[0];
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == majority)
        {
            count++;
        }
        else
        {
            count--;
        }

        if (count == 0)
        {
            majority = nums[i];
            count++;
        }
        cout << endl
             << "Majority: " << majority << ", Count: " << count << endl;
    }
    return majority;
}
int main()
{
    vector<int> a = {3, 2, 3};
    cout << "\n\n ANSWER: " << majorityElement(a);
    return 0;
}