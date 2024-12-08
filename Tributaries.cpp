#include "Tributaries.h"
#include <iostream>
using namespace std;
// Constructor
Tributaries::Tributaries() : root(nullptr) {}

// Destructor
Tributaries::~Tributaries() {
    // Implement tree cleanup if necessary.
}

void Tributaries::insert(TreeNode*& node, TributaryInfo data) {
    if (!node) {
        node = new TreeNode(data);
    } else if (data.name < node->info.name) {  // Use name as the key
        insert(node->left, data);
    } else {
        insert(node->right, data);
    }
}

void Tributaries::insert(TributaryInfo data) {
    insert(root, data);
}

void Tributaries::inOrderTraversal(TreeNode* node) {
    if (node) {
        inOrderTraversal(node->left);
        cout << "Name: " << node->info.name << ", Discharge: " << node->info.avgDischarge << endl;
        inOrderTraversal(node->right);
    }
}

void Tributaries::traverseInOrder() {
    inOrderTraversal(root);
}
