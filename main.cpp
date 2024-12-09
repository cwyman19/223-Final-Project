#include "RiverTree.h"
#include "dataLoader.h"
#include <iostream>
//header = "Name","Left/Right","Length(km)","Basin size(km2)","Average discharge(m3/s)","Parent River","IsParent","IsDams"

int main() {
    RiverTree tree;
    tree.initializeRoot();

    // File paths
    const std::string tributaryFile = "Tributary_info_cleaned.txt";
    const std::string damFile = "Dam_info_cleaned.txt";

    // Read data
    readTributaryData(tributaryFile, tree);
    readDamData(damFile, tree);

    // Start interactive traversal
    std::cout << "Starting interactive traversal of the Columbia River and its tributaries:\n";
    tree.interactiveTraversal();

    return 0;
}
