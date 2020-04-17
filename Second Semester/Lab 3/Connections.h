//
// Created by Hrayr on 4/8/2020.
//

#ifndef CPP_LABS_CONNECTIONS_H
#define CPP_LABS_CONNECTIONS_H


class Connections {
private:
    /**
     * Every _connections[i][0] is count of the connections
     */
    size_t **_connections; // Pointers indexes with their connections
    char **_pointers; // Pointers titles associated with indexes
    size_t _count;

public:
    size_t *getPointer(size_t index);

    char *getTitle(size_t index);

    size_t *getPointer(char *pointer);

    size_t getPointerIndex(char *pointer);

    int checkPointer();

    /**
     * In points array first pointer should say how many pointers are there so it will be the count of
     * connections for current pointer
     * @param title
     * @param points
     * @return
     */
    // First item is the count of all items in points list
    bool add(char *title, char **points);

    // First item is the count of all items in points list
    bool add(size_t index, char **points);

    /**
     * Adds One point to another point
     * @param title
     * @param point
     * @param connect
     * @return
     */
    bool add(char *title, char *point);

    bool add(size_t index, char *point);

    bool add(size_t index1, size_t index2); // If connect is false add index2 to index1

    size_t createPointer(char *pointer); // Creates new element in pointers list and returns index of created element

    bool remove();

    bool removeAll();

    size_t count() {
        return _count;
    }

    bool show();
    bool show(size_t index);
    bool show(char* pointer);

    Connections();

};


#endif //CPP_LABS_CONNECTIONS_H
