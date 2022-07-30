//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented

struct Item {
    int value;
    int weight;
};

class Solution
{
public:
    static bool comparator(Item a, Item b) {
        if ((double)((a.value * 0.1) / a.weight) > (double)((b.value * 0.1) / b.weight))
            return true;
        else
            return false;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double profit = 0;
        int weightLeft = W;
        sort(arr, arr + n, comparator);
        for (int i = 0; i < n; i++) {

            int weightTaken = arr[i].weight;
            if (arr[i].weight >= weightLeft) {

                profit += weightLeft * (double)((arr[i].value * 1.0) / arr[i].weight);

                break;
            }
            else {
                profit += arr[i].value;
                weightLeft = weightLeft - arr[i].weight;
            }

        }
        return profit;
    }

};


//{ Driver Code Starts.
int main()
{
    int t;
    //taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--) {
        //size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        //value and weight of each item
        for (int i = 0;i < n;i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        //function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}