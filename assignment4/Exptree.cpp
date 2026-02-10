#include <iostream>
#include <string>

using namespace std;

struct ExprNode 
{
    string value;
    ExprNode* left;
    ExprNode* right;

    ExprNode(string val) : value(val), left(nullptr), right(nullptr) {}
};

void inorder(ExprNode* node) 
{
    if (node == nullptr) return;
    if (node->left || node->right) cout << "(";
    inorder(node->left);
    cout << node->value;
    inorder(node->right);
    if (node->left || node->right) cout << ")";
}

int main() 
{
    ExprNode* node_a = new ExprNode("a");
    ExprNode* node_b = new ExprNode("b");
    ExprNode* node_c = new ExprNode("c");
    ExprNode* node_d = new ExprNode("d");
    ExprNode* node_2 = new ExprNode("2");

    ExprNode* plus_ab = new ExprNode("+");
    plus_ab->left = node_a;
    plus_ab->right = node_b;

    ExprNode* mult_2_ab = new ExprNode("*");
    mult_2_ab->left = node_2;
    mult_2_ab->right = plus_ab;

    ExprNode* mult_cd = new ExprNode("*");
    mult_cd->left = node_c;
    mult_cd->right = node_d;

    ExprNode* root = new ExprNode("+");
    root->left = mult_2_ab;
    root->right = mult_cd;

    cout << "Inorder (expression): ";
    inorder(root);
    cout << endl;

    return 0;
}
