#include <iostream>
#include "IntList.h"
#include "MergedIntLists.h"
#include "ConcatedIntLists.h"
#include "IntListUtils.h"
#include "IntListComparators.h"
using namespace std;

int main() {
	IntList<1, 2, 3>::head; // = 1
	IntList<1, 2, 3>::next::next; // = IntList<3>
	static_assert(IntListsEqual<IntList<1, 2, 3>::next::next, IntList<3> >::value, "Failed!");
	IntList<1, 2>::size; // = 2
	IntList<1, 2>::next::next::empty; // = true
	typedef ConcatedIntLists<IntList<1>, IntList<>, IntList<2, 3, 4>>::list Concated; // = IntList<1,2,3,4> 
	static_assert(IntListsEqual<Concated, IntList<1, 2, 3, 4>>::value, "Failed!");
	MergedIntLists<IntList<1, 9>, IntList<1, 2, 3, 4>>::list; // = IntList<1,1,9,2,3,4> 
	typedef IntListUtils<IntList<1, 2, 3>>::reversed MyList; // = IntList<3,2,1>
	static_assert(IntListsEqual<MyList, IntListUtils<IntListUtils<MyList>::reversed>::reversed>::value, "Failed!");
	IntListUtils<IntList<1, 2, 3>>::max; // = 3
	IntListUtils<IntList<1, 2, 3>>::min; // = 1
	IntListsEqual<IntList<2, 3>, IntList<2, 3>>::value; // = true
	IntListContains<IntList<2, 3>, 2, 3>::value; // = true
	IntListIndexEquals<IntList<1, 2>, 0, 1>::value; // = true (index 0 contains 1)

    /**  *   ||           ***************************       ||   *******************
 *****  \||/                   IntList                 \||/  *******************
 *****   \/           ***************************       \/   **************** */

    static_assert(IntList<>::empty, "Failed!");
    static_assert(IntList<>::size == 0, "Failed!");
    //static_assert(IntList<>::head, "GOOD! please comment this line to continue");
    //static_assert(IntList<>::next, "GOOD! please comment this line to continue");

    static_assert(IntList<5>::empty == false, "Failed!");
    static_assert(IntList<5>::size == 1, "Failed!");
    static_assert(IntList<5>::head == 5, "Failed!");
    static_assert(IntList<5>::next::empty, "Failed!");
    static_assert(IntList<5>::next::size == 0, "Failed!");
    //static_assert(IntList<5>::next::head, "GOOD! please comment this line to continue");
    //static_assert(IntList<5>::next::next, "GOOD! please comment this line to continue");

    static_assert(IntList<1, 2, 3>::head == 1, "Failed!");
    static_assert(IntList<1, 2, 3>::next::head == 2, "Failed!");
    static_assert(IntList<1, 2, 3>::next::next::head == 3, "Failed!");
    //static_assert(IntList<1, 2, 3>::next::head == 4, "GOOD! please comment this line to continue");
    static_assert(IntList<1>::size == 1, "Failed!");
    static_assert(IntList<1, 2>::size == 2, "Failed!");
    static_assert(IntList<1, 2>::next::next::empty, "Failed!");


/**  *   ||           ***************************       ||   *******************
 *****  \||/                MergedIntLists             \||/  *******************
 *****   \/           ***************************       \/   **************** */

    static_assert(MergedIntLists<IntList<>,IntList<>>::list::empty, "Failed!");
    static_assert(MergedIntLists<IntList<5>,IntList<>>::list::size == 1, "Failed!");
    static_assert(MergedIntLists<IntList<>,IntList<5>>::list::size == 1, "Failed!");
    static_assert(MergedIntLists<IntList<5>,IntList<>>::list::head == 5, "Failed!");
    static_assert(MergedIntLists<IntList<>,IntList<5>>::list::head == 5, "Failed!");

    static_assert(MergedIntLists<IntList<1,2>,IntList<9>>::list::next::head == 9, "Failed!");
    static_assert(MergedIntLists<IntList<9>,IntList<1,2>>::list::head == 9, "Failed!");
    static_assert(MergedIntLists<IntList<9>,IntList<1,2>>::list::next::head == 1, "Failed!");


/**  *   ||           ***************************       ||   *******************
 *****  \||/                ConcatedIntLists           \||/  *******************
 *****   \/           ***************************       \/   **************** */

    static_assert(ConcatedIntLists<IntList<>>::list::empty, "Failed!");
    //static_assert(ConcatedIntLists<IntList<1>>::list::empty, "GOOD! please comment this line to continue");
    static_assert(ConcatedIntLists<IntList<1>>::list::head == 1, "Failed!");
    static_assert(ConcatedIntLists<IntList<>, IntList<1>>::list::head == 1, "Failed!");
    static_assert(ConcatedIntLists<IntList<1>, IntList<>>::list::head == 1, "Failed!");
    static_assert(ConcatedIntLists<IntList<>, IntList<>>::list::empty, "Failed!");
    static_assert(ConcatedIntLists<IntList<1,2>, IntList<3,4>, IntList<5,6>>::list::head == 1, "Failed!");
    static_assert(ConcatedIntLists<IntList<1,2>, IntList<3,4>, IntList<5,6>, IntList<7,8>, IntList<>, IntList<9>>::list::next::head == 2, "Failed!");

    /**  *   ||           ***************************       ||   *******************
 *****  \||/                IntListUtils               \||/  *******************
 *****   \/           ***************************       \/   **************** */

    static_assert(IntListUtils<IntList<>>::reversed::empty, "Failed!");
    static_assert(IntListUtils<IntList<>>::reversed::size == 0, "Failed!");
    //static_assert(IntListUtils<IntList<>>::reversed::max, "GOOD! please comment this line to continue");
    //static_assert(IntListUtils<IntList<>>::reversed::min, "GOOD! please comment this line to continue");

    static_assert(IntListUtils<IntList<5>>::max == 5, "Failed!");
    static_assert(IntListUtils<IntList<5>>::min == 5, "Failed!");
    static_assert(IntListUtils<IntList<5>>::reversed::empty == false, "Failed!");
    static_assert(IntListUtils<IntList<5>>::reversed::size == 1, "Failed!");
    static_assert(IntListUtils<IntList<5>>::reversed::head == 5, "Failed!");
    static_assert(IntListUtils<IntList<5>>::reversed::next::empty, "Failed!");
    static_assert(IntListUtils<IntList<5>>::reversed::next::size == 0, "Failed!");
    //static_assert(IntListUtils<IntList<5>>::reversed::next::head, "GOOD! please comment this line to continue");
    //static_assert(IntListUtils<IntList<5>>::reversed::next::next, "GOOD! please comment this line to continue");

    static_assert(IntListUtils<IntList<1,2,3>>::max == 3, "Failed!");
    static_assert(IntListUtils<IntList<1,2,3>>::min == 1, "Failed!");
    static_assert(IntListUtils<IntList<1,2,3>>::reversed::head == 3, "Failed!");
    static_assert(IntListUtils<IntList<1,2,3>>::reversed::next::head == 2, "Failed!");
    static_assert(IntListUtils<IntListUtils<IntList<1,2,3>>::reversed>::reversed::head == 1, "Failed!");

    static_assert(IntListUtils<IntList<3,2,1>>::max == 3, "Failed!");
    static_assert(IntListUtils<IntList<3,2,1>>::min == 1, "Failed!");
    static_assert(IntListUtils<IntList<1,1,2,7,3,45,0,8,6,2,1>>::max == 45, "Failed!");
    static_assert(IntListUtils<IntList<1,1,2,7,3,45,0,8,-12,2,1>>::min == -12, "Failed!");

/**  *   ||           ***************************       ||   *******************
 *****  \||/                  IntListsEqual            \||/  *******************
 *****   \/           ***************************       \/   **************** */

    static_assert(IntListsEqual<IntList<>, IntList<> >::value, "Failed!");
    static_assert(IntListsEqual<IntList<1>, IntList<1> >::value, "Failed!");
    static_assert(IntListsEqual<IntList<1>, IntList<2> >::value == false, "Failed!");
    static_assert(IntListsEqual<IntList<1,2>, IntList<1,2> >::value, "Failed!");
    static_assert(IntListsEqual<IntList<1,2>, IntList<2,1> >::value == false, "Failed!");
    static_assert(IntListsEqual<IntList<2,1>, IntList<1,2> >::value == false, "Failed!");

    static_assert(IntListsEqual<IntList<1, 2, 3>::next::next, IntList<3> >::value, "Failed!");
    static_assert(IntListsEqual<IntList<1, 2, 3, 4>, IntList<1, 2, 3, 4>>::value, "Failed!");
    static_assert(IntListsEqual<IntList<1, 2, 3, 5>, IntList<1, 2, 3, 4>>::value == false, "Failed!");
    static_assert(IntListsEqual<IntListUtils<IntList<1, 2, 3>>::reversed, IntListUtils<IntListUtils<IntListUtils<IntList<1, 2, 3>>::reversed>::reversed>::reversed>::value, "Failed!");
    static_assert(IntListsEqual<IntList<2, 3>, IntList<2, 3>>::value, "Failed!");

/**  *   ||           ***************************       ||   *******************
 *****  \||/                IntListContains            \||/  *******************
 *****   \/           ***************************       \/   **************** */

    static_assert(IntListContains<IntList<> >::value, "Failed!");
    static_assert(IntListContains<IntList<1> >::value == false, "Failed!");
    static_assert(IntListContains<IntList<1>, 1 >::value, "Failed!");
    static_assert(IntListContains<IntList<1,2>, 1,2 >::value, "Failed!");
    static_assert(IntListContains<IntList<1,2> >::value == false, "Failed!");
    static_assert(IntListContains<IntList<1,2>, 2, 1 >::value == false, "Failed!");
    static_assert(IntListContains<IntList<1,2>, 1 >::value == false, "Failed!");
    static_assert(IntListContains<IntList<1,2>, 1,2,3 >::value == false, "Failed!");

/**  *   ||           ***************************       ||   *******************
 *****  \||/               IntListIndexEquals          \||/  *******************
 *****   \/           ***************************       \/   **************** */

    static_assert(IntListIndexEquals<IntList<>, 0, 1 >::value == false, "Failed!");
    static_assert(IntListIndexEquals<IntList<>, 1, 0 >::value == false, "Failed!");
    static_assert(IntListIndexEquals<IntList<>, 0, 0 >::value == false, "Failed!");
    static_assert(IntListIndexEquals<IntList<>, 6, 0 >::value == false, "Failed!");
    static_assert(IntListIndexEquals<IntList<>, 0, 6 >::value == false, "Failed!");
    static_assert(IntListIndexEquals<IntList<1>, 0, 5 >::value == false, "Failed!");
    static_assert(IntListIndexEquals<IntList<1,3>, 0, 5 >::value == false, "Failed!");
    static_assert(IntListIndexEquals<IntList<1>, 0, 1 >::value, "Failed!");
    static_assert(IntListIndexEquals<IntList<1,2>, 1, 2 >::value, "Failed!");
    static_assert(IntListIndexEquals<IntList<1,2,3>, 2, 3 >::value, "Failed!");
    static_assert(IntListIndexEquals<IntList<1,2,3,4,5,6,7,8,40>, 8, 40 >::value, "Failed!");
    static_assert(IntListIndexEquals<IntList<1,2,3>, 5, 1 >::value == false, "Failed!");

/**  *   ||           ***************************       ||   *******************
 *****  \||/                     Segel                 \||/  *******************
 *****   \/           ***************************       \/   **************** */

    IntList<1, 2, 3>::head; // = 1
    //IntList<1, 2, 3>::next::next; // = IntList<3>
    static_assert(IntListsEqual<IntList<1, 2, 3>::next::next, IntList<3> >::value, "Failed!");
    IntList<1, 2>::size; // = 2
    IntList<1, 2>::next::next::empty; // = true
    typedef ConcatedIntLists<IntList<1>, IntList<>, IntList<2, 3, 4>>::list Concated; // = IntList<1,2,3,4>
    static_assert(IntListsEqual<Concated, IntList<1, 2, 3, 4>>::value, "Failed!");
    //MergedIntLists<IntList<1, 9>, IntList<1, 2, 3, 4>>::list; // = IntList<1,1,9,2,3,4>
    typedef IntListUtils<IntList<1, 2, 3>>::reversed MyList; // = IntList<3,2,1>
    static_assert(IntListsEqual<MyList, IntListUtils<IntListUtils<MyList>::reversed>::reversed>::value, "Failed!");
    IntListUtils<IntList<1, 2, 3>>::max; // = 3
    IntListUtils<IntList<1, 2, 3>>::min; // = 1
    IntListsEqual<IntList<2, 3>, IntList<2, 3>>::value; // = true
    IntListContains<IntList<2, 3>, 2, 3>::value; // = true
    IntListIndexEquals<IntList<1, 2>, 0, 1>::value; // = true (index 0 contains 1)


    return 0;
}