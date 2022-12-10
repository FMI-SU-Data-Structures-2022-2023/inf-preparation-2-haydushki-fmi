#include "node.hpp"
#include <stdexcept>

struct Interval
{
    unsigned from;
    unsigned to;

    Interval* next = nullptr;
};

template <typename T>
void reverseSublists(Node<T>* list, const Interval* intervals)
{
    const Interval *currentInterval = intervals;
    while (currentInterval) {
        Node<T> *startingPoint = list;
        Node<T> *previous = list;
        unsigned index = currentInterval->from;
        while (startingPoint && index > 0) {
            previous = startingPoint;
            startingPoint = startingPoint->next;
            index--;
        }

        if (index > 0) {
            throw std::invalid_argument("Index must be valid!");
        }

        Node<T> *reversedPoint = reverse(startingPoint,
                                         currentInterval->to - currentInterval->from + 1);
        if (previous == list) {
            list = reversedPoint;
        } else {
            previous->next = reversedPoint;
        }

        currentInterval = currentInterval->next;
    }
}

template<typename T>
Node<T> *reverse(Node<T> *list, unsigned countOfNodes)
{
    if (!list) {
        throw std::invalid_argument("First node must not be a nullptr!");
    }

    if (countOfNodes == 0) {
        return list;
    }

    // Example: A->B->C->D->E->F and B is passed as the first node, countOfNodes = 3
    Node<T> *current = list;
    Node<T> *previous = nullptr;
    Node<T> *toBecomeLast = list; // Becomes B
    while (current && countOfNodes > 0) {
        // If we're generating a new list
        //        Node<T> *temp = new Node(current->key);
        //        temp->next = previous;

        Node<T> *next = current->next;
        current->next = previous;
        previous = current;
        current = next;

        countOfNodes--;
    }

    if (countOfNodes != 0) {
        throw std::invalid_argument("Index must be valid!");
    }
    toBecomeLast->next = current; // Point B to E
    return previous;
}
