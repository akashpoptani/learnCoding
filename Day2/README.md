# C++ Day 2 and Day 3 Learnings

This repository contains example code and experiments covering foundational and intermediate C++ concepts from **Day 2 and Day 3** of the focused learning plan. It is designed for learners progressing from data structures basics into memory handling, algorithms, and hash maps with collision handling.

***

## 📑 Table of Contents

1. [Arrays: Basics and Properties](#1-arrays-basics-and-properties)  
2. [Prefix Sums (Cumulative Sums)](#2-prefix-sums-cumulative-sums)  
3. [Sliding Window Technique](#3-sliding-window-technique)  
4. [Problem: Smallest Subarray with Sum at Least S](#4-problem-smallest-subarray-with-sum-at-least-s)  
5. [Pointer Basics](#5-pointer-basics)  
6. [Linked List Basics and Operations](#6-linked-list-basics-and-operations)  
7. [Linked List Cycle Detection (Tortoise-Hare Algorithm)](#7-linked-list-cycle-detection-tortoise-hare-algorithm)  
8. [Hash Map Basics and Frequency Counting](#8-hash-map-basics-and-frequency-counting)  
9. [Problem: Two Sum (Hash Map Problem)](#9-problem-two-sum-hash-map-problem)  
10. [Phone Directory using Open Addressing (Collision Handling)](#10-phone-directory-using-open-addressing-collision-handling)  
11. [Compilation and Execution Commands](#11-compilation-and-execution-commands)  

***

## 📘 Learnings and Examples

### 1. Arrays: Basics and Properties  
- Arrays are contiguous blocks of memory for elements of the same type.  
- Access is O(1) by index due to direct memory addressing.

***

### 2. Prefix Sums (Cumulative Sums)  
Precompute prefix sums of an array to answer range sum queries efficiently.  
Given array `arr`, build prefix sum `prefix` where:  

$$
prefix[i] = arr + arr + \cdots + arr[i-1]
$$

Sum for range $$[l, r)$$ is:  

$$
prefix[r] - prefix[l]
$$

Avoids recalculating sums multiple times, reducing repeated query time from $$O(n)$$ to $$O(1)$$.

**Example file:** `prefix_sum.cpp`

```bash
g++ -std=c++17 prefix_sum.cpp -o prefix_sum
./prefix_sum
```

***

### 3. Sliding Window Technique  
Efficiently solve problems on substrings or subarrays by maintaining a running window of fixed or dynamic size.

**Example:** Maximum sum subarray of size k

**Example file:** `sliding_window.cpp`  

```bash
g++ -std=c++17 sliding_window.cpp -o sliding_window
./sliding_window
```

***

### 4. Problem: Smallest Subarray with Sum at Least S  
Given an array of positive integers and a target sum $$S$$, find the length of the smallest contiguous subarray whose sum is at least $$S$$. Return 0 if no such subarray exists.

**Example file:** `min_subarray_sliding_window.cpp`

```bash
g++ -std=c++17 min_subarray_sliding_window.cpp -o min_subarray
./min_subarray
```

***

### 5. Pointer Basics  
- A pointer stores the memory address of another variable.  
- Use `&` to get the address, and `*` to dereference.

**Code snippet:**

```cpp
int a = 10;
int* ptr = &a;    // ptr points to 'a'
std::cout << "Address: " << ptr << "\n";
std::cout << "Value at address: " << *ptr << "\n"; // 10
*ptr = 20; // changes a to 20
std::cout << "a after change: " << a << "\n";
```

**Example file:** `pointer_basics.cpp`
ptr is a pointer to int.

*ptr accesses the value 'a' points to (10), and changing *ptr changes a.

```bash
Sample Output:
Address: 0x7ffd8f9b2c5c
Value at address: 10
a after change: 20
```

***

### 6. Linked List Basics and Operations  
- Linked lists consist of nodes with values and pointers to next nodes.  
- Not contiguous memory; dynamic structure.  

**Basic struct:**

```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
```

**Topics:** build, traverse, insert, delete, reverse, merge linked lists.

**Example files:** `linkedlist.cpp`, `linked_list_reverse.cpp`, `merge_sorted_lists.cpp`

Build, Traverse, Insert, Delete LinkedList

```bash
g++ -std=c++17 linkedlist.cpp -o linkedlist
./linkedlist
```
Building and Printing and Reversing a Linked List (Pointer Manipulation Challenge)
```bash
g++ -std=c++17 linked_list_reverse.cpp -o linked_list_reverse
./linked_list_reverse
```
Problem: Given two heads of sorted singly linked lists, merge them into a single sorted linked list and return the head of the new merged list.

```bash
g++ -std=c++17 merge_sorted_lists.cpp -o merge_sorted_lists
./merge_sorted_lists
```

***

### 7. Linked List Cycle Detection (Brute Force and Tortoise-Hare)

**Problem:**  
Detect if a singly linked list contains a cycle (loop).

**Brute Force:**
- Use a hash set of visited nodes while traversing.
- For each node, check if in set:
  - If yes, cycle detected.
  - If no, add to set and continue.
- If end (`nullptr`) reached, no cycle.
- *Time*: $O(n)$, *Space*: $O(n)$.

**Floyd’s Cycle-Finding Algorithm (Tortoise-Hare):**
- Use two pointers: slow moves 1 step, fast moves 2 steps each iteration.
- If list has a cycle, fast will meet slow inside the loop.
- If fast reaches end, no cycle.

**Example file:** `cycle_detection.cpp`

```bash
g++ -std=c++17 cycle_detection.cpp -o cycle_detection
./cycle_detection
```

***

### 8. Hash Map Basics and Frequency Counting  
- Use `std::unordered_map` for key-value storage with average O(1) access.  
- Example: counting frequencies of elements in an array.

```cpp
std::unordered_map<int, int> freq;
for (int num : nums) freq[num]++;
```

**Example file:** `hashmap_frequency.cpp`

```bash
g++ -std=c++17 hashmap_frequency.cpp -o hashmap_frequency
./hashmap_frequency
```
```cpp
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::vector<int> nums = {1, 2, 2, 3, 5, 1, 4, 2};
    std::unordered_map<int, int> freq;

    for (int num : nums) {
        freq[num]++;
    }

    std::cout << "Frequencies:\n";
    for (auto& p : freq) {
        std::cout << p.first << " appears " << p.second << " times\n";
    }

    return 0;
}
```

***

### 9. Problem: Find Two Numbers That Add Up to a Target

Given array `nums` and target integer `target`, return indices of two numbers adding to target. Each input has exactly one solution.

**Input:**  
`nums = [2,7,11,15]`, `target = 9`  
**Output:**  
`[0,1]` because `nums + nums == 9`.

**Brute Force:**
- Nested loops check all pairs.
- Time: $O(n^2)$.
  
**Hash Map Approaches:**

- *Method 1:* Build hash map of value → index, then lookup complement.
- *Method 2:* Iterate once, checking if complement in map and inserting current value.

**Example file:** `two_sum.cpp`

```bash
g++ -std=c++17 two_sum.cpp -o two_sum
./two_sum
```

***

### 10. Phone Directory Using Open Addressing (Collision Handling)

Design a phone directory that supports insert, remove, and exists operations on phone numbers (integers).

- Use open addressing with **linear probing** for collisions.
- Fixed-size array (size 20).
- Hash function: `hash(number) = number % array_size`.
- On collision, probe next slot cyclically `(index + 1) % array_size`.
- Use a marker for occupied slots to continue probing correctly.

**Example file:** `phone_directory.cpp`

```bash
g++ -std=c++17 phone_directory.cpp -o phone_directory
./phone_directory
```

***