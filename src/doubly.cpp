#include "doubly.h"
doublylinkedlist::doublylinkedlist(const doublylinkedlist& rhs)
{ 
    cout << "Copy constructor called!" << endl;
    head = nullptr;
    for(int i = 0; i < rhs.size(); i++){ //keep copying the data on the right hand side of the = sign
        push(rhs.at(i));
    }
}

void doublylinkedlist::operator=(const doublylinkedlist& rhs)
{
    cout << "Copy assignment override called!" << endl;
    // free the original list
    while(head != nullptr)
    { // delete the data in the element
        node* temp = head->next;
        delete head;
        head = temp;
    }
    // copy rhs list
    for(int i = 0; i < rhs.size(); i++){ // assign it new data from the rhs side on the = sign
        push(rhs.at(i));
    }
}

doublylinkedlist::~doublylinkedlist()
{ // avoid any leaks
    cout << "Destructor called!" << endl;
    while(head != nullptr){
        node* temp = head->next;
        delete head;
        head = temp;
    }
}
void doublylinkedlist::push(int data)
{ //adds an element at the end of the object
    if (head==nullptr)
    { // checks if there is nothing in the object 
        head = new node;
        head->next = nullptr;
        head->data = data; 
        head->prev = nullptr;
        tail = head;
    }
    else
    {
        
    tail->next = new node; // uses the tail to insert the data
    tail->next->data = data;  // sets the data of the last element
    tail->next->prev = tail;
    tail = tail->next;
    tail->next = nullptr; 
    }
    
    
}
void doublylinkedlist:: pop()
{ // remove the last element in the object
    if (head == nullptr)
    { // checks if there is nothing in the object
        cout<<"There is nothing to pop"<<endl;
        return;
    }
    else 
    { // if there is more than one element
        tail = tail->prev; 
        delete tail->next; // delete the element next to tail (last element). 
        tail->next = nullptr; 
    }
}
int doublylinkedlist:: size() const
{
    node * currentnode = head;
    int count=1;
    if (tail == nullptr)
    { // if there is nothing in the list
        count = 0; // size is 0
    }
    else
    {
        while (currentnode->next != nullptr)
        { // keep going until the next element is nullptr
            currentnode = currentnode->next; 
            ++ count; 
        }
    }
    return count; 

}
void doublylinkedlist::print()
{
    node* temp = head; 
    if (head == nullptr)
    {
        cout<<"There is nothing to print"<<endl;
        return;
    }

        
    else 
    {
        while (temp != nullptr )
        { // keep going and print the data until nullptr appears
            cout<<temp->data<<endl;
            temp  = temp->next;   
        }
            
    }
}
int& doublylinkedlist::at(int idx) const 
{ 
node* count = head; 
int counter=0; 
    while (counter!=idx)
    { // use idx vairable as index and keep going until you get to index
        ++counter;
        count = count->next; 
    }
    return count->data; 
}
void doublylinkedlist:: insert(int data , int idx)
{ //use idx vairable as index and keep going until you get to index
    int counter= 0; 
    node* currentnode = head; 
    if (idx==0)
    {
        node* temp = head; 
        head = new node; 
        head->data = data; 
        head->next = temp; 
        return;
    }
    else
    {
        while( counter!=idx-1)
        { // keep going until you find idx and then insert this data in this position
            ++counter;
            currentnode= currentnode->next;

        }
        node* temp = currentnode->next;
        currentnode->next = new node;
        currentnode->next->data = data;
        currentnode->next->prev = currentnode;
        
        currentnode->next->next = temp; 
        
        
    }
    
    
}
void doublylinkedlist:: remove(int pos)
{
    int counter=0;
    if (pos == 0)
    { // delet the head if the desired position is 0 
        node* temp = head->next; 
        delete head; 
        head = temp; 
        head->prev = nullptr; 
        
    }
    else 
    {
        node* currentnode = head; 
        while (counter!=pos)
        {// keep going until you find the position
            currentnode = currentnode->next;  
            ++counter; 
            
        }
        currentnode->prev->next = currentnode->next; 
        currentnode->next->prev = currentnode->prev; 
        delete currentnode; 
    }
}
