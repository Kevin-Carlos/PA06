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
BinarySearchTree::BinarySearchTree ( )
{
   rootPtr = nullptr;
}

//Copy Constructor
BinarySearchTree::BinarySearchTree ( const int& rootItem )
{
   rootPtr = new BinaryNode;
   rootPtr->data = rootItem;
}

//Destructor
BinarySearchTree::~BinarySearchTree ( )
{
   clear ( );
}

   //---------------------------------------------------------------------------
   //		Protected Utility Methods Section:
   //		Recursive helper methods for the public methods.
   //---------------------------------------------------------------------------

auto BinarySearchTree::placeNode ( BinaryNode* subTreePtr ,
   BinaryNode* newNode ) -> decltype ( subTreePtr )
{
   //If empty, add new entry as root
   if (subTreePtr == nullptr)
   {
      return newNode;
   }
   //If root > newEntry
   else if (subTreePtr->getItem ( ) > newNode->getItem ( ))
   {
      subTreePtr->left = placeNode ( subTreePtr->left , newNode );
   }
   else if (subTreePtr->getItem ( ) < newNode->getItem ( ))
   {
      subTreePtr->right = placeNode ( subTreePtr->right , newNode );
   }
   else
   {
      std::cout << "Cry..." << std::endl;
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
   BinaryNode* newNodePtr = new BinaryNode ( );
   newNodePtr->data = newEntry;
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

void BinarySearchTree::preorderTraverse ( BinaryNode* ptr ) const
{
   if (ptr == nullptr)
   {
      return;
   }

   std::cout << ptr->data << std::endl;
   preorderTraverse ( ptr->left );
   //std::cout << "Went left...\n";
   preorderTraverse ( ptr->right );
   //std::cout << "Went right...\n";
}

void BinarySearchTree::inorderTraverse ( BinaryNode* ptr ) const
{
   if (ptr == nullptr)
   {
      return;
   }

   inorderTraverse ( ptr->left );
   //std::cout << "Went left...\n";
   std::cout << ptr->data << std::endl;
   inorderTraverse ( ptr->right );
   //std::cout << "Went right...\n";
}

void BinarySearchTree::postorderTraverse ( BinaryNode* ptr ) const
{
   if (ptr == nullptr)
   {
      return;
   }

   postorderTraverse ( ptr->left );
   //std::cout << "Went left...\n";
   postorderTraverse ( ptr->right );
   //std::cout << "Went right...\n";
   std::cout << ptr->data << std::endl;
}

void BinarySearchTree::printPreOrder ( )
{
   preorderTraverse ( rootPtr );
}

void BinarySearchTree::printInOrder ( )
{
   inorderTraverse ( rootPtr );
}

void BinarySearchTree::printPostOrder ( )
{
   postorderTraverse ( rootPtr );
}