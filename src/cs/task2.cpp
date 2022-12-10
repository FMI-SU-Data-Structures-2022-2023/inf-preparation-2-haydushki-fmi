#include "node.hpp"

template<typename T>
bool makeTotal(Node<T> *list)
{
    if (!list) {
        return false;
    }

    unsigned nodeCount = 1;
    Node<T> *current = list->next;

    while (current) {
        nodeCount++;
        current = current->next;
    }

    if (nodeCount < 3) {
        return false;
    }

    // Check for balance
    bool hasIntervened = false;  // If nodes have been removed
    bool hasBalanced = false;    // If there's at least one balanced
    bool hasNotBalanced = false; // If there's at least one not balanced

    Node<T> *previous = list;
    current = list->next;
    Node<T> *next = current->next;
    while (current && current->next) {
        bool result = hasBalance(previous, current, next);
        hasBalanced = hasBalanced || result;
        hasNotBalanced = hasNotBalanced || !result;

        previous = previous->next;
        current = current->next;
        next = current ? current->next : nullptr;
    }

    // Remove balanced if needed
    if (hasBalanced && hasNotBalanced) {
        previous = list;
        current = list->next;
        next = current->next;
        while (current && current->next) {
            bool result = hasBalance(previous, current, next);

            // If there are balanced and not balanced and if this one is balanced
            if (hasBalanced && hasNotBalanced && result) {
                hasIntervened = true;
                current->next = nullptr;
                // delete current;
                previous->next = next;

                current = next;
                next = current ? current->next : nullptr;
                continue;
            }

            previous = previous->next;
            current = current->next;
            next = current ? current->next : nullptr;
        }
    }

    return hasBalanced && !hasIntervened;
}

template<typename T>
bool hasBalance(Node<T> *previous, Node<T> *current, Node<T> *next)
{
    if (previous == nullptr || current == nullptr || next == nullptr) {
        return false;
    }
    return (previous->value + next->value) == current->value;
}
