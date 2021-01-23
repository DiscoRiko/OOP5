#include <iostream>
#include "p1/IntList.h"
#include "p1/MergedIntLists.h"
#include "p1/IntListUtils.h"
#include "p1/IntListComparators.h"
#include "p2/Field.h"
using namespace std;

int main() {

/**  *   ||           ***************************       ||   *******************
 *****  \||/                     Part2                 \||/  *******************
 *****   \/           ***************************       \/   **************** */

    auto* field = new Field("dude", "dudeClass", INT, true);
    cout << field->name() << endl;
    cout << field->getDeclaringClass() << endl;

    return 0;
}
