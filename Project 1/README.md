# Project 1 : an analysis of sorting algorithms

### Implemented algorithms:
- [x] sort from STL
- [x] Bubble sort
- [x] Comb sort
- [x] Quicksort with random pivot
- [x] Quicksort with median of 3
- [x] Quicksort with median of medians
- [x] Radixsort in base 16
- [x] Radixsort in base 256
- [x] Mergesort
- [x] Insertion sort
- [x] Binary insertion sort
- [x] Shell sort

### Mentions and conclusions:
* Each algorithms has certain restrictions on input data so that each sort doesn't run for more than 5 seconds
* I also analised the difference between sorting a vector of random ints and sorting a decresing vector and found the following:
  * Quicksort and Radixsort have about the same complexity on both cases
* On certain inputs my implementation of Radixsort is faster than the sort in STL
* Comb sort is a very good improvement to Bubble sort and runs much faster, although it still has O(n^2) worst case complexity
* Binary insertions sort is a good improvement to Insertion sort
* For Shell sort I used the formula (3^k-1)/2 which guarantees O(n^(3/2)) in worst case (see: http://en.wikipedia.org/wiki/Shellsort#Gap_sequences)


