//
// Created by Gchiko on 23-Jan-21.
//

#include "Class.h"

Class::Class(Class *c, const string &name) : super_class(c), class_name(name){
    this->static_int_fields = new map<string, int>;
    this->static_obj_fields = new map<string, Object*>;
    this->class_methods = new map<string, Func>;
}

string Class::name() {
    return this->class_name;
}

Class *Class::getSuperClass() {
    return this->super_class;
}

Object *Class::newInstance() {
    if(this->super_class == nullptr)
        return new Object(this, nullptr, this->instance_int_fields, this->instance_obj_fields);
    return new Object(this, this->super_class->newInstance(), this->instance_int_fields, this->instance_obj_fields);
}

void Class::addMethod(string name, Func func) {
    (*this->class_methods)[name] = func;
}

void Class::addInstanceField(string name, Type t) {
    if(t == INT)
        this->instance_int_fields.push_back(name);
    if(t == OBJECT)
        this->instance_obj_fields.push_back(name);
}

void Class::addStaticField(string name, Type t) {
    if(t == INT)
        (*this->static_int_fields)[name] = 0;
    if(t == OBJECT)
        (*this->static_obj_fields)[name] = nullptr;
}

Field Class::getField(string name) {
    bool found = false;
    bool isStatic;
    Type t;

    if(find(this->instance_int_fields.begin(), this->instance_int_fields.end(), name) != this->instance_int_fields.end()) {
        found = true;
        isStatic = false;
        t = INT;
    }

    if(find(this->instance_obj_fields.begin(), this->instance_obj_fields.end(), name) != this->instance_obj_fields.end()) {
        found = true;
        isStatic = false;
        t = OBJECT;
    }

    if(this->static_int_fields->find(name) != this->static_int_fields->end()) {
        found = true;
        isStatic = true;
        t = INT;
    }

    if(this->static_obj_fields->find(name) != this->static_obj_fields->end()) {
        found = true;
        isStatic = true;
        t = OBJECT;
    }

    if(found)
        return Field(name, this->name(), t, isStatic);
    else {
        if(this->super_class == nullptr)
            throw FieldNotFound();
        else
            return this->super_class->getField(name);
    }
}

Method Class::getMethod(string name) {
    if(this->class_methods->find(name) != this->class_methods->end()) {
        return Method(name, this->name(), (*this->class_methods)[name]);
    }
    else {
        if(this->super_class == nullptr)
            throw MethodNotFound();
        else
            return this->super_class->getMethod(name);
    }
}

list<Field> Class::getFields() {
    list<Field> all_fields;

    // Extract unfold instance int fields
    for (auto const& field_name : this->instance_int_fields)
        all_fields.emplace_back(field_name, this->name(), INT, false);

    // Extract unfold instance obj fields
    for (auto const& field_name : this->instance_obj_fields)
        all_fields.emplace_back(field_name, this->name(), OBJECT, false);

    // Extract unfold static int fields
    for (auto const& field_pair : (*this->static_int_fields))
        all_fields.emplace_back(field_pair.first, this->name(), INT, true);

    // Extract unfold static obj fields
    for (auto const& field_pair : (*this->static_obj_fields))
        all_fields.emplace_back(field_pair.first, this->name(), OBJECT, true);

    if(this->super_class != nullptr)
        all_fields.merge(this->super_class->getFields(), naive_comparison<Field>);

    return all_fields;
}

list<Method> Class::getMethods() {
    list<Method> all_methods;

    // Extract unfold class methods
    for (auto const& method_pair : (*this->class_methods))
        all_methods.emplace_back(method_pair.first, this->name(), method_pair.second);

    if(this->super_class != nullptr)
        all_methods.merge(this->super_class->getMethods(), naive_comparison<Method>);

    return all_methods;
}

void Class::setInt(string name, int value) {
    // Check if there is an obj field with that name
    map<string, Object*>::iterator stat_obj_iter;
    stat_obj_iter = this->static_obj_fields->find(name);
    if(stat_obj_iter != this->static_obj_fields->end())
        throw TypeError();

    // Check if there is an int field with that name
    map<string, int>::iterator stat_int_iter;
    stat_int_iter = this->static_int_fields->find(name);
    if(stat_int_iter == this->static_int_fields->end()) {
        if(this->super_class == nullptr)
            throw FieldNotFound();
        else
            this->super_class->setInt(name, value);
    }
    else
        stat_int_iter->second = value;
}

int Class::getInt(string name) {
    // Check if there is an obj field with that name
    map<string, Object*>::iterator stat_obj_iter;
    stat_obj_iter = this->static_obj_fields->find(name);
    if(stat_obj_iter != this->static_obj_fields->end())
        throw TypeError();

    // Check if there is an int field with that name
    map<string, int>::iterator stat_int_iter;
    stat_int_iter = this->static_int_fields->find(name);
    if(stat_int_iter == this->static_int_fields->end()) {
        if(this->super_class == nullptr)
            throw FieldNotFound();
        else
            return this->super_class->getInt(name);
    }
    else
        return stat_int_iter->second;
}

void Class::setObj(string name, Object *value) {
    // Check if there is an int field with that name
    map<string, int>::iterator stat_int_iter;
    stat_int_iter = this->static_int_fields->find(name);
    if(stat_int_iter != this->static_int_fields->end())
        throw TypeError();

    // Check if there is an obj field with that name
    map<string, Object*>::iterator stat_obj_iter;
    stat_obj_iter = this->static_obj_fields->find(name);
    if(stat_obj_iter == this->static_obj_fields->end()) {
        if(this->super_class == nullptr)
            throw FieldNotFound();
        else
            this->super_class->setObj(name, value);
    }
    else
        stat_obj_iter->second = value;
}

Object *Class::getObj(string name) {
    // Check if there is an int field with that name
    map<string, int>::iterator stat_int_iter;
    stat_int_iter = this->static_int_fields->find(name);
    if(stat_int_iter != this->static_int_fields->end())
        throw TypeError();

    // Check if there is an obj field with that name
    map<string, Object*>::iterator stat_obj_iter;
    stat_obj_iter = this->static_obj_fields->find(name);
    if(stat_obj_iter == this->static_obj_fields->end()) {
        if(this->super_class == nullptr)
            throw FieldNotFound();
        else
            return this->super_class->getObj(name);
    }
    else
        return stat_obj_iter->second;
}

// Getters
map<string, int> *Class::getStaticIntFields() const {
    return this->static_int_fields;
}

map<string, Object *> *Class::getStaticObjFields() const {
    return this->static_obj_fields;
}

map<string, Func> *Class::getClassMethods() const {
    return this->class_methods;
}

template<class T>
bool Class::naive_comparison(T first, T second) {
    return true;
}

void Class::setAccessible(bool a) {
}
