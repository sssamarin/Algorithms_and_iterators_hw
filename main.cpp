#include <iostream>
#include "support_file.h"
#define RANGE(container) std::begin(container), std::end(container)
int main() {
    auto current_timestamp = std::chrono::steady_clock::now().time_since_epoch().count();
    auto generator = std::mt19937_64(current_timestamp);
    auto distribution = std::uniform_int_distribution(1, 10);

    // 1#
    std::vector<int> p1 (10);
    std::iota(RANGE(p1) , 1 );
    std::cout << "1: p1 is  " << p1 << std::endl; std::cout << std::endl;

    // 2#
    int int_to_insert;
    for (auto i = 0 ; i != 2 ;  i++ ){
        std::cout << "Enter the ints to insert" << std::endl;
        std::cin >> int_to_insert;
        std::back_inserter(p1) = int_to_insert ;
    }
    std::cout << "2: " << p1 << std::endl;  std::cout << std::endl;

//    //3#
//    std::random_shuffle(RANGE(p1));
//    std::cout << "3: " << p1 << std::endl;  std::cout << std::endl;

    //4#
    std::generate_n(std::back_inserter(p1), 8,[&distribution, &generator](){return distribution(generator);});
    std::cout << "4: " << p1 << " -> ";
    std::sort(RANGE(p1));
    auto it = std::unique(RANGE(p1));
    p1.erase(it , std::end(p1));
    std::cout  << p1 << std::endl; std::cout << std::endl;
//    std::cout << "4: " << p1 << " -> ";
//    std::vector<int> p2; std::unique_copy(std::begin(p1), std::end(p1), std::back_inserter(p2));
//    std::cout  << p2 << std::endl;

    //5#
    int S = std::count_if(RANGE(p1), [](int i ){return i % 2 != 0;});
    std::cout << "5: " << "there are "  << S << " numbers in sequence non divisible by 2" << std::endl;  std::cout << std::endl;

    //6#
    int Max = *std::max_element(RANGE(p1));
    int Min = *std::min_element(RANGE(p1));
    std::cout << "6: " <<"max element is - "<< Max <<
    ", min element is - " << Min << std::endl;  std::cout << std::endl;

    //7#
    int Simple = *std::find_if(RANGE(p1), is_simple);
    std::cout << "7: the first simple to meet is - " << Simple << std::endl;  std::cout << std::endl;

    //8#
    std::vector<int> squared;
    std::transform(RANGE(p1), std::back_inserter(squared), [](auto elem){return elem * elem;});
    std::cout << "8:  squared sequence " << squared << std::endl;  std::cout << std::endl;

    //9#
    std::vector<int> p2 ;
    std::generate_n(std::back_inserter(p2), p1.size(),[&distribution, &generator](){return distribution(generator);});
    std::cout << "9: p2 is  " << p2 << std::endl;  std::cout << std::endl;

    //10#
    int Sum = std::accumulate(RANGE(p2), 0);
    std::cout << "10: sum of p2 elements is - " << Sum << std::endl;  std::cout << std::endl;
//    int ptotal = accumulate(p1.begin(), p1.end(), 1, std::multiplies<int>());          //поочередное перемножение эл-в
//    std::cout << "The product of the integers from 1 to 10 is: " << ptotal << "." << std::endl;

    //11#
    std::replace_if(std::begin(p2), std::next(std::begin(p2), 4),
                    [](auto elem){return elem;}, 1);
    std::cout << "11: replacing elements with 1 " << p2 << std::endl;  std::cout << std::endl;

    //12#
    std::vector<int> p3;
    std::transform(RANGE(p1), std::begin(p2),std::back_inserter(p3), [](auto lhs, auto rhs){return lhs - rhs;});
    std::cout << "12: p3 is " << p3 << std::endl;  std::cout << std::endl;

    //13#
    std::replace_if(RANGE(p3), [](auto elem){return elem <= 0 ;}, 0);
    std::cout << "13: replacing negatives with 0 " << p3 << std::endl;  std::cout << std::endl;

    //14#
    p3.erase(std::remove(RANGE(p3), 0), std::end(p3));
    std::cout << "14: removing 0 " << p3 << std::endl;  std::cout << std::endl;

    //15#
    std::reverse(RANGE(p3));
    std::cout << "15: reversing p3 " << p3 << std::endl;  std::cout << std::endl;

    //16#
    std::vector<int> top3;
    std::nth_element(std::begin(p3), std::prev(std::end(p3), 3), std::end(p3) );
    std::copy(std::prev(std::end(p3),3), std::end(p3), std::back_inserter(top3));
    std::cout << "16: top3 of p3 " << top3 << std::endl;  std::cout << std::endl;

    //17#
    std::sort(RANGE(p1));
    std::sort(RANGE(p2));
    std::cout << "17: sorted p1 and p2 " << p1 <<" ; "<< p2 <<   std::endl;  std::cout << std::endl;

    //18#
    std::vector<int> p4;
    std::merge(RANGE(p1), RANGE(p2), std::back_inserter(p4));
    std::cout << "18: p4 is  " << p4 <<   std::endl;  std::cout << std::endl;

    //19#
    auto distance = std::distance(std::find_if(RANGE(p4), [](auto elem){return elem > 0 ;}),
                                  std::find_if(RANGE(p4), [](auto elem){return elem > 1;}));
    std::cout << "19: distance is  " << distance <<   std::endl;  std::cout << std::endl;

    //20#
    std::cout << "20: p1 is " << p1 <<std::endl<<
    "    p2 is " << p2<< std::endl << "    p3 is " << p3<< std::endl <<"    p4 is "<< p4 <<std::endl;
    std::cout << std::endl;

    return 0;
}
