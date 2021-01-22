#ifndef CONCATEDINTLISTS
#define CONCATEDINTLISTS
#include "IntList.h"

template<typename...>
struct ConcatedIntLists;

template<>
struct ConcatedIntLists<IntList<>> {
    typedef IntList<> list;
};

template<int... IL>
struct ConcatedIntLists<IntList<IL...>> {
    typedef IntList<IL...> list;
};

template<int... IL1, int... IL2>
struct ConcatedIntLists<IntList<IL1...>, IntList<IL2...>> {
    typedef IntList<IL1..., IL2...> list;
};

template<int... IL1, int... IL2, typename... ILL>
struct ConcatedIntLists<IntList<IL1...>, IntList<IL2...>, ILL...> {
    typedef typename ConcatedIntLists<typename ConcatedIntLists<IntList<IL1...>, IntList<IL2...>>::list, ILL...>::list list;
};

#endif // !CONCATEDINTLISTS
