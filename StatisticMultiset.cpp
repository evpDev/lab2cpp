#include "StatisticMultiset.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <utility>
//StatisticMultiset::StatisticMultiset() {}
template<class T>
void StatisticMultiset<T>::UpdateFlags() {
    needNewValMax = true;
    needNewValAvg = true;
    needNewValMin = true;
    needNewValCountUnder = true;
    needNewValCountAbove = true;
};
template<class T>
void StatisticMultiset<T>::AddNum(T num) {
    if (mySet.empty()) mySet.push_back(num);
    else {
        typename std::vector<T>::iterator it;
        for (it = mySet.begin(); *it < num; it++);
        mySet.insert(it, num);
    }
    sumOfNums += num;
    UpdateFlags();
}
template<class T>
void StatisticMultiset<T>::AddNum(const std::vector<T>& numbers) {
    for (int i = 0; i < numbers.size(); i++) sumOfNums += numbers[i];
    mySet.insert(mySet.end(), numbers.begin(), numbers.end());
    std::sort(mySet.begin(), mySet.end());
    UpdateFlags();
}
//THere is equal code...
template<class T>
void StatisticMultiset<T>::AddNum(std::list<T>& numbers) {
    typename std::list<T>::iterator it = numbers.begin();
    for (; it != numbers.end(); it++) sumOfNums += *it;
    mySet.insert(mySet.end(), numbers.begin(), numbers.end());
    std::sort(mySet.begin(), mySet.end());
    UpdateFlags();
}
template<class T>
void StatisticMultiset<T>::AddNumsFromFile(const char* filename) {
    std::ifstream fin(filename);
    int num;
    if (fin.is_open()) while (fin >> num) AddNum(num);
    else std::cout << "No such files" << std::endl;
    fin.close();
    UpdateFlags();
}
template<class T>
void StatisticMultiset<T>::AddNums(const StatisticMultiset& statSetObj) {
    AddNum(statSetObj.mySet);
    UpdateFlags();
}

// Maximum number.
template<class T>
T StatisticMultiset<T>::GetMax() const {
    if (needNewValMax) {
        valMax = mySet[mySet.size()-1];
        needNewValMax = false;
    } return valMax;
}
// Minimal number.
template<class T>
T StatisticMultiset<T>::GetMin() const {
    if (needNewValMin) {
        valMin = mySet[0];
        needNewValMin = false;
    } return valMin;
}
// Average number from amount of numbers.
template<class T>
float StatisticMultiset<T>::GetAvg() const {
    if (needNewValAvg) {
        valAvg = sumOfNums/mySet.size();
        needNewValAvg = false;
    } return valAvg;
}
// Amount of number which less than threshold.
template<class T>
int StatisticMultiset<T>::GetCountUnder(float threshold) const {
    if (needNewValCountUnder) {
        int i;
        for (i = 0; mySet[i] < threshold; i++);
        valCountUnder = std::make_pair(threshold, i);
    } return valCountUnder.second;
    //return i;
}
// Amount of number which more than threshold.
template<class T>
int StatisticMultiset<T>::GetCountAbove(float threshold) const {
    if (needNewValCountAbove) {
        int i;
        for (i = 0; mySet[i] <= threshold; i++);
        valCountAbove = std::make_pair(threshold, i);
    } return valCountAbove.second;
    //return mySet.size() - i;
}
//it shows all numbers
template<class T>
void StatisticMultiset<T>::ShowNums() {
    int i;
    for (i = 0; i < mySet.size()-1; i++) std::cout << mySet[i] << ", ";
    std::cout << mySet[i] << std::endl;
}
