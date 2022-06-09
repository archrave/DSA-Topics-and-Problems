#include <bits/stdc++.h>
using namespace std;

int main()
{
    // **************************************************** UNORDERED MAP ****************************************************

    unordered_map<char, int> umap;
    umap['a'] = 1;
    umap['b'] = 2;
    umap['c'] = 3;
    umap['d'] = 4;
    umap['e'] = 5;
    unordered_map<char, int>::iterator it;
    // or
    // auto it = it.begin();

    // This traversal could follow any order, since our map is unordered

    cout << "Unordered Map: \n{\n";
    for (it = umap.begin(); it != umap.end(); it++) // begin() points at the first element, while end() points at the element next to last(outside of map)
    {
        cout << "  {" << it->first << ", " << it->second << "}\n";
    }
    cout << "}\n";
    cout << "\n\n";

    // **************************************************** MAP ****************************************************

    // In the case of a map(ordered), it will ALWAYS SORT OUR KEYS

    map<string, int> m;
    m["abc4"] = 4;
    m["abc3"] = 3;
    m["abc2"] = 2;
    m["abc5"] = 5;
    m["abc1"] = 1;
    map<string, int>::iterator it1;
    // or

    // This traversal could follow any order, since our map is unordered

    cout << "Map: \n{\n";
    for (it1 = m.begin(); it1 != m.end(); it1++)
    {
        cout << "  {" << it1->first << ", " << it1->second << "}\n";
    }
    cout << "}\n";

    // **************************************************** VECTOR ****************************************************

    vector<int> v = {10, 20, 30, 40, 50, 60};
    vector<int>::iterator vitr;
    cout << "\n\nVector: " << endl;
    for (vitr = v.begin(); vitr != v.end(); vitr++)
    {
        cout << *vitr << " "; // We use a * i.e dereferencing operator to access the value of the iterator pointer.
    }
    cout << endl;

    // To erase the entire map:

    umap.erase(umap.begin(), umap.end());

    // Nothing will get printed:
    for (it = umap.begin(); it != umap.end(); it++)
    {
        cout << "  {" << it->first << ", " << it->second << "}\n";
    }
    return 0;
}