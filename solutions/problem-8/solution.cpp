/**
 * @author Servuc
 * Related on project Euler : https://projecteuler.net/problem=8
 * Github issue : https://github.com/moghya/hacktoberfest-projecteuler/issues/10
 */

#include <iostream>
#include <string>
#include <cstdlib>

//Input text
#define IN "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450"

//Length of text to test
#define LENGTH_TO_CHECK 4

/**
 * @brief Transform text to product value of all number chars
 * @param text Text to compute
 * @return Product of chars
 */
unsigned long computeValue( std::string text ) {
  unsigned long myOut = 1;
  for( int i = 0; i < text.length(); i++ ) {
    myOut *= strtoul(text.substr( i, 1 ).c_str(), nullptr, 10);
  }

  return myOut;
}

int main() {
  //Store text in variable to get method on it
  std::string myIn = IN;
  //Compute length for for loop
  unsigned int myInLength = myIn.length();

  //Prepare vars to know the max
  std::string myMaxText;
  unsigned long myMaxValue = 0;

  //Substring each possibilities
  for( int i = 0; i < myInLength - LENGTH_TO_CHECK; i++ ) {
    std::string myText = myIn.substr( i, LENGTH_TO_CHECK );

    //Compute value
    unsigned long myValue = computeValue( myText );

    //Bigger ?
    if( myMaxValue < myValue ) {
      myMaxValue = myValue;
      myMaxText = myText;
    }
  }

  std::cout << "Text : " << myMaxText << " | Value : " << myMaxValue << std::endl;

  return 0;
}