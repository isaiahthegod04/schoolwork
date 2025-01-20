#ifndef ALIST_H
#define ALIST_H
#include <iostream>

using namespace std;

template <typename Object>
class AList 
{
public:
    AList()
    {  
        theCapacity = 12;
        objects = new Object[theCapacity]; 
        theSize = 0;
        left = 0;  // Index just before the left-most element
        right = 0; // Index where the next right element will go
    }
    
    ~AList() //destructor, deletes excess memory ----------- talk to TA about it
    { delete[] objects; }
    bool  empty() const { return theSize == 0; }
    int size() const { return theSize; }
    void clear()  {
        theSize = 0; // sets item count to 0   
        left = 0; // sets the left pointer to 0      [  ,  ,  ,]
        right = 0;// sets the right pointer to 1     L^  R^
    }


// Opertions are below 
// should these be integers whty is is x?
    void addLeft(const Object x){
        // check this again
        left = (left - 1 + theCapacity) % theCapacity; // Move left pointer backward
        objects[left] = x; // Assign value
        theSize++; // Increment size
    }

    void addRight(const Object x)// puts opject on right end
    {
        objects[right] = x; // Assign value
        right = (right + 1) % theCapacity; // Move right pointer forward
        theSize++; // Increment size
    }

    Object removeLeft()// remove and return right end
    {
        if (empty()) {
            cout << "Nothing to remove" << endl;
            return Object(); // Return this if theres nothing there
        }
        Object removed = objects[left]; // remove the leftmost value
        left = (left + 1) % theCapacity; // Move left pointer forward
        theSize--; // Decrement size
        return removed;
    }

    Object removeRight()
    {
        if (empty()) {
            cout << "Nothing to remove" << endl;
            return Object(); // Return this if theres nothing there 
        }
        right = (right - 1 + theCapacity) % theCapacity; // Move right pointer backward
        Object removed = objects[right]; // Get the rightmost value
        theSize--; // Decrement size
        return removed;
    }

    void display() const // prints everythin gthats in the alist
    {
        if (empty()) {
            cout << "Nothing in AList" << endl;
            return;// if empty print this
        }
        int Lpointer = left;
        for (int i = 0; i < theSize; ++i) {
            cout << objects[Lpointer] << " ";
            Lpointer = (Lpointer + 1) % theCapacity; // Move forward in circular array
        }
           // this loop prints all the elements
      // i represents the number of loop cycles it takes
      // obvi can't have more loop cycles then there is objects in section
      // it continues the loop if the number of current loops is < the size   
        cout << endl;
    }

    void ddisplay() const// print out the contents of the objects 
    // array, and relevant variables, for debugging or verifying 
    // correctness. 
    {
        cout << "The elements in the list are: ";
        display();
        cout << "The internal array is: ";
        for (int i = 0; i < theCapacity; ++i) {
                    // this loop cycles thru the array 0 to 11 (the capacity - 1) times

            cout << objects[i] << " ";
            // for each cycle, it prints whatever object is there, no matter what it is.

        }
        cout << endl;
        cout << "The size of the list is: " << theSize << endl;
        cout << "The left pointer is: " << left << endl;
        cout << "The right pointer is: " << right << endl;
    }
    // prints info about list

private:
    int theSize;
    int left;
    int right;
    int theCapacity;
    Object* objects;
};

#endif
