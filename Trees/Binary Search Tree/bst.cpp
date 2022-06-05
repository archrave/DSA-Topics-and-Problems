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

class BST
{
    void printLevelWise(TreeNode<int> *root)
    {
        if (!root)
            return;
        cout << endl;
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

    bool _hasData(TreeNode<int> *node, int data)
    {
        if (!node)
            return false;
        if (node->data == data)
        {
            return true;
        }
        else if (data < node->data)
        {
            return _hasData(root->left, data);
        }
        else
        {
            return _hasData(root->right, data);
        }
    }
    TreeNode<int> *_insert(TreeNode<int> *root, int data)
    {
        if (!root)
        {
            root = new TreeNode<int>(data);
            return root;
        }

        if (data < root->data)
            root->left = _insert(root->left, data);
        else if (data > root->data)
            root->right = _insert(root->right, data);
        else
            cout << "\nA node with the same value already exists!\n";

        return root;
    }
    int _min(TreeNode<int> *root)
    {
        if (!root)
            return INT_MAX;
        TreeNode<int> *temp = root;
        while (temp->left)
        {
            temp = temp->left;
        }
        return temp->data;
    }
    TreeNode<int> *_delete(TreeNode<int> *root, int data)
    {
        if (!root)
            return root;
        if (data == root->data)
        {
            if (!root->right && !root->left)
            {
                delete root;
                return NULL;
            }
            else if (root->right && !root->left)
            {
                TreeNode<int> *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else if (root->left && !root->right)
            {
                TreeNode<int> *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else
            {

                int minVal = _min(root->right);
                root->data = minVal;
                root->right = _delete(root->right, minVal);
                return root;
            }
        }
        else if (data < root->data)
        {
            root->left = _delete(root->left, data);
        }
        else
        {
            root->right = _delete(root->right, data);
        }
        return root;
    }

    pair<TreeNode<int> *, TreeNode<int> *> _convertToLL(TreeNode<int> *root)
    {
        pair<TreeNode<int> *, TreeNode<int> *> p;
        if (!root)
        {
            p.first = NULL;
            p.second = NULL;
            return p;
        }
        if (!root->left && !root->right)
        {
            p.first = root;
            p.second = root;
        }
        else if (!root->left && root->right)
        {
            p = _convertToLL(root->right);
            root->right = p.first;
            p.first = root;
        }
        else if (root->left && !root->right)
        {
            p = _convertToLL(root->left);
            p.second->right = root;
            p.second = root;
            root->left = NULL;
        }
        else
        {
            pair<TreeNode<int> *, TreeNode<int> *> p1;
            p = _convertToLL(root->left);
            p1 = _convertToLL(root->right);
            root->left = NULL;
            p.second->right = root;
            root->right = p1.first;
            p.second = p1.second;
        }
        return p;
    }

public:
    TreeNode<int> *root;

    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }

    int min()
    {
        return _min(root);
    }

    void print()
    {
        printLevelWise(root);
    }

    void deleteData(int data)
    {
        root = _delete(root, data);
    }

    void insert(int data)
    {
        _insert(root, data);
    }

    bool hasData(int data)
    {
        return _hasData(root, data);
    }

    // A singly linked list iwth connnections with the 'right' pointer Or a Right skewed BST

    pair<TreeNode<int> *, TreeNode<int> *> convertToLL()
    {
        pair<TreeNode<int> *, TreeNode<int> *> p = _convertToLL(root);
        root = p.first;
    }
};

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

// Recursive
int maxValueInBST(TreeNode<int> *root)
{
    if (!root)
        return INT_MIN;
    if (!root->right)
    {
        return root->data;
    }
    return maxValueInBST(root->right);
}

int main()
{
    // 1 2 3 4 5 -1 -712 -1 -1 -1 6 -1 -1 -1 -1
    // 6 4 10 1 5 7 12 -1 -1 -1 -1 -1 8 -1 -1 -1 -1

    // 10 7 12 -1 8 -1 -1 -1 -1
    // 5 1 4 -1 -1 3 6

    BST bst;
    bst.root = takeInputLevelWise();
    bst.print();
    bst.convertToLL();

    // bst.insert(2);
    // bst.deleteData(1);
    // bst.deleteData(6);
    // bst.hasData();
    bst.print();
    return 0;
}
