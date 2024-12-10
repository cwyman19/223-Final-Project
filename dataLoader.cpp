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
#include <algorithm>
#include <cctype>
#include <string>

// Helper to clean numeric strings: remove commas and quotes
std::string cleanNumericString(const std::string& input) {
    std::string result;
    bool insideQuotes = false;

    for (char ch : input) {
        if (ch == '"') {
            insideQuotes = !insideQuotes;
        } else if (ch == ',' && !insideQuotes) {
            continue; // Skip commas outside quotes
        } else if (ch != '\n' && ch != '\r') {
            result += ch; // Skip newline characters
        }
    }

    // Trim whitespace from the result
    result.erase(result.begin(), std::find_if(result.begin(), result.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    result.erase(std::find_if(result.rbegin(), result.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), result.end());

    return result;
}



// Updated readTributaryData function
void readTributaryData(const std::string& filename, RiverTree& tree) {
    auto data = ReadCSV::read(filename);
    int lineNumber = 0;
    double length;
    double basinSize;
    double avgDischarge;

    std::cout << "Starting to read file: " << filename << "\n";

    for (const auto& row : data) {
        ++lineNumber;

        if (row.size() < 8) {
            std::cerr << "Skipping line " << lineNumber << ": insufficient columns\n";
            continue;
        }

        try {
            std::string name = row[0];


            std::string side = row[1];


            std::string rawLength = row[2];
            std::string rawBasinSize = row[3];
            std::string rawAvgDischarge = row[4];


            try {
                length = !rawLength.empty() ? std::stod(cleanNumericString(rawLength)) : 0.0;
                basinSize = !rawBasinSize.empty() ? std::stod(cleanNumericString(rawBasinSize)) : 0.0;
                avgDischarge = !rawAvgDischarge.empty() ? std::stod(cleanNumericString(rawAvgDischarge)) : 0.0;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error converting string to number: " << e.what() << "\n";
                continue;
}


            std::string parent = row[5];

            bool isParent = (row[6] == "Yes");

            bool isDams = (row[7] == "Yes");

            tree.addRiver(name, side, length, basinSize, avgDischarge, parent, isParent, isDams);

        } catch (const std::exception& e) {
            std::cerr << "Error processing line " << lineNumber << ": ";
            for (const auto& col : row) std::cerr << col << " ";
            std::cerr << "\nException: " << e.what() << "\n";
        }
    }

    std::cout << "Finished processing file.\n";
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
