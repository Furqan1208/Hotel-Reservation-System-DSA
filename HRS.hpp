#define HRS_HPP

#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <sstream>

using namespace std;

// Structure for client information
struct Client {
    string name;
    string email;
    string contactNo;
    string username;
    string password;
};

// Structure for reservation information
struct Reservation {
    string roomType;
    string referenceNumber;
    int month;
    int fromDate;
    int toDate;
    bool confirmed;
    string loggedInUsername;
};


struct Node {
    Reservation reservation;
    Node* next;
};

class HotelReservationSystem {
private:
    Node* head;

public:
    HotelReservationSystem() {
        head = nullptr;
    }

    // Function to add a reservation to the linked list
    void addReservation(Reservation res) {
        Node* newNode = new Node;
        newNode->reservation = res;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
};

/*
In the context of a hotel reservation system, the use of a linked list for storing reservations is a design choice that depends on the specific requirements of the system. Let's discuss why a linked list might be chosen over a stack or a queue:

Order of Reservations:

A linked list preserves the order in which reservations are made. The reservations are added to the end of the list, and the order is maintained. This is important for a hotel reservation system where the chronological order of reservations might be relevant.
Flexibility:

A linked list allows for easy insertion and removal of reservations at any position in the list. This flexibility might be useful in scenarios where reservations need to be modified or canceled.
Traversal:

Linked lists support forward traversal, which is helpful if the system needs to display or process reservations in the order they were made. This is different from a stack, which only allows access to the most recently added element (last in, first out), or a queue, which only allows access to the least recently added element (first in, first out).
Dynamic Size:

Linked lists can dynamically grow or shrink based on the number of reservations. This dynamic size is beneficial for a system where the number of reservations may vary, and it's not known in advance.
While a stack or queue could be used in specific scenarios (e.g., if the system only needs to process the most recent reservation or the oldest reservation), a linked list provides a more general-purpose solution that accommodates various requirements of a hotel reservation system. The choice of data structure depends on the specific needs and functionalities of the application.
*/