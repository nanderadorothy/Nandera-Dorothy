#include <iostream>
#include <string>
using namespace std;
// fuunction protoypes
bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

// returns true if the card is valid
bool isValid(long long number) {
    int size = getSize(number);
    if (size < 13 || size > 16) 
    return false;
    bool validPrefix = prefixMatched(number, 4) || prefixMatched(number, 5) || 
                       prefixMatched(number, 37) || prefixMatched(number, 6);
    return validPrefix && ((sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0);
}
// gets the results from step 2
int sumOfDoubleEvenPlace(long long number) {
    int sum = 0;
    for (number /= 10; number > 0; number /= 100) sum += getDigit((number % 10) * 2);
    return sum;
}
// returns the number if it is a single digit, otherwise, returns the sum of the two digits
int getDigit(int number) { 

    return number < 10 ? number : (number / 10 + number % 10); 
}
//returns the sum of odd place digits in number
int sumOfOddPlace(long long number) {
    int sum = 0;
    for (; number > 0; number /= 100) sum += number % 10;
    return sum;
}
// returns true if the digit d is a prefix for a number
bool prefixMatched(long long number, int d) {
    string sNum = to_string(number), sD = to_string(d);
    return sNum.rfind(sD, 0) == 0;
}
// returns the number of digits in d
int getSize(long long d) { 
    return to_string(d).length(); 
}
//returns the first k number of digits from number. if the number of digits in the number is less than k
long long getPrefix(long long number, int k) {
    string s = to_string(number);
    return s.length() < k ? number : stoll(s.substr(0, k));
}
int main() {
    long long card;
    cout << "Enter credit card number: ";
    cin >> card;
    cout << card << (isValid(card) ? " is valid." : " is invalid.") << endl;

    return 0;
}
