#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

vector<int> timeStamps, samples;
int delta, n;
std::function<bool(int , int)> comparator;

void countAvg()
{
    int r = 0, start = 0, size = 0, sum = 0;

    for (int i = 0; i < n; i++)
    {
        //remove the items that are outside the time window
        while (size > 0 && timeStamps[i] > timeStamps[start] + delta)
        {
            // remove elements from the left
            sum -= samples[start++];
            size--;
        }
        //  condition is met for current sample, sum / size = avg,
        // so we compare sample[i] {cmp} sum / size (eq times size)
        // samples[i] * size {cmp} sum
        r += (size > 0 && comparator(samples[i] * size, sum));
        sum += samples[i];
        size++;
    }
    std::cout << r << std::endl;
}

void countMinMax(bool isMin)
{
    int result = 0;

    // heap is ordered based on sample value
    auto heapCmp = isMin ? std::function<bool(int, int)>([](int a, int b) { return samples[a] > samples[b]; }) :
                   std::function<bool(int, int)>([](int a, int b) { return samples[a] < samples[b]; });

    vector<int> heap;
    make_heap(heap.begin(), heap.end(), heapCmp);

    for(int i = 0; i < n; i++)
    {
        //remove the items that are outside the time window
        while(!heap.empty() && timeStamps[i] > timeStamps[heap.front()] + delta)
        {
            // move the first el at the end of the heap
            pop_heap(heap.begin(), heap.end(), heapCmp);
            // remove it from the heap
            heap.pop_back();
        }

        //  condition is met for current sample
        if(!heap.empty() && comparator(samples[i], samples[heap.front()]))
            result++;

        // add index of current sample into the heap for next queries
        heap.push_back(i);
        push_heap(heap.begin(), heap.end(), heapCmp);
    }
    std::cout << result << std::endl;
}



int main ()
{
    string cmp, agr;
    int queries;

    while(cin >> n)
    {
        timeStamps.clear();
        samples.clear();

        // read the data
        for(int i = 0; i < n; i++)
        {
            int sample, timeStamp;
            cin >> timeStamp >> sample;
            timeStamps.push_back(timeStamp);
            samples.push_back(sample);
        }

        cin >> queries;

        for(int i = 0; i < queries; i++)
        {
            cin >> cmp >> agr >> delta;

            if(cmp == "gt")
                comparator = std::greater<>();
            else
                comparator = std::less<>();

            if(agr == "avg")
                countAvg();
            else
                countMinMax(agr == "min");
        }
    }
    return 0;
}