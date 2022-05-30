#include <iostream>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

void printTree(TreeNode<int> *root)
{
    if (!root)
        return;
    cout << root->data << ": ";
    if (root->left)
        cout << "L = " << root->left->data << " ";
    if (root->right)
        cout << "R = " << root->right->data;
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

void printLevelWise(TreeNode<int> *root)
{
    if (!root)
        return;
    cout << "****************************" << endl;
    queue<TreeNode<int> *> q;
    q.push(root);

    cout << endl;
    while (!q.empty())
    {
        TreeNode<int> *f = q.front();
        q.pop();
        cout << f->data << ": ";
        if (f->left)
        {
            cout << " L = " << f->left->data;
            q.push(f->left);
        }
        if (f->right)
        {
            cout << " R = " << f->right->data;
            q.push(f->right);
        }
        cout << endl;
    }
}

TreeNode<int> *takeInput()
{

    cout << "Enter data: ";
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    TreeNode<int> *root = new TreeNode<int>(rootData);

    root->left = takeInput();
    root->right = takeInput();
    return root;
}

TreeNode<int> *takeInputLevelWise()
{
    int data;
    cout << "Enter root: ";
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        cout << "Enter data for the leftchild of " << q.front()->data << ": ";
        cin >> data;
        if (data == -1)
        {
            q.front()->left = NULL;
        }
        else
        {
            q.front()->left = new TreeNode<int>(data);
            q.push(q.front()->left);
        }

        cout << "Enter data for the rightchild of " << q.front()->data << ": ";
        cin >> data;
        if (data == -1)
        {
            q.front()->right = NULL;
        }
        else
        {
            q.front()->right = new TreeNode<int>(data);
            q.push(q.front()->right);
        }

        q.pop();
    }
    return root;
}

int countNodes(TreeNode<int> *root)
{
    if (!root)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

bool findNode(TreeNode<int> *root, int key)
{
    if (!root)
        return false;
    if (root->data == key)
        return true;
    return (findNode(root->left, key) || findNode(root->right, key));
}

int findMin(TreeNode<int> *root)
{
    if (!root)
        return INT_MAX;

    return min(root->data, min(findMin(root->left), findMin(root->right)));
}

int countLeafNodes(TreeNode<int> *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

bool rootToNode(TreeNode<int> *root, vector<int> &v, int key)
{
    if (!root)
        return false;
    int sum = 0;
    if (root->data == key)
    {
        v.push_back(key);
        sum += key;
        return true;
    }

    bool isDatainLeftTree = rootToNode(root->left, v, key);
    bool isDatainRightTree = rootToNode(root->right, v, key);
    if (isDatainLeftTree || isDatainRightTree)
    {
        v.push_back(root->data);
        sum += root->data;
    }

    return isDatainLeftTree || isDatainRightTree;
}

bool rootToNode2(TreeNode<int> *root, int key, vector<int> &v)
{
    if (!root)
    {
        return false;
    }

    v.push_back(root->data);

    if (root->data == key)
    {
        return true;
    }

    bool isDataPresent = rootToNode2(root->left, key, v) || rootToNode2(root->right, key, v);
    if (!isDataPresent)
    {
        v.pop_back();
    }
    return isDataPresent;
}

int main()
{
    // 1 2 3 4 5 -1 -712 -1 -1 -1 6 -1 -1 -1 -1
    TreeNode<int> *root = NULL;
    // TreeNode<int> *root = new TreeNode<int>(1);
    // root->left = new TreeNode<int>(2);
    // root->right = new TreeNode<int>(3);
    root = takeInputLevelWise();
    printLevelWise(root);
    // cout << endl
    //      << "Count: " << countNodes(root);
    // cout << endl
    //      << findNode(root, 712);
    vector<int> v;
    if (rootToNode2(root, -712, v))
    {
        cout << "Path: ";
        // for (int i = v.size() - 1; i >= 0; i--)
        // {
        //     cout << v[i] << " ";
        // }
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "\nSorry, the key is not present in the given tree!\n";
    }
    return 0;
}