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
#include <iostream>

using namespace std;


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
   //		Protected Utility Methods Section:
   //		Recursive helper methods for the public methods.
   //---------------------------------------------------------------------------

auto BinarySearchTree::placeNode ( BinaryNode* subTreePtr , 
   BinaryNode* newNode ) -> decltype ( subTreePtr )
{
   BinaryNode* tempPtr;
   int newEntry;

   //If empty, add new entry as root
   if ( isEmpty ( ) )
   {
      return newNode;
   }
   else if ( subTreePtr->getItem ( ) > newNode->getItem ( ) )
   {
      newEntry = newNode->getItem ( );
      rootPtr->left = new BinaryNode ( newEntry );
      tempPtr = placeNode ( subTreePtr->getLeftChildPtr ( ) , newNode );
      subTreePtr->setLeftChildPtr ( tempPtr );
   }
   else
   {
      if ( rootPtr->right == nullptr )
      {
         newEntry = newNode->getItem ( );
         rootPtr->right = new BinaryNode ( newEntry );
         tempPtr = placeNode ( subTreePtr->getRightChildPtr ( ) , newNode );
         subTreePtr->setRightChildPtr ( tempPtr );
      }
   }

   return subTreePtr;
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
   rootPtr->left = nullptr;
   rootPtr->right = nullptr;
}

int BinarySearchTree::getRightData ( ) const
{
   return rootPtr->right->data;
}

int BinarySearchTree::getLeftData ( ) const
{
   return rootPtr->left->data;
}

bool BinarySearchTree::add ( const int& newEntry )
{
   BinaryNode* newNodePtr = new BinaryNode ( newEntry );
   rootPtr = placeNode ( rootPtr , newNodePtr );
   return true;
}


void BinarySearchTree::clear ( )
{
   //BinaryNode* tempPtr;

   //while ( tempPtr != nullptr )
   //{
     // tempPtr = rootPtr;
   //}
}