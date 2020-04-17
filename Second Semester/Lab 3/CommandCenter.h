//
// Created by Hrayr on 4/11/2020.
//

#ifndef CPP_LABS_COMMANDCENTER_H
#define CPP_LABS_COMMANDCENTER_H
#include "Connections.h"

class CommandCenter {
public:
    static const int
            MENU_ITEM_ADD_CONNECTIONS = 1,
            MENU_ITEM_ADD_CONNECTION = 2,
            MENU_ITEM_REMOVE_CONNECTION = 3,
            MENU_ITEM_SHOW_CONNECTIONS = 4,
            MENU_ITEM_SHOW_ITEM_CONNECTIONS = 5,
            MENU_ITEM_EXIT = 0;

    static const char* _menu;
    static Connections connections;
    static bool Menu(); // Shows menu and waiting for menu item selection

    static bool addConnection(); // To add one connection/item
    static bool addConnections(); // To add list of connections/items
    static bool showConnections(); // Shows all connections
    static bool showItemConnections(); // Shows Item connections
    static bool removeConnections(); // Remove provided connections

};


#endif //CPP_LABS_COMMANDCENTER_H
