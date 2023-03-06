#include <iostream>
#include <vector>
#include "LinkedList.cpp"
using namespace std;
/*******************************************

Igor Alyeksyeyenko, ia22016

GG7. Create function to delete from list all elements with bigger value than previous element (before any element is deleted).

Linked List version

Unit test version

Program created: 2023/03/06

*******************************************/

string areEqual(LinkedList* expected, LinkedList actual)
{
    Node* expectedList = expected->list;
    Node* actualList = actual.list;
    while(expectedList->next!=NULL)
    {
        if(actualList==NULL)//actual is of different size
            return "false";
        if(expectedList->value!=actualList->value)//different values
            return "false";

        expectedList = expectedList->next;
        actualList = actualList->next;
    }
    //advance both by one to make them both null
    expectedList = expectedList->next;
    actualList = actualList->next;

    if(expectedList!=NULL)//should be null just like expected one at this point
        return "false";

    return "true";
}

int main()
{
    cout<<"test case 1"<<endl;
    LinkedList* list = new LinkedList{1};
    list->push_back(2);
    list->push_back(3);
    list->push_back(10);
    list->printList();
    cout<<areEqual(list,vector<int> {1,2,3,10})<<endl;
    list->removeAllLargerThanPrevious();
    list->printList();
    cout<<areEqual(list,vector<int> {1})<<endl;
    cout<<"======================================="<<endl;
    cout<<"test case 2"<<endl;
    list = new LinkedList(1);
    list->push_back(NULL);
    list->printList();
    cout<<areEqual(list,vector<int> {1,0})<<endl;
    list->removeAllLargerThanPrevious();
    list->printList();
    cout<<areEqual(list,vector<int> {1,0})<<endl;
    cout<<"======================================="<<endl;
    cout<<"test case 3"<<endl;
    try{
        list = new LinkedList(vector<int>{});
    }
    catch(invalid_argument& e){
        cout<<e.what()<<endl;
    }
    cout<<"======================================="<<endl;
    cout<<"test case 4"<<endl;
    list = new LinkedList(-1);
    list->push_back(-2);
    list->push_back(-3);
    list->push_back(-10);
    list->printList();
    cout<<areEqual(list,vector<int> {-1,-2,-3,-10})<<endl;
    list->removeAllLargerThanPrevious();
    list->printList();
    cout<<areEqual(list,vector<int> {-1,-2,-3,-10})<<endl;
    cout<<"======================================="<<endl;
    cout<<"test case 5"<<endl;
    list = new LinkedList(4);
    list->push_back(7);
    list->push_back(3);
    list->push_back(4);
    list->printList();
    cout<<areEqual(list,vector<int> {4,7,3,4})<<endl;
    list->removeAllLargerThanPrevious();
    list->printList();
    cout<<areEqual(list,vector<int> {4,3})<<endl;
    cout<<"======================================="<<endl;
    cout<<"test case 6"<<endl;
    list = new LinkedList(1);
    list->push_back(2);
    list->push_back(3);
    list->push_back(4);
    list->push_back(3);
    list->push_back(2);
    list->push_back(1);
    list->push_back(7);
    list->push_back(7);
    list->printList();
    cout<<areEqual(list,vector<int> {1,2,3,4,3,2,1,7,7})<<endl;
    list->removeAllLargerThanPrevious();
    list->printList();
    cout<<areEqual(list,vector<int> {1,3,2,1,7})<<endl;

    return 0;
}
