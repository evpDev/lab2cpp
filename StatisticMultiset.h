/*#ifndef STATISTICMULTISET_H_INCLUDED
#define STATISTICMULTISET_H_INCLUDED
#endif // STATISTICMULTISET_H_INCLUDED*/
#include <vector>
#include <list>
#include <map>
class StatisticMultiset {
    std::vector<int> mySet;
    float sumOfNums = 0;
    mutable bool needNewValMax, needNewValAvg, needNewValMin, needNewValCountUnder, needNewValCountAbove;
    mutable int valMax, valMin;
    mutable float valAvg;
    mutable std::pair<float, int> valCountUnder, valCountAbove;
    void UpdateFlags();
public:
    StatisticMultiset();
    void AddNum(int num);
    void AddNum(const std::vector<int>& numbers);
    void AddNum(std::list<int>& numbers);
    void AddNumsFromFile(const char* filename);
    void AddNums(const StatisticMultiset& statSetObj);
    int GetMax() const;
    int GetMin() const;
    float GetAvg() const;
    int GetCountUnder(float threshold) const;
    int GetCountAbove(float threshold) const;
    void ShowNums();
};

