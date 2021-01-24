//
// Created by Gchiko on 23-Jan-21.
//

#include "Method.h"

Method::Method(string name, string className, Func f) : Member(move(name), move(className)), f(f){}

void Method::invoke(Object *const obj) {
    obj->invokeMethod(this->name());
}