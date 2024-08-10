#define SORTED_ROOMPRICE_HPP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Room {
    string type;
    string details;
    int price;
};

bool compareByPrice(const Room& room1, const Room& room2) {
    return room1.price > room2.price;
}

int partition(vector<Room>& rooms, int low, int high) {
    int pivot = rooms[high].price;
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (rooms[j].price >= pivot) {
            ++i;
            swap(rooms[i], rooms[j]);
        }
    }

    swap(rooms[i + 1], rooms[high]);
    return i + 1;
}

void quickSort(std::vector<Room>& rooms, int low, int high) {
    if (low < high) {
        int pi = partition(rooms, low, high);

        quickSort(rooms, low, pi - 1);
        quickSort(rooms, pi + 1, high);
    }
}

void displayRoomInformation() {
    vector<Room> rooms = {
        {"PENTHOUSE",
         "  Room Capacity: 10 or more\n"
         "  All amenities included in a Suite Room\n\n"
         "  *Included: (only for Penthouse guests)\n"
         "     - Expansive space and luxurious design\n"
         "     - Private balcony\n"
         "     - Personalized gourmet dining experience with a \n"
         "      private chef and customized menu\n"
         "     - Private access to a jacuzzi\n"
         "     - Unlimited access to hotel's sport facility and \n"
         "      hotel's recreational facility\n"
         "     - Private butler service for the duration of the stay",
         35000},

         {"EXECUTIVE ROOM",
         "  Room Capacity: 6\n"
         "  All amenities included in a Deluxe Room\n"
         "  Additional Single bedsize (1)\n\n"
         "  *Included: (only for Executive Room guests)\n"
         "     - Complimentary daily breakfast and exclusive access \n"
         "      to an executive lounge with snacks and beverages\n"
         "     - Access to the hotel's business center and meeting rooms\n"
         "     - Priority access to the hotel's recreational facilities \n"
         "      limited to spa and game room",
         20000},

         {"SUITE ROOM",
         "  Room Capacity: 4\n"
         "  All amenities included in a Deluxe Room\n"
         "  Double bedsize (2)\n"
         "  Separate living room\n"
         "  Kitchenette / fully-equipped kitchen\n\n"
         "  *Included: (only for Suite Room guests)\n"
         "     - Personalized in-room dining experience with a private chef\n"
         "     - Welcome fruit basket and a bottle of wine upon arrival\n"
         "     - Private yoga session\n"
         "     - Access to the hotel's sports facility limited to bowling \n"
         "      and billiard",
         12000},

         {"DELUXE ROOM",
         "  Room Capacity: 4\n"
         "  All amenities included in a Standard Room\n"
         "  Mini-refrigerator\n"
         "  California King bedsize (1)\n"
         "  Single bedsize (1)\n"
         "  Upgraded furnishings and decor\n\n"
         "  *Included: (only for Deluxe Room guests)\n"
         "     - Option for a gourmet dining experience at an on-site \n"
         "      restaurant\n"
         "     - Complimentary access to the hotel's fitness center\n"
         "     - Cooking class with a professional chef",
         9000},

         {"STANDARD ROOM",
         "  Room Capacity: 1 or 2\n"
         "  Single bedsize (2)\n"
         "  Private bathroom with shower\n"
         "  Television\n"
         "  Wi-Fi\n"
         "  Air condition\n\n"
         "  *Included: (only for Standard Room guests)\n"
         "     - Option for in-room dining with a variety of meal \n"
         "      choices available",
         5000}
    };

    int n = rooms.size();
    
    // Replace the std::sort with quickSort
    quickSort(rooms, 0, n - 1);

    cout << "Room Information (Highest to Lowest Price):" << endl;
    for (const Room& room : rooms) {
        cout << endl << "======================================================================" << endl;
        cout << "Price: " << room.price << " RS/night" << endl;
        cout << "Type: " << room.type << endl << endl;
        cout << room.details << endl << endl;
        cout << "======================================================================" << endl;
        cout << endl;
    }
}

