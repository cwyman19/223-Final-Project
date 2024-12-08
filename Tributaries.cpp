#include "Tributaries.h"
#include <iostream>
using namespace std;

// Constructor
Tributaries::Tributaries() : root(nullptr) {}

// Destructor
Tributaries::~Tributaries() {
    cleanup(root);
}

// Cleanup Helper
void Tributaries::cleanup(TreeNode* node) {
    if (node) {
        cleanup(node->left);
        cleanup(node->right);
        delete node;
    }
}

// Private Recursive Insert
void Tributaries::insert(TreeNode*& node, TributaryInfo data) {
    if (!node) {
        node = new TreeNode(data);
    } else if (data.name < node->info.name) {
        insert(node->left, data);
    } else {
        insert(node->right, data);
    }
}

// Public Insert
void Tributaries::insert(TributaryInfo data) {
    insert(root, data);
}

// Recursive In-Order Traversal
void Tributaries::inOrderTraversal(TreeNode* node) {
    if (node) {
        inOrderTraversal(node->left);
        cout << "Name: " << node->info.name
             << ", Left/Right: " << node->info.leftOrRight
             << ", Length: " << node->info.length
             << ", Basin Size: " << node->info.basinSize
             << ", Avg Discharge: " << node->info.avgDischarge
             << ", Parent River: " << node->info.parentRiver
             << ", Is Parent: " << node->info.isParent << endl;
        inOrderTraversal(node->right);
    }
}

// Public Traversal
void Tributaries::traverseInOrder() {
    inOrderTraversal(root);
}
