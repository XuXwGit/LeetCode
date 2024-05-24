/*
3. 最优索引选择
某项目组打算使用建立索引方法提升数据库系统的性能。

已知当前数据库系统存在N个表，并且已经通过实际业务workload测试，得到了各个表进行索引的实用值（收益），以及索引的空间开销。

我们把索引分成若干个索引组，所有索引组构成一个树型结构，每个索引组作为树的一个节点。并且挑选索引时有以下两个约束：

1、父子依赖：当从某个索引组节点中挑选索引，则需要保证其父节点至少存在一个索引已经被挑选。题目保证树的正确性，并且保证父节点的组编号，小于子节点的组编号。

2、路径互斥：不同路径上的索引组存在互斥。当挑选了某个路径上的索引，则不能挑选其他不在该路径上的索引。

如下图，根据父子依赖约束，假设挑选组路径为[0，1，3］，当挑选组3里面的索引，需要保证组1里至少有一个索引已被挑选，同样需要保证组0里至少有一个索引已经被挑选。然后根据路径互斥约束，组3和组2不在同一个路径里，挑选了组3里面的索引，则不能再挑选组2里面的索引。

请根据每个表的索引的实用值、空间开销、组的依赖关系和组的互斥关系，选择若干个索引，保证所选的索引总空间开销不超过给定的空间闽值 B 的前提下，使得总实用值最大，并输出这个最大值。

解答要求

时间限制: C/C++ 2000ms,其他语言: 4000ms内存限制: C/C++ 256MB, 其他语言: 512MB

输入：

第一行3个整数（单空格间隔），依次表示：空间阈值B [1,5000］、表索引的数量N [1,10000］，和分组数量M[1,100]（组编号从0开始依次递增）。

第二行至第N+1行每行3个整数（单空格间隔），依次表示每个表索引的组编号、实用值和空间开销。

第N+2行M个整数（单空格间隔），从组0开始依次为每个组的父组编号；若值为-1，表示无父（该组即为根节点）。

输出

第一行：输出最大的总实用值

示例 1：

输入：

40 4 2
0 10 10
1 30 10
0 5 20
1 60 40
-1 0
输出：

45
*/