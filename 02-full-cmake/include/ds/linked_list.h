#pragma once
#include <memory>
#include <string>

namespace ds
{

    template <typename T>
    class DoublyLinkedList
    {
    private:
        struct Node
        {
            T data;
            std::shared_ptr<Node> next;
            std::weak_ptr<Node> prev;

            Node(const T &value) : data(value), next(nullptr), prev() {}
        };

        std::shared_ptr<Node> head; // head of the list
        std::shared_ptr<Node> tail; // tail of the list

    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr) {}

        DoublyLinkedList(const DoublyLinkedList &other) : head(nullptr), tail(nullptr)
        {
            auto current = other.head;
            while (current)
            {
                append(current->data);
                current = current->next;
            }
        }

        class Iterator
        {
        private:
            std::shared_ptr<Node> current;

        public:
            using value_type = T;
            using pointer_type = T *;
            using reference_type = T &;

            Iterator(std::shared_ptr<Node> node) : current(node) {}
            reference_type operator*() { return current->data; }
            pointer_type operator->() { return &current->data; }

            Iterator &operator++() // Pre-increment，返回自增后的引用
            {
                if (current)
                    current = current->next;
                return *this;
            }

            Iterator operator++(int) // Post-increment，返回自增前的副本
            {
                Iterator temp = *this;
                ++(*this);
                return temp;
            }

            Iterator &operator--() // Pre-decrement
            {
                if (current && current->prev.lock())
                    current = current->prev.lock();
                else if (current) // If current is the head
                    current = nullptr; // Move to end (nullptr)
                return *this;
            }

            Iterator operator--(int) // Post-decrement
            {
                Iterator temp = *this;
                --(*this);
                return temp;
            }

            bool operator==(const Iterator &other) const
            {
                return current == other.current;
            }

            bool operator!=(const Iterator &other) const
            {
                return !(*this == other);
            }
        };

        // Add a new node at the end of the list
        void
        append(const T &value)
        {
            auto newNode = std::make_shared<Node>(value);
            if (!head)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        // Add a new node at the beginning of the list
        void prepend(const T &value)
        {
            auto newNode = std::make_shared<Node>(value);
            if (!head)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }

        // Remove the first node
        void removeFirst()
        {
            if (!head)
                return;       // List is empty
            if (head == tail) // Only one element
            {
                head.reset();
                tail.reset();
            }
            else
            {
                head = head->next;
                head->prev.reset();
            }
        }

        // Remove the last node
        void removeLast()
        {
            if (!tail)
                return;       // List is empty
            if (head == tail) // Only one element
            {
                head.reset();
                tail.reset();
            }
            else
            {
                tail = tail->prev.lock();
                tail->next.reset();
            }
        }

        // Get the head of the list
        std::shared_ptr<Node> getHead() const { return head; }

        // Get the tail of the list
        std::shared_ptr<Node> getTail() const { return tail; }

        // convert the list to a string representation
        std::string toString() const
        {
            std::string result;
            auto current = head;
            while (current)
            {
                result += std::to_string(current->data) + " <-> ";
                current = current->next;
            }
            if (!result.empty())
                result.erase(result.size() - 5); // Remove the last " <-> "
            return result;
        }

        // Get an iterator to the beginning of the list
        Iterator begin() const
        {
            return Iterator(head);
        }

        // Get an iterator to the end of the list
        Iterator end() const
        {
            return Iterator(nullptr);
        }

        Iterator rbegin() const
        {
            return Iterator(tail);
        }

        Iterator rend() const
        {
            return Iterator(nullptr);
        }
    };

}; // namespace ds