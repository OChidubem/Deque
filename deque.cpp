#include <iostream>
#include "Deque.h"

/**
 * @file main.cpp
 * @brief Demonstrates the usage of the Deque class implemented using a circular doubly linked chain.
 * 
 * This file contains a simple menu-driven program that allows the user to interact 
 * with a Deque. The operations supported include adding and removing elements 
 * from both the front and back, as well as displaying the front and back elements.
 * 
 * @author: Chidubem Okoye
 * @date: December 1, 2024
 * @class: CSCI 301
 * @professor: Dr. Anda Andrew
 */

int main() {
    Deque<int> deque;  // Create an empty Deque to store integers.
    int choice, value; // Variables for user input.

    // Infinite loop to display the menu and perform operations until the user exits.
    while (true) {
        // Display menu options to the user.
        std::cout << "\n--- Deque Menu ---\n";
        std::cout << "1. Add to Front\n";   // Option 1: Add value to the front.
        std::cout << "2. Add to Back\n";    // Option 2: Add value to the back.
        std::cout << "3. Remove from Front\n"; // Option 3: Remove value from the front.
        std::cout << "4. Remove from Back\n";  // Option 4: Remove value from the back.
        std::cout << "5. Display Front\n";    // Option 5: Display the front value.
        std::cout << "6. Display Back\n";     // Option 6: Display the back value.
        std::cout << "7. Exit\n";              // Option 7: Exit the program.
        std::cout << "Enter your choice: ";   // Prompt user for a choice.
        std::cin >> choice;                   // Read the user's choice.

        try {
            switch (choice) {
                case 1: // Add to front
                    std::cout << "Enter a value to add to the front: ";
                    std::cin >> value;       // Read the value to add.
                    deque.addFront(value);   // Add value to the front.
                    std::cout << "Value " << value << " added to the front.\n";
                    break;

                case 2: // Add to back
                    std::cout << "Enter a value to add to the back: ";
                    std::cin >> value;       // Read the value to add.
                    deque.addBack(value);    // Add value to the back.
                    std::cout << "Value " << value << " added to the back.\n";
                    break;

                case 3: // Remove from front
                    deque.removeFront();     // Remove value from the front.
                    std::cout << "Front value removed.\n";
                    break;

                case 4: // Remove from back
                    deque.removeBack();      // Remove value from the back.
                    std::cout << "Back value removed.\n";
                    break;

                case 5: // Display front
                    std::cout << "Front value: " << deque.getFront() << "\n";  // Display front value.
                    break;

                case 6: // Display back
                    std::cout << "Back value: " << deque.getBack() << "\n";  // Display back value.
                    break;

                case 7: // Exit
                    std::cout << "Exiting program.\n";  // Exit message.
                    return 0;  // Terminate the program.

                default:
                    // If the user enters an invalid option, notify them.
                    std::cout << "Invalid choice. Please try again.\n";
            }
        } catch (const std::underflow_error& e) {
            // Catch any exceptions related to underflow (such as accessing an empty deque).
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    return 0;  // Exit main.
}
