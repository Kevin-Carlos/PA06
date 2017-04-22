//Driver File //////////////////////////////////////////////////////////////////
/**
  * @file PA06.cpp
  *
  * @details Driver file to run and test the Binary Search Tree class
  *
  * @version 1.02
  *          +Created Case 1, 2, and 3

  * @version 1.01
  *          +Added RNG of unique values and insertion into a vector
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

#include "BinarySearchTree.h"

// Directives //////////////////////////////////////////////////////////////////
using std::cin;
using std::cout;
using std::endl;

//Function Protoypes ///////////////////////////////////////////////////////////
void randNumCreator ( std::vector<int>&, const int );

//Main Function Implementation /////////////////////////////////////////////////
int main ( )
{
   //Variables
   int nums, numIndex;
   BinarySearchTree BST1;
   BinarySearchTree BST2;
   std::vector<int> rngNumsCase1;
   std::vector<int> indexCreator;
   std::vector<int> rngNumsCase2;
   const int MAX_SIZE1 = 100;
   const int MAX_SIZE2 = 10;

   //Seed the RNG
   srand ( time ( NULL ) );

   //---------------------------------------------------------------------------
   //Case 1: 100 unique numbers in the range 1-200
   //---------------------------------------------------------------------------
   
   cout << "\nCASE1 \n";
   cout << "--------\n";

   //Create a vector of above specs
   randNumCreator ( rngNumsCase1, MAX_SIZE1 );
   
   //Add these values to a tree
   for ( int index = 0; index < MAX_SIZE1; index++ )
   {
      nums = rngNumsCase1 [ index ];
      BST1.add ( nums );
   }
   cout << "Height of tree: " << BST1.getHeight ( ) << endl;
   cout << "BST1 InOrder: ";
   BST1.printInOrder ( );
   cout << endl;

   //---------------------------------------------------------------------------
   //Case 2: Generate 10 values that overlap with BST1 and insert into BST1
   //---------------------------------------------------------------------------

   cout << "\nCASE2 \n";
   cout << "--------\n";

   randNumCreator ( indexCreator , MAX_SIZE2 );

   //Create a vector of these values
   for ( int loopIndex = 0; loopIndex < MAX_SIZE2; loopIndex++ )
   {
      numIndex = indexCreator [ loopIndex ];
      nums = rngNumsCase1.at( numIndex );
      rngNumsCase2.push_back ( nums );
   }

   //Add to the tree
   for ( int loopIndex = 0; loopIndex < MAX_SIZE2; loopIndex++ )
   {
      nums = rngNumsCase2 [ loopIndex ];
      BST2.add ( nums );
   } 
   //Print the tree all three ways
   cout << "BST2 Preorder: "; 
   BST2.printPreOrder ( );
   cout << "\nBST2 Inorder: ";
   BST2.printInOrder ( );
   cout << "\nBST2 Postorder: ";
   BST2.printPostOrder ( );
   cout << endl;
   
   //---------------------------------------------------------------------------
   // Case3: Find and remove any values of BST2 from BST1. Print height, number 
   // of nodes, and inorder output of the modified BST1 tree.
   //---------------------------------------------------------------------------
   
   cout << "\nCASE3 \n";
   cout << "--------\n";
   for ( int loopIndex = 0; loopIndex < MAX_SIZE2; loopIndex++ )
   {
      nums = rngNumsCase2 [ loopIndex ];
      BST1.remove ( nums );
   }
   //Print height
   cout << "Height of BST1: " << BST1.getHeight ( ) << endl;
   //Print # of nodes
   //numNodes = BST1.getNumberofNodes ( );
   cout << "# of Nodes: " << BST1.getNumberOfNodes() << endl;
   //Print inorder
   cout << "BST1 InOrder: ";
   BST1.printInOrder ( );
   cout << endl;

   return 0;
}

/**
  * @function randNumCreator
  *
  * @details generates unique random numbers and puts them into a vector
  *               and returns that created vector
*/
void randNumCreator ( std::vector<int>& rngNums, const int MAX_SIZE )
{
   long int numbers;
   int index = 0;
   bool contains;

   while ( index < MAX_SIZE )
   {
      contains = false;
      //Generate a random number
      //if to handle my index creator so i dont go out of bounds
      if ( MAX_SIZE == 10 )
      {
         numbers = ( rand ( ) % 100 ) + 1;
      }
      else
         numbers = ( rand ( ) % 200 ) + 1;

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

      //Push values into vector
      if ( contains == false )
      {
         rngNums.push_back ( numbers );
         index++;
      }
   }
}
