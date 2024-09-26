#include "doubly.h"

doublylinkedlist::doublylinkedlist()
{
    head = nullptr; 
    tail = nullptr; 
}
doublylinkedlist::doublylinkedlist(const doublylinkedlist& rhs)
{ 
    cout << "Copy constructor called!" << endl;
    head = nullptr;
    for(int i = 0; i < rhs.size(); i++)
    { //keep copying the data on the right hand side of the = sign
        push(rhs.at(i));
    }
}

void doublylinkedlist::printHelp() 
{
    cout << "List of available commands:\n";
    for (int cmd = DLL_COPY; cmd < DLL_NUM_OF_CMD; ++cmd) 
    {
        cout << getCommandString((dll_cmd_t)cmd) << endl;
    }
}

void doublylinkedlist::handleInput(string input)
{
    dll_cmd_t cmd = (dll_cmd_t)stoi(input);
    switch(cmd) 
    {
        case DLL_COPY: return;
        case DLL_PUSH:
            {
                int numberToBePusehd; 
                cout <<"Enter the number to be pushed>>>\n";
                cin>> numberToBePusehd;
                this->push(numberToBePusehd);
            }
        break;
        case DLL_SIZE:
            cout<<"The size of this double linked list is: "<<this->size()<<endl;
        break;
        case DLL_POP:
            {
                int elementToBePopped = this->at(this->size()-1);
                this->pop();
                cout<<"Element: "<<elementToBePopped<<" is no longer in the list\n";
            }
        break;
        case DLL_INSERT: 
            {
                int idx, elemntToBeInserted;
                cout<<"Enter the element to be inserted>>>\n";
                cin>>elemntToBeInserted;
                cout<<"Enter the index of the element\n";
                cin>>idx;
                if (idx>this->size()) cout<<"The index you entered is more than the size of the list\n";
                else this->insert(elemntToBeInserted, idx);
            }
        break;
        case DLL_REMOVE: 
            {
                int idx;
                cout<<"Enter the index of the element to be removed\n";
                cin>>idx;
                if (idx>this->size()) cout<<"The index you entered is more than the size of the list\n";
                else this->remove(idx);
            }
        break;
        case DLL_AT:
            {
                int idx;
                cout<<"Enter the of the element you would like to access\n";
                cin>>idx;
                if (idx>this->size()) cout<<"The index you entered is more than the size of the list\n";
                else cout<<this->at(idx)<<endl;
            }
        case DLL_PRINT:
            {
                this->print();
            }
        break;
    }
}

string doublylinkedlist::getCommandString(dll_cmd_t cmd) 
{
    switch(cmd) 
    {
        case DLL_COPY: return "1 - Copies the linked list.";
        case DLL_PUSH: return "2 - Pushes an element to the linked list.";
        case DLL_SIZE: return "3 - Returns the size of the linked list.";
        case DLL_POP: return "4 - Pops an element from the linked list.";
        case DLL_INSERT: return "5 - Inserts an element at a given position.";
        case DLL_REMOVE: return "6 - Removes an element from a given position.";
        case DLL_AT: return "7 - Retrieves the element at a given position.";
        case DLL_PRINT: return "8 - Prints the DLL.";
        case CMD_HELP: return "h - Displays this help message.";
        default: return "Unknown command.";
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
    { 
        // If the list is empty
        cout << "There is nothing to pop" << endl;
        return;
    }
    
    else if (head == tail) 
    {
        // If there is only one element in the list
        delete head;
        head = nullptr;
        tail = nullptr;
        cout << "The last element has been popped" << endl;
    }
    else 
    {
        // If there is more than one element
        tail = tail->prev; 
        delete tail->next; // Delete the last element
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
        if (head == nullptr)
        {
            this->push(data);
            return;
        }
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
