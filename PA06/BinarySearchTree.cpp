// Class Implementation File ///////////////////////////////////////////////////
/**
* @file BinarySearchTree.cpp
*
* @details Implementation file for the BinarySearchTree class
*
* @version 1.05
*          +Am able to remove the correct target node
*              ---Must delete the pointer pointing to deleted node
*
* @version 1.04
*          +Implementation of traversals and work arounds to print them
*
* @version 1.02
*          +Set and gets for binary node
*
* @version 1.01
*          +Several constructors, isEmpty, getRootData, setRootData
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
//Sets rootPtr node and data
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

/**
  * @function Placenode
  *
  * @details Helper function to the function "add"
  *
  * @param[in] subTreePtr - which is rootPtr
  *
  * @param[in] newNode - pointer to the node containing the new entry
  *
  * @post a node/ leaf or root is inserted into the tree
  *
*/
auto BinarySearchTree::placeNode ( BinaryNode* subTreePtr ,
   BinaryNode* newNode ) -> decltype ( subTreePtr )
{
   //If empty, add new entry as root
   if (subTreePtr == nullptr)
   {
      return newNode;
   }
   //If root > newEntry place the item on the left side of tree
   else if (subTreePtr->getItem ( ) > newNode->getItem ( ))
   {
      subTreePtr->left = placeNode ( subTreePtr->left , newNode );
   }
   //if root < newEntry place the item on the right side fo the tree
   else if (subTreePtr->getItem ( ) < newNode->getItem ( ))
   {
      subTreePtr->right = placeNode ( subTreePtr->right , newNode );
   }
   else //Error
   {
      std::cout << "Cry..." << std::endl;
   }
   return subTreePtr;
}


   //---------------------------------------------------------------------------
   //    Public Methods Section
   //---------------------------------------------------------------------------

/**
  * @function isEmpty
  *
  * @details Boolean that returns whether or not the tree is empty
  *
  * @post if rootPtr is equal to null that means nothing in the tree, so true
  *
*/
bool BinarySearchTree::isEmpty ( ) const
{
   return ( rootPtr == nullptr );
}

/**
  * @function getHeight
  *
  * @details returns the height of the tree
  *
*/
int BinarySearchTree::getHeight ( ) const
{
   return treeHeight;
}

/**
  * @function getNumberOfNodes
  *
  * @details returns the number of nodes in the tree
  *
*/
int BinarySearchTree::getNumberOfNodes ( ) const
{
   return numNodes;
}

/**
  * @function getRootData
  *
  * @details returns the data held by rootPtr
  *
*/
int BinarySearchTree::getRootData ( ) const
{
   return rootPtr->data;
}

/**
  * @function setRootData
  *
  * @details sets the data to be helds by rootPtr
  *
*/
void BinarySearchTree::setRootData ( const int& newData )
{
   rootPtr->data = newData;
   rootPtr->left = nullptr;
   rootPtr->right = nullptr;
}

/**
  * @function getRightData
  *
  * @details gets the data held by the right leaf
  *
*/
int BinarySearchTree::getRightData ( ) const
{
   return rootPtr->right->data;
}

/**
  * @function getRightData
  *
  * @details gets the data held by the left leaf
  *
*/
int BinarySearchTree::getLeftData ( ) const
{
   return rootPtr->left->data;
}

/**
  * @function add
  *
  * @details creates a new node containing the new entry and a pointer to that 
  *            node
  *
  * @param[in] newEntry 
  *            -Passed in to create the new node and add to the tree
*/
bool BinarySearchTree::add ( const int& newEntry )
{
   BinaryNode* newNodePtr = new BinaryNode ( );
   newNodePtr->data = newEntry;
   rootPtr = placeNode ( rootPtr , newNodePtr );
   treeHeight++;
   numNodes++;
   return true;
}

/**
  * @function clear
  *
  * @details clears the entire binary search tree
  *
  * @pre A tree containing values/nodes
  *
  * @post An empty tree
*/
void BinarySearchTree::clear ( )
{
   //BinaryNode* tempPtr;

   //while ( tempPtr != nullptr )
   //{
   // tempPtr = rootPtr;
   //}
}

/**
  * @function remove
  *
  * @details A boolean to tell whether or not the remove was successful
  *
  * @param[in] target
  *               The item to be looked for and removed
  *
  * @post the target removed and leafs shifted to maintain the tree
*/
bool BinarySearchTree::remove ( const int & target )
{
   bool flag;
   BinaryNode* tempPtr;

   //Case 1: if root is null
   if ( rootPtr == nullptr )
   {
      flag = false; //Nothing to remove
   }
   //Case 2: if root is the target
   else if ( rootPtr->data == target )
   {
      std::cout << "Root is target...\n";
      flag = true;
   }
   //Else search the tree for the node
   else
   {
      tempPtr = findNode ( rootPtr , target );
      removeNode ( tempPtr );
   }
   numNodes--;

   return flag;
}

/**
  *
  *
  *
  *
  *
*/
//int BinarySearchTree::getEntry ( const int& anEntry )
//{
//   BinaryNode* tempPtr; //hold the ptr
//
//   tempPtr = findNode ( rootPtr , anEntry );
//
//   return anEntry;
//}

/**
  *
  *
  *
  *
  *
*/
void BinarySearchTree::removeNode ( BinaryNode* nodePtr )
{
   delete nodePtr;
}

/**
  * @function findNode
  *
  * @details Helper function that iteratively searches through the tree while 
  *                the ptr does not equal the target integer
  *
  * @param[in] treePtr - passed in as rootPtr
  *
  * @param[in] target - the target we're searching for
  *
  * @returns the ptr to the node containing the target value
  *
*/
auto BinarySearchTree::findNode ( BinaryNode* treePtr , const int& target ) 
      const -> decltype ( treePtr )
{
   //While the tree node data does not equal target
   while ( treePtr->data != target )
   {
      //Go left if the target is less than the npde
      if ( target < treePtr->data )
      {
         treePtr = treePtr->left;
      }
      //Go right if the target is greater than the npde
      else if ( target > treePtr->data )
      {
         treePtr = treePtr->right;
      }
      else
      {
         std::cout << "Bruh...tragedy...\n";
      }
   }
   return treePtr;
}

/**
  * @function contains
  *
  * @details To find whether or not the item is in the tree
  *
  * @param[in] entry passed in from remove to find the desired removal item
*/
//bool BinarySearchTree::contains ( const int & anEntry ) const
//{
//   inorderTraverse ( rootPtr );
//   if ( rootPtr->data == anEntry )
//   {
//      std::cout << "Success!\n";
//      return true;
//   }
//   else {
//      std::cout << "Falso!\n";
//      return false;
//   }
//
//}

//------------------------------------------------------------------------------
//    Public Traversals
//------------------------------------------------------------------------------

/**
  * @function preorderTraverse
  * 
  * @details traverses the tree and couts in a preorder manner
  *
  * @param[in] BinaryNode* ptr - a general ptr name to use as a cursor
  *               throughout the tree
  *
*/
void BinarySearchTree::preorderTraverse ( BinaryNode* ptr ) const
{
   if (ptr == nullptr)
   {
      return;
   }

   std::cout << ptr->data << ", ";
   preorderTraverse ( ptr->left );
   //std::cout << "Went left...\n";
   preorderTraverse ( ptr->right );
   //std::cout << "Went right...\n";
}

/**
  * @function inorderTraverse
  *
  * @details traverses the tree and couts in a sequential manner
  *
  * @param[in] BinaryNode* ptr - a general ptr name to use as a cursor
  *               throughout the tree
  *
*/
void BinarySearchTree::inorderTraverse ( BinaryNode* ptr ) const
{
   if (ptr == nullptr)
   {
      return;
   }

   inorderTraverse ( ptr->left );
   //std::cout << "Went left...\n";
   std::cout << ptr->data << ", ";
   inorderTraverse ( ptr->right );
   //std::cout << "Went right...\n";
}

/**
  * @function postorderTraverse
  *
  * @details traverses the tree and couts in a post order manner
  *
  * @param[in] BinaryNode* ptr - a general ptr name to use as a cursor
  *               throughout the tree
  *
*/
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
   std::cout << ptr->data << ", ";
}

//------------------------------------------------------------------------------
//    Relatively Useless functions used for specific traversals
//    ****Need to do this a better way
//------------------------------------------------------------------------------

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