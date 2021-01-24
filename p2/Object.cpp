//
// Created by Gchiko on 23-Jan-21.
//

#include <list>
#include "Class.h"

Object::Object(Class *cls, Object* super_object,
               const list<string>& instance_int_fields,
               const list<string>& instance_obj_fields) {
    this->cls = cls;
    this->super_object = super_object;

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
// TODO - in all next 4, should add accessible logic
int Object::getInt(string name) {
    // Check if there is an obj field with that name
    map<string, Object*>::iterator inst_obj_iter = this->instance_obj_fields.find(name);
    map<string, Object*>::iterator stat_obj_iter = this->cls->getStaticObjFields()->find(name);
    if(inst_obj_iter != this->instance_obj_fields.end() || stat_obj_iter != this->cls->getStaticObjFields()->end())
        throw TypeError();

    // Check if there is an int field with that name
    map<string, int>::iterator it;
    it = this->instance_int_fields.find(name);
    if(it == this->instance_int_fields.end()) {
        it = this->cls->getStaticIntFields()->find(name);
        if(it == this->cls->getStaticIntFields()->end()) {
            if(this->super_object == nullptr)
                throw FieldNotFound();
            else
                return this->super_object->getInt(name);
        }
        else
            return it->second;
    }
    else
        return it->second;
}

void Object::setInt(string name, int value) {
    // Check if there is an obj field with that name
    map<string, Object*>::iterator inst_obj_iter;
    map<string, Object*>::iterator stat_obj_iter;
    inst_obj_iter = this->instance_obj_fields.find(name);
    stat_obj_iter = this->cls->getStaticObjFields()->find(name);
    if(inst_obj_iter != this->instance_obj_fields.end() || stat_obj_iter != this->cls->getStaticObjFields()->end())
        throw TypeError();

    // Check if there is an int field with that name
    map<string, int>::iterator it;
    it = this->instance_int_fields.find(name);
    if(it == this->instance_int_fields.end()) {
        it = this->cls->getStaticIntFields()->find(name);
        if(it == this->cls->getStaticIntFields()->end()) {
            if(this->super_object == nullptr)
                throw FieldNotFound();
            else
                this->super_object->setInt(name, value);
        }
        else
            it->second = value;
    }
    else
        it->second = value;
}

Object *Object::getObj(string name) {
    // Check if there is an obj field with that name
    map<string, int>::iterator inst_int_iter;
    map<string, int>::iterator stat_int_iter;
    inst_int_iter = this->instance_int_fields.find(name);
    stat_int_iter = this->cls->getStaticIntFields()->find(name);
    if(inst_int_iter != this->instance_int_fields.end() || stat_int_iter != this->cls->getStaticIntFields()->end())
        throw TypeError();

    // Check if there is an int field with that name
    map<string, Object*>::iterator it;
    it = this->instance_obj_fields.find(name);
    if(it == this->instance_obj_fields.end()) {
        it = this->cls->getStaticObjFields()->find(name);
        if(it == this->cls->getStaticObjFields()->end()) {
            if(this->super_object == nullptr)
                throw FieldNotFound();
            else
                return this->super_object->getObj(name);
        }
        else
            return it->second;
    }
    else
        return it->second;
}

void Object::setObj(string name, Object *value) {
    // Check if there is an obj field with that name
    map<string, int>::iterator inst_int_iter;
    map<string, int>::iterator stat_int_iter;
    inst_int_iter = this->instance_int_fields.find(name);
    stat_int_iter = this->cls->getStaticIntFields()->find(name);
    if(inst_int_iter != this->instance_int_fields.end() || stat_int_iter != this->cls->getStaticIntFields()->end())
        throw TypeError();

    // Check if there is an int field with that name
    map<string, Object*>::iterator it;
    it = this->instance_obj_fields.find(name);
    if(it == this->instance_obj_fields.end()) {
        it = this->cls->getStaticObjFields()->find(name);
        if(it == this->cls->getStaticObjFields()->end()) {
            if(this->super_object == nullptr)
                throw FieldNotFound();
            else
                this->super_object->setObj(name, value);
        }
        else
            it->second = value;
    }
    else
        it->second = value;
}

void Object::invokeMethod(string name) {
    map<string, Func>::iterator it;
    it = this->cls->getClassMethods()->find(name);
    if(it == this->cls->getClassMethods()->end()) {
        if(this->super_object == nullptr)
            throw MethodNotFound();
        else
            this->super_object->invokeMethod(name);
    }
    else
        it->second(this);
}

bool Object::isInstanceOf(string c) {
    return this->cls->name() == c;
}

bool Object::isKindOf(string c) {
    if(this->isInstanceOf(c))
        return true;

    if(this->super_object == nullptr)
        return false;

    return this->super_object->isKindOf(c);
}