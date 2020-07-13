#include <iostream>
using namespace std;

struct TreeNode  {
int val;   //1~9
struct TreeNode *left;
struct TreeNode *right;
};

struct TreeNode* newNode(int data) {
    struct TreeNode* node = new struct TreeNode();
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int pseudoPolindromicPaths (TreeNode *root, int s = 0){
    if(!root) return 0;
    s ^= (1 << root->val);      //s is a bit number
    if(!root->left && !root->right)
        return __builtin_popcount(s) <= 1;
    int ans = 0;
    ans +=  pseudoPolindromicPaths(root->left, s);
    ans +=  pseudoPolindromicPaths(root->right, s);
    return s;
}

int main()
{
    struct TreeNode *root = newNode(2);
    root->left = newNode(3);
    root->left->left = newNode(3);
    root->left->right = newNode(1);

    root->right = newNode(1);
    root->right->right = newNode(1);

    cout << pseudoPolindromicPaths(root);

 	return 0;
}
