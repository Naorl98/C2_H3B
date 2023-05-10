#include "Fraction.hpp" 
#include "iostream"
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iomanip> 
using namespace std;
namespace ariel{

    Fraction ::Fraction (){
        this->numerator =1;
        this->denominator =1;
    }
    Fraction :: Fraction (int coun, int deno){
        if (deno == 0)
        {
            throw std :: invalid_argument("Division is zero\n");
        }
        if ((coun < std::numeric_limits<int>::min()) || (coun > std::numeric_limits<int>::max()) || ((deno > std::numeric_limits<int>::max() || deno < std::numeric_limits<int>::min()))) {
            throw std::overflow_error("Overflow");
        }
        int r = gcd(coun, deno);
        this->numerator =coun / r;
        this->denominator=deno / r;
        if ((this->denominator < 0) && (this->numerator > 0)) {
            this->denominator *= -1;
            this->numerator *= -1;
        }
    }

    Fraction :: Fraction (float num){
        int ten = 1000;
        num *= 1000;
        int r = gcd((int)num, ten);
        this->numerator =((int)num) / r;
        this->denominator=ten / r;
    }

    int Fraction::gcd(int a, int b)     // gcd 
    {
        if(b ==0) return a;
        return gcd(b, a% b);
    }
    int Fraction :: getDenominator () const{
        return denominator;
    }
    int Fraction :: getNumerator () const{
        return numerator;
    }

    Fraction Fraction :: operator+(const Fraction& newfrac) const{
        long long newnumber =(long long)numerator * newfrac.getDenominator() + denominator * newfrac.getNumerator();
        long long ten =  (long long)denominator * newfrac.getDenominator();

        if ((newnumber < std::numeric_limits<int>::min()) || (newnumber > std::numeric_limits<int>::max()) || ((ten > std::numeric_limits<int>::max() || ten < std::numeric_limits<int>::min()))) {
            throw std::overflow_error("Overflow");
        }
        return Fraction((int) newnumber, (int)ten);
    }

    const Fraction Fraction::operator+(const float& num) const
    {
        int newnumber = (int) (num * 1000);
        int ten = 1000;
        long long numerator2 = (long long) numerator * ten + denominator * newnumber;
        long long denominator2 = (long long)denominator * ten;        
        if ((numerator2 < std::numeric_limits<int>::min()) || (numerator2 > std::numeric_limits<int>::max()) || ((denominator2 > std::numeric_limits<int>::max() || denominator2 < std::numeric_limits<int>::min()))) {
            throw std::overflow_error("Overflow");
        }
        return Fraction((int)numerator2, (int)denominator2);
    }    
    Fraction operator+(const float& num, const Fraction& frac) {
        int newnumber = (int) (num * 1000);
        int ten = 1000;
        long long numerator2 = (long long)frac.getNumerator() * ten + frac.getDenominator() * newnumber;
        long long denominator2 = (long long)frac.getDenominator() * ten;
        if ((numerator2 < std::numeric_limits<int>::min()) || (numerator2 > std::numeric_limits<int>::max()) || ((denominator2 > std::numeric_limits<int>::max() || denominator2 < std::numeric_limits<int>::min()))) {
            throw std::overflow_error("Overflow");
        }
        return Fraction((int)numerator2, (int)denominator2);
    }
    Fraction Fraction :: operator-(const Fraction &newfrac) const{
        long long newnumber =  (long long)numerator * newfrac.denominator - denominator * newfrac.numerator;
        long long ten = (long long) denominator * newfrac.denominator;
        if ((newnumber < std::numeric_limits<int>::min()) || (newnumber > std::numeric_limits<int>::max()) || ((ten > std::numeric_limits<int>::max() || ten < std::numeric_limits<int>::min()))) {
            throw std::overflow_error("Overflow");
        }
        return Fraction((int) newnumber, (int)ten);
    }
    const Fraction Fraction::operator-(const float& num) const{
        int newnumber = (int) (num * 1000);
        int ten = 1000;
        long long numerator2 = (long long) ten * numerator - newnumber * denominator;
        long long denominator2 = (long long) ten * denominator;

        if ((numerator2 < std::numeric_limits<int>::min()) || (numerator2 > std::numeric_limits<int>::max()) || ((denominator2 > std::numeric_limits<int>::max() || denominator2 < std::numeric_limits<int>::min()))) {
            throw std::overflow_error("Overflow");
        }
        return Fraction((int)numerator2, (int)denominator2);
    }  
    Fraction operator-(const float& num, const Fraction& frac) {
        int newnumber = (int) (num * 1000);
        int ten = 1000;
        long long numerator2 = (long long) newnumber * frac.getDenominator() - ten * frac.getNumerator();
        long long denominator2 = (long long) ten * frac.getDenominator();
        if ((numerator2 < std::numeric_limits<int>::min()) || (numerator2 > std::numeric_limits<int>::max()) || ((denominator2 > std::numeric_limits<int>::max() || denominator2 < std::numeric_limits<int>::min()))) {
            throw std::overflow_error("Overflow");
        }
        return Fraction((int)numerator2, (int)denominator2);
    }  

    Fraction Fraction :: operator*(const Fraction &newfrac) const{
        long long newnumber = (long long)newfrac.getNumerator() * numerator;
        long long ten = (long long)newfrac.getDenominator() * denominator;
        if ((newnumber < std::numeric_limits<int>::min()) || (newnumber > std::numeric_limits<int>::max()) || ((ten > std::numeric_limits<int>::max() || ten < std::numeric_limits<int>::min()))) {
            throw std::overflow_error("Overflow");
        }
        return Fraction((int) newnumber,(int)ten);
    }
    const Fraction Fraction::operator*(const float& num) const{
        long long newnumber = (int) (num * 1000);
        long long ten = 1000;
        newnumber =( long long)numerator * newnumber;
        ten =(long long) denominator * ten;
        if ((newnumber < std::numeric_limits<int>::min()) || (newnumber > std::numeric_limits<int>::max()) || ((ten > std::numeric_limits<int>::max() || ten < std::numeric_limits<int>::min()))) {
            throw std::overflow_error("Overflow");
        }
        return Fraction((int) newnumber, (int)ten);
    }

    Fraction operator*(const float& num, const Fraction& frac) {
        long long newnumber = (int) (num * 1000);
        long long ten = 1000;
        newnumber = (long long)frac.getNumerator() * newnumber;
        ten =(long long)frac.getDenominator() * ten;
        if ((newnumber < std::numeric_limits<int>::min()) || (newnumber > std::numeric_limits<int>::max()) || ((ten > std::numeric_limits<int>::max() || ten < std::numeric_limits<int>::min()))) {
            throw std::overflow_error("Overflow");
        }
        return Fraction((int) newnumber,(int) ten);
    }
    Fraction Fraction :: operator/(const Fraction &newfrac) const{
        if (newfrac.getNumerator() == 0 || getDenominator() == 0){
            throw std::overflow_error("division by zero is not defined");
        }
        long long newnumber = (long long)newfrac.getDenominator() * numerator;
        long long ten =(long long) newfrac.getNumerator() * denominator;
        if ((newnumber < std::numeric_limits<int>::min()) || (newnumber > std::numeric_limits<int>::max()) || ((ten > std::numeric_limits<int>::max() || ten < std::numeric_limits<int>::min()))) {
            throw std::overflow_error("Overflow");
        }
        return Fraction((int) newnumber, (int)ten);
    }
    const Fraction Fraction::operator/(const float& num) const{
        if (num * 1000 == 0){
            throw std::overflow_error("division by zero");
        }

        long long newnumber = (int) (num * 1000);
        long long ten = 1000;
        long long saved = newnumber;
        newnumber = (long long)numerator * ten;
        ten = (long long) denominator * saved;
        if ((newnumber < std::numeric_limits<int>::min()) || (newnumber > std::numeric_limits<int>::max()) || ((ten > std::numeric_limits<int>::max() || ten < std::numeric_limits<int>::min()))) {
            throw std::overflow_error("Overflow");
        }
        return Fraction((int) newnumber, (int)ten);
    }
    Fraction operator/(const float& num, const Fraction& frac) {
        
        long long newnumber = (int) (num * 1000);
        long long ten = 1000;
        newnumber = (long long)frac.getDenominator() * newnumber;
        ten = (long long)frac.getNumerator() * ten;
        if ((newnumber < std::numeric_limits<int>::min()) || (newnumber > std::numeric_limits<int>::max()) || ((ten > std::numeric_limits<int>::max() || ten < std::numeric_limits<int>::min()))) {
            throw std::overflow_error("Overflow");
        }        
        return Fraction((int) newnumber, ten);
    }

    Fraction& Fraction ::operator++(){
        numerator += denominator;
        int r = gcd(numerator,denominator);
        numerator = numerator / r;
        denominator = denominator / r;
        return *this;
        
    }
    Fraction Fraction::operator++(int)
    {
        Fraction fr = (*this);
        numerator += denominator;
        int r = gcd(numerator,denominator);
        numerator = numerator / r;
        denominator = denominator / r;
        return fr;
    }
    Fraction& Fraction ::operator--(){
        numerator -= denominator;
        int r = gcd(numerator,denominator);
        numerator = numerator / r;
        denominator = denominator / r;
        return *this;
        
    }
    Fraction Fraction::operator--(int)
    {
        Fraction fr = (*this);
        numerator -= denominator;
        int r = gcd(numerator,denominator);
        numerator = numerator / r;
        denominator = denominator / r;
        return fr;
    }
    const bool Fraction :: operator==(const Fraction& newfrac)const{
        return numerator * newfrac.getDenominator() == newfrac.getNumerator() * denominator;
    }
    const bool Fraction :: operator==(const float& number)const{
        return number == (float)this->numerator /(float)this->denominator;
    }

    const bool operator==(const float& num, const Fraction& fraction){
        float newNum = (float)fraction.getNumerator()/(float)fraction.getDenominator();
        return num == newNum;
    }

    const bool Fraction :: operator!=(const Fraction& newfrac)const{
        return numerator * newfrac.getDenominator() != newfrac.getNumerator() * denominator;
    }
    const bool Fraction :: operator!=(const float& num)const{
        float newNum = (float)this->numerator /(float)this->denominator;
        return num != newNum;
    }
    const bool operator!=(const float& num, const Fraction& fraction){
        float newNum = (float)fraction.getNumerator()/(float)fraction.getDenominator();
        return num != newNum;
    }
    const bool Fraction :: operator>(const Fraction& newfrac)const{
        return numerator * newfrac.getDenominator() > newfrac.getNumerator() * denominator;    }
    
    const bool Fraction :: operator>(const float& num)const{
        float newNum = (float)this->numerator /(float)this->denominator;
        return newNum > num;
    }
    const bool operator>(const float& num, const Fraction& fraction){
        float newNum = (float)fraction.getNumerator()/(float)fraction.getDenominator();
        return num > newNum;
    }
    const bool Fraction::operator>=(const Fraction& newfrac) const{
        return numerator * newfrac.getDenominator() >= newfrac.getNumerator() * denominator;    }

    const bool Fraction :: operator>=(const float& num)const{
        float newNum = (float)this->numerator /(float)this->denominator;
        return newNum >= num;
    }
    const bool operator>=(const float& num, const Fraction& fraction){
        float newNum = (float)fraction.getNumerator()/(float)fraction.getDenominator();
        return num >= newNum;
    }
    const bool Fraction :: operator<(const Fraction& newfrac)const{
       return numerator * newfrac.getDenominator() < newfrac.getNumerator() * denominator;    }

    const bool Fraction :: operator<(const float& num)const{
        float newNum = (float)this->numerator /(float)this->denominator;
        return newNum < num;
    }
    const bool operator<(const float& num, const Fraction& fraction){
        float newNum = (float)fraction.getNumerator()/(float)fraction.getDenominator();
        return num < newNum;
    }
    const bool Fraction :: operator<=(const Fraction& newfrac)const{
       return numerator * newfrac.getDenominator() <= newfrac.getNumerator() * denominator;    }

    const bool Fraction :: operator<=(const float& num)const{
        float newNum = (float)this->numerator /(float)this->denominator;
        return newNum <= num;
    }
    const bool operator<=(const float& num, const Fraction& fraction){
        float newNum = (float)fraction.getNumerator()/(float)fraction.getDenominator();
        return num <= newNum;
    }


    std::ostream& operator<<(std::ostream& os, const Fraction& fraction)
        
    {  
        os << fraction.getNumerator()  << "/"  << fraction.getDenominator();
        return os;
    }
    std::istream& operator>>(std::istream& is, Fraction& fraction)
    {
        int num, den;
        if (!((is) >> num >> den)) {throw runtime_error("Invalid input for Fraction");}
        if (den == 0) throw runtime_error("Division by zero");
        fraction = Fraction(num, den);
        return is;
    }
}
