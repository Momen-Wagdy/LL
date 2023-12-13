#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to insert element at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to remove element from the beginning
    void removeFromBeginning() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            std::cout << "List is empty. Cannot remove from an empty list." << std::endl;
        }
    }

    // Function to find sum, average, and count
    void findSumAvgCount() {
        int sum = 0;
        int count = 0;

        Node* current = head;
        while (current) {
            sum += current->data;
            count++;
            current = current->next;
        }

        double average = (count == 0) ? 0 : static_cast<double>(sum) / count;

        std::cout << "Sum: " << sum << std::endl;
        std::cout << "Average: " << average << std::endl;
        std::cout << "Count: " << count << std::endl;
    }

    // Function to search for an element
    bool searchElement(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return true; // Element found
            }
            current = current->next;
        }
        return false; // Element not found
    }
};

int main() {
    LinkedList myList;

    // Insert elements at the beginning
    myList.insertAtBeginning(10);
    myList.insertAtBeginning(20);
    myList.insertAtBeginning(30);

    // Find sum, average, and count
    myList.findSumAvgCount();

    // Search for an element
    int searchValue = 20;
    if (myList.searchElement(searchValue)) {
        std::cout << searchValue << " found in the list." << std::endl;
    } else {
        std::cout << searchValue << " not found in the list." << std::endl;
    }

    // Remove elements from the beginning
    myList.removeFromBeginning();

    // Find sum, average, and count after removal
    myList.findSumAvgCount();

    return 0;
}
