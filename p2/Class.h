#ifndef CLASS_H_
#define CLASS_H_

#include <list>
#include "Object.h"

class Class{

private:

    list<string> instance_int_fields;

    list<string> instance_obj_fields;

    map<string, int>* static_int_fields;

    map<string, Object*>* static_obj_fields;

public:
/*
    Class(Class* c, const std::string& name);
		
	Class* getSuperClass();
	
	Object* newInstance();

	void addMethod(std::string name, Func func);
	
	void addInstanceField(std::string name, Type t);

	void addStaticField(std::string name, Type t);

	Field getField(std::string name);

	std::list<Field> getFields();

	Method getMethod(std::string name);

	std::list<Method> getMethods();

	int getInt(std::string name);

	void setInt(std::string name, int value);

	Object* getObj(std::string name);

	void setObj(std::string name, Object* value);

*/
    const list<string> &getSuperInstanceIntFields() const;

    const list<string> &getSuperInstanceObjFields() const;

    map<string, int> *getSuperStaticIntFields() const;

    map<string, Object *> *getSuperStaticObjFields() const;
};

#endif /* CLASS_H_ */
