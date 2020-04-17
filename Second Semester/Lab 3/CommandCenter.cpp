//
// Created by Hrayr on 4/11/2020.
//

#include "CommandCenter.h"
#include "Helper.cpp"
#include <iostream>

using namespace std;

const char *CommandCenter::_menu = " 1. Add a connection\r\n"
                            " 2. Add connections\r\n"
                            " 3. Remove a connection\r\n"
                            " 4. Show all connections\r\n"
                            " 5. Show item connections\r\n"
                            " 0. Exit\r\n";
Connections CommandCenter::connections;

bool CommandCenter::addConnections() {
    char* input = new char[1000];

    char* pointer = new char[1];
    // First item is the count of all items in points list
    char** pointers = (char**)malloc(sizeof(char));
    Helper::starting_text_input = true;
    Helper::pointer_found_      = false;
    size_t index = 1;
    cout << "Input pointers in format: <pointer> - <pointer1>,<pointer2>,<pointer3>...\\" << endl
    << "Maximum input characters 1000." << endl;
    cin.getline (input, 1000);
    while(true) {
        Helper::new_line = true;
        cout << "something" << endl;
        cin.getline (input, 1000);
        cout << "second something" << endl;
        // Type '\' or just press enter again to finish typing
        if ((input[0] == '\\' && input[1] == '\0') || input[0] == '\0') {
            cout << "third something" << endl;
            break;
        }
        Helper::preparePointer(input, pointer, pointers, index);
        pointers[0] = static_cast<char*>(static_cast<void*>(&index)); // lets save the raw data in index into pointers [0]
        // Saved data has size of size_t` 8 bytes
//        CommandCenter::connections.add(pointer, pointers);
        cout << pointer << endl;
        input[0] = '\0';
    }
    Helper::starting_text_input = false;
}

bool CommandCenter::removeConnections() {

}

bool CommandCenter::showConnections() {
    CommandCenter::connections.show();
}

bool CommandCenter::showItemConnections() {

}

bool CommandCenter::Menu() {
    int chosen = -2;
    while (chosen != CommandCenter::MENU_ITEM_EXIT) {
        cout << CommandCenter::_menu << endl;
        cin >> chosen;
        switch (chosen) {
            case CommandCenter::MENU_ITEM_ADD_CONNECTIONS:
                CommandCenter::addConnections();
                break;
            case CommandCenter::MENU_ITEM_REMOVE_CONNECTION:
                CommandCenter::removeConnections();
                break;
            case CommandCenter::MENU_ITEM_SHOW_CONNECTIONS:
                CommandCenter::showConnections();
                break;
            case CommandCenter::MENU_ITEM_SHOW_ITEM_CONNECTIONS:
                CommandCenter::showItemConnections();
                break;
            case CommandCenter::MENU_ITEM_EXIT:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Wrong command! Try again." << endl;
        }
    }
    return true;
}