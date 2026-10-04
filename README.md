# VSCode C++ 竞赛编程代码仓库

这是一个 C++ 竞赛编程代码仓库，包含了丰富的算法模板和各类编程竞赛题目解答。适用于算法学习、竞赛训练和面试准备。

## 项目简介

本仓库收集了多种算法题目的 C++ 实现，涵盖以下主要领域：

- **基础算法**：快速幂、前缀和、差分数组、离散化
- **数据结构**：线段树、树状数组、并查集(DSU)、稀疏表
- **图论算法**：BFS、DFS、Dijkstra、SPFA、拓扑排序
- **字符串算法**：KMP、Manacher
- **动态规划**：背包问题、最长上升子序列(LIS)等
- **数学算法**：质数筛选、最大公约数、进制转换

## 目录结构

```
├── 000CodeTemplate.cpp    # 算法模板汇总
├── ACM1/                  # ACM竞赛练习
│   ├── T1.cpp
│   ├── T2.cpp
│   └── T3.cpp
├── MC04xx/                # 模拟题系列
│   ├── MC0401.cpp ~ MC0436.cpp
├── OI1/                   # OI训练题
│   ├── T1.cpp ~ T5.cpp
├── Pxxxx/                 # 洛谷题目
│   ├── P1001.cpp
│   ├── P1049.cpp
│   ├── P1060.cpp
│   └── ...
├── Test1/                 # 测试练习
└── ...
```

## 算法模板 (000CodeTemplate.cpp)

仓库核心算法模板包括：

| 算法 | 功能 |
|------|------|
| `qpow` | 快速幂运算 |
| `buildPrefix` | 一维前缀和 |
| `buildPrefix2D` | 二维前缀和 |
| `initDiff/addRange` | 差分数组 |
| `SparseTable` | 稀疏表 RMQ |
| `DSU` | 并查集 |
| `bfsGrid` | 网格BFS |
| `knap01` | 01背包 |
| `LIS` | 最长上升子序列 |
| `topoSort` | 拓扑排序 |
| `dijkstra` | 最短路径 |
| `spfa` | SPFA算法 |
| `nextGreater` | 单调栈 |
| `slidingWindowMax` | 滑动窗口最大值 |
| `manacher` | Manacher回文算法 |
| `kmp` | KMP字符串匹配 |

## 编译运行

### 环境要求

- C++ 编译器 (g++ 10.0+)
- VSCode (可选，推荐使用)

### 编译命令

```bash
g++ -std=c++17 -O2 -Wall -o main filename.cpp
```

### 运行

```bash
./main < input.txt > output.txt
```

## 题目分类

### 动态规划
- P1049 - 装箱问题
- P1060 - 开心的金明
- P1802 - 背包问题
- MC0429 - DP系列

### 图论
- P14540 - 最短路径
- P15392 - 树形DP
- P1993 - SPFA检测负环
- P2865 - 次短路径

### 数据结构
- ML03313 - 线段树维护
- ML03421 - 线段树
- ML03755 - 树状数组
- MC0417 - 树状数组应用

## 使用说明

1. **学习算法**：参考 `000CodeTemplate.cpp` 学习各类基础算法
2. **刷题训练**：按目录分类选择对应题目进行练习
3. **竞赛准备**：可以作为模板库快速查阅

## 注意事项

- 代码使用 `#define int long long` 扩展整数范围
- 常量定义使用 `kMaxN` 表示最大数组长度
- 所有代码兼容 C++17 标准

## 贡献

欢迎提交 Issue 和 Pull Request 完善题解或添加新算法模板。

## 许可证

本项目仅供学习交流使用。
