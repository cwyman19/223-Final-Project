#include "Rivertree.h"
#include "dataLoader.h"

int main() {
    RiverTree tree;

    // File paths
    const std::string tributaryFile = "Tributary_info_cleaned.csv";
    const std::string damFile = "Dam_info_cleaned.csv";

    // Read data
    readTributaryData(tributaryFile, tree);
    readDamData(damFile, tree);

    // Start interactive traversal
    std::cout << "Starting interactive traversal of the Columbia River and its tributaries:\n";
    tree.interactiveTraversal();

    return 0;
}
