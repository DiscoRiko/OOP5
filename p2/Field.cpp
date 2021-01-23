//
// Created by Gchiko on 22-Jan-21.
//

#include "Field.h"

Field::Field(string name, string className, Type t, bool isStatic) : Member(move(name), move(className)), t(t), isStatic(isStatic){}

Type Field::getType() {
    return this->t;
}

void Field::setInt(Object *obj, int value) {
    if(t==OBJECT)
        throw TypeError();
    //TODO Will throw FieldNotFound & FieldNotAccessible - Maybe also will throw TypeError - if so, no need to throw it here ^
    obj->setInt(this->name(), value);
}

int Field::getInt(Object *obj) {
    if(t==OBJECT)
        throw TypeError();
    //TODO Will throw FieldNotFound & FieldNotAccessible - Maybe also will throw TypeError - if so, no need to throw it here ^
    return obj->getInt(this->name());
}

void Field::setObj(Object *obj, Object *value) {
    if(t==INT)
        throw TypeError();
    //TODO Will throw FieldNotFound & FieldNotAccessible - Maybe also will throw TypeError - if so, no need to throw it here ^
    obj->setObj(this->name(), value);
}

Object *Field::getObj(Object *obj) {
    if(t==INT)
        throw TypeError();
    //TODO Will throw FieldNotFound & FieldNotAccessible - Maybe also will throw TypeError - if so, no need to throw it here ^
    return obj->getObj(this->name());
}

