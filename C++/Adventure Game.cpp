//Adventure Game
//Nickalus Lowrey
//Version 2.5.2

//Game is an endless loop I think
//forgot how to refresh the screen after each imput
//Intructions should work
//May or May not work

#include <iostream>
#include <string>
#include <vector>

std::string playerName;
int playerHealth = 100;
int playerGold = 0;

// Inventory system
struct Item {
    std::string name;
    std::string description;
    bool isUsable;
    int healAmount;  // Amount of health restored if it's a healing item
};

std::vector<Item> inventory;

// Function to use item
void useItem(int itemIndex) {
    if (itemIndex >= 0 && itemIndex < inventory.size()) {
        Item& item = inventory[itemIndex];

        if (item.isUsable) {
            if (item.name.find("Potion") != std::string::npos || 
                item.name.find("Fruit") != std::string::npos) {
                int oldHealth = playerHealth;
                playerHealth += item.healAmount;
                if (playerHealth > 100) playerHealth = 100;
                std::cout << "\nUsed " << item.name << "! Restored " 
                         << (playerHealth - oldHealth) << " health.\n";
                // Remove the item after use
                inventory.erase(inventory.begin() + itemIndex);
            }
        } else {
            std::cout << "\nThis item cannot be used!\n";
        }
    } else {
        std::cout << "\nInvalid item number!\n";
    }
}

// Function to display inventory with usable items
void showInventory() {
    std::cout << "\n=== Inventory ===\n";
    if (inventory.empty()) {
        std::cout << "Your inventory is empty!\n";
    } else {
        std::cout << "Items:\n";
        for (size_t i = 0; i < inventory.size(); i++) {
            std::cout << i + 1 << ". " << inventory[i].name << " - " 
                     << inventory[i].description;
            if (inventory[i].isUsable) {
                std::cout << " [Usable]";
            }
            std::cout << "\n";
        }

        std::cout << "\nWould you like to use an item? (1-" << inventory.size() 
                 << ", or 0 to cancel): ";
        int choice;
        std::cin >> choice;
        if (choice > 0 && choice <= inventory.size()) {
            useItem(choice - 1);
        }
    }
    std::cout << "Gold: " << playerGold << "\n";
}

// Function to add item to inventory
void addItem(std::string name, std::string description, bool isUsable = false, int healAmount = 0) {
    Item newItem = {name, description, isUsable, healAmount};
    inventory.push_back(newItem);
    std::cout << "\nAdded " << name << " to inventory!\n";
}

int start() {
    int choice;

    std::cout << "\nWelcome brave adventurer!\n";
    std::cout << "What is your name? ";
    std::cin.ignore();
    std::getline(std::cin, playerName);

    std::cout << "\nGreetings, " << playerName << "! Your adventure begins...\n";

    while (true) {
        std::cout << "\n=== Current Status ===\n";
        std::cout << "Health: " << playerHealth << "/100\n";
        std::cout << "Gold: " << playerGold << "\n";
        std::cout << "\nYou find yourself in a mysterious valley. Ahead you see:\n";
        std::cout << "1. A dark cave entrance\n";
        std::cout << "2. A winding forest path\n";
        std::cout << "3. Check inventory\n";
        std::cout << "4. Return to main menu\n";
        std::cout << "Choose your path (1-4): ";

        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "\nYou approach the cave...\n";
                std::cout << "1. Enter deeper into the cave\n";
                std::cout << "2. Search near the entrance\n";
                std::cout << "Choose (1-2): ";
                int caveChoice;
                std::cin >> caveChoice;

                if (caveChoice == 1) {
                    std::cout << "You find a treasure chest but disturb a bat!\n";
                    std::cout << "You lose 10 health but gain 50 gold!\n";
                    playerHealth -= 10;
                    playerGold += 50;
                    addItem("Ancient Sword", "A rusty but powerful looking sword", false);
                } else {
                    std::cout << "You find some useful supplies!\n";
                    playerHealth += 5;
                    if (playerHealth > 100) playerHealth = 100;
                    addItem("Health Potion", "Restores 20 health when used", true, 20);
                }
                break;
            }
case 2: {
                std::cout << "\nYou take the forest path...\n";
                std::cout << "1. Climb a tall tree\n";
                std::cout << "2. Follow a mysterious sound\n";
                std::cout << "Choose (1-2): ";
                int forestChoice;
                std::cin >> forestChoice;

                if (forestChoice == 1) {
                    std::cout << "You get a great view and find some fruit!\n";
                    std::cout << "Health increased!\n";
                    playerHealth += 10;
                    if (playerHealth > 100) playerHealth = 100;
                    addItem("Magic Fruit", "A mysterious fruit that restores 15 health", true, 15);
                } else {
                    std::cout << "You encounter a wild animal and get scared!\n";
                    std::cout << "You lose some health while running away!\n";
                    playerHealth -= 15;
                    addItem("Wolf Fang", "A sharp fang from your encounter", false);
                    playerGold += 20;
                }
                break;
            }
            case 3:
                showInventory();
                break;
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }

        if (playerHealth <= 0) {
            std::cout << "\nGame Over! Your health reached 0!\n";
            return 0;
        }
    }
    return 0;
}

int settings() {
    int choice;

    while (true) {
        std::cout << "\n===== Settings =====\n";
        std::cout << "1. Display Game Instructions\n";
        std::cout << "2. About Game\n";
        std::cout << "3. Return to Main Menu\n";
        std::cout << "Choose an option (1-3): ";

        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "\nGame Instructions:\n";
                std::cout << "- Use numbers to make choices\n";
                std::cout << "- Explore different paths\n";
                std::cout << "- Watch your health! Don't let it reach 0\n";
                std::cout << "- Collect and use items to restore health\n";
                std::cout << "- Check your inventory often\n";
                std::cout << "- Find treasures and survive!\n";
                break;
            case 2:
                std::cout << "\nAdventure Game v1.5.2\n";
                std::cout << "Created by Nickalus Lowrey\n";
                std::cout << "A text-based adventure game\n";
                break;
            case 3:
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}

int quit() {
    std::cout << "\nThanks for playing, " << playerName << "!\n";
    std::cout << "Final Stats:\n";
    std::cout << "Health: " << playerHealth << "/100\n";
    std::cout << "Gold collected: " << playerGold << "\n";
    std::cout << "Items collected: " << inventory.size() << "\n";
    return 0;
}

int main() {
    int choice;
    bool running = true;

    while (running) {
        // Display menu options
        std::cout << "\n===== Welcome to Adventure =====\n";
        std::cout << "\n";
        std::cout << "\n            Start\n";
        std::cout << "\n";
        std::cout << "\n           Setting\n";
        std::cout << "\n";
        std::cout << "\n            Quit\n";
        std::cout << "\n";
        std::cout << "Enter your choice (1-3): ";

        // Get user input
        std::cin >> choice;

        // Process the choice
        switch (choice) {
            case 1:
                std::cout << "Starting Adventure!\n";
                start();
                break;
            case 2:
                std::cout << "Opening Settings...\n";
                settings();
                break;
            case 3:
                quit();
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1-3.\n";
        }
    }

    return 0;
}