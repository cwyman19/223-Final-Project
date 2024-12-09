#include "dataLoader.h"
#include "ReadCSV.h"
#include <iostream>
#include <algorithm>

// Function to check if a string is numeric
bool isNumeric(const std::string& str) {
    return !str.empty() && std::all_of(str.begin(), str.end(), [](char c) {
        return std::isdigit(c) || c == '.' || c == '-';
    });
}

// Function to read tributary data from a CSV file and add it to the RiverTree
void readTributaryData(const std::string& filename, RiverTree& tree) {
    auto data = ReadCSV::read(filename);
    int lineNumber = 0;
    for (const auto& row : data) {
        ++lineNumber;
        if (row.size() < 8) {
            std::cerr << "Skipping line " << lineNumber << ": insufficient columns\n";
            continue;
        }
        //std::cout << "row: " << row[0] << std::endl;
        try {
            std::string name = row[0];
            std::string side = row[1];
            double length = isNumeric(row[2]) ? std::stod(row[2]) : 0.0;
            double basinSize = isNumeric(row[3]) ? std::stod(row[3]) : 0.0;
            double avgDischarge = isNumeric(row[4]) ? std::stod(row[4]) : 0.0;
            std::string parent = row[5];
            bool isParent = (row[6] == "Yes") ? true:false;
            bool isDams = (row[7] == "Yes") ? true:false;

            tree.addRiver(name, side, length, basinSize, avgDischarge, parent, isParent, isDams);
        } catch (const std::exception& e) {
            std::cerr << "Error processing line " << lineNumber << ": ";
            for (const auto& col : row) std::cerr << col << " ";
            std::cerr << "\nException: " << e.what() << "\n";
        }
    }
}

// Function to read dam data from a CSV file and add it to the RiverTree
void readDamData(const std::string& filename, RiverTree& tree) {
    auto data = ReadCSV::read(filename);
    int lineNumber = 0;
    for (const auto& row : data) {
        ++lineNumber;
        if (row.size() < 6) {
            std::cerr << "Skipping line " << lineNumber << ": insufficient columns\n";
            continue;
        }

        try {
            std::string damName = row[0];
            std::string height = row[1];
            int capacity = isNumeric(row[2]) ? std::stoi(row[2]) : 0;
            int yearCompleted = isNumeric(row[3]) ? std::stoi(row[3]) : 0;
            std::string reservoir = row[4];
            std::string riverName = row[5];

            tree.addDam(damName, height, capacity, yearCompleted, reservoir, riverName);
        } catch (const std::exception& e) {
            std::cerr << "Error processing line " << lineNumber << ": ";
            for (const auto& col : row) std::cerr << col << " ";
            std::cerr << "\nException: " << e.what() << "\n";
        }
    }
}
