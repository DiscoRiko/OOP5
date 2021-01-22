#ifndef INTLISTCOMPARATORS
#define INTLISTCOMPARATORS
#include "IntList.h"

/**Equal**/
template<typename, typename>
struct IntListsEqual;

template<>
struct IntListsEqual<IntList<>, IntList<>> {
    constexpr static bool value = true;
};

template<int... IL>
struct IntListsEqual<IntList<>, IntList<IL...>> {
    constexpr static bool value = false;
};

template<int... IL>
struct IntListsEqual<IntList<IL...>, IntList<>> {
    constexpr static bool value = false;
};

template<int i1, int... IL1, int i2, int... IL2>
struct IntListsEqual<IntList<i1, IL1...>, IntList<i2, IL2...>> {
    constexpr static bool value = (i1 == i2) && (IntListsEqual<IntList<IL1...>, IntList<IL2...>>::value);
};

/**Contains**/
template<typename, int...>
struct IntListContains;

template<int... IL1, int... IL2>
struct IntListContains<IntList<IL1...>, IL2...> {
    constexpr static bool value = IntListsEqual<IntList<IL1...>, IntList<IL2...>>::value;
};

/**IndexEqual**/
template<typename, int, int>
struct IntListIndexEquals;

template<int index, int val>
struct IntListIndexEquals<IntList<>, index, val> {
    constexpr static bool value = false;
};

template<int i, int... IL, int val>
struct IntListIndexEquals<IntList<i, IL...>, 0, val> {
    constexpr static bool value = i == val;
};

template<int i, int... IL, int index, int val>
struct IntListIndexEquals<IntList<i, IL...>, index, val> {
    constexpr static bool value = IntListIndexEquals<IntList<IL...>, index-1, val>::value;
};



#endif // !INTLISTCOMPARATORS
