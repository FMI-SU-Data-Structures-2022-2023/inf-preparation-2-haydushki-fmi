#include <stdexcept>
struct Node
{
    unsigned int value;

    Node *next;
    Node *pushBack(Node *toAdd)
    {
        this->next = toAdd;
        return toAdd;
    }
};

void deleteNodes(Node *list)
{
    Node *current = list;
    while (current) {
        Node *next = current->next;
        delete current;
        current = next;
    }
}

Node *sumOfBigNumbers(const Node *first, const Node *second)
{
    if (!first || !second) {
        throw std::invalid_argument("Numbers must exist! (nullptr received)");
    }

    unsigned int value = first->value + second->value;
    unsigned int carry = value / 10;
    value = value % 10;

    Node *result = new Node{value, nullptr};
    Node *endNode = result;

    const Node *currentFirst = first->next;
    const Node *currentSecond = second->next;
    while (currentFirst && currentSecond) {
        value = currentFirst->value + currentSecond->value + carry;
        carry = value / 10;
        value = value % 10;
        endNode = endNode->pushBack(new Node{value});

        currentFirst = currentFirst->next;
        currentSecond = currentSecond->next;
    }

    // Different lengths
    if (currentFirst) {
        while (currentFirst) {
            value = currentFirst->value + carry;
            carry = value / 10;
            value = value % 10;
            endNode = endNode->pushBack(new Node{value});
            currentFirst = currentFirst->next;
        }
    } else if (currentSecond) {
        while (currentSecond) {
            value = currentSecond->value + carry;
            carry = value / 10;
            value = value % 10;
            endNode = endNode->pushBack(new Node{value});
            currentSecond = currentSecond->next;
        }
    }

    // If there's carry remaining
    if (carry) {
        endNode->pushBack(new Node{carry});
    }

    return result;
}
