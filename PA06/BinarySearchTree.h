// Class Header File ///////////////////////////////////////////////////////////
/**
  * @file BinarySearchTree.h
  *
  * @details Link-based implementation of the ADT binary search tree.
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

#include "BinarySearchTree.cpp"

//Template declaration
typedef BinarySearchTree<int> searchTree;

template<class ItemType>
class BinarySearchTree
{
private: BinaryNode<ItemType>* rootPtr;

protected:
	//--------------------------------------------------------------------------
	//		Protected Utility Methods Section:
	//		Recursive helper methods for the public methods.
	//--------------------------------------------------------------------------
	// Places a given new node at its proper position in this binary
   // search tree

//   auto placeNode ( std::shared_ptr<BinaryNode<ItemType>> subTreePtr ,
//                     std::shared_ptr<BinaryNode<ItemType>> newNode;
//
//   //Removes the given target value from the tree while maintaing a 
//   //binary search tree
//   auto removeValue ( std::shared_ptr<BinaryNode<ItemType>> subTreePtr ,
//                        const ItemType target ,
//                        bool& isSuccessful ) override;
//  
//   //Removes a given node from a tree while maintaing a binary search tree
//   auto removeNode ( std::shared_ptr<BinaryNode<ItemType>> nodePtr );
//
//   //Removes the leftmost node in the left subtree of the node
//   //pointed to by nodePtr.
//   //Sets inorderSuccessor to the value in this node.
//   //Returns a pointer to the revised subtree
//   auto removeLeftmostNode ( std::shared_ptr<BinaryNode<ItemType>> subTreePtr ,
//                              ItemType& inorderSuccessor );
//
//   //Returns a pointer to the node containing the given value
//   //or nullptr if not found
//   auto findNode ( std::shared_ptr<BinaryNode<ItemType>> treePtr ,
//                     const ItemType& target ) const;
//
//public:
//   //---------------------------------------------------------------------------
//   //    Constructor and Destructor Section
//   //---------------------------------------------------------------------------
//   BinarySearchTree ( );
//   BinarySearchTree ( const ItemType& rootItem );
//   BinarySearchTree ( const BinarySearchTree<ItemType>& tree );
//   ~BinarySearchTree ( );
//
//   //---------------------------------------------------------------------------
//   //    Public Methods Section
//   //---------------------------------------------------------------------------
//   bool isEmpty ( ) const;
//   int getHeight ( ) const;
//   int getNumberOfNodes ( ) const;
//   ItemType getRootData ( ) const;
//   void setRootData ( const ItemType& newData );
//   bool add ( const ItemType& newEntry );
//   bool remove ( const ItemType& target );
//   void clear ( );
//   ItemType getEntry ( const ItemType& anEntry );
//   bool contains ( const ItemType& anEntry ) const;
//
//   //---------------------------------------------------------------------------
//   //    Public Traversals Section
//   //---------------------------------------------------------------------------
//   void preorderTraverse ( void visit ( ItemType& ) ) const;
//   void inorderTraverse ( void visit ( ItemType& ) ) const;
//   void postorderTraverse ( void visit ( ItemType& ) ) const;

   //---------------------------------------------------------------------------
   //    Overloaded Operator Section
   //---------------------------------------------------------------------------
   operator=( const BinarySearchTree<ItemType>& rightHandSide );
};
#endif
