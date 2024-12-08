#ifndef TRIBUTARIES_H
#define TRIBUTARIES_H

#include <string>
using namespace std;

class Tributaries {
public:
    struct TributaryInfo {
        string name;
        string leftOrRight;
        int length;
        double basinSize;
        double avgDischarge;
        string parentRiver;
        string isParent;
    };

private:
    struct TreeNode {
        TributaryInfo info;
        TreeNode* left;
        TreeNode* right;

        TreeNode(TributaryInfo data) : info(data), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;

    void insert(TreeNode*& node, TributaryInfo data); // Private helper
    void inOrderTraversal(TreeNode* node);
    void cleanup(TreeNode* node); // Helper for destructor

public:
    Tributaries();
    ~Tributaries();

    void insert(TributaryInfo data); // Public method
    void traverseInOrder();
};

#endif
