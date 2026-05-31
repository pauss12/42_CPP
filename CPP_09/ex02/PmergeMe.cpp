#include "PmergeMe.hpp"

struct Item
{
    int value;
    std::size_t index;
};

struct PairData
{
    Item small;
    Item big;
};

struct ItemLess
{
    bool operator()(const Item &left, const Item &right) const
    {
        return (left.value < right.value);
    }
};

static void printError()
{
    std::cerr << "Error" << std::endl;
}

static bool parsePositiveInteger(const std::string &token, int &value)
{
    if (token.empty())
        return (false);

    long long parsed = 0;
    for (std::string::size_type i = 0; i < token.size(); ++i)
    {
        if (token[i] < '0' || token[i] > '9')
            return (false);
        parsed = parsed * 10 + (token[i] - '0');
        if (parsed > INT_MAX)
            return (false);
    }
    if (parsed <= 0)
        return (false);

    value = static_cast<int>(parsed);
    return (true);
}

static std::vector<int> parseArguments(int argc, char *argv[], bool &valid)
{
    std::vector<int> values;

    valid = false;
    if (argc < 2)
        return values;

    for (int i = 1; i < argc; ++i)
    {
        int value = 0;
        if (!parsePositiveInteger(argv[i], value))
        {
            values.clear();
            return values;
        }
        values.push_back(value);
    }
    valid = true;
    return values;
}

static double elapsedMicroseconds(const timeval &start, const timeval &end)
{
    return (static_cast<double>(end.tv_sec - start.tv_sec) * 1000000.0
        + static_cast<double>(end.tv_usec - start.tv_usec));
}

template <typename Container>
static typename Container::iterator findByIndex(Container &container, std::size_t index)
{
    typename Container::iterator it = container.begin();
    for (; it != container.end(); ++it)
    {
        if (it->index == index)
            return it;
    }
    return container.end();
}

template <typename Container>
static void insertBounded(Container &chain, const Item &item, typename Container::iterator bound)
{
    typename Container::iterator pos = std::lower_bound(chain.begin(), bound, item, ItemLess());
    chain.insert(pos, item);
}

template <typename Container>
static Container mergeInsertSort(Container chain)
{
    if (chain.size() <= 1)
        return chain;

    std::vector<PairData> pairs;
    Item leftover;
    bool hasLeftover = false;

    typename Container::iterator it = chain.begin();
    while (it != chain.end())
    {
        Item first = *it;
        ++it;
        if (it == chain.end())
        {
            leftover = first;
            hasLeftover = true;
            break;
        }

        Item second = *it;
        ++it;
        if (first.value > second.value)
            std::swap(first, second);

        PairData pair;
        pair.small = first;
        pair.big = second;
        pair.small.index = pairs.size();
        pair.big.index = pairs.size();
        pairs.push_back(pair);
    }

    Container bigs;
    for (std::size_t i = 0; i < pairs.size(); ++i)
        bigs.push_back(pairs[i].big);

    std::sort(bigs.begin(), bigs.end(), ItemLess());
    Container sorted = bigs;

    for (std::size_t i = 0; i < pairs.size(); ++i)
    {
        typename Container::iterator partner = findByIndex(sorted, i);
        if (partner == sorted.end())
            return Container();
        insertBounded(sorted, pairs[i].small, partner);
    }

    if (hasLeftover)
        insertBounded(sorted, leftover, sorted.end());

    return sorted;
}

static std::vector<Item> toItems(const std::vector<int> &values)
{
    std::vector<Item> items;
    items.reserve(values.size());
    for (std::size_t i = 0; i < values.size(); ++i)
    {
        Item item;
        item.value = values[i];
        item.index = 0;
        items.push_back(item);
    }
    return items;
}

static std::deque<Item> toItems(const std::deque<int> &values)
{
    std::deque<Item> items;
    for (std::size_t i = 0; i < values.size(); ++i)
    {
        Item item;
        item.value = values[i];
        item.index = 0;
        items.push_back(item);
    }
    return items;
}

static std::vector<int> extractValues(const std::vector<Item> &items)
{
    std::vector<int> values;
    values.reserve(items.size());
    for (std::size_t i = 0; i < items.size(); ++i)
        values.push_back(items[i].value);
    return values;
}

static std::deque<int> extractValues(const std::deque<Item> &items)
{
    std::deque<int> values;
    for (std::size_t i = 0; i < items.size(); ++i)
        values.push_back(items[i].value);
    return values;
}

template <typename Container>
static void printSequence(const Container &values)
{
    for (typename Container::const_iterator it = values.begin(); it != values.end(); ++it)
    {
        if (it != values.begin())
            std::cout << ' ';
        std::cout << *it;
    }
}

template <typename Container>
static bool sameSequence(const Container &left, const Container &right)
{
    if (left.size() != right.size())
        return (false);

    typename Container::const_iterator itLeft = left.begin();
    typename Container::const_iterator itRight = right.begin();
    for (; itLeft != left.end(); ++itLeft, ++itRight)
    {
        if (*itLeft != *itRight)
            return (false);
    }
    return (true);
}

static double sortWithVector(const std::vector<int> &input, std::vector<int> &sortedValues)
{
    timeval start;
    timeval end;

    gettimeofday(&start, 0);
    std::vector<Item> items = toItems(input);
    std::vector<Item> sortedItems = mergeInsertSort(items);
    sortedValues = extractValues(sortedItems);
    gettimeofday(&end, 0);
    return elapsedMicroseconds(start, end);
}

static double sortWithDeque(const std::vector<int> &input, std::deque<int> &sortedValues)
{
    timeval start;
    timeval end;

    gettimeofday(&start, 0);
    std::deque<Item> items = toItems(std::deque<int>(input.begin(), input.end()));
    std::deque<Item> sortedItems = mergeInsertSort(items);
    sortedValues = extractValues(sortedItems);
    gettimeofday(&end, 0);
    return elapsedMicroseconds(start, end);
}

PmergeMe::PmergeMe(int argc, char *argv[])
    : _input(), _valid(false)
{
    _input = parseArguments(argc, argv, _valid);
}

int PmergeMe::execute() const
{
    if (!_valid)
    {
        printError();
        return (1);
    }

    std::cout << "Before: ";
    printSequence(_input);
    std::cout << std::endl;

    std::vector<int> vectorSorted;
    std::deque<int> dequeSorted;
    double vectorTime = sortWithVector(_input, vectorSorted);
    double dequeTime = sortWithDeque(_input, dequeSorted);

    if (!sameSequence(vectorSorted, std::vector<int>(dequeSorted.begin(), dequeSorted.end())))
    {
        printError();
        return (1);
    }

    std::cout << "After: ";
    printSequence(vectorSorted);
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _input.size()
              << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _input.size()
              << " elements with std::deque : " << dequeTime << " us" << std::endl;
    return (0);
}