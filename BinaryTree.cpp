//
// Created by Mohamed Ibrahim on 05/10/2024.
//

#include "BinaryTree.h"
#include "iostream"
using namespace std;

BinaryTree::BinaryTree() :root(nullptr) {

}

void BinaryTree::insert(int data) {
    TreeNode* temp=new TreeNode(data);
    if(root==nullptr) {
        root=temp;
        return;
    }
    else {
        TreeNode* t=root;
        TreeNode* p=nullptr;
        while(t!=nullptr&&t->data!=data) {
            p=t;
            if (data<t->data) {
                t=t->left;
            }
            else if (data>t->data) {
                t=t->right;
            }
        }
        if (t==nullptr) {

            if (data<p->data) {
                p->left=temp;
            }
            else if (data>p->data) {
                p->right=temp;
            }

        }
//        if (data==t->data) {
//            cout<<"duplicate"<<endl;
//            return;
//        }
    }
}

bool BinaryTree::search(int key){
    // we need to check tree is empty or not
    if(root == nullptr){
        cout<<"Tree is empty"<<endl;
        return false;
    }

    TreeNode* t = root;
    while (t!=nullptr) {
        if (key<t->data) {
            t=t->left;
        }
        else if (key>t->data) {
            t=t->right;
        }
        else
            return true;
    }
    return false;
}



// yehia in-order
void BinaryTree::inorder(TreeNode* root) {
    if (root == nullptr) return;

    else {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);

    }

}

void BinaryTree::helperinorder() {
    inorder(root);
}

// salma pre-order
void BinaryTree::preorder(TreeNode* root) {
    if (root == nullptr) return;

    else {

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);

    }


}

void BinaryTree::helperpreorder() {
    preorder(root);
}


// ziad post-order
void BinaryTree::Postordertraversal(TreeNode* root) {

    TreeNode* temp = root;

    if (temp == nullptr) {
        return;
    }

    Postordertraversal(temp->left);
    Postordertraversal(temp->right);
    cout << temp->data << endl;
}

void BinaryTree::postorderhelper() {
    Postordertraversal(root);
}