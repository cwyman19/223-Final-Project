#include "Tributaries.h"
#include <iostream>  // For std::cout
#include <fstream>   // For file operations
#include <sstream>   // For string stream
#include <vector>    // For vector

using namespace std;  // Optional: Allows direct use of cout, cin, etc.

void loadFromCSV(Tributaries& tree, const string& filePath) {
    ifstream file(filePath);
    string line, word;
    vector<string> row;

    while (getline(file, line)) {
        stringstream ss(line);
        row.clear();

        while (getline(ss, word, ',')) {
            row.push_back(word);
        }

        if (row.size() < 7) continue; // Skip invalid rows.

        Tributaries::TributaryInfo info = { row[0], row[1], stoi(row[2]), stod(row[3]), stod(row[4]), row[5], row[6] };
        tree.insert(info);
    }
}

int main() {
    Tributaries tree;

    loadFromCSV(tree, "/mnt/data/Tributary_info_cleaned.csv");
    
    // Output using std::cout
    cout << "In-Order Traversal of Tributaries:" << endl;
    tree.traverseInOrder();

    return 0;
}
