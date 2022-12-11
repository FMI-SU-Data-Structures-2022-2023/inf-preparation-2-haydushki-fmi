#include "node.hpp"

bool areNeighbours(int current, int other)
{
    return current == other + 1 || current == other - 1;
}

bool makeTotal(Node<int> *list)
{
    if (!list) {
        return false;
    }

    unsigned nodeCount = 1;
    Node<int> *current = list->next;
    while (current && nodeCount < 2) {
        nodeCount++;
        current = current->next;
    }

    if (nodeCount < 2) {
        return false;
    }

    bool hasOneNeighbour = false;
    bool hasOneNotNeighbour = false;

    // Manually check the first element
    {
        // At this point list has at least 2 elements so there's no danger for list->next == nullptr
        bool result = areNeighbours(list->value, list->next->value);
        hasOneNeighbour = hasOneNeighbour || result;
        hasOneNotNeighbour = hasOneNotNeighbour || !result;
    }

    Node<int> *previous = current;
    current = list->next;
    while (current) {
        bool result = areNeighbours(previous->value, current->value);
        hasOneNeighbour = hasOneNeighbour || result;
        hasOneNotNeighbour = hasOneNotNeighbour || !result;
        previous = current;
        current = current->next;
    }

    if (hasOneNeighbour && hasOneNotNeighbour) {
        previous = list;
        current = list->next;
        while (current) {
            if (areNeighbours(previous->value, current->value)) {
                Node<int> *next = current->next;
                previous->next = next;
                // delete current;
                current->next = nullptr;

                current = next;
                continue;
            }

            previous = current;
            current = current->next;
        }
        return false;
    }

    return true;
}
