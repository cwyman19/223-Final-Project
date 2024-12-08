#include "Tributaries.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void loadFromCSV(Tributaries& tree) {
    const string filePath = "Tributary_info_cleaned.csv"; // File in the same folder as the executable
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error: Could not open file: " << filePath << endl;
        return;
    }

    string line, word;
    vector<string> row;

    while (getline(file, line)) {
        stringstream ss(line);
        row.clear();

        while (getline(ss, word, ',')) {
            row.push_back(word);
        }

        if (row.size() < 7) continue; // Skip invalid rows.

        try {
            // Convert string values to the correct data types with error handling
            Tributaries::TributaryInfo info = {
                row[0], // name
                row[1], // leftOrRight
                stoi(row[2]), // length, may throw std::invalid_argument
                stod(row[3]), // basinSize
                stod(row[4]), // avgDischarge
                row[5], // parentRiver
                row[6]  // isParent
            };
            tree.insert(info);
        } catch (const std::invalid_argument& e) {
            cerr << "Invalid data on line: " << line << " (" << e.what() << ")\n";
        } catch (const std::out_of_range& e) {
            cerr << "Value out of range on line: " << line << " (" << e.what() << ")\n";
        }
    }

    file.close();
}

int main() {
    Tributaries tree;

    loadFromCSV(tree);
    
    cout << "\nIn-Order Traversal of Tributaries:\n";
    tree.traverseInOrder();

    return 0;
}
