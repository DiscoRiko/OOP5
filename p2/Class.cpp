//
// Created by Gchiko on 23-Jan-21.
//

#include "Class.h"

// TODO - all 4 should return the union of all their super classes
const list<string> &Class::getSuperInstanceIntFields() const {
    return instance_int_fields;
}

const list<string> &Class::getSuperInstanceObjFields() const {
    return instance_obj_fields;
}

map<string, int> *Class::getSuperStaticIntFields() const {
    return static_int_fields;
}

map<string, Object *> *Class::getSuperStaticObjFields() const {
    return static_obj_fields;
}
