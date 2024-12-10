#include "RiverTree.h"
#include "dataLoader.h"
#include "unitTests.cpp"
#include <iostream>
#include <cassert> // Standard assertions

int main() {
    // Run tests
    //runTests();
    // File paths
    const std::string tributaryFile = "Tributary_info_cleaned.txt";
    const std::string damFile = "Dam_info_cleaned.txt";

    // Initialize the tree
    RiverTree tree;
    tree.initializeRoot();

    // Read data
    readTributaryData(tributaryFile, tree);
    readDamData(damFile, tree);

    // Start interactive traversal
    std::cout << "Starting interactive traversal of the Columbia River and its tributaries:\n";
    tree.interactiveTraversal();

    return 0;
}