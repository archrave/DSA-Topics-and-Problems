#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode *> children;

    TreeNode(T data)
    {
        this->data = data;
    }
    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

void printTree(TreeNode<int> *root)
{
    // The following is an 'edge case' and not the 'base case'

    // The leaf nodes create our basecase. Since their 'children' vector has
    // size = 0, the loop doesn't run and the recursion stops
    if (!root)
    {
        return;
    }
    cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data;
        if (i != root->children.size() - 1)
            cout << ", ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

// Iterative
void printLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        cout << q.front()->data << ":";
        int n = q.front()->children.size();

        for (int i = 0; i < n; i++)
        {
            cout << " " << q.front()->children[i]->data;
            if (i != n - 1)
                cout << ",";
            q.push(q.front()->children[i]);
        }
        q.pop();
        cout << endl;
    }
}

// This is not a good way to take input. Since it won't be clear to the user thatdata for which node they're supposedto enter
TreeNode<int> *takeInput()
{
    int rootData, n;
    cout << "\nEnter data: ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    cout << "\nEnter Number of children: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

// Iterative
TreeNode<int> *takeInputLevelWise()
{
    queue<TreeNode<int> *> q;
    int rootData, n, rootCount = 0, childCount = 0;
    cout << "\nEnter root: ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    q.push(root);
    while (!q.empty())
    {
        cout << "\nEnter Number of children of " << (q.front())->data << ": ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {

            TreeNode<int> *child = new TreeNode<int>(rootData);
            q.front()->children.push_back(child);
            cout << "Enter Data of the " << i + 1 << "th child of " << q.front()->data << ": ";
            cin >> child->data;
            q.push(child);
        }
        q.pop();
    }
    return root;
}

// Iterative
int countNodes(TreeNode<int> *root)
{
    if (!root)
        return 0;
    queue<TreeNode<int> *> q;
    int count = 1;
    q.push(root);

    while (!q.empty())
    {
        count += q.front()->children.size();
        for (int i = 0; i < q.front()->children.size(); i++)
        {
            q.push(q.front()->children[i]);
        }
        q.pop();
    }
    return count;
}

int countRecursive(TreeNode<int> *root, int count = 0)
{
    if (!root)
        return 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += countRecursive(root->children[i]);
    }
    return count + 1;
}

int height(TreeNode<int> *root)
{
    if (!root)
        return 0;
    if (root->children.size() == 0)
        return 1;

    int maxSmallHeight = INT_MIN;

    for (int i = 0; i < root->children.size(); i++)
    {
        int smallHeight = height(root->children[i]);
        if (maxSmallHeight < smallHeight)
            maxSmallHeight = smallHeight;
    }

    return maxSmallHeight + 1;
}

void printAllNodesAtLevelK(TreeNode<int> *root, int k)
{
    queue<TreeNode<int> *> q;
    int count = 0;
    q.push(root);
    while (!q.empty())
    {
        if (count < k)
        {
            count++;
        }
        for (int i = 0; i < q.front()->children.size(); i++)
        {
            if (count == k)
            {
                cout << q.front()->children[i]->data << " ";
            }
            else
                q.push(q.front()->children[i]);
        }
        q.pop();
    }
}

void printAtK(TreeNode<int> *root, int k)
{
    if (!root)
        return;
    if (k == 0)
    {
        cout << root->data << " ";
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        printAtK(root->children[i], k - 1);
    }
}

int countLeafNodes(TreeNode<int> *root)
{
    if (!root)
    {
        return 0;
    }
    if (root->children.size() == 0)
    {
        return 1;
    }
    int count = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += countLeafNodes(root->children[i]);
    }
    return count;
}
void preOrder(TreeNode<int> *root)
{
    // Edge case
    if (!root)
        return;

    cout << root->data << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrder(root->children[i]);
    }
}

void postOrder(TreeNode<int> *root)
{
    // Edge case
    if (!root)
        return;

    for (int i = 0; i < root->children.size(); i++)
    {
        postOrder(root->children[i]);
    }
    cout << root->data << endl;
}

void deleteTree(TreeNode<int> *root)
{
    // Edge case
    if (!root)
        return;

    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    // TreeNode<int>* temp = root;
    delete root;
}
int main()
{
    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 1 9 0

    TreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);

    // cout << "\nHeight: " << height(root);
    // printAllNodesAtLevelK(root, 2);
    // printAtK(root, 2);
    // cout << "Leaf Nodes: " << countLeafNodes(root);

    cout << endl;
    // deleteTree(root);
    delete root;
    printLevelWise(root);

    return 0;
}
