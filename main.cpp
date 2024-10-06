#include <iostream>
#include "BinaryTree.h"

using namespace std;
int main() {
    BinaryTree tree;

    tree.insert(3);
    tree.insert(1);
    tree.insert(2);
    tree.insert(4);

    if(tree.search(3)){
        cout<<"Value is in tree"<<endl;
    }else{
        cout<<"Value not found"<<endl;
    }

    tree.helperinorder();
    tree.postorderhelper();
    tree.helperpreorder();
    return 0;
}
