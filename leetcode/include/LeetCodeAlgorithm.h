#pragma once
#ifndef _LEETCODEALGORITHM_H_
#define _LEETCODEALGORITHM_H_
#include <vector>
#include <string>

namespace lzy {
	bool isPalindrome(int x);		// 9.�жϻ�����

	std::vector<int> twoSum(std::vector<int>& nums, int target);		// 1.����֮��

	bool canJump(std::vector<int>& nums);	// 55.��Ծ��Ϸ

	int uniquePaths(int m, int n);			// 62.��ͬ·��

	std::string intToRoman(int num);		// 12.����ת��������

	std::string intToRoman1(int num);		// 12.����ת�������֣�̰�ģ�

	int removeElement(std::vector<int>& nums, int val);		// 27.�Ƴ�Ԫ��

	void rotate(std::vector<std::vector<int>>& matrix);		// 48.��תͼ��

	std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target);		// 39.����ܺ�

	int climbStairs(int n);		// 70.��¥��

	std::vector<std::string> letterCombinations(std::string digits);	// 17.�绰�������ĸ���

	void setZeroes(std::vector<std::vector<int>>& matrix);		// 73.��������
}
#endif // !_LEETCODEALGORITHM_H_


