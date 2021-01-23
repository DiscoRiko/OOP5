//
// Created by Gchiko on 22-Jan-21.
//
#ifndef OOP5_MEMBER_H
#define OOP5_MEMBER_H

#include <string>
#include <utility>

using namespace std;

class Member {
private:

    string _name;

    string _declaring_class;

public:

    Member(string name, string declaring_class);

    string name() const;

    string getDeclaringClass() const;

};

#endif //OOP5_MEMBER_H
