#ifndef INTLISTUTILS
#define INTLISTUTILS
#include "IntList.h"

template<typename>
struct IntListUtils;

template<>
struct IntListUtils<IntList<>> {
    typedef IntList<> reversed;
};

template<int i>
struct IntListUtils<IntList<i>> {
    constexpr static int max = i;
    constexpr static int min = i;
    typedef IntList<i> reversed;
};

template<int i, int... IL>
struct IntListUtils<IntList<i, IL...>> {
    constexpr static int tail_max = IntListUtils<IntList<IL...>>::max;
    constexpr static int max = i > tail_max ? i : tail_max;

    constexpr static int tail_min = IntListUtils<IntList<IL...>>::min;
    constexpr static int min = i < tail_min ? i : tail_min;

    typedef typename ConcatedIntLists<typename IntListUtils<IntList<IL...>>::reversed, IntList<i>>::list reversed;
};

#endif // !INTLISTUTILS
