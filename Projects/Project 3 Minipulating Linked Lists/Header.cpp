#include "Header.h"

OOLList::OOLList()
{
	this->start = NULL;
}

int OOLList::getListSize()
{
    OOLNode* iterator = this->start;
    
    if (iterator == NULL) {
        cout << "<empty>" << endl;
        return 0;
    }
    else {
        cout << ": ";
        int i = 0;
        while (iterator != NULL) {
            iterator = iterator->next;
            i++;
        }
        cout << i << endl;
        return i;
        
    }
}

int OOLList::getListSizeInBytes()
{
   cout << sizeof(this->start)<<  endl;

    return sizeof(this->start);
}

int OOLList::getListElements(int* populateMeWithElements)
{
    return 0;
}

int OOLList::addElement(int addMe)
{
    //Allocate memory for a new OOLNode
    OOLNode* newValue = NULL;
    newValue = new(OOLNode);
    if (newValue == NULL) {
        return ERROR_MEMORY;
    }
    // Populate the new StackNode with data.
    newValue->next = NULL;
    newValue->payload = addMe;

    // if the Stack is empty
    if (this->start == NULL) {
        this->start = newValue;
    }
    else {
        //temp node to scan the numbers in the list
        OOLNode* temp = this->start;
        // when data is to be inserted at first node 
        if (addMe < temp->payload) {
            newValue->next = this->start;
            this->start = newValue;
            return OK;
        }
        while (temp->next !=NULL){
           
            if (addMe > temp->next->payload) {
                temp = temp->next;
            }
            else {
                newValue->next = temp->next;
                temp->next = newValue;
                return OK;
            }
        }
        if (addMe > temp->payload) {
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newValue;
        }
        
    }
 return OK;

}

int OOLList::operator+(int addMe)
{
   
    return  addElement(addMe);
}

bool OOLList::deleteElement(int deleteMe)
{
    // BORDER CASE #1 - The list is EMPTY.
    if (this->start == NULL) {
        deleteMe = -1;
        return ERROR_MEMORY;
    }

    // BORDER CASE #2 - The list has a single element.
    else if (this->start->next == NULL) {
        deleteMe = this->start->payload;
        delete this->start;
        this->start = NULL;
        return OK;
    }
    
    OOLNode* q = this->start;
    OOLNode* p = this->start->next;
    if (deleteMe == q->payload) { //first node
        this->start = p;
        delete (q);
        return OK;
    }
    else {
        while (p->payload != deleteMe)
        {
            p = p->next;
            q = q->next;
        }
        if (p->next == NULL){ //last node
            q->next = NULL;
            delete(p);
            return OK;
        }
        else { //internal node
            q->next = p->next;
            delete(p);
            return OK;
        }
    }
   
    return NOT_FOUND;
}

bool OOLList::operator-(int deleteMe)
{
    return deleteElement(deleteMe);
}

void OOLList::CosolePrint()
{
    OOLNode* iterator = this->start;
    // Iterate through and print the list.
    cout << left;
    if (iterator == NULL) {
         cout   << ": " << "<empty>" << endl;
    }
    else {
       
        cout << ": ";
        while (iterator != NULL) {
            cout << setw(4) << iterator->payload;
            iterator = iterator->next;
        }
        cout << endl;
    }
}
