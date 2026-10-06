# VSCode C++ 竞赛编程代码仓库

这是一个专为竞赛编程设计的 C++ 代码仓库，汇集了丰富的算法模板与各类编程竞赛题目解答。适用于算法学习、竞赛训练和面试准备。

## 项目简介

本仓库收集了多种算法题目的 C++ 实现，涵盖以下主要领域：

- **基础算法**：快速幂、前缀和、差分数组、离散化、质数筛选、最大公约数、进制转换
- **数据结构**：线段树、树状数组、并查集(DSU)、稀疏表、单调栈、滑动窗口
- **图论算法**：BFS、DFS、Dijkstra、SPFA、拓扑排序、次短路径
- **字符串算法**：KMP、Manacher
- **动态规划**：背包问题、最长上升子序列(LIS)、树形DP等

## 目录结构

```
├── 000CodeTemplate.cpp    # 核心算法模板汇总
├── ACM1/                  # ACM竞赛练习
│   ├── T1.cpp ~ T3.cpp
├── MC04xx/                # 模拟题系列
│   ├── MC0401.cpp ~ MC0436.cpp
├── MLxxxx/                # 数据结构专项训练
│   ├── ML03313.cpp        # 线段树（Lazy Propagation）
│   ├── ML03421.cpp        # 线段树基础
│   ├── ML03755.cpp        # 树状数组
│   └── ...
├── OI1/                   # OI训练题
│   ├── T1.cpp ~ T5.cpp
├── OI2/                   # OI进阶题
├── Pxxxx/                 # 洛谷题目
│   ├── P1001.cpp          # A+B Problem
│   ├── P1049.cpp          # 装箱问题
│   ├── P1060.cpp          # 开心的金明
│   ├── P14540.cpp         # 最短路径
│   ├── P1993.cpp          # SPFA检测负环
│   └── ...
├── Test1/                 # 测试练习
└── LICENSE                # 许可证文件
```

## 算法模板 (000CodeTemplate.cpp)

仓库核心算法模板包含以下实现：

| 算法 | 功能描述 |
|------|----------|
| `qpow` | 快速幂运算，支持取模 |
| `buildPrefix` | 一维前缀和构建 |
| `buildPrefix2D` | 二维前缀和构建 |
| `initDiff/addRange/restore1D` | 一维差分数组操作 |
| `initDiff2D/addSubMatrix/restore2D` | 二维差分数组操作 |
| `SparseTable` | 稀疏表 RMQ 查询 |
| `DSU` | 并查集（路径压缩+按秩合并） |
| `bfsGrid` | 网格BFS最短路径 |
| `knap01` | 01背包动态规划 |
| `LIS` | 最长上升子序列 |
| `topoSort` | 拓扑排序 |
| `dijkstra` |  Dijkstra最短路径（堆优化） |
| `spfa` | SPFA算法 |
| `nextGreater` | 单调栈应用 |
| `slidingWindowMax` | 滑动窗口最大值 |
| `manacher` | Manacher回文算法 |
| `kmp` | KMP字符串匹配 |
| `discretize` | 数组离散化 |
| `getPrimes` | 埃拉托斯特尼筛法 |
| `convertBase` | 进制转换 |

## 题目分类

### 动态规划
- P1049 - 装箱问题
- P1060 - 开心的金明
- P1802 - 背包问题
- P1359 - 乒乓球比赛
- P1832 - DP+素数
- MC0429 - DP系列

### 图论
- P14540 - 最短路径（Dijkstra）
- P15392 - 树形DP
- P1993 - SPFA检测负环
- P2865 - 次短路径
- P1203 - 字符串处理

### 数据结构
- ML03313 - 线段树维护（Lazy Propagation）
- ML03421 - 线段树基础
- ML03755 - 树状数组
- MC0417 - 树状数组应用

## 编译运行

### 环境要求

- C++ 编译器 (g++ 10.0+)
- 支持 C++17 标准

### 编译命令

```bash
g++ -std=c++17 -O2 -Wall -o main filename.cpp
```

### 运行

```bash
./main < input.txt > output.txt
```

## 使用说明

1. **学习算法**：参考 `000CodeTemplate.cpp` 学习各类基础算法实现
2. **刷题训练**：按目录分类选择对应题目进行练习
3. **竞赛准备**：可作为模板库在比赛中快速查阅

## 代码规范

- 使用 `#define int long long` 扩展整数范围
- 常量定义使用 `kMaxN` 表示最大数组长度
- 所有代码兼容 C++17 标准

## 贡献

欢迎提交 Issue 和 Pull Request 完善题解或添加新算法模板。

## 许可证

本项目仅供学习交流使用。