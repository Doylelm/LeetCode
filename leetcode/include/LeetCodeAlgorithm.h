#pragma once
#ifndef _LEETCODEALGORITHM_H_
#define _LEETCODEALGORITHM_H_
#include <vector>
#include <string>

namespace lzy {
	bool isPalindrome(int x);		// 9.判断回文数

	std::vector<int> twoSum(std::vector<int>& nums, int target);		// 1.两数之和

	bool canJump(std::vector<int>& nums);	// 55.跳跃游戏

	int uniquePaths(int m, int n);			// 62.不同路径

	std::string intToRoman(int num);		// 12.整数转罗马数字

	std::string intToRoman1(int num);		// 12.整数转罗马数字（贪心）

	int removeElement(std::vector<int>& nums, int val);		// 27.移除元素

	void rotate(std::vector<std::vector<int>>& matrix);		// 48.旋转图像

	std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target);		// 39.组合总和

	int climbStairs(int n);		// 70.爬楼梯

	std::vector<std::string> letterCombinations(std::string digits);	// 17.电话号码的字母组合

	void setZeroes(std::vector<std::vector<int>>& matrix);		// 73.矩阵置零
}
#endif // !_LEETCODEALGORITHM_H_


