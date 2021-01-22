#include <iostream>
#include "p1/IntList.h"
#include "p1/MergedIntLists.h"

int main() {
/**  *   ||           ***************************       ||   *******************
 *****  \||/                   IntList                 \||/  *******************
 *****   \/           ***************************       \/   **************** */
/*
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
*/

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

    return 0;
}
