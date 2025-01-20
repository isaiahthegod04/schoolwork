#include <iostream>
#include "Alist.cpp"

using namespace std;

int main() {
    // Make Alist only hold numbers
    AList<int> alist;

    cout << "Step 1: Check if the list is empty\n"; // Check if the list is empty
    if (alist.empty()) {
        cout << "The list is initially empty.\n"; // Should output: "The list is initially empty."
    }

    cout << "\nStep 2: Add elements to the left side of the list\n";
    alist.addLeft(10);  // Adds 10 to the left
    alist.addLeft(20);  // Adds 20 to the left 
    alist.addLeft(30);  // Adds 30 to the left 
    cout << "Current list contents (left to right): "; // Should display 30 20 10
    alist.display();
    cout << endl;

    cout << "\nStep 3: Add elements to the right side of the list\n";
    alist.addRight(40);  // Adds 40 to the right 
    alist.addRight(50);  // Adds 50 to the right 
    alist.addRight(60);  // Adds 60 to the right 
    cout << "Current list contents (left to right): "; // Should display 30 20 10 40 50 60
    alist.display();
    cout << endl;

    cout << "\nStep 4: Remove elements from the left side of the list\n";
    cout << "Removed from left: " << alist.removeLeft() << endl;  // Removes the current leftmost element (30) 
    cout << "Removed from left: " << alist.removeLeft() << endl;  // Removes the next leftmost element (20) 
    cout << "Current list contents (left to right): "; // Should display 10 40 50 60
    alist.display();
    cout << endl;

    cout << "\nStep 5: Remove elements from the right side of the list\n";
    cout << "Removed from right: " << alist.removeRight() << endl;  // Removes the current rightmost element (60) 
    cout << "Removed from right: " << alist.removeRight() << endl;  // Removes the next rightmost element (50) 
    cout << "Current list contents (left to right): "; // Should display 10 40
    alist.display();
    cout << endl;

    cout << "\nStep 6: Add and remove to test circular array behavior\n";
    cout << "Adding elements 70, 80, 90 to the left\n";
    alist.addLeft(70); // Adds 70 to the left 
    alist.addLeft(80); // Adds 80 to the left 
    alist.addLeft(90); // Adds 90 to the left 
    cout << "Adding elements 100, 110 to the right\n";
    alist.addRight(100); // Adds 100 to the right 
    alist.addRight(110); // Adds 110 to the right 
    cout << "Current list contents: "; // Should display 90 80 70 10 40 100 110
    alist.display();
    cout << endl;

    cout << "Removing elements from both ends...\n";
    cout << "Removed from left: " << alist.removeLeft() << endl;  // Removes 90 
    cout << "Removed from right: " << alist.removeRight() << endl; // Removes 110 
    cout << "Current list contents: "; // Should display: 80 70 10 40 100
    alist.display();
    cout << endl;

    cout << "\nStep 7: Check debugging display for internal state\n";
    alist.ddisplay();

    cout << "\nStep 8: Clear the list and verify\n";
    alist.clear(); // Clears the list -> Current list: []
    cout << "Cleared the list. Checking if it is empty...\n";
    if (alist.empty()) {
        cout << "The list is now empty.\n"; // Should output: "The list is now empty."
    } else {
        cout << "The list is not empty.\n";
    }

    return 0;
}
