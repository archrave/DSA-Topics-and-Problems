#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int search(vector<int> v, int key)
{
    int i = 0;
    for (i = 0; i < v.size(); i++)
    {
        if (v[i] == key)
            return i;
    }
    return -1;
}

TreeNode *build(vector<int> pre, vector<int> in, int iS, int iE, int pS, int pE)
{
    if (iS > iE)
        return NULL;
    TreeNode *root = new TreeNode;
    root->val = pre[pS];

    if (pre.size() == 1)
    {
        return root;
    }

    int rootIndex = search(in, pre[pS]);
    root->left = build(pre, in, iS, rootIndex - 1, pS + 1, rootIndex - iS + pS);
    root->right = build(pre, in, rootIndex + 1, iE, rootIndex - iS + pS + 1, pE);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int iS = 0, iE = inorder.size() - 1, pS = 0, pE = preorder.size() - 1;
    return build(preorder, inorder, iS, iE, pS, pE);
}

void printLevelWise(TreeNode *root)
{
    if (!root)
        return;

    queue<TreeNode *> q;
    q.push(root);

    cout << endl;
    while (!q.empty())
    {
        TreeNode *f = q.front();
        q.pop();
        cout << f->val << ": ";
        if (f->left)
        {
            cout << " L = " << f->left->val;
            q.push(f->left);
        }
        if (f->right)
        {
            cout << " R = " << f->right->val;
            q.push(f->right);
        }
        cout << endl;
    }
}

int main()
{
    vector<int> pre = {3, 9, 20, 15, 7};
    vector<int> in = {9, 3, 15, 20, 7};
    TreeNode *root = buildTree(pre, in);
    printLevelWise(root);
    return 0;
}