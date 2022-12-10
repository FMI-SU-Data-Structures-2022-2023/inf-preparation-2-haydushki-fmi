#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
struct Node {
    T value;
    Node<T> *next;

    Node(T key)
    {
        this->value = key;
        this->next = nullptr;
    }
};

#endif // NODE_HPP
