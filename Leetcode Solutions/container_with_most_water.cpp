#include <bits/stdc++.h>
using namespace std;
long long int maxArea(vector<int> &a)
{
    long int area = 0;
    int n = a.size(), maxHeight = 0;
    bool isMax = false;
    for (int i = n - 1; i > 0; i--)
    {
        isMax = false;

        if (a[i] > maxHeight)
        {
            for (int j = 0; j < i; j++)
            {
                int smaller = min(a[j], a[i]);
                long long int currentArea = smaller * (i - j);
                if (smaller == a[i])
                    isMax = true;

                cout << area << " , " << currentArea << endl;
                if (area < currentArea)
                {
                    area = currentArea;
                }

                if (isMax)
                    break;
            }
        }
        if (maxHeight < a[i])
            maxHeight = a[i];
    }
    return area;
}

int main()
{
    vector<int> arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    long long int area = maxArea(arr);
    cout << "\n\nMax Area: " << area << endl;
    return 0;
}