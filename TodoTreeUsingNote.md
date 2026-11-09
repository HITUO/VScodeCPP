# Todo Tree 标签速查

> 适用于 VS Code 插件 **Todo Tree**（Gruntfuggly.todo-tree）
> 只识别 `todo-tree.general.tags` 名单里的词，区分大小写。

## 五个标签

| 标签 | 含义 | 什么时候用 |
|---|---|---|
| `TODO` | 待办：还没做完的事 | `// TODO: 这题要补个 O(n log n) 的解法` |
| `FIXME` | 已知有问题，但暂时没修 | `// FIXME: n=1 时会越界` |
| `BUG` | 确认是 bug（比 FIXME 更严重） | `// BUG: 负数取模结果不对` |
| `HACK` | 临时凑合的写法，将来要重写 | `// HACK: 打表过的，正赛不能用` |
| `NOTE` | 提示/笔记，不是问题 | `// NOTE: 这题卡常，记得开快读` |

## 信奥场景示例

```cpp
// NOTE: 洛谷 P1049 装箱问题 —— 01 背包变形
// TODO: 补上二维 DP → 一维滚动数组的推导过程
// FIXME: 这版对 m = 0 没特判
#include <bits/stdc++.h>
using namespace std;

int main() {
    // HACK: 数据太水，直接暴力能过，但正赛会被卡
    // NOTE: 答案要开 long long，1e18 级别
    return 0;
}
```

## 必需的配置（键名别写错）

```jsonc
{
  // 识别哪些标签
  "todo-tree.general.tags": ["TODO", "FIXME", "BUG", "HACK", "NOTE"],

  // ripgrep 路径（便携版必须手填，注意是两层 .ripgrep）
  "todo-tree.ripgrep.ripgrep": "E:/VSCode-win32-x64-1.145.2/rg.exe",

  // 排除构建产物，避免扫描过慢
  "todo-tree.filtering.useBuiltInExcludes": true,
  "todo-tree.filtering.excludeGlobs": [
    "**/node_modules/**",
    "**/build/**",
    "**/cmake-build*/**",
    "**/.git/**"
  ],

  // 状态栏显示总条数
  "todo-tree.general.statusBar": "total",

  // 导出路径（面板有导出按钮）
  "todo-tree.general.exportPath": "~/Desktop/todo-%Y%m%d.md"
}
```

## 命名规律（容易踩坑）

Todo Tree 的配置几乎都是 `todo-tree.<组>.<项>` **两层结构**：

| 正确 | 错误写法（会变成"未知的设置"） |
|---|---|
| `todo-tree.general.tags` | `todo-tree.tags` |
| `todo-tree.ripgrep.ripgrep` | `todo-tree.ripgrep` |
| `todo-tree.filtering.excludeGlobs` | `todo-tree.excludeGlobs` |

> 插件报错信息里写的 `set 'todo-tree.ripgrep'` 是作者文案笔误，实际键名是 `todo-tree.ripgrep.ripgrep`。

## 面板操作

| 操作 | 效果 |
|---|---|
| 顶部搜索框输入 `TODO` | 只看某一类标签 |
| 点击条目 | 跳到对应文件的那一行 |
| 标题栏过滤图标 | 按标签 / 文件树筛选 |
| 标题栏刷新按钮 | 重新扫描 |
| 右键条目 | 复制路径、侧边打开 |
| 导出按钮 | 生成 Markdown 清单 |

## 使用原则

1. **别贪多**：日常 `TODO` + `NOTE` 就够，`BUG` / `HACK` 只在真需要时用。
2. **区分大小写**：`todo:` 小写不会被识别。
3. **别写在字符串里**：`printf("TODO")` 也会被扫到。
4. **写完就清**：长期不清会变成噪音，面板就没人看了。
5. **比赛前清账**：把 `BUG` / `FIXME` 清零，别把坏模板带进考场。

## 边界说明

Todo Tree **不是任务管理器**：

- 没有优先级、截止日期
- 没有"完成"状态（只能删注释）
- 不跨仓库、不联网同步

定位是：**把散落在代码里的待办聚合成一个面板**。
