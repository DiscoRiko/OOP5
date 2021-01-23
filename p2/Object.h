#ifndef OBJECT_H_
#define OBJECT_H_

#include <string>
#include <map>
#include "Method.h"

class Class;
class Field;

using namespace std;

class Object {
private:

    Class* cls;

    map<string, int> instance_int_fields;

    map<string, Object*> instance_obj_fields;

    map<string, int>* static_int_fields;

    map<string, Object*>* static_obj_fields;

public:

    Object(Class* cls, const list<string>& instance_int_fields,
           const list<string>& instance_obj_fields,
           map<string, int>* static_int_fields,
           map<string, Object*>* static_obj_fields);

    Class* getClass();

	int getInt(string name);

	void setInt(string name, int value);
	
	Object* getObj(string name);

	void setObj(string name, Object* value);

	virtual void invokeMethod(string name);

	bool isInstanceOf(string c);
	
	bool isKindOf(string c);

};

#endif /* OBJECT_H_ */
