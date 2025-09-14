#ifndef BIGNUMCALC_H
#define BIGNUMCALC_H

#include <list>
#include <string>

class BigNumCalc {
    private:
        // helper to remove leading zeros in front of list
        void trimLeadingZeroes(std::list<int>& num);
    public:
        BigNumCalc() = default;     // constructor
        ~BigNumCalc() = default;    // destructor

        // build number list from string
        std::list<int> buildBigNum(const std::string& numString);

        // addition
        std::list<int> add(const std::list<int>& num1, const std::list<int>& num2);

        // subtract
        std::list<int> sub(const std::list<int>& num1, const std::list<int>& num2);

        // multiply
        std::list<int> mul(const std::list<int>& num1, const std::list<int>& num2);

};

#endif