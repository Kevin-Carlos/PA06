//Driver File //////////////////////////////////////////////////////////////////
/**
  * @file PA06.cpp
  *
  * @details Driver file to run and test the Binary Search Tree class
  *
  * @version 1.00 
  *          Kevin Carlos (19 April 2017)
  *          Initial Development
  *
  * @notes none
*/
// Header Files ////////////////////////////////////////////////////////////////
#include <iostream>

#include "BinarySearchTree.h"

using std::cin;
using std::cout;

int main ( )
{
   BinarySearchTree tree;
   tree.add ( 11 );
   tree.add ( 6 );
   tree.add ( 2 );
   tree.add ( 12 );
   tree.add ( 1 );   
   tree.add ( 99 );
   tree.add ( 8 );
   tree.add ( 4 );

   std::cout << "Root: " << tree.getRootData ( ) << std::endl;
   std::cout << "Right: " << tree.getRightData ( ) << std::endl;
   std::cout << "Left: " << tree.getLeftData ( ) << std::endl;

   return 0;
}