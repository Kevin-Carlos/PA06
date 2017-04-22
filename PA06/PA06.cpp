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
#include <vector>
#include <ctime>
#include <algorithm>

#include "BinarySearchTree.h"

using std::cin;
using std::cout;
using std::endl;

//Function Protoypes ///////////////////////////////////////////////////////////
void case1 ( std::vector<int>& );

int main ( )
{
   int choice;
   BinarySearchTree tree;
   std::vector<int> rngNumsCase1;

   //Seed the RNG
   srand ( time ( NULL ) );

   //Case 1: 100 unique numbers in the range 1-200
   //Create a vector of above specs
   case1 ( rngNumsCase1 );


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

   cout << "After remove: \n";
   tree.printPreOrder ( );

   cout << "Height of tree: " << tree.getHeight ( ) << endl;


   return 0;
}

void case1 ( std::vector<int>& rngNums )
{
   long int numbers;
   int index = 0;
   bool contains;
   const int MAX_SIZE = 100;

   while ( index < MAX_SIZE )
   {
      contains = false;
      //Generate a random number
      numbers = ( rand ( ) % 200 ) + 1; //Generate numbers within 1-200

      //Check if vector is empty
      if ( rngNums.empty ( ) )
      {
         contains = false;
      }
      //else check the vector if the number already exists
      else
      {
         for ( int index2 = 0; index2 < MAX_SIZE; index2++ )
         {
            //If true will set to true
            //contains = ( rngNums [ index2 ] == numbers ) ? true : false;
            if ( rngNums [ index2 ] == numbers )
            {
               contains = true;
            }
         }
      }
      if ( contains == false )
      {
         rngNums.push_back ( numbers );
         index++;
      }
   }
}
