/* 问题：
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
*/
/*
题意：一个m x n 的网格，每个格子里有一个非负整数，找到一条从左上角到右下角的路径，使其经过的格子数值之和最小，每一步只能向右或向下。

分析：这是一道典型的动态规划题，使用动态规划求解问题，最重要的就是确定动态规划三要素：问题的阶段,每个阶段的状态以及从前一个阶段转化到后一个阶段之间的递推关系。递推关系必须是从次小的问题开始到较大的问题之间的转化，
从这个角度来说，动态规划往往可以用递归程序来实现，不过因为递推可以充分利用前面保存的子问题的解来减少重复计算，所以对于大规模问题来说，有递归不可比拟的优势，这也是动态规划算法的核心之处。确定了动态规划的这三要素，
整个求解过程就可以用一个最优决策表来描述，最优决策表是一个二维表，其中行表示决策的阶段，列表示问题状态，表格需要填写的数据一般对应此问题的在某个阶段某个状态下的最优值（如最短路径，最长公共子序列，最大价值等），填
表的过程就是根据递推关系，从1行1列开始，以行或者列优先的顺序，依次填写表格，最后根据整个表格的数据通过简单的取舍或者运算求得问题的最优解。

本题我们首先可以找出递推关系，比如设存放起点到每个格子 i，j 的最小路径和的二维数组为 MPS[i][j]，那么递推公式为：

MPS[i][j] = Min（MPS[i-1][j]，MPS[i][j-1]）+ val[i][j]；
即格子 i，j 的MPS值可能有两个来源：其左侧格子 i，j-1 或者其上侧格子 i-1，j ；取这两个来源的较小MPS值，再加上当前格子的值 val[i][j] 即为结果。

由于是从左上方向右下方走，故我们可以利用一个双重循环来进行迭代计算，外层循环以行为单位，内层循环以列为单位，这样可以利用已经计算好的阶段 、状态来计算当前格子的结果，因为每次计算某个格子时，其左侧格子和上侧格子结果
已经算好，这也是动态规划比递归要快的原因。

设N为格子总数（N=m*n），上面的代码空间复杂度为O(N)，时间复杂度为O(N)；如果可以直接改变grid的值的话，就无需申请新的数组空间，但是通常我们不能修改grid的值。
*/
class Solution {
public:
	int minPathSum(vector<vector<int>> &grid) {
		if (grid.size() == 0)
			return 0;
		vector<vector<int>> res(grid);
		int i, j;
		for (int j = 1; j < res[0].size(); ++j) {
			res[0][j] += res[0][j - 1];
		}
		for (int j = 1; j < res.size(); ++j) {
			res[j][0] += res[j - 1][0];
		}
		for (int i = 1; i < res.size(); ++i) {
			for (int j = 1; j < res[i].size(); ++j) {
				res[i][j] = min(res[i - 1][j], res[i][j - 1]) + grid[i][j];
			}
		}
		return res[grid.size() - 1][grid[0].size() - 1];
	}
};