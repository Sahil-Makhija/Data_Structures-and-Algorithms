#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    LinkedList(Node *head = NULL)
    {
        if (head == NULL)
        {
            this->head = NULL;
            this->tail = NULL;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            this->tail = temp;
        }
    }

    LinkedList(Node *head, Node *tail)
    {
        this->head = head;
        this->tail = tail;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " --> ";
            temp = temp->next;
        }
        cout << "END" << endl;
    }

    void insertAtHead(Node *newNode)
    {
        newNode->next = head;
        this->head = newNode;
        if (tail == NULL)
        {
            tail = newNode;
        }
    }

    void insertAtTail(Node *newNode)
    {
        newNode->next = NULL;
        if (tail != NULL)
        {
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            head = newNode;
            tail = newNode;
        }
    }

    void deleteHeadNode()
    {
        if (head != NULL)
        {
            Node *nextNode = head->next;
            delete head;
            head = nextNode;
            if (head == NULL)
            {
                tail = NULL;
            }
        }
    }

    void deleteTailNode()
    {
        if (tail != NULL)
        {
        }
    }

    ~LinkedList()
    {
        cout << "Node DTOR :: " << endl;
        Node *current = head;
        Node *nextNode = nullptr;
        while (current != NULL)
        {
            nextNode = current->next;
            cout << "Deleting node with data: " << current->data << endl;
            delete current;
            current = nextNode;
        }
    }
};

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);

    first->next = second;
    second->next = third;
    third->next = fourth;

    LinkedList List(first);
    List.print();
    // List.insertAtHead(new Node(100));
    // List.insertAtTail(new Node(500));
    List.deleteHeadNode();
    List.print();
}
