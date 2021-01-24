//
// Created by Gchiko on 22-Jan-21.
//

#include "Field.h"

Field::Field(string name, string className, Type t, bool isStatic) : Member(move(name), move(className)), t(t), isStatic(isStatic){}

Type Field::getType() {
    return this->t;
}

void Field::setInt(Object *obj, int value) {
    obj->setInt(this->name(), value);
}

int Field::getInt(Object *obj) {
    return obj->getInt(this->name());
}

void Field::setObj(Object *obj, Object *value) {
    obj->setObj(this->name(), value);
}

Object *Field::getObj(Object *obj) {
    return obj->getObj(this->name());
}

