#include <iostream>
#include <vector>
using namespace std;
struct Node
{
public:
    int value;
    Node* next;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
    Node(int values[])
    {
        //safe to assume array has at least one element, otherwise other constructor would fire
        this->value = values[0];
        this->next = NULL;
        //insert every passed array value as a new node
        for (int i = 1; i <= sizeof(values) / sizeof(int); i++)
        {
            this->push_back(values[i]);
        }
    }
    void push_back(int value)
    {
        Node* current = this;
        //find the last item in the list
        while (current->next != NULL)
            current = current->next;
        //add a new node to the end
        Node* new_node = new Node(value);
        current->next = new_node;
    }
};

class LinkedList
{
public:
    Node* list;
    LinkedList(int value)
    {
        list = new Node(value);
    }
    LinkedList(vector<int> values)
    {
        if(values.size()<1)
            throw std::invalid_argument("passed vector is empty");

        list = new Node(values[0]);

        for(int i=1; i<values.size();i++)
            list->push_back(values[i]);
    }

    void push_back(int value)
    {
        Node* current = list;
        //find the last item in the list
        while (current->next != NULL)
            current = current->next;
        //add a new node to the end
        Node* new_node = new Node(value);
        current->next = new_node;
    }
    void removeAllLargerThanPrevious()
    {
        if (!list)//empty/null list passed
           throw std::logic_error("The existing list is empty");

        Node* current = list;
        Node* newList = new Node(list->value);//start a new list which will contain only the remaining elements
        Node* previous = current;
        current = current->next;
        //go over each node, starting from second
        while (current != NULL)
        {
            //if the previous node is smaller, do nothing
            if (previous->value < current->value)
            {

            }//if the previous node is larger, keep it in
            else
            {
                newList->push_back(current->value);
            }

            current = current->next;
            previous = previous->next;
        }

        this->list = newList;
    }
    void printList()
    {
        Node* head = list;
        Node* current = head;
        //if the passed list is empty, print nothing
        if (current != NULL)
        {
            //print out the first value outside of loop(for proper formatting)
            cout << head->value;
            //go over each remaining node in the list
            while (current->next != NULL)
            {
                //print them out
                current = current->next;
                cout << "->";
                cout << current->value;
            }
            //print new line after all of the elements to prevent further input/output on same line
            cout << endl;
        }
    }
};
