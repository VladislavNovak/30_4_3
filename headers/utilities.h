#ifndef INC_30_4_3_UTILITIES_H
#define INC_30_4_3_UTILITIES_H

#include <algorithm>
#include <map>

template<typename T, typename N>
bool isIncludes(const T &range, const N &item) {
    return std::any_of(range.begin(),
                       range.end(),
                       [&item](const N &c) { return c == item; });
}

template<typename F, typename S>
bool addEntryToMap(const std::pair<F, S> &entry, std::map<F, S> &target) {
    if (target.count(entry.first) == 1) return false;

    target.insert(entry);

    return true;
}

#endif //INC_30_4_3_UTILITIES_H
