#include <iostream>
#include "StatisticMultiset.cpp"

int main() {

    StatisticMultiset ml;
    ml.AddNum(123);
    ml.AddNum(12);
    ml.AddNum(12);
    ml.AddNum(124);
    ml.AddNum(11);
    std::vector<int> a = {1,2,3,4};
    std::list<int> b = {25,6,7,8};
    ml.AddNum(a);
    ml.AddNum(b);
    ml.AddNumsFromFile("numbers.txt");
    ml.ShowNums();
    StatisticMultiset ml2;
    ml2.AddNum(255);
    ml2.AddNums(ml);
    ml2.ShowNums();
    std::cout << ml.GetCountUnder(12) << std::endl;
    std::cout << ml.GetMax() << std::endl;
    std::cout << ml2.GetAvg() << std::endl;
    std::cout << ml.GetMin() << std::endl;
    return 0;
}
