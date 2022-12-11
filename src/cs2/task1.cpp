#include "node.hpp"
#include <stdexcept>

struct Interval
{
    unsigned from;
    unsigned to;

    Interval *next;
};

template<typename T>
void rotateSublists(Node<T> *list, const Interval *intervals)
{
    if (!list) {
        throw std::invalid_argument("List must not be nullptr!");
    }

    const Interval *currentInterval = intervals;
    while (currentInterval) {
        unsigned index = currentInterval->from;
        Node<T> *startingPoint = list;
        Node<T> *current = list;

        while (current && index > 0) {
            startingPoint = current;
            current = current->next;
            index--;
        }

        if (index != 0) {
            throw std::invalid_argument("Interval must be valid!");
        }

        Node<T> *previous;
        index = currentInterval->to - currentInterval->from;
        while (current && index > 0) {
            previous = current;
            current = current->next;
            index--;
        }

        if (index != 0) {
            throw std::invalid_argument("Interval must be valid!");
        }

        if (previous != list) {
            previous->next = current ? current->next : nullptr;
            current->next = startingPoint->next;
            startingPoint->next = current;
        } else {
            previous->next = current ? current->next : nullptr;
            current->next = startingPoint;
        }

        currentInterval = currentInterval->next;
    }
}
