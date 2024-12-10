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
    std::string river;

    Dam(std::string n, std::string h, int c, int y, std::string r, std::string ri)
        : name(std::move(n)), height(std::move(h)), capacity(c), yearCompleted(y), reservoir(std::move(r)), river(std::move(ri)) {}
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

    River(std::string n, std::string s, double l, double b, double a, std::string p, bool ip, bool id)
        : name(std::move(n)), side(std::move(s)), length(l), basinSize(b), avgDischarge(a), parent(std::move(p)), isParent(ip), isDams(id) {}

};

class RiverTree {
private:
    struct Node {
        std::shared_ptr<River> river;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        std::shared_ptr<Node> parent; // New parent pointer

        explicit Node(std::shared_ptr<River> r) : river(std::move(r)), left(nullptr), right(nullptr), parent(nullptr) {}
    };
    std::vector<std::shared_ptr<Dam>> dams;
    std::shared_ptr<Node> root;
    bool addingDam(const std::shared_ptr<Dam>& dam) {
        dams.push_back(dam);
        return true;
    }
    void addRiverHelper(std::shared_ptr<Node>& node, const std::shared_ptr<River>& river, std::shared_ptr<Node>& prev) {
    if (!node) {
        std::cerr << "Null node encountered.\n";
        return;
    }

    if (node->left == nullptr && node->river->name == river->parent) {
        if (river->side == "Left") {
            node->left = std::make_shared<Node>(river);
            node->left->parent = node; // Update parent pointer
            node->right = std::make_shared<Node>(node->river);
            node->right->parent = node; // Update parent pointer
        } else {
            node->right = std::make_shared<Node>(river);
            node->right->parent = node; // Update parent pointer
            node->left = std::make_shared<Node>(node->river);
            node->left->parent = node; // Update parent pointer
        }
        return;
    }

    if (river->parent == node->river->name && node->left != nullptr) {
        addRiverHelper(node->left, river, node);
    } else if (river->parent != node->river->name) {
        if (node->left != nullptr) {
            addRiverHelper(node->left, river, node);
        } else {
            addRiverHelper(prev->right, river, node);
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
    
    std::shared_ptr<Node> searchTreeDFS(const std::shared_ptr<Node>& node, const std::string& riverName) {
        if (!node) return nullptr;
        if (node->river->name == riverName) return node;
        auto leftResult = searchTreeDFS(node->left, riverName);
        if (leftResult) return leftResult;
        return searchTreeDFS(node->right, riverName);
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
        /*if (!river->dams.empty()) {
            std::cout << "  Dams:\n";
            for (const auto& dam : river->dams) {
                std::cout << "    - " << dam->name << " (Height: " << dam->height
                          << ", Capacity: " << dam->capacity << " MW, Completed: "
                          << dam->yearCompleted << ", Reservoir: " << dam->reservoir << ")\n";
            }
        }*/
    }

public:
    RiverTree() : root(nullptr) {}
    
    void initializeRoot() {
        auto river = std::make_shared<River>("Columbia", "", 2000, 670000, 6650, "Columbia", true, true);
        root = std::make_shared<Node>(river);
    }

    void addRiver(const std::string& name, const std::string& side, double length, double basinSize, double avgDischarge,
        const std::string& parent, bool isParent, bool isDams) {
        // std::cout << "Adding river: " << name << "\n";
        // std::cout << "Parent: " << parent << "\n";

        // Create the river
        auto river = std::make_shared<River>(name, side, length, basinSize, avgDischarge, parent, isParent, isDams);

        // Find the parent location
        auto locationRoot = searchTreeDFS(root, parent);
        if (locationRoot == nullptr) {
            std::cerr << "Error: Parent river '" << parent << "' not found in the tree.\n";
            if (!isParent) {
                std::cerr << "Cannot add tributary '" << name << "' without a valid parent.\n";
                return;
            } else {
                // Handle creating a new root for parent if it's missing
                std::cout << "Adding new root parent river: " << parent << "\n";
                // Add the missing parent river
                this->addRiver(parent, "Unknown", 0.0, 0.0, 0.0, "", true, false);
                locationRoot = searchTreeDFS(root, parent); // Reattempt to find the parent
            }
        }

        // Add the river
        try {
            addRiverHelper(locationRoot, river, locationRoot);
        } catch (const std::exception& e) {
            std::cerr << "Exception while adding river '" << name << "': " << e.what() << "\n";
        }
    }


    bool addDam(const std::string& damName, const std::string& height, int capacity, int yearCompleted, const std::string& reservoir, const std::string& riverName) {
        auto dam = std::make_shared<Dam>(damName, height, capacity, yearCompleted, reservoir, riverName);
        addingDam(dam);
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
            printRiver(current->river);

            // Show available options based on node connections
            std::cout << "Options:\n";
            if (current->left) {
                std::cout << "1. Go to the left tributary: " << current->left->river->name << "\n";
            }
            if (current->right) {
                std::cout << "2. Go to the right tributary: " << current->right->river->name << "\n";
            }
            if (current->parent) {
                std::cout << "3. Go back to the parent river: " << current->parent->river->name << "\n";
            }
            std::cout << "4. View dams on this river\n";
            std::cout << "5. Quit Program\n";

            // Input from the user
            std::cout << "Enter your choice: ";
            int choice;
            std::cin >> choice;

            if (choice == 1 && current->left) {
                current = current->left;
            } else if (choice == 2 && current->right) {
                current = current->right;
            } else if (choice == 3 && current->parent) {
                current = current->parent;
            } else if (choice == 4) {
                if (current->river->isDams) {
                    std::cout << "Dams on the " << current->river->name << " River:\n";
                    bool hasDams = false;
                    for (const auto& dam : dams) {
                        if (dam->river == current->river->name) {
                            hasDams = true;
                            std::cout << "  - " << dam->name << " (Height: " << dam->height
                                    << ", Capacity: " << dam->capacity << " MW, Completed: "
                                    << dam->yearCompleted << ", Reservoir: " << dam->reservoir << ")\n";
                        }
                    }
                    if (!hasDams) {
                        std::cout << "  No dams found for this river.\n";
                    }
                } else {
                    std::cout << "No dams are associated with the " << current->river->name << " River.\n";
                }
            } else if (choice == 5) {
                std::cout << "Exiting program.\n";
                exit(0);
            } else {
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
    }

};

#endif