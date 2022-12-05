#include "strFuncs.h"
#include <cctype>

using namespace std;


/* Precondition: s1 is a valid string that may contain upper or lower case alphabets, no spaces or special characters
 * Postcondition: Returns true if s1 is a palindrome, false otherwise
 *
 * Palindromes are NOT case-sensitive - "RaCecaR" is a valid palindrome
 *
 *You should provide a recursive solution*/
bool isPalindrome(const string s1){
    int size = s1.size();
    if (size == 1 || (size == 2 && tolower(s1.at(0)) == tolower(s1.at(1))))
    // base cases: if s1 is a single letter, or two identical letters
    {
        return true;
    }
    else if (tolower(s1.at(0)) != tolower(s1.at(size-1)))
    // if first letter is not equal to last letter
    {
        return false;
    }
    else
    // recursive case
    {
        return isPalindrome(s1.substr(1,size-2));
    }
}
