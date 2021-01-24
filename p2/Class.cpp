//
// Created by Gchiko on 23-Jan-21.
//

#include "Class.h"

string Class::name() {
    return this->class_name;
}

map<string, int> *Class::getStaticIntFields() const {
    return this->static_int_fields;
}

map<string, Object *> *Class::getStaticObjFields() const {
    return this->static_obj_fields;
}

map<string, Func> *Class::getMethods() const {
    return this->methods;
}
