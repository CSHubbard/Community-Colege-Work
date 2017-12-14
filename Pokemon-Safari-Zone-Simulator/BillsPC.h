#ifndef BILLSPC_H
#define BILLSPC_H
#include <iostream>
#include <string>
using namespace std;

// Stack template
int counter;

template <class T>
class BillsPC
{
private:
   struct PCSlot
   {
      T StoredMon;      // The StoredMon in the slot
      PCSlot *left;    // Pointer to left child slot
      PCSlot *right;   // Pointer to right child slot
   };

   PCSlot *root;       // Pointer to the root slot
   
   // Private member functions
   void insert(PCSlot *&, PCSlot *&);
   void displayInOrder(PCSlot *) const;
   int countslots(PCSlot* , string);

public:
   // Constructor
   BillsPC()
      { root = NULL; }
      
   // Unused Destructor
   ~BillsPC()
	{}

      
   // PC operations
   void insertslot(T);
   bool searchslot(T);

   
   int displayCount(string ID)
	{	
		counter = 0;
		return countslots(root, ID); 
    }

   void displayInOrder() const
      {  displayInOrder(root); }
};


//Creates a newslot and then passes it to the actual insert function
template <class T>
void BillsPC<T>::insertslot(T pokemon)
{
   PCSlot *newslot;      // Pointer to a new slot.

   // Create a new slot and store num in it.
   newslot = new PCSlot;
   newslot->StoredMon = pokemon;
   newslot->left = newslot->right = NULL;
   
   // Insert the slot.
   insert(root, newslot);
}

 
//uses created neslot to and inserts into the tree, recursive.
template <class T>
void BillsPC<T>::insert(PCSlot *&slotPtr, PCSlot *&newslot)
{
   if (slotPtr == NULL)
      slotPtr = newslot;                  // Insert the slot.
   else if (newslot->StoredMon < slotPtr->StoredMon)
      insert(slotPtr->left, newslot);     // Search the left branch
   else 
      insert(slotPtr->right, newslot);    // Search the right branch
}


//searches the tree for a pokemon
template <class T>
bool BillsPC<T>::searchslot(T pokemon)
{
   PCSlot *slotPtr = root;

   while (slotPtr)
   {
      if (slotPtr->StoredMon == pokemon)
         return true;
      else if (pokemon < slotPtr->StoredMon)
         slotPtr = slotPtr->left;
      else
         slotPtr = slotPtr->right;
   }
   return false;
}


//displays the pokemon caught in alphebetical order
template <class T>
void BillsPC<T>::displayInOrder(PCSlot *slotPtr) const
{
   if (slotPtr)
   {
      displayInOrder(slotPtr->left);
      cout << slotPtr->StoredMon << endl;
      displayInOrder(slotPtr->right);
   }
}

//counts the number of a certain pokemon that have been caught in total

template <class T>
int BillsPC<T>::countslots(PCSlot *slotPtr, string ID)
{
   if (slotPtr)
   {

	countslots(slotPtr->left, ID);	
	if (slotPtr->StoredMon == ID)
		{
			counter++;
		}
	countslots(slotPtr->right, ID);
   }
	return counter;
}
#endif