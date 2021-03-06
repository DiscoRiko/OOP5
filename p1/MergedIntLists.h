#ifndef MERGEDLIST
#define MERGEDLIST
#include "IntList.h"
#include "ConcatedIntLists.h"

template<typename, typename>
struct MergedIntLists;

template<>
struct MergedIntLists<IntList<>, IntList<>> {
    typedef IntList<> list;
};

template<int... IL>
struct MergedIntLists<IntList<IL...>, IntList<>> {
    typedef IntList<IL...> list;
};

template<int... IL>
struct MergedIntLists<IntList<>, IntList<IL...>> {
    typedef IntList<IL...> list;
};

template<int... IL1, int... IL2>
struct MergedIntLists<IntList<IL1...>, IntList<IL2...>> {
    typedef typename ConcatedIntLists<IntList<IntList<IL1...>::head>, typename MergedIntLists<IntList<IL2...>, typename IntList<IL1...>::next>::list>::list list;
};



#endif // !MERGEDLIST