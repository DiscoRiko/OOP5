#ifndef INTLIST
#define INTLIST


template<int...>
struct IntList;

template<>
struct IntList<> {
    constexpr static bool empty = true;
    constexpr static int size = 0;
};

/*template<int i>
struct IntList<i> {
    constexpr static int head = i;
    typedef IntList<> next;
    constexpr static bool empty = false;
    constexpr static int size = 1;
};*/

template<int i, int... IL>
struct IntList<i, IL...> {
    constexpr static bool empty = false;
    constexpr static int size = 1 + sizeof...(IL);
    constexpr static int head = i;
    typedef IntList<IL...> next;
};

#endif