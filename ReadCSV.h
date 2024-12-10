#ifndef READCSV_H
#define READCSV_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class ReadCSV {
public:
    static std::vector<std::vector<std::string>> read(const std::string& filename) {
        std::ifstream file(filename);
        std::vector<std::vector<std::string>> data;
        std::string line;

        while (std::getline(file, line)) {
            std::vector<std::string> row;
            std::stringstream ss(line);
            std::string cell;
            bool insideQuotes = false;

            for (char ch : line) {
                if (ch == '"') {
                    insideQuotes = !insideQuotes; // Toggle quote state
                } else if (ch == ',' && !insideQuotes) {
                    row.push_back(cell);
                    cell.clear();
                } else {
                    cell += ch;
                }
            }
            if (!cell.empty()) {
                row.push_back(cell);
            }

            data.push_back(row);
        }
        return data;
    }
};

#endif // READCSV_H
