#ifndef RIVER_TREE_H
#define RIVER_TREE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

struct Dam {
    std::string name;
    std::string height;
    int capacity; // in MW
    int yearCompleted;
    std::string reservoir;

    Dam(std::string n, std::string h, int c, int y, std::string r)
        : name(std::move(n)), height(std::move(h)), capacity(c), yearCompleted(y), reservoir(std::move(r)) {}
};

struct River {
    std::string name;
    std::string side; // Left or Right
    double length; // in km
    double basinSize; // in km²
    double avgDischarge; // in m³/s
    std::string parent;
    bool isParent;
    bool isDams;
    std::vector<std::shared_ptr<Dam>> dams;

    River(std::string n, std::string s, double l, double b, double a, std::string p, bool ip, bool id)
        : name(std::move(n)), side(std::move(s)), length(l), basinSize(b), avgDischarge(a), parent(std::move(p)), isParent(ip), isDams(id) {}

    void addDam(const std::shared_ptr<Dam>& dam) {
        dams.push_back(dam);
    }
};

class RiverTree {
private:
    struct Node {
        std::shared_ptr<River> river;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;

        explicit Node(std::shared_ptr<River> r) : river(std::move(r)), left(nullptr), right(nullptr) {}
    };

    std::shared_ptr<Node> root;

    void addRiverHelper(std::shared_ptr<Node>& node, const std::shared_ptr<River>& river) {
        //std::cout << "Node River Parent: " << node->river->parent << std::endl;
        //std::cout << "River Name: " << river->name << std::endl;
        //std::cout << "River Side: " << river->side << std::endl;
        if (node->left == nullptr && node->river->name == river->parent) {
            if (river->side == "Left") {
                std::cout << "addLeft" << std::endl;
                std::cout << "River Name: " << river->name << std::endl;
                std::cout << "----------------------------" << std::endl;
                node->left = std::make_shared<Node>(river);
                node->right = std::make_shared<Node>(node->river);
                return;
            } else {
                std::cout << "addRight" << std::endl;
                std::cout << "River Name: " << river->name << std::endl;
                std::cout << "----------------------------" << std::endl;
                node->right = std::make_shared<Node>(river);
                node->left = std::make_shared<Node>(node->river);
                return;
            }
        }
        else if (river->parent == node->river->name && node->left != nullptr) {
            addRiverHelper(node->left, river);
        } else if (river->parent != node->river->name)
        {
            if (node->left != nullptr) {
                addRiverHelper(node->left, river);
            }
            else if (node->right != nullptr) {
                //std::cout << "[right]";
                addRiverHelper(node->right, river);
            }
        }
    }

    std::shared_ptr<Node> searchRiverHelper(const std::shared_ptr<Node>& node, const std::string& riverName) const {
        if (!node || node->river->name == riverName) {
            return node;
        }
        if (riverName < node->river->name) {
            return searchRiverHelper(node->left, riverName);
        } else {
            return searchRiverHelper(node->right, riverName);
        }
    }

    void inOrderTraversalHelper(const std::shared_ptr<Node>& node) const {
        if (!node) return;
        inOrderTraversalHelper(node->left);
        printRiver(node->river);
        inOrderTraversalHelper(node->right);
    }

    void printRiver(const std::shared_ptr<River>& river) const {
        std::cout << "River: " << river->name << " (Side: " << river->side
                  << ", Length: " << river->length << " km, Basin Size: " << river->basinSize
                  << " km², Avg Discharge: " << river->avgDischarge << " m³/s)\n";
        if (!river->dams.empty()) {
            std::cout << "  Dams:\n";
            for (const auto& dam : river->dams) {
                std::cout << "    - " << dam->name << " (Height: " << dam->height
                          << ", Capacity: " << dam->capacity << " MW, Completed: "
                          << dam->yearCompleted << ", Reservoir: " << dam->reservoir << ")\n";
            }
        }
    }

public:
    RiverTree() : root(nullptr) {}
    
    void initializeRoot() {
        auto river = std::make_shared<River>("Columbia", "", 2000, 670000, 6650, "Columbia", true, true);
        root = std::make_shared<Node>(river);
    }

    void addRiver(const std::string& name, const std::string& side, double length, double basinSize, double avgDischarge,
    const std::string& parent, bool isParent, bool isDams) {
        auto river = std::make_shared<River>(name, side, length, basinSize, avgDischarge, parent, isParent, isDams);
        addRiverHelper(root, river);
    }

    bool addDam(const std::string& riverName, const std::string& damName, const std::string& height, int capacity, int yearCompleted, const std::string& reservoir) {
        auto riverNode = searchRiverHelper(root, riverName);
        if (!riverNode) {
            return false;
        }
        auto dam = std::make_shared<Dam>(damName, height, capacity, yearCompleted, reservoir);
        riverNode->river->addDam(dam);
        return true;
    }

    std::shared_ptr<River> searchRiver(const std::string& riverName) const {
        auto riverNode = searchRiverHelper(root, riverName);
        return riverNode ? riverNode->river : nullptr;
    }

    void inOrderTraversal() const {
        inOrderTraversalHelper(root);
    }

    bool containsRiver(const std::string& riverName) const {
        return searchRiverHelper(root, riverName) != nullptr;
    }

    void interactiveTraversal() const {
        auto current = root;
        while (current) {
            // Print the current river and its dams
            printRiver(current->river);

            // Show two options if they exist
            if (current->left && current->right) {
                std::cout << "Options:\n";
                std::cout << "1. Go to the left tributary: " << current->left->river->name << "\n";
                std::cout << "2. Go to the right tributary: " << current->right->river->name << "\n";
                std::cout << "3. Quit Program\n"; 
                std::cout << "Enter 1 or 2 to choose: ";

                int choice;
                std::cin >> choice;

                if (choice == 1) {
                    current = current->left;
                } else if (choice == 2) {
                    current = current->right;
                } else if (choice == 3) {
                    exit(1);
                } else {
                    std::cout << "Invalid choice. Exiting traversal.\n";
                    break;
                }
            } else if (current->left) {
                std::cout << "Only one option available: Go to the left tributary: " << current->left->river->name << "\n";
                current = current->left;
            } else if (current->right) {
                std::cout << "Only one option available: Go to the right tributary: " << current->right->river->name << "\n";
                current = current->right;
            } else {
                std::cout << "No more tributaries. End of traversal.\n";
                break;
            }
        }
    }
};

#endif