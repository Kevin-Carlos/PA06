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
using std::endl;

int main ( )
{
   int choice;
   BinarySearchTree tree;
   tree.add ( 11 );
   tree.add ( 6 );
   tree.add ( 2 );
   tree.add ( 12 );
   //tree.add ( 1 );   
   //tree.add ( 99 );
   //tree.add ( 8 );
   //tree.add ( 4 );

   cout << "Print preorder: \n";
   tree.printPreOrder ( );
   cout << "Print inorder: \n";
   tree.printInOrder ( );
   cout << "Print postorder: \n";
   tree.printPostOrder ( );

   cout << "Value to remove: ";
   cin >> choice;
   tree.remove ( choice );


   return 0;
}