/**
Project id: Group Project C2
Project Name: Algorithm Comparison
Programmer: Christian Inglehart
Description: This program takes two algorithms and compares the time the two take to determine which is quicker.
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Function to partition the sequence into three parts: <pivot, =pivot, >pivot
void partition(const vector<int>& seq, int pivot, vector<int>& less, vector<int>& equal, vector<int>& greater) {
    for (int elem : seq) {
        if (elem < pivot)
            less.push_back(elem);
        else if (elem == pivot)
            equal.push_back(elem);
        else
            greater.push_back(elem);
    }
}

// The select algorithm to find the kth element
int select(vector<int>& seq, int k) {
    if (seq.size() == 1)
        return seq[0];

    // Pick a random pivot
    int pivot = seq[rand() % seq.size()];

    // Partition the sequence into less, equal, and greater
    vector<int> less, equal, greater;
    partition(seq, pivot, less, equal, greater);

    int n1 = less.size();
    int n2 = equal.size();

    // Recursively select based on the position of k
    if (k < n1)
        return select(less, k);
    else if (k < n1 + n2)
        return pivot;
    else
        return select(greater, k - n1 - n2);
}

// Function to find the median using the select algorithm
int findMedianSelect(vector<int>& seq) {
    int n = seq.size();
    return select(seq, n / 2);
}

// Function to find the median using the sorting method
int findMedianSort(vector<int>& seq) {
    sort(seq.begin(), seq.end());
    return seq[seq.size() / 2];
}

int main() {
    srand(time(0));  // Seed for random pivot selection

    // Generate a large random sequence
    int n = 100000;  // Size of sequence
    vector<int> sequence(n);
    for (int i = 0; i < n; ++i)
        sequence[i] = rand() % 1000000;

    // Copy the sequence to use for both algorithms
    vector<int> sequence_for_select = sequence;
    vector<int> sequence_for_sort = sequence;

    // Measure time for select algorithm to find median
    clock_t start_select = clock();
    int median_select = findMedianSelect(sequence_for_select);
    clock_t end_select = clock();
    double time_select = double(end_select - start_select) / CLOCKS_PER_SEC;

    // Measure time for sorting algorithm to find median
    clock_t start_sort = clock();
    int median_sort = findMedianSort(sequence_for_sort);
    clock_t end_sort = clock();
    double time_sort = double(end_sort - start_sort) / CLOCKS_PER_SEC;
    
    //initialize value for the time difference between the two algorithms
    double time_difference;
    

    // Output results
    cout << "Median (select algorithm): " << median_select << endl;
    cout << "Time (select algorithm): " << time_select << " seconds" << endl;

    cout << "Median (sorting algorithm): " << median_sort << endl;
    cout << "Time (sorting algorithm): " << time_sort << " seconds" << endl;
    
    //calculate and output the time difference between the two algorithms
    if(median_select > median_sort)
    {
        time_difference = time_select - time_sort;
        cout << "Select algorithm is faster than Sort algorithm by "<< time_difference << " seconds" << endl;
    }
    else
    {
        time_difference = time_sort - time_select;
        cout << "Sort algorithm is faster than Select algorithm by "<< time_difference << " seconds" << endl;
    }

    return 0;
}
