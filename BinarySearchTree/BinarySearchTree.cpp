#include <BinarySearchTree.h>
#include <iostream>


using namespace std;


template<class DT, class KF> 
BSTree<DT, KF>::BSTree(){

    root = NULL;
}


template<class DT, class KF> 
BSTree<DT, KF>::~BSTree(){

    clear();

}

// delete all nodes of tree
template<class DT, class KF>
void BSTree<DT, KF>::clear() {

    clearHelper(root);
    root = nullptr;
}


template<class DT, class KF>
void BSTree<DT, KF>::clearHelper(BSTreeNode* node) {

    if (node == nullptr) {
        return;
    }

    clearHelper(node->left);
    clearHelper(node->right);
    delete node;
}


template<class DT, class KF> 
BSTree<DT, KF>::BSTreeNode::BSTreeNode(const DT& nodeDataItem, BSTreeNode* leftPtr, BSTreeNode* rightPtr) {

    dataItem = nodeDataItem;
    left = leftPtr;
    right = rightPtr;

}


template<class DT, class KF>
bool BSTree<DT, KF>::isEmpty() const{
    //If the root is NULL, then obviously the tree doesn't have anything in it
    return (root == NULL);

}


template<class DT, class KF>
void BSTree<DT, KF>::insert(const DT& newDataItem) {

    insertHelper(newDataItem, root);

}


template<class DT, class KF>
void BSTree<DT, KF>::insertHelper(const DT& newDataItem, BSTreeNode*& p) {
    //Base case, p is NULL so there is room to insert
    if (p == NULL)
    {
        p = new BSTreeNode(newDataItem, NULL, NULL);
    }
    else
    {
        if ((p->dataItem).getKey() == newDataItem.getKey())
            p->dataItem = newDataItem;
        else if ((p->dataItem).getKey() > newDataItem.getKey())
            insertHelper(newDataItem, p->left);
        else
            insertHelper(newDataItem, p->right);
    }

}


template<class DT, class KF>
bool BSTree<DT, KF>::remove(KF deleteKey) {

    return removeHelper(root, deleteKey);
}


template<class DT, class KF>
bool BSTree<DT, KF>::removeHelper(BSTreeNode*& node, KF deleteKey) {

    if (node == nullptr) {
        return false; // Key not found
    }

    if (deleteKey < node->dataItem.getKey()) {
        return removeHelper(node->left, deleteKey);
    }
    else if (deleteKey > node->dataItem.getKey()) {
        return removeHelper(node->right, deleteKey);
    }
    else {
        // Node found, delete
        if (node->left == nullptr) {
            BSTreeNode* temp = node->right;
            delete node;
            node = temp;
        }
        else if (node->right == nullptr) {
            BSTreeNode* temp = node->left;
            delete node;
            node = temp;
        }
        else {
            // Node has 2 path
            node->dataItem = minValue(node->right)->dataItem;
            removeHelper(node->right, node->dataItem.getKey());
        }
        return true;
    }
}


template<class DT, class KF>
typename BSTree<DT, KF>::BSTreeNode* BSTree<DT, KF>::minValue(BSTreeNode* node) {

    BSTreeNode* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

template<class DT, class KF>
bool BSTree<DT, KF>::find(KF searchKey) const {
    return findHelper(root, searchKey);
}

template<class DT, class KF>
bool BSTree<DT, KF>::findHelper(BSTreeNode* node, KF searchKey) const {
    if (node == nullptr) {
        return false;
    }

    if (node->dataItem.getKey() == searchKey) {
        return true;
    }

    return findHelper(node->left, searchKey) || findHelper(node->right, searchKey);
}


template<class DT, class KF>
void BSTree<DT, KF>::show() const {

    if (root == NULL)
        cout << "*** Empty tree ***" << endl;

    else

    {
        cout << endl;
        showHelper(root, 1);
        cout << endl;
    }

}



template<class DT, class KF>
void BSTree<DT, KF>::showHelper(BSTreeNode* p, int level) const
// Recursive helper for show.
{
    int j;   // Loop counter

    if (p != NULL)

    {
        showHelper(p->right, level + 1);         // Output right subtree
        for (j = 0; j < level; j++)       // Tab over to level
            cout << "\t";

        cout << " " << p->dataItem.getKey();  // Output key

        if ((p->left != NULL) && (p->right != NULL)) // Output "connector"
            cout << "<";
        else if (p->right != NULL)
            cout << "/";
        else if (p->left != NULL)
            cout << "\\";
        cout << endl;

        showHelper(p->left, level + 1);          // Output left subtree

    }

};
