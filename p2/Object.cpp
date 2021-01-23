//
// Created by Gchiko on 23-Jan-21.
//

#include <list>
#include "Object.h"

Object::Object(Class *cls, const list<string>& instance_int_fields,
               const list<string>& instance_obj_fields,
               map<string,int>* static_int_fields,
               map<string, Object*>* static_obj_fields) {
    this->cls = cls;
    this->static_int_fields = static_int_fields;
    this->static_obj_fields = static_obj_fields;

    for (auto const& field_name : instance_int_fields) {
        this->instance_int_fields[field_name] = 0;
    }

    for (auto const& field_name : instance_obj_fields) {
        this->instance_obj_fields[field_name] = nullptr;
    }
}

Class *Object::getClass() {
    return this->cls;
}

int Object::getInt(std::string name) {
    return 0;
}

void Object::setInt(std::string name, int value) {

}

Object *Object::getObj(std::string name) {
    return nullptr;
}

void Object::setObj(std::string name, Object *value) {

}

void Object::invokeMethod(std::string name) {

}

bool Object::isInstanceOf(std::string c) {
    return false;
}

bool Object::isKindOf(std::string c) {
    return false;
}