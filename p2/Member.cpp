//
// Created by Gchiko on 22-Jan-21.
//
#include "Member.h"

Member::Member(string name, string declaring_class) : _name(move(name)), _declaring_class(move(declaring_class)){}

string Member::getDeclaringClass() const{
    return this->_declaring_class;
}

string Member::name() const{
    return this->_name;
}
