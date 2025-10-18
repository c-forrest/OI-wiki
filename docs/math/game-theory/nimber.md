前置知识：[公平组合游戏](./impartial-game.md)

本文介绍 Nim 数的性质和计算。

## 概念

正如 Sprague–Grundy 理论所指出的那样，每一个 Nim 数都描述一个公平组合游戏。第 $\alpha$ 个 Nim 数定义[^nim-ord]为

$$
\ast\alpha = \{\ast\beta : \beta < \alpha\}.
$$

局面 $\ast\alpha$ 的全体后继状态就是所有序号排在它前面的局面，即所有满足 $\beta < \alpha$ 的局面 $\ast\beta$。

式子中的 $\alpha$ 不只可以是一般的自然数 $n\in\mathbf N$，也可以是任何 [序数](https://en.wikipedia.org/wiki/Ordinal_number) $\alpha$，包括那些无穷大的序数。例如，第 $\omega$ 个 Nim 数

$$
\ast\omega = \{\ast 0, \ast 1, \ast 2,\cdots, \ast n,\cdots\}
$$

表示从局面 $\ast\omega$ 出发，可以到达任何有限局面 $\ast n$。在公平组合游戏页面已经说明，有限 Nim 数 $*n$ 描述石子数量为 $n$ 的单堆 Nim 游戏。为了理解 $\ast\omega$ 的含义，可以考虑一个无穷大的石子堆，且每次取石子总是将石子数量缩小到有限值。这样就得到一个后继状态为所有 $\ast n~(n\in\mathbf N)$ 的游戏局面，这就是 $\ast\omega$ 的含义。下一个 Nim 数

$$
*(\omega+1) = \{\ast 0,\ast 1,\ast 2,\cdots,\ast n,\cdots,\ast\omega\}
$$

可以理解为一个刚刚那样的无穷大石子堆，再加上一枚额外的石子。取石子时，在从无穷大石子堆取石子之前，总是要求先取走那枚额外的石子；但是，可以只取走这枚额外的石子，而不从无穷大石子堆内取走任何石子。

或者，可以设想一架下端有限、而向上无限延伸的梯子。每一格梯子都对应一个可以下降的台阶。每次移动时，都可以向下走任意多步，只要最终停留在某一格上。这一梯子就代表 $\ast\omega$ 的局面：从这个无限高的梯子顶端出发，可以落到任何有限高度。将两个这样的梯子上下架到一起，从上面那个梯子的下数第一格出发，得到的局面就是 $\ast(\omega+1)$。进一步地，如果从上面那个梯子的顶端出发，就得到局面 $\ast(\omega+\omega) = \ast(\omega\cdot 2)$。进一步地，如果有无穷多架梯子首尾相连地叠到一起，那么这些梯子的最顶端就对应局面 $\ast(\omega\cdot\omega)=\ast(\omega^2)$。如果再向上一格，就得到局面 $*(\omega^2+1)$。其他局面的含义可以依此类推。

???+ info "记号"
    在不引起混淆时，本文将省略星号记号，直接用对应的序数 $\alpha$ 表示 Nim 数 $\ast\alpha$。

## 代数性质

尽管 Nim 数 $\alpha$ 的集合表示和它对应的序数 $\alpha$ 一致，但是它们的运算并不相同，代数性质也并不一致。本节介绍 Nim 数的运算和代数性质。

对于 Nim 数 $\alpha,\beta$，可以定义如下加法和乘法运算：

-   Nim 和：$\alpha\oplus\beta = \operatorname{mex}(\{\alpha'\oplus\beta:\alpha' < \alpha\}\cup\{\alpha\oplus\beta':\beta' < \beta\})$。
-   Nim 积：$\alpha\otimes\beta = \operatorname{mex}(\{(\alpha'\otimes\beta)\oplus(\alpha\otimes\beta')\oplus(\alpha'\otimes\beta'):\alpha < \alpha',~\beta < \beta'\})$。

其中，$\operatorname{mex} S$ 表示没有出现在集合 $S$ 中的最小序数。


## 参考资料与注释

-   [Nimber - Wikipedia](https://en.wikipedia.org/wiki/Nimber)

[^nim-ord]: 正如下文所说，Nim 数可以定义在任何序数 $\alpha$ 上，所以 Nim 数的严格定义需要用到 [超限递归](https://en.wikipedia.org/wiki/Transfinite_induction)。全体 Nim 数是一个 [真类](https://en.wikipedia.org/wiki/Class_(set_theory))。
