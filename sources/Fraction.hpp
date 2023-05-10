#include "math.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
using namespace std;
namespace ariel{

    class Fraction
    {
        private:
        int numerator ;
        int denominator;
        
        public:
            Fraction();
            Fraction(int , int);
            Fraction(float);
            int getNumerator() const;
            int getDenominator() const;
            int gcd(int num1, int num2);
            Fraction operator+(const Fraction& other) const;
            Fraction operator-(const Fraction& other) const;
            Fraction operator*(const Fraction& other) const;
            Fraction operator/(const Fraction& other) const;
            const bool operator==(const Fraction& other)const;
            const bool operator!=(const Fraction& other) const;
            const bool operator>(const Fraction&other )const  ;
            const bool operator>=(const Fraction& other)const ;
            const bool operator<(const Fraction& other)const ;           
            const bool operator<=(const Fraction& other)const ;


            Fraction& operator++();
            Fraction operator++(int);
            Fraction& operator--();
            Fraction operator--(int);
            
            // Type conversions
            explicit operator double() const;

            friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);
            friend std::istream& operator>>(std::istream& input, Fraction& fraction);        
            const bool operator==(const float& num)const;
            const friend bool operator==(const float& num, const Fraction& fraction);
            const bool operator!=(const float& num)const;
            const friend bool operator!=(const float& num, const Fraction& fraction);
            const bool operator>(const float& num)const;
            const friend bool operator>(const float& num, const Fraction& fraction);
            const bool operator>=(const float& num)const;
            const friend bool operator>=(const float& num, const Fraction& fraction);
            const bool operator<(const float& num)const;
            const friend bool operator<(const float& num, const Fraction& fraction);
            const bool operator<=(const float& num)const;
            const friend bool operator<=(const float& num, const Fraction& fraction);
            const Fraction operator*(const float& num) const;    
            friend Fraction operator*(const float& num, const Fraction& fraction);
            const Fraction operator+(const float& num) const;    
            friend Fraction operator+(const float& num, const Fraction& fraction);
            const Fraction operator-(const float& num) const;    
            friend Fraction operator-(const float& num, const Fraction& fraction);
            const Fraction operator/(const float& num) const;    
            friend Fraction operator/(const float& num, const Fraction& fraction);
    };
     
}
