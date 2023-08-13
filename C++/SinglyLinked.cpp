#include <iostream>

class Node {
public:
    int value;
    Node* next;
    int index;

    Node(int value, Node* next, int index) : value(value), next(next), index(index) {}

    void deleteNode() {
        next = next->next;
    }
};

class SinglyLinked {
private:
    Node* list;
    int length;

public:
    SinglyLinked() : list(nullptr), length(0) {}

    void insert(int value) {
        Node* node = new Node(value, list, length);
        list = node;
        length++;
    }

    std::string checkIfExists(int val) {
        Node* data = list;
        std::string ans = "Not Found";
        while (data) {
            if (data->value == val) {
                ans = "Found";
                break;
            } else {
                data = data->next;
            }
        }
        return ans;
    }

    Node* getNode(int index) {
        Node* data = list;
        Node* ans = nullptr;
        while (data) {
            if (data->index == index) {
                ans = data;
                break;
            } else {
                data = data->next;
            }
        }
        return ans;
    }

    void remove(int index) {
        getNode(index + 1)->deleteNode();
        Node* data = list;
        length--;
        while (data) {
            if (data->index < index) {
                break;
            }
            data->index--;
            data = data->next;
        }
    }

    void print() {
        Node* data = list;
        while (data) {
            std::cout << "{" << "\n";
            std::cout << "Index: " << data->index << ",\n";
            std::cout << "Value: " << data->value << ",\n";
            if (data->next != nullptr) {
                std::cout << "Next: " << data->next->value << "\n";
            } else {
                std::cout << "Next: Null\n";
            }
            std::cout << "}\n\n";
            data = data->next;
        }
    }
};

int main() {
    SinglyLinked test;
    test.insert(3);
    test.insert(15);
    test.insert(25);
    test.insert(33);
    test.insert(43);
    test.insert(83);
    test.insert(45);
    test.insert(38);
    test.insert(37);
    test.insert(12);

    test.remove(3);
    std::cout << test.checkIfExists(33) << std::endl;

    return 0;
}