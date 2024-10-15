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

bool BinaryTree::deleteNode(int key){
    if (root== nullptr) return false;    //if empty tree

    TreeNode* t = root;
    if(search(key)){               //check the presence  of the value
        while (t != nullptr && t->data != key) {
            if (key < t->data) {
                t = t->left;
            }
            else if (key > t->data) {
                t = t->right;
            }
        }
        if(t->left == nullptr && t->right == nullptr){   //this is a leaf node
            cout<<"This is leaf node target"<<endl;
            delete t;
            return true;
        }
        else if (t->left == nullptr){
            TreeNode* temp = t;
            t = t->right;
            delete temp;
        }else if (t->right == nullptr){
            TreeNode* temp = t;
            t = t->left;
            delete temp;
        }else{
            TreeNode* temp = t;
            t = t->right;
            delete temp;
        }
    }
    return false;

}

void BinaryTree::printTree(TreeNode* root, int space) {
    if (root == nullptr) {
        return;
    }

    space += 10;

    printTree(root->right, space);

    cout << endl;
    for (int i = 10; i < space; i++) {
        cout << " ";
    }
    cout << root->data << "\n";

    // Process left child
    printTree(root->left, space);
}

void BinaryTree::printHelper() {
    printTree(root, 0);
}