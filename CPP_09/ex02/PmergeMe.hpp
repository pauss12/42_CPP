#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <algorithm>
#include <climits>
#include <deque>
#include <iomanip>
#include <iostream>
#include <string>
#include <sys/time.h>

class PmergeMe
{
public:
    PmergeMe(int argc, char *argv[]);
    int execute() const;

private:
    std::vector<int> _input;
    bool _valid;
};

#endif