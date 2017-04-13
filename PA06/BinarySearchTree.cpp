// Class Implementation File ///////////////////////////////////////////////////
/**
  * @file BinarySearchTree.cpp
  *
  * @details Implementation file for the BinarySearchTree class
  *
  * @version 1.00 
  *          Kevin Carlos (12 April 2017)
  *          Initial Implementation
  *
  * @notes none
*/

//Header Files
#include "BinarySearchTree.h"

//Overloaded operator
template <class ItemType>
BinarySearchTree<ItemType>::
      operator=(const BinarySearchTree<ItemType>& rightHandSide)
{
   //Check for self-assignment
   if (this == &rightHandSide)
   {
      return *this;
   }
   else //assign data
   {

   }
}