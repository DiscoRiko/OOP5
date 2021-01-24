#ifndef CLASS_H_
#define CLASS_H_

#include "Field.h"
#include "Method.h"
#include <algorithm>
#include <stack>

class Class{

private:
    string class_name;

    Class* super_class;

    list<string> instance_int_fields;

    list<string> instance_obj_fields;

    map<string, int>* static_int_fields;

    map<string, Object*>* static_obj_fields;

    map<string, Func>* class_methods;

    static bool accessible;

    static stack<Object*> current_obj;

    template<class T>
    static bool naive_comparison (T first, T second);

public:

    Class(Class* c, const string& name);

    string name();
		
	Class* getSuperClass();
	
	Object* newInstance();

	void addMethod(string name, Func func);
	
	void addInstanceField(string name, Type t);

	void addStaticField(string name, Type t);

	Field getField(string name);

	Method getMethod(string name);

    list<Field> getFields();

	list<Method> getMethods();

	void setInt(string name, int value);

    int getInt(string name);

    void setObj(string name, Object* value);

    Object* getObj(string name);

    static void setAccessible(bool a);

	// Getters
    map<string, int> *getStaticIntFields() const;

    map<string, Object *> *getStaticObjFields() const;

    map<string, Func> *getClassMethods() const;

    static bool isAccessible();

    // current object stack functions
    static void push_current_obj(Object* obj);

    static void pop_current_obj();

    static Object* top_current_obj();
};

#endif /* CLASS_H_ */
