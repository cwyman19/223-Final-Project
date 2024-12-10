#include "RiverTree.h"
#include "dataLoader.h"
#include <iostream>
#include <cassert> // Standard assertions

void runTests() {
    // Initialize the tree
    RiverTree tree;
    tree.initializeRoot();

    // Test root initialization
    auto root = tree.searchRiver("Columbia");
    assert(root != nullptr); // Ensure the root is created
    assert(root->name == "Columbia");
    assert(root->length == 2000);
    assert(root->isParent == true);

    // Test adding rivers
    tree.addRiver("Willamette", "Right", 187, 29600, 680, "Columbia", false, true);

    auto willamette = tree.searchRiver("Willamette");
    assert(willamette != nullptr);
    assert(willamette->name == "Willamette");
    assert(willamette->parent == "Columbia");
    assert(willamette->side == "Right");

    // Test adding dams
    tree.addDam("Grand Coulee", "168 m", 6809, 1942, "Franklin D. Roosevelt Lake", "Columbia");
    tree.addDam("Hells Canyon", "100 m", 1167, 1967, "Hells Canyon Reservoir", "Snake");

    bool foundGrandCoulee = false;
    bool foundHellsCanyon = false;

    for (const auto& dam : tree.getDams()) {
        if (dam->name == "Grand Coulee" && dam->river == "Columbia") {
            foundGrandCoulee = true;
        } else if (dam->name == "Hells Canyon" && dam->river == "Snake") {
            foundHellsCanyon = true;
        }
    }

    assert(foundGrandCoulee); // Ensure "Grand Coulee" dam exists
    assert(foundHellsCanyon); // Ensure "Hells Canyon" dam exists

    // Test tree traversal
    std::cout << "Testing in-order traversal:\n";
    tree.inOrderTraversal();

    // Verify river hierarchy
    auto columbia = tree.searchRiver("Columbia");
    assert(columbia != nullptr && columbia->isParent == true);

    auto willametteNode = tree.searchRiver("Willamette");
    assert(willametteNode != nullptr && willametteNode->parent == "Columbia");

    // Test searching for a non-existent river
    auto nonexistentRiver = tree.searchRiver("Amazon");
    assert(nonexistentRiver == nullptr); // Ensure it returns nullptr

    std::cout << "All tests passed successfully!\n";
}
