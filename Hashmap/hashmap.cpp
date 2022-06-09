#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // Stores data in the form of key-value pair.
    unordered_map<string, int> myMap;

    // To insert an entry:

    // 1. Using a pair class object
    pair<string, int> p("abc", 1);
    myMap.insert(p);

    // 2. Using square brackets
    myMap["def"] = 2;

    // To access elements:

    // 1. Using square brackets:
    cout << myMap["abc"] << endl;

    // 2. Using at() function:
    cout << myMap.at("abc") << endl;

    /* Difference btw [] and at() function is, when the key which is accessed is
     not present in the referenced map, the at() function will throw an error, while
     the '[]' will push the key in the map, and assign it's value to be 0/false/NULL. */

    cout << endl
         << "Size: " << myMap.size() << endl;
    cout << myMap["ghi"] << endl;
    cout << endl
         << "Size: " << myMap.size() << endl;

    /* Now, to check whether a key exists in a map or not, we can neither use the at()
     function nor can we use the [] (since it will push the key), so how do we do that? */

    // To check if a key exists in the map, we can use the count function():

    if (myMap.count("ghi") > 0)
        cout << "Key \"ghi\"  exits." << endl;
    else
        cout << "Key \"ghi\"  doesn't exit!" << endl;

    // count() returns how many times a key is present. (only can return 0 or 1)

    // To update a value:
    myMap["abc"] = 20;

    // To Delete an entry:
    myMap.erase("ghi");

    /* For the simple map class (ordered map), all the functions are the same
    but with different time complexity (O(logN)) */
    return 0;
}