//
// Created by Mohamed Ibrahim on 05/10/2024.
//

#ifndef SESSION_5_BINARYTREE_H
#define SESSION_5_BINARYTREE_H

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    //constructor
    TreeNode(int value):data(value), left(nullptr), right(nullptr){

    }
};

class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree();
    void insert(int value);
    bool search(int key);
    void inorder(TreeNode* );
    void Postordertraversal(TreeNode* );
    void helperinorder();
    void postorderhelper();
    void preorder(TreeNode*);
    void helperpreorder();
};


#endif //SESSION_5_BINARYTREE_H
