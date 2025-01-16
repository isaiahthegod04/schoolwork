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
         theCapacity = 12 ;
         objects = new Object[ theCapacity ]; 
         theSize = 0 ;
         left = 0 ; // array index of location just before the left-most list element  
         right = 1 ; // array index just past the right-most list element
      }
      
    ~AList( ) //destructor, deletes excess memory ----------- talk to TA about it
      { delete [ ] objects; }

    bool empty( ) const  { return size( ) == 0; }
    int size( ) const { return theSize; }
    void clear( ) {
         theSize = 0 ;// sets item count to 0     
         left = 0 ;   // sets the left pointer to 0      [  ,  ,  ,]
         right = 1 ;  // sents the right pointer to 1    L^  R^
    }

    // Operations 



// shouldn't these be integers?
    void addLeft( const Object x )// Insert a new object at the left end 
    {

	// Check This

       theSize ++ ;
	left = (left - 1 + theCapacity) % theCapacity;
        objects[left] = x;
    }

    void addRight( const Object x )// Insert a new object at the right end
    {
        theSize ++ ;
	objects[right] = x ;
        right = (right+1) % theCapacity ;
    }



    Object removeRight( )// Remove and return the object at the right end
    {
         if(empty()) {cout << "Nothing to remove"}; // if theres nothing in the list display this

        right = (right - 1 + theCapacity) % theCapacity; // moves the pointer over one space LEFT, then adds the capacity so it can't have negative value, & includes modular feature so it wraps
        Object RmvRight = objects[right];// removed the right object
        theSize--;// decreased total size by one
        return RmvRight; //returns the removed object
    }



    Object removeLeft( )// Remove and return the object at the left end
    {
        if(empty()) {cout << "Nothing to remove"};

        left = (left + 1) % theCapacity;// just moves the pointer one space RIGHT 
        Object RmvLeft = objects[left];
        theSize--;// decreased size by one 
        return RmvLeft;
    }



    void display() const // print out the contents of the Alist
  {

     if(empty()) {cout << "Nothing in Alist"};// if its emplty print this


      int Lpointer = left // rename make understanding easier 
       for (int i = 0; i < theSize; ++i)
         cout << objects[Lpointer] << " ";
       Lpointer =  (Lpointer + 1) % theCapacity; 
      // this loop prints all the elements
      // i represents the number of loop cycles it takes
      // obvi can't have more loop cycles then there is objects in section
      // it continues the loop if the number of current loops is < the size   
    }


    void ddisplay() const // print out the contents of the objects 
    // array, and relevant variables, for debugging or verifying 
    // correctness. 
    {   cout << "the elements in the list are: ";
        display();
        cout << "the other junk is: ";
        for (int i = 0; i < theCapacity; ++i)
        // this loop cycles thru the array 0 to 11 (the capacity - 1) times
          cout << objects[i] << " ";
// for each cycle, it prints whatever object is there, no matter what it is.
          cout <<  "The size of the list is: " << theSize << "The left element is: " << left << " The right element is: " << right << endl;
    }
    // prints info about list


  private:
    int theSize;
    int left;
    int right;
    int theCapacity;
    Object * objects;
};

#endif
