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


   //---------------------------------------------------------------------------
   //    Constructor and Destructor Section
   //---------------------------------------------------------------------------

// Default Constructor
BinarySearchTree::BinarySearchTree( )
{
   rootPtr = nullptr; 
}

//Copy Constructor
BinarySearchTree::BinarySearchTree( const int& rootItem )
{
   rootPtr = new BinaryNode;
   rootPtr->data = rootItem;
}

//Destructor
BinarySearchTree::~BinarySearchTree()
{
   clear();
}

   //---------------------------------------------------------------------------
   //    Public Methods Section
   //---------------------------------------------------------------------------
bool BinarySearchTree::isEmpty ( ) const
{
   return ( rootPtr == nullptr );
}

int BinarySearchTree::getRootData ( ) const
{
   return rootPtr->data;
}

void BinarySearchTree::setRootData ( const int& newData )
{
   rootPtr->data = newData;
   rootPtr->left = NULL;
   rootPtr->right = NULL;
}

bool BinarySearchTree::add ( const int& newEntry )
{
   bool flag = false;

   //If empty, add new entry as root
   if ( isEmpty ( ) )
   {
      setRootData ( newEntry );
      flag = true;
   }
   // Find the position to insert entry
   else
   {
      flag = true;
   }
   return flag;
}


void BinarySearchTree::clear ( )
{
   //BinaryNode* tempPtr;

   //while ( tempPtr != nullptr )
   //{
     // tempPtr = rootPtr;
   //}
}