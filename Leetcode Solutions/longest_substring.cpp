#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> m;
    int count = 0, max = -1, newIndex = 0;
    for (int i = 0; i < s.length();)
    {
        m[s[i]]++;
        if (m.at(s[i]) == 2)
        {
            if (max < count)
            {
                max = count;
            }
            count = 0;
            m.clear();
            newIndex++;
            i = newIndex;
            continue;
        }
        else
            count++;
        i++;
        // cout << "Count: " << count << endl;
        // cout << "Max: " << max << endl
        //      << endl;
    }
    return count > max ? count : max;
}

int main()
{
    string s = "abcabcbb";
    // cout << lengthOfLongestSubstring(s);
    vector<int> dict(256, -1);
    cout << dict.size() << endl;
    cout << dict[0] << " ";
    cout << dict[1] << " ";
    cout << dict[2] << " ";
    cout << dict[3] << " ";
    cout << dict[4] << " ";
    return 0;
}