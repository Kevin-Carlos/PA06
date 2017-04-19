// Header Files ////////////////////////////////////////////////////////////////
#include <iostream>

#include "BinarySearchTree.h"

using std::cin;
using std::cout;

int main ( )
{
   BinarySearchTree tree;
   tree.add ( 5 );
   tree.add ( 6 );
   tree.add ( 2 );
   tree.add ( 10 );
   tree.add ( 1 );

   std::cout << tree.getRootData ( ) << std::endl;
   std::cout << tree.getRightData ( ) << std::endl;
   std::cout << tree.getLeftData ( ) << std::endl;

   return 0;
}