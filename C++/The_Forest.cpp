//The Forest?
//Nickalus Lowrey
//Version 2.8.5

//Yes, I know it looks funny I needed help I struggled a bit so from info I could find this is what I made.

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>

struct Player {
    std::string currentRoom;
    std::vector<std::string> inventory;
};

struct Room {
    std::string item;
    bool hasItem;
};

void clearScreen() {
    for(int i = 0; i < 50; i++) {
        std::cout << "\n";
    }
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool hasRequiredItems(const Player& player) {
    std::vector<std::string> requiredItems = {"ancient key", "glowing mushroom", "crystal water"};
    for (const auto& item : requiredItems) {
        if (std::find(player.inventory.begin(), player.inventory.end(), item) == player.inventory.end()) {
            return false;
        }
    }
    return true;
}

void displayRoom(const std::string& room, std::map<std::string, Room>& rooms, const Player& player) {
    std::cout << "\n=== Current Location ===\n";
    if (room == "clearing") {
        std::cout << "You're in a Moonlit Clearing. Silvery light filters through the leaves above.\n";
        std::cout << "Paths lead to: dense woods (north), babbling brook (east)\n";
    }
    else if (room == "dense_woods") {
        std::cout << "You're in the Dense Woods. Dark trees tower around you.\n";
        std::cout << "Paths lead to: clearing (south), ancient tree (north), mushroom grove (east)\n";
    }
    else if (room == "babbling_brook") {
        std::cout << "You're at a Babbling Brook. Crystal clear water flows gently.\n";
        if (rooms["babbling_brook"].hasItem) {
            std::cout << "You notice some crystal water you could collect.\n";
        }
        std::cout << "Paths lead to: clearing (west)\n";
    }
    else if (room == "ancient_tree") {
        std::cout << "You stand before an Ancient Tree. Its trunk is wider than any you've seen.\n";
        if (rooms["ancient_tree"].hasItem) {
            std::cout << "An ancient key gleams among the roots.\n";
        }
        std::cout << "Paths lead to: dense woods (south)\n";
        if (hasRequiredItems(player)) {
            std::cout << "You notice a mysterious door in the tree trunk...(enter 'enter' to use)\n";
        }
    }
    else if (room == "mushroom_grove") {
        std::cout << "You're in a Glowing Mushroom Grove. Bioluminescent fungi light the area.\n";
        if (rooms["mushroom_grove"].hasItem) {
            std::cout << "A particularly bright mushroom catches your eye.\n";
        }
        std::cout << "Paths lead to: dense woods (west)\n";
    }
    else if (room == "secret_room") {
        clearScreen();
        std::cout << "\n╔════════════════════════════════════════╗\n";
        std::cout << "║           CONGRATULATIONS!              ║\n";
        std::cout << "║                                        ║\n";
        std::cout << "║  You've found the heart of the forest! ║\n";
        std::cout << "║     A magical sanctuary of peace.      ║\n";
        std::cout << "║                                        ║\n";
        std::cout << "║            YOU WIN!!!                  ║\n";
        std::cout << "║                                        ║\n";
        std::cout << "║  Thank you for playing The Forest!     ║\n";
        std::cout << "╚════════════════════════════════════════╝\n\n";
    }
}

void displayInventory(const Player& player) {
    std::cout << "\nInventory: ";
    if (player.inventory.empty()) {
        std::cout << "empty";
    } else {
        for (const std::string& item : player.inventory) {
            std::cout << item << ", ";
        }
    }
    std::cout << std::endl;
}

bool movePlayer(Player& player, const std::string& direction, std::map<std::string, Room>& rooms) {
    std::string currentRoom = player.currentRoom;
    bool validMove = false;

    if (currentRoom == "clearing") {
        if (direction == "north") {
            player.currentRoom = "dense_woods";
            validMove = true;
        }
        else if (direction == "east") {
            player.currentRoom = "babbling_brook";
            validMove = true;
        }
    }
    else if (currentRoom == "dense_woods") {
        if (direction == "south") {
            player.currentRoom = "clearing";
            validMove = true;
        }
        else if (direction == "north") {
            player.currentRoom = "ancient_tree";
            validMove = true;
        }
        else if (direction == "east") {
            player.currentRoom = "mushroom_grove";
            validMove = true;
        }
    }
    else if (currentRoom == "babbling_brook") {
        if (direction == "west") {
            player.currentRoom = "clearing";
            validMove = true;
        }
    }
    else if (currentRoom == "ancient_tree") {
        if (direction == "south") {
            player.currentRoom = "dense_woods";
            validMove = true;
        }
        else if (direction == "enter" && hasRequiredItems(player)) {
            player.currentRoom = "secret_room";
            validMove = true;
            return true;
        }
    }
    else if (currentRoom == "mushroom_grove") {
        if (direction == "west") {
            player.currentRoom = "dense_woods";
            validMove = true;
        }
    }

    return validMove;
}

bool takeItem(Player& player, std::map<std::string, Room>& rooms) {
    if (!rooms[player.currentRoom].hasItem) {
        return false;
    }

    std::string item = rooms[player.currentRoom].item;
    player.inventory.push_back(item);
    rooms[player.currentRoom].hasItem = false;
    std::cout << "You picked up: " << item << std::endl;
    return true;
}

void startGame() {
    Player player;
    player.currentRoom = "clearing";
    std::string command;
    bool gameRunning = true;

    // Initialize rooms and items
    std::map<std::string, Room> rooms;
    rooms["ancient_tree"] = {"ancient key", true};
    rooms["mushroom_grove"] = {"glowing mushroom", true};
    rooms["babbling_brook"] = {"crystal water", true};

    clearScreen();
    std::cout << "Welcome to The Forest!\n";
    std::cout << "Night has fallen and you must find your way...\n";
    std::cout << "Commands: north, south, east, west, take, inventory, quit\n";
    std::cout << "Hint: Collect all items to discover a secret...\n";

    while (gameRunning) {
        displayRoom(player.currentRoom, rooms, player);
        displayInventory(player);
        std::cout << "\nWhat would you like to do? ";
        std::getline(std::cin, command);

        if (command == "quit") {
            gameRunning = false;
        }
        else if (command == "take") {
            if (!takeItem(player, rooms)) {
                std::cout << "There's nothing here to take.\n";
            }
        }
        else if (command == "inventory") {
            displayInventory(player);
        }
        else if (command == "north" || command == "south" || command == "east" || command == "west" || command == "enter") {
            if (movePlayer(player, command, rooms)) {
                if (player.currentRoom == "secret_room") {
                    displayRoom(player.currentRoom, rooms, player);
                    std::cout << "\nPress Enter to return to main menu...";
                    std::cin.get();
                    gameRunning = false;
                } else {
                    std::cout << "You move " << command << ".\n";
                }
            }
            else {
                std::cout << "You can't go that way!\n";
            }
        }
        else {
            std::cout << "Invalid command. Try: north, south, east, west, take, inventory, or quit\n";
        }
    }
}

void settings() {
    clearScreen();
    std::cout << "Ha! You thought you could change things!\n";
    std::cout << "Press Enter to return to menu...";
    clearInputBuffer();
    std::cin.get();
}

int main() {
    int choice;
    bool running = true;

    while (running) {
        clearScreen();
        std::cout << "===== The Forest =====\n";
        std::cout << "1. Start Game\n";
        std::cout << "2. Settings\n";
        std::cout << "3. Quit\n";
        std::cout << "Choose (1-3): ";

        while(!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            clearScreen();
            std::cout << "Invalid input! Please enter a number.\n";
            std::cout << "===== The Forest =====\n";
            std::cout << "1. Start Game\n";
            std::cout << "2. Settings\n";
            std::cout << "3. Quit\n";
            std::cout << "Choose (1-3): ";
        }

        clearInputBuffer();

        switch (choice) {
            case 1:
                startGame();
                break;
            case 2:
                settings();
                break;
            case 3:
                std::cout << "Goodbye!\n";
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Press Enter to try again...";
                std::cin.get();
                break;
        }
    }
    return 0;
}