# C++ Day 1 Learnings

This repository contains example code and experiments covering foundational C++ concepts and performance explorations from **Day 1** of the focused learning plan. It is designed for learners who want practical insights into essential C++ features along with observations on compiler optimizations.

***

## 📑 Table of Contents
1. [References are aliases for variables](#1-references-are-aliases-for-variables)  
2. [Resource Acquisition Is Initialization (RAII)](#2-resource-acquisition-is-initialization-raii)  
3. [Return Value Optimization (RVO) and Move Semantics](#3-return-value-optimization-rvo-and-move-semantics)  
4. [Operations around strings and vectors](#4-operations-around-strings-and-vectors)  
5. [Pass by Value vs Pass by Reference](#5-pass-by-value-vs-pass-by-reference)  
6. [Copy vs Move Constructors and Assignments](#6-copy-vs-move-constructors-and-assignments)  
7. [Compiler Optimizations Example](#7-compiler-optimizations-example)  
8. [Compilation and Execution](#compilation-and-execution)  

***

## 📘 Learnings and Examples

### 1. References are aliases for variables
References in C++ create aliases to existing variables, enabling indirect modification without copying. This powerful feature simplifies code and helps avoid unnecessary data duplication.

**Example file:** `references.cpp`

```bash
g++ -std=c++17 references.cpp -o references
./references
```

***

### 2. Resource Acquisition Is Initialization (RAII)
RAII is a key C++ idiom where resource allocation is tied to object lifetime, ensuring resources are properly released when objects go out of scope. It prevents leaks and guarantees exception safety.

**Example file:** `raii.cpp`

```bash
g++ -std=c++17 raii.cpp -o raii
./raii
```

***

### 3. Return Value Optimization (RVO) and Move Semantics
RVO is a compiler optimization that eliminates unnecessary copying of returned objects. Move semantics allow efficient transfer of resource ownership using `std::move`, improving performance in many scenarios.

**Example files:** `move_semantics.cpp`, `custom_move_benchmark.cpp`

```bash
g++ -std=c++17 move_semantics.cpp -o move_semantics
./move_semantics
```

***

### 4. Operations around strings and vectors
Demonstrates basic usage and manipulation of dynamic containers like `std::string` and `std::vector`. These are foundational types for handling scalable data in C++.

**Example file:** `vector_string.cpp`

```bash
g++ -std=c++17 vector_string.cpp -o vector_string
./vector_string
```

***

### 5. Pass by Value vs Pass by Reference
Explores different function parameter-passing strategies: pass-by-value copies arguments, while pass-by-reference provides efficient access allowing modifications to the original variables.

**Example file:** `pass_reference_value.cpp`

```bash
g++ -std=c++17 pass_reference_value.cpp -o pass_ref_val
./pass_ref_val
```

***

### 6. Copy vs Move Constructors and Assignments
Shows how copy and move constructors and assignment operators differ in behavior and performance, highlighting when and how move semantics optimize resource management.

**Example file:** `custom_move_benchmark.cpp`

```bash
g++ -std=c++17 custom_move_benchmark.cpp -o custom_move_benchmark
./custom_move_benchmark
```

***

### 7. Compiler Optimizations Example
Compares various compiler optimization flags (`-O0`, `-O1`, `-O2`, `-O3`, `-Ofast`, and `-march=native`) to analyze their impact on runtime performance and efficiency. Also demonstrates how to generate assembly for detailed inspection.

**Example file:** `optimization_benchmark.cpp`

```bash
g++ -std=c++17 -O0 optimization_benchmark.cpp -o bench_O0
./bench_O0

g++ -std=c++17 -O1 optimization_benchmark.cpp -o bench_O1
./bench_O1

g++ -std=c++17 -O2 optimization_benchmark.cpp -o bench_O2
./bench_O2

g++ -std=c++17 -O3 optimization_benchmark.cpp -o bench_O3
./bench_O3

g++ -std=c++17 -Ofast optimization_benchmark.cpp -o bench_Ofast
./bench_Ofast

g++ -std=c++17 -O3 -march=native optimization_benchmark.cpp -o bench_O3_native
./bench_O3_native

# Generate assembly for inspection
g++ -std=c++17 -O3 -march=native -S optimization_benchmark.cpp -o optimization_benchmark_O3_native.s
g++ -std=c++17 -O0 -S optimization_benchmark.cpp -o optimization_benchmark_O0.s
```

***

## Compilation and Execution Commands

All example files can be compiled and executed using `g++` with the C++17 standard support. Replace the example filename as needed.

Basic commands:

```bash
g++ -std=c++17 filename.cpp -o output_executable
./output_executable
```

This setup allows experimental exploration of key C++ concepts with hands-on code and viewing the impacts of compiler settings on performance and behavior.

***