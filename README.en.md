# VSCode C++ Competitive Programming Repository

This is a C++ competitive programming code repository containing rich algorithm templates and solutions for various programming contest problems. It is suitable for algorithm learning, competition training, and interview preparation.

## Project Introduction

This repository collects C++ implementations of various algorithm problems, covering the following main areas:

- **Basic Algorithms**: Fast Exponentiation, Prefix Sums, Difference Arrays, Discretization
- **Data Structures**: Segment Tree, Binary Indexed Tree (BIT/Fenwick Tree), Disjoint Set Union (DSU), Sparse Table
- **Graph Algorithms**: BFS, DFS, Dijkstra, SPFA, Topological Sort
- **String Algorithms**: KMP, Manacher
- **Dynamic Programming**: Knapsack Problems, Longest Increasing Subsequence (LIS), etc.
- **Mathematical Algorithms**: Prime Sieve, Greatest Common Divisor, Base Conversion

## Directory Structure

```
├── 000CodeTemplate.cpp    # Summary of Algorithm Templates
├── ACM1/                  # ACM Competition Practice
│   ├── T1.cpp
│   ├── T2.cpp
│   └── T3.cpp
├── MC04xx/                # Simulation Problem Series
│   ├── MC0401.cpp ~ MC0436.cpp
├── OI1/                   # OI Training Problems
│   ├── T1.cpp ~ T5.cpp
├── Pxxxx/                 # Luogu Problems
│   ├── P1001.cpp
│   ├── P1049.cpp
│   ├── P1060.cpp
│   └── ...
├── Test1/                 # Test Exercises
└── ...
```

## Algorithm Templates (000CodeTemplate.cpp)

The core algorithm templates in the repository include:

| Algorithm | Functionality |
|------|------|
| `qpow` | Fast Exponentiation |
| `buildPrefix` | 1D Prefix Sum |
| `buildPrefix2D` | 2D Prefix Sum |
| `initDiff/addRange` | Difference Array |
| `SparseTable` | Sparse Table RMQ |
| `DSU` | Disjoint Set Union |
| `bfsGrid` | Grid BFS |
| `knap01` | 0/1 Knapsack |
| `LIS` | Longest Increasing Subsequence |
| `topoSort` | Topological Sort |
| `dijkstra` | Shortest Path |
| `spfa` | SPFA Algorithm |
| `nextGreater` | Monotonic Stack |
| `slidingWindowMax` | Sliding Window Maximum |
| `manacher` | Manacher Palindrome Algorithm |
| `kmp` | KMP String Matching |

## Build & Run

### Environment Requirements

- C++ Compiler (g++ 10.0+)
- VSCode (Optional, Recommended)

### Compilation Command

```bash
g++ -std=c++17 -O2 -Wall -o main filename.cpp
```

### Run

```bash
./main < input.txt > output.txt
```

## Problem Classification

### Dynamic Programming
- P1049 - Packing Problem
- P1060 - Happy Jinming
- P1802 - Knapsack Problem
- MC0429 - DP Series

### Graph Theory
- P14540 - Shortest Path
- P15392 - Tree DP
- P1993 - SPFA Negative Cycle Detection
- P2865 - Second Shortest Path

### Data Structures
- ML03313 - Segment Tree Maintenance
- ML03421 - Segment Tree
- ML03755 - Binary Indexed Tree
- MC0417 - BIT Application

## Usage Instructions

1. **Learn Algorithms**: Refer to `000CodeTemplate.cpp` to learn various basic algorithms
2. **Practice Problems**: Select corresponding problems by category in the directories for practice
3. **Competition Prep**: Can be used as a template library for quick reference

## Notes

- Code uses `#define int long long` to extend integer range
- Constant definitions use `kMaxN` to represent maximum array length
- All code is compatible with C++17 standard

## Contribution

Issues and Pull Requests are welcome to improve solutions or add new algorithm templates.

## License

This project is for learning and communication purposes only.