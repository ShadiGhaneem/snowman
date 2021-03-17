
#include "snowman.hpp"
#include "snowman.cpp"
#include <iostream>
#include <stdexcept>
using namespace std;



int main() {
	cout << ariel::snowman(13232124) << endl;   /* Should print:
 _===_  
\(o_O)
 (] [)>
 (   )
	*/


	cout << ariel::snowman(33333323) << endl;   /* Should print:
   _    
  /_\   
 (O_O)  
/(] [)\  
 (___) 

	*/


	cout << ariel::snowman(13133234) << endl;   /* Should print:
     
 _===_  
 (._O)/ 
/(> <) 
 (   ) 

	*/




	try {
		cout << ariel::snowman(5) << endl;
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  
	}

    try {
		cout << ariel::snowman(55555555) << endl;   // Exception - not a valid code
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "The characters must be between 1 and 4"
	}

    return 0;
}