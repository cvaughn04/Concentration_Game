#pragma once
#include <string>

enum class AbilityT: size_t {STRONG, WEAK, TOUGH, SICKLEY, CLEVER, DENSE, WISE, FOOLISH, DEXTEROUS, FUMBLING, AGILE, CLUMSY, FAST, SLOW, CHARMING, UNPLEASANT, ATTRACTIVE, UGLY, NONE};

const AbilityT FIRST_ABILITY {AbilityT::STRONG};

std::string AbilityTToString(AbilityT a);
AbilityT StringToAbilityT(std::string s);
std::string toLower(std::string s);

AbilityT operator + (AbilityT a, size_t  b);
AbilityT operator - (AbilityT a, size_t  b);
AbilityT & operator++(AbilityT & a);
AbilityT operator++(AbilityT & a, int);
AbilityT & operator +=(AbilityT & a, size_t n);
AbilityT operator -(AbilityT a);

std::ostream & operator << (std::ostream & s, const AbilityT & ability);
std::istream & operator >> (std::istream & s, AbilityT & ability);



