/*
Cole Vaughn
Homework 1
*/


#include <iostream>
#include "AbilityT.h"
#include <iomanip>



using namespace std;

const string ABILITY_NAMES[]{"strong", "weak", "tough", "sickley", "clever", "dense", "wise", "foolish", "dexterous", "fumbling", "agile", "clumsy", "fast", "slow", "charming", "unpleasant", "attractive", "ugly", "none"};
const size_t ABILITY_COUNT {static_cast<size_t>(AbilityT::NONE)};

string AbilityTToString(AbilityT a){
   size_t offset {static_cast<size_t>(a)};
   if (offset > ABILITY_COUNT) {
      offset = ABILITY_COUNT;
   }
   return ABILITY_NAMES[offset];
}

AbilityT StringToAbilityT(string s) {
    size_t pos = ABILITY_COUNT;
    s = toLower(s);

    for(size_t i = 0; i < ABILITY_COUNT; ++i) {
        if (s == ABILITY_NAMES[i]) {
            pos = i;
        } 
    }

    AbilityT a {static_cast<AbilityT>(pos)};
    return a;
}

AbilityT operator + (AbilityT a, size_t  b) {
   size_t offset{static_cast<size_t>(a)};
   AbilityT returnValue{AbilityT::NONE};

   offset += b;
   if (offset <= static_cast<size_t>(AbilityT::NONE)) {
      returnValue = static_cast<AbilityT>(offset);
   }

   return returnValue;
}

AbilityT operator - (AbilityT a, size_t  b) {
   size_t offset{static_cast<size_t>(a)};
   AbilityT returnValue{AbilityT::NONE};

   offset -= b;
   if (offset <= static_cast<size_t>(AbilityT::NONE)) {
      returnValue = static_cast<AbilityT>(offset);
   }

   return returnValue;
}

AbilityT & operator++(AbilityT & a) {
    a = a + 2;
    return a;
}

AbilityT operator++(AbilityT & a, int) {
    AbilityT tmp{a};
    a = a + 2;
    return tmp;
}

AbilityT & operator +=(AbilityT & a, size_t n) {
     a = a + n;
     return a;
} 

AbilityT operator -(AbilityT a) {
    size_t n{static_cast<size_t>(a)};

    if (n % 2 == 0) {
        a = a + 1;
    } else {
        a = a - 1;
    }

    return a;
}

ostream & operator << (ostream & s, const AbilityT & ability) {
     s << AbilityTToString(ability);
     return s; 
}

istream & operator >> (istream & s, AbilityT & ability) {
    string a;
    s >> a;
    ability = StringToAbilityT(a);
    return s; 
}

string toLower(string s) {
    size_t i;

    for( i = 0; i < s.size(); ++i ) {
       s[i] = tolower(s[i]);
    }

    return s;
}