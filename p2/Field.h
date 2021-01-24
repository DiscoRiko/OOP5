#ifndef FIELD_H_
#define FIELD_H_

#include "Member.h"
#include "Object.h"

class Field: public Member{
private:

    Type t;

    bool isStatic;

public:

	Field(string name, string className, Type t, bool isStatic);

	Type getType();

	void setInt(Object* obj, int value);

	int getInt(Object* obj);
	
	void setObj(Object* obj, Object* value);

	Object* getObj(Object* obj);

};

#endif /* FIELD_H_ */
