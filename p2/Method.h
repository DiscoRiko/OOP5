#ifndef METHOD_H_
#define METHOD_H_

#include "Member.h"
#include "Object.h"

class Method: public Member{
private:

    Func f;

public:

	Method(string name,string className,Func f);

	virtual void invoke(Object* const obj);

};


#endif /* METHOD_H_ */
