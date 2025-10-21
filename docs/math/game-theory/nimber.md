前置知识：[公平组合游戏](./impartial-game.md)、[抽象代数基本概念](../algebra/basic.md)、[域论](../algebra/field-theory.md)

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

对于 Nim 数 $\alpha,\beta$，可以递归地定义如下加法和乘法运算：

-   Nim 和：$\alpha\oplus\beta = \operatorname{mex}(\{\alpha'\oplus\beta:\alpha' < \alpha\}\cup\{\alpha\oplus\beta':\beta' < \beta\})$。
-   Nim 积：$\alpha\otimes\beta = \operatorname{mex}(\{(\alpha'\otimes\beta)\oplus(\alpha\otimes\beta')\oplus(\alpha'\otimes\beta'):\alpha < \alpha',~\beta < \beta'\})$。

其中，$\operatorname{mex} S$ 表示没有出现在集合 $S$ 中的最小序数。

???+ note "定理"
    全体 Nim 数构成一个特征为 $2$ 的域[^class]，即它对加、减、乘、除（以非零数）封闭，满足加法交换律、加法结合律、乘法交换律、乘法结合律，以及乘法对加法的分配律，而且所有 Nim 数的相反数都是它自身。

??? note "证明"
    注意到，Nim 数的加法和乘法运算都是递归定义的，所以这些性质的证明都需要归纳地给出。归纳起点都是显然的。接下来只需要逐条验证归纳步骤成立。

    为了节省篇幅，证明中将用集合 $\{f(\alpha')\}$ 表示 $\{f(\alpha'):\alpha' < \alpha\}$，而用集合 $\{f(\alpha^*)\}$ 表示

    $$
    \{f(\alpha^*):\exists S(\alpha = \operatorname{mex}S\land\alpha^*\in S)\}.
    $$

    也就是说，集合符号中出现的 $\alpha'$ 默认遍历所有小于 $\alpha$ 的数，$\alpha^*$ 默认遍历所有小于 $\alpha$ 的数以及一部分大于 $\alpha$ 的数（但是不能包含 $\alpha$ 自身）。集合 $\{f(\alpha^*)\}$ 的含义应该从上下文推断出。另外，证明中将用 $(+,\cdot)$ 代替 $(\oplus,\otimes)$，它们遵循正常的运算顺序且乘号经常略去不写。

    Nim 数的加法和乘法定义都是通过撇号给出的。可以证明，它们也可以通过星号给出：

    $$
    \begin{aligned}
    \alpha+\beta &= \operatorname{mex}(\{\alpha^*+\beta\}\cup\{\alpha+\beta^*\}),\\
    \alpha\beta &= \operatorname{mex}(\{\alpha^*\beta+\alpha\beta^*+\alpha^*\beta^*\}).
    \end{aligned}
    $$

    这两条性质的证明将和其他代数性质一同给出。接下来，后面性质的证明可能依赖于前面已证明的性质。

    -   加法的等价定义：将撇号换成星号，只可能扩大 $\operatorname{mex}$ 作用的集合，得到的结果只会更大。要证明得到的结果仍然是 $\alpha+\beta$，只需要证明对于任意 $\alpha^* > \alpha$ 和 $\beta^* > \beta$，都有

        $$
        \alpha+\beta \neq \alpha^*+\beta \text{ or } \alpha+\beta^*.
        $$

        由 $\alpha^*+\beta$ 的定义和 $\alpha < \alpha^*$ 可知，$\alpha^*+\beta \neq \alpha+\beta$ 必然成立；对称地，$\alpha+\beta^*\neq \alpha+\beta$ 也成立。

    -   加法交换律：

        $$
        \alpha+\beta = \operatorname{mex}(\{\alpha'+\beta\}\cup\{\alpha+\beta'\})= \operatorname{mex}(\{\beta'+\alpha\}\cup\{\beta+\alpha'\}) = \beta+\alpha.
        $$

        其中，第二个等号用到了归纳假设，即加法交换律对于 $(\alpha',\beta')\le(\alpha,\beta)$ 且 $(\alpha',\beta')\neq(\alpha,\beta)$ 都成立。下同。

    -   加法结合律：

        $$
        \begin{aligned}
        (\alpha+\beta)+\gamma &= \operatorname{mex}(\{(\alpha+\beta)^*+\gamma\}\cup\{(\alpha+\beta)+\gamma'\}) \\
        &= \operatorname{mex}(\{(\alpha'+\beta)+\gamma\}\cup\{(\alpha+\beta')+\gamma\}\cup\{(\alpha+\beta)+\gamma'\}) \\
        &= \operatorname{mex}(\{\alpha'+(\beta+\gamma)\}\cup\{\alpha+(\beta'+\gamma)\}\cup\{\alpha+(\beta+\gamma')\})\\
        &= \cdots = \alpha+(\beta+\gamma).
        \end{aligned}
        $$

    -   加法单位元：

        $$
        \alpha+ 0 = \operatorname{mex}(\{\alpha'+ 0\}\cup\varnothing) = \operatorname{mex}(\{\alpha'\}) = \alpha.
        $$

    -   加法逆元是它自身：由归纳假设，$\alpha'+\alpha'=0$。所以，由加法结合律可知

        $$
        (\alpha+\alpha')+\alpha' = \alpha+(\alpha'+\alpha') = \alpha.
        $$

        这说明 $\alpha+\alpha'\neq 0$，否则左式等于 $\alpha'$，进而不等于右式。所以，有

        $$
        \alpha+\alpha = \operatorname{mex}(\{\alpha+\alpha'\}) = 0.
        $$

    -   乘法的等价定义：与加法的等价定义类似，只需要证明对于任意 $\alpha < \alpha^*$ 和 $\beta < \beta^*$ 都有

        $$
        \alpha+\beta \neq \alpha^* \beta + \alpha \beta^* + \alpha^* \beta^*.
        $$

        应用加法运算的性质，该式等价于

        $$
        \alpha^* \beta^* \neq \alpha \beta^* + \alpha^* \beta + \alpha \beta.
        $$

        由 $\alpha^* \beta^*$ 的定义可知，这是成立的。

    -   乘法交换律：

        $$
        \alpha \beta = \operatorname{mex}(\{\alpha' \beta + \alpha \beta' + \alpha' \beta'\})= \operatorname{mex}(\{\beta' \alpha+\beta \alpha'+\beta' \alpha'\}) = \beta \alpha.
        $$

    -   乘法对加法的分配律：

        $$
        \begin{aligned}
        (\alpha+\beta) \gamma &= \operatorname{mex}(\{(\alpha+\beta)^* \gamma + (\alpha+\beta) \gamma' + (\alpha+\beta)^* \gamma'\}) \\
        &= \operatorname{mex}(\{(\alpha'+\beta) \gamma+(\alpha+\beta) \gamma'+(\alpha'+\beta) \gamma'\}\\
        &\qquad \qquad\cup \{(\alpha+\beta') \gamma+(\alpha+\beta) \gamma'+(\alpha+\beta') \gamma'\})\\
        &= \operatorname{mex}(\{\alpha' \gamma+\beta \gamma+\alpha \gamma'+\beta \gamma'+\alpha' \gamma'+\beta \gamma'\}\\
        &\qquad \qquad\cup \{\alpha \gamma+\beta' \gamma+\alpha \gamma'+\beta \gamma'+\alpha \gamma'+\beta' \gamma'\})\\
        &= \operatorname{mex}(\{(\alpha' \gamma+\alpha \gamma'+\alpha' \gamma')+\beta \gamma\}\cup \{\alpha\gamma+(\beta' \gamma+\beta \gamma'+\beta' \gamma')\})\\
        &= \operatorname{mex}(\{(\alpha \gamma)^*+\beta \gamma\}\cup\{\alpha \gamma+(\beta \gamma)^*\}) = \alpha \gamma+\beta \gamma.
        \end{aligned}
        $$

    -   乘法结合律：

        $$
        \begin{aligned}
        (\alpha \beta) \gamma &= \operatorname{mex}(\{(\alpha \beta)^* \gamma+(\alpha \beta) \gamma'+(\alpha \beta)^* \gamma'\})\\
        &= \operatorname{mex}(\{(\alpha' \beta+\alpha \beta'+\alpha' \beta') \gamma+(\alpha \beta) \gamma'+(\alpha' \beta+\alpha \beta'+\alpha' \beta') \gamma'\})\\
        &= \operatorname{mex}(\{\alpha' \beta \gamma+\alpha \beta' \gamma+\alpha' \beta' \gamma + \alpha \beta \gamma' + \alpha' \beta \gamma' + \alpha \beta' \gamma' + \alpha' \beta' \gamma'\})\\
        &= \cdots = \alpha (\beta \gamma).
        \end{aligned}
        $$

    -   乘法单位元：因为 $1' = 0$ 且 $\alpha\cdot 0 = \operatorname{mex}(\varnothing) = 0$，所以

        $$
        \alpha\cdot 1 = \operatorname{mex}(\{\alpha'\cdot 1+\alpha\cdot 0+\alpha\cdot 0\}) = \operatorname{mex}(\{\alpha'\}) = \alpha.
        $$

    -   乘法逆元：对 $\alpha \neq 0$，设集合 $S$ 为满足条件

        $$
        0 \in S\land\forall \alpha'\forall\beta^*\left(\beta^*\in S\land 0 < \alpha' < \alpha \implies \dfrac{1 + (\alpha'+\alpha) \beta^*}{\alpha'}\in S\right)
        $$

        的最小集合。那么，$\beta = \operatorname{mex} S$ 就是 $\alpha$ 的逆元。

        集合 $S$ 一定存在。递归地，构造 $S_0=\{0\}$，以及

        $$
        S_n = S_{n-1} \cup \left\{\dfrac{1 + (\alpha'+\alpha) \beta^*}{\alpha'} : 0 < \alpha' < \alpha,~ \beta^*\in S_{n-1}\right\},~n = 1,2,\cdots.
        $$

        那么，只要取 $S = \bigcup_{n\in\mathbf N} S_n$ 就可以得到符合条件的集合。

        进而，$\beta$ 存在。而且，$\beta \neq 0$ 意味着 $\alpha\beta \neq 0$。但是，对于任何 $\alpha' < \alpha$ 和 $\beta^* \in S$ 都成立

        $$
        \alpha'\beta + \alpha\beta^* + \alpha'\beta^* \neq 1.
        $$

        由乘法的等价定义，这说明 $\alpha\beta = 1$。

???+ example "例子"


???+ info "为什么 Nim 数的运算要这样定义？"


而且，全体 Nim 数还是一个代数闭域。

## 参考资料与注释

-   [Nimber - Wikipedia](https://en.wikipedia.org/wiki/Nimber)
-   Conway, John H. On numbers and games. AK Peters/CRC Press, 2000.

[^nim-ord]: 正如下文所说，Nim 数可以定义在任何序数 $\alpha$ 上，所以 Nim 数的严格定义需要用到 [超限递归](https://en.wikipedia.org/wiki/Transfinite_induction)。全体 Nim 数是一个 [真类](https://en.wikipedia.org/wiki/Class_(set_theory))。

[^class]: 除了全体 Nim 数是真类而不是集合这一点外。
