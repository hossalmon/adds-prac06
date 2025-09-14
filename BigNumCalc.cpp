#include "BigNumCalc.h"
#include <algorithm>
#include <cctype>

// trim leading 0s
void BigNumCalc::trimLeadingZeroes(std::list<int>& num) {
    while (num.size() > 1 && num.front() == 0) {
        num.pop_front();
    }
}


// build number list from string
std::list<int> BigNumCalc::buildBigNum(const std::string& numString) {
    std::list<int> result;
    for (char c : numString) {
        if(isdigit(c)) {
            result.push_back(c - '0'); // convert char to int digit
        }
    }

    return result;
}

// addition - loop backwards since least significant digit is at the end of the list
std::list<int> BigNumCalc::add(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result;

    // start from right most digits
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    int carry = 0;

    // continue until both numbers fully used and no carry left
    while (it1 != num1.rend() || it2 != num2.rend() || carry > 0) {
        int d1 = (it1 != num1.rend()) ? *it1++ : 0;     // digit from num1 or 0
        int d2 = (it2 != num2.rend()) ? *it2++ : 0;     // digit from num2 or 0

        int sum = d1 + d2 + carry;
        result.push_front(sum % 10);    // store last digit
        carry = sum / 10;               // update carry (0 or 1)
    }

    return result;
}

// subtraction
std::list<int> BigNumCalc::sub(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result;

    auto it1 = num1.rbegin(); // digits from num1 (right to left)
    auto it2 = num2.rbegin(); // digits from num2 (right to left)
    int borrow = 0;

    // loop until all digits from num1 and num2 are used
    while (it1 != num1.rend() || it2 != num2.rend()) {
        int d1 = (it1 != num1.rend()) ? *it1++ : 0;
        int d2 = (it2 != num2.rend()) ? *it2++ : 0;

        int diff = d1 - d2 - borrow;

        if (diff < 0) {
            diff += 10;  // borrow from next digit
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.push_front(diff);
    }

    // remove leading zeroes
    trimLeadingZeroes(result);
    return result;
}

// multiplication 
std::list<int> BigNumCalc::mul(const std::list<int>& num1, const std::list<int>& num2) {
    int multiplier = num2.front();    // extract multiplier

    std::list<int> result;
    int carry = 0;

    // loop through num1 from back (rightmost digit)
    for (auto it1 = num1.rbegin(); it1 != num1.rend(); ++it1) {
        int prod = (*it1) * multiplier + carry;
        result.push_front(prod % 10); // store single digit
        carry = prod / 10;            // carry over remainder
    }

    // if something left in carry, push it in front
    if (carry > 0) {
        result.push_front(carry);
    }

    // remove leading zeroes
    trimLeadingZeroes(result);
    return result;
}