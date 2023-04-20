#include <iostream>

using namespace std;

template < class DT, class KF >     // DT : tree data item
class BSTree                        // KF : key field

{

public:

    BSTree();  // Constructor
    ~BSTree(); // Destructor

// Binary search tree status operations

    bool isEmpty() const;                                  // Tree is empty

// Binary search tree manipulation operations

    void insert(const DT& newDataItem);                    // Insert data item
    bool find(KF searchKey) const; // retreive data item
    bool remove(KF deleteKey);                             // Remove data item
    void clear();                                          // Clear tree


// Output the tree structure

    void show() const;

private:

    class BSTreeNode

    {

    public:

        BSTreeNode(const DT& nodeDataItem, BSTreeNode* leftPtr, BSTreeNode* rightPtr); //Constructor

        // Data members

        DT dataItem;        // Binary search tree data item
        BSTreeNode* left;   // Pointer to the left child
        BSTreeNode* right;  // Pointer to the right child

    };

    // Recursive partners of the public member functions

    void insertHelper(const DT& newDataItem, BSTreeNode*& p);
    void showHelper(BSTreeNode* p, int level) const;
    bool removeHelper(BSTreeNode * &node, KF deleteKey);
    void clearHelper(BSTreeNode* node);
    bool findHelper(BSTreeNode* node, KF searchKey) const;
    typename BSTree<DT, KF>::BSTreeNode* minValue(BSTreeNode * node);


    BSTreeNode* root;   // Pointer to the root node

};


class DataNode

{

public:

    void setKey(int newKey)
    {   // Set the key
        keyField = newKey;
    }

    int getKey() const
    {    // Returns the key
        return keyField;
    }

private:

    int keyField;            // Key for the data item

};