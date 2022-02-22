#include <iostream>
#include <random>
#include <iterator>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <stdio.h>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <map>

using namespace std::chrono;
constexpr auto is_simple(unsigned int n){
    if (n == 1){return false;}
    else {
        for (auto i = 2u; i < (n / 2) + 1; i++) {
            if (n % i == 0) { return false; }
        }
        return true;
    }
}

#ifndef ALGORITHMS_AND_ITERATORS_SUPPORT_FILE_H
#define ALGORITHMS_AND_ITERATORS_SUPPORT_FILE_H

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vector) {
    out << '[';
    std::copy(std::begin(vector), std::prev(std::end(vector)), std::ostream_iterator<T>(out, " "));
    return out << *std::prev(std::end(vector)) << ']' ;
}

#endif //ALGORITHMS_AND_ITERATORS_SUPPORT_FILE_H
