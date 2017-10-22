/*#ifndef STATISTICMULTISET_H_INCLUDED
#define STATISTICMULTISET_H_INCLUDED
#endif // STATISTICMULTISET_H_INCLUDED*/
#include <vector>
#include <list>
#include <map>
template<class T>
class StatisticMultiset {
    std::vector<T> mySet;
    float sumOfNums = 0;
    mutable bool needNewValMax, needNewValAvg, needNewValMin, needNewValCountUnder, needNewValCountAbove;
    mutable int valMax, valMin;
    mutable float valAvg;
    mutable std::pair<float, T> valCountUnder, valCountAbove;
    void UpdateFlags();
public:
    //StatisticMultiset();
    void AddNum(T num);
    void AddNum(const std::vector<T>& numbers);
    void AddNum(std::list<T>& numbers);
    void AddNumsFromFile(const char* filename);
    void AddNums(const StatisticMultiset& statSetObj);
    T GetMax() const;
    T GetMin() const;
    float GetAvg() const;
    int GetCountUnder(float threshold) const;
    int GetCountAbove(float threshold) const;
    void ShowNums();
};

