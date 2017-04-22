// Class Header File ///////////////////////////////////////////////////////////
/**
* @file BinarySearchTree.h
*
* @details Link-based implementation of the ADT binary search tree.

* @version 1.03
*          +Implementation of traversals and work arounds to print them
*
* @version 1.02
*          +Set and gets for binary node
*
* @version 1.01
*          +Several constructors, isEmpty, getRootData, setRootData
*
* @version 1.00
*			 Kevin Carlos (12 April 2017)
*			 Initial development
*
* @notes none
*/

//Pre-compiler Directives //////////////////////////////////////////////////////
#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

// Header Files ////////////////////////////////////////////////////////////////
#include <memory>
#include <iostream>

class BinarySearchTree
{
private:
   struct BinaryNode
   {
      int data;
      BinaryNode *left ,
         *right;

      // Default Constructor
      BinaryNode ( )
      {
         data = 0;
         left = right = nullptr;
      }

      //Parameterized constructor
      BinaryNode ( int entry )
      {
         data = entry;
      }

      //Getter Functions
      BinaryNode* getLeftChildPtr ( ) const
      {
         return left;
      }

      BinaryNode* getRightChildPtr ( ) const
      {
         return right;
      }

      int getItem ( )
      {
         return data;
      }

      //Setter Functions
      void setLeftChildPtr ( BinaryNode* leftPtr )
      {
         left = leftPtr;
      }

      void setRightChildPtr ( BinaryNode* rightPtr )
      {
         right = rightPtr;
      }
   };

   BinaryNode* rootPtr;
   int treeHeight = 0;

protected:
   //--------------------------------------------------------------------------
   //		Protected Utility Methods Section:
   //		Recursive helper methods for the public methods.
   //--------------------------------------------------------------------------
   
   // Places a given new node at its proper position in this binary
   // search tree
   auto placeNode ( BinaryNode* subTreePtr , BinaryNode* newNode )
      -> decltype ( subTreePtr );

   //Removes the given target value from the tree while maintaing a 
   //binary search tree
   //   auto removeValue ( std::shared_ptr<BinaryNode<ItemType>> subTreePtr ,
   //                        const ItemType target ,
   //                        bool& isSuccessful ) override;

   //Removes a given node from a tree while maintaing a binary search tree
   void removeNode ( BinaryNode* nodePtr );

   //Removes the leftmost node in the left subtree of the node
   //pointed to by nodePtr.
   //Sets inorderSuccessor to the value in this node.
   //Returns a pointer to the revised subtree
   //   auto removeLeftmostNode ( std::shared_ptr<BinaryNode<ItemType>> subTreePtr ,
   //                              ItemType& inorderSuccessor );

   //Returns a pointer to the node containing the given value
   //or nullptr if not found
   auto findNode ( BinaryNode* treePtr , const int& target ) const 
      -> decltype ( treePtr );

public:
   //---------------------------------------------------------------------------
   //    Constructor and Destructor Section
   //---------------------------------------------------------------------------
   BinarySearchTree ( );
   BinarySearchTree ( const int& rootItem );
   //   BinarySearchTree ( const BinarySearchTree& tree );
   ~BinarySearchTree ( );

   //---------------------------------------------------------------------------
   //    Public Methods Section
   //---------------------------------------------------------------------------
   bool isEmpty ( ) const;
   int getHeight ( ) const;
   //   int getNumberOfNodes ( ) const;
   int getRightData ( ) const;
   int getLeftData ( ) const;
   int getRootData ( ) const;
   void setRootData ( const int& newData );
   bool add ( const int& newEntry );
   bool remove ( const int& target );
   void clear ( );
   //int getEntry ( const int& anEntry );
   //bool contains ( const int& anEntry ) const;

   //---------------------------------------------------------------------------
   //    Public Traversals Section
   //---------------------------------------------------------------------------
   void preorderTraverse ( BinaryNode* ptr ) const;
   void inorderTraverse ( BinaryNode* ptr ) const;
   void postorderTraverse ( BinaryNode* ptr ) const;
   void printPreOrder ( );
   void printInOrder ( );
   void printPostOrder ( );

};
#endif