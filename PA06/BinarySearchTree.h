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

template<class Itemtype>
class BinarySearchTree
{
private: BinaryNode<ItemType>* rootPtr;
protected:
	//--------------------------------------------------------------------------
	//		Protected Utility Methods Section:
	//		Recursive helper methods for the public methods.
	//--------------------------------------------------------------------------
	//	Recursively finds where the given node should be placed and
	//	Inserts it in a leaf at that point. 
   BinaryNode<ItemType>* insertInorder(BinaryNode<ItemType>* subTreePtr,
                                       BinaryNode<ItemType>* newNode);
   BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr,
                                     const ItemType target,
                                     bool* success);
   BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodePtr;);
   BinaryNode<ItemType>* removeLeftmostNode(
      BinaryNode<ItemType>* subTreePtr, ItemType& inorderSuccessor);


};

#endif