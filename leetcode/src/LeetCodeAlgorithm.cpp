#include <map>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include "LeetCodeAlgorithm.h"

// 9.�жϻ�����
bool lzy::isPalindrome(int x) {
	if (x < 0) return false;

	std::string s = std::to_string(x);
	std::string::const_iterator cEnd = s.cend() - 1;
	std::string::const_iterator cBegin = s.cbegin();

	while (1) {
		if (*cEnd != *cBegin) {
			return false;
		}
		else if ((cEnd == cBegin) || (cBegin == cEnd - 1)) {
			return true;
		}
		cBegin++;
		cEnd--;
	}

	return true;
}

// 1.����֮��
std::vector<int> lzy::twoSum(std::vector<int>& nums, int target) {
	std::vector<int> numsCopy = nums;
	std::sort(numsCopy.begin(), numsCopy.end());		// ����

	for (int begin = 0; begin < nums.size(); begin++) {
		for (int end = nums.size() - 1; end > -1; end--) {
			int sum = numsCopy[begin] + numsCopy[end];
			if (sum < target) {
				break;
			}
			else if (sum == target) {
				typedef std::vector<int>::const_iterator cIt;
				cIt pos1 = std::find(nums.cbegin(), nums.cend(), numsCopy[begin]);
				cIt pos2 = std::find(nums.cbegin(), nums.cend(), numsCopy[end]);
				if (pos1 == pos2) {
					pos2 = std::find(pos2 + 1, nums.cend(), numsCopy[end]);
				}
				int res1 = static_cast<int>(pos1 - nums.cbegin());
				int res2 = static_cast<int>(pos2 - nums.cbegin());
				return { res1, res2 };
			}
		}
	}
	return { 0 };
}

// 55.��Ծ��Ϸ
bool lzy::canJump(std::vector<int>& nums) {
	typedef std::vector<int> vecInt;

	// ����Ϊ1ֱ�ӵ������true��
	vecInt::size_type count = nums.size();
	if (count == 1) {
		return true;
	}

	// ���ñ���¼ ÿ���ڵ�ֻ��һ��
	// ֵΪ0��ʾû���߹� ֵΪ1��ʾ�߹�
	vecInt memories(count);

	// ��ĩβ�ڵ�ѹջ
	std::stack<int> al;
	al.push(count - 1);

	// �𲽳�ջ����
	while (!al.empty()) {
		al.pop();
		int point = al.top();
		memories[point] = 1;

		if (point == 0) {
			return true;
		}

		for (int prePoint = point - 1; prePoint > -1; prePoint--) {
			if (nums[prePoint] + prePoint >= point && memories[prePoint] == 0) {
				al.push(prePoint);
			}
		}
	}
	return false;
}

// 62.��ͬ·��
int lzy::uniquePaths(int m, int n) {
	typedef std::vector<std::vector<int>> vecInt;

	if (m == 0 || n == 0) {
		return m + n;
	}

	// ӳ�� (x, y) -> paths 
	vecInt paths(m);
	for (auto& vec : paths) {
		vec.resize(n);
	}

	// ��ʼ��·����
	for (int x = 0; x < m; x++) {
		paths[x][0] = 1;
	}
	for (int y = 0; y < n; y++) {
		paths[0][y] = 1;
	}

	// ���㵽�����·����
	for (int x = 1; x < m; x++) {
		for (int y = 1; y < n; y++) {
			if (paths[x][y] == 0) {
				paths[x][y] = paths[x - 1][y] + paths[x][y - 1];
			}
		}
	}

	return paths[m - 1][n - 1];
}

// 12.����ת��������
std::string lzy::intToRoman(int num) {
	typedef std::unordered_map<int, std::string> romanString;

	// �����ַ�
	romanString romans{ {1, "I"}, {4, "IV"}, {5, "V" }, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"},
	{400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"} };


	std::string res;	// ���
	std::string numStr = std::to_string(num);
	int count = numStr.size();	// λ��
	for (int i = 0; i < count; i++) {
		int multiplier = pow(10, (count - 1 - i));
		int posInt = std::stoi(numStr.substr(i, 1));
		int posNum = posInt * multiplier;
		romanString::const_iterator it = romans.find(posNum);
		// �Ƿ��Ѽ�¼�����ַ�
		if (it != romans.cend()) {
			res += it->second;	// ƴ��
		}
		else {
			std::string part;
			// ����5��Ҫ�Ȼ�ȡ5
			if (posInt > 5) {
				part = romans.at(5 * multiplier);
				for (int i = 0; i < posInt - 5; i++) {
					part += romans.at(multiplier);
				}
			}
			else {
				for (int i = 0; i < posInt; i++) {
					part += romans.at(multiplier);
				}
			}
			res += part;
		};
	}
	return res;
}

// 12.����ת�������֣�̰�ģ�
std::string lzy::intToRoman1(int num) {
	typedef std::vector<int> intVec;
	typedef std::vector<std::string> stringVec;

	intVec nums{ 1, 4, 5, 9,10, 40, 50, 90, 100, 400, 500, 900, 1000 };
	stringVec romans{ "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };

	std::string res;
	int index = nums.size() - 1;
	while (num > 0) {
		int posNum = nums.at(index);
		if (posNum <= num) {
			int count = num / posNum;
			for (int i = 0; i < count; i++) {
				num -= posNum;
				res += romans.at(index);
			}
		}
		index--;
	}

	return res;
}

// 27.�Ƴ�Ԫ��
int lzy::removeElement(std::vector<int>& nums, int val) {
	int pos = 0;
	for (int index = 0; index < nums.size(); index++) {
		if (nums[index] != val) {
			nums[pos++] = nums[index];
		}
	}

	return pos;
}

// 48.��תͼ��
void lzy::rotate(std::vector<std::vector<int>>& matrix) {
	int temp = 0;	// ���汻�滻����
	size_t length = matrix.size();

	// ����Գƾ���
	for (int x = 1; x < length; x++) {
		for (int y = 0; y < x; y++) {
			temp = matrix[x][y];
			matrix[x][y] = matrix[y][x];
			matrix[y][x] = temp;
		}
	}

	// ˮƽ�Գƾ���
	for (int x = 0; x < length; x++) {
		for (int y = 0; y < length / 2; y++) {
			temp = matrix[x][length - 1 - y];
			matrix[x][length - 1 - y] = matrix[x][y];
			matrix[x][y] = temp;
		}
	}
}

// 39.����ܺ�
void combinationSumDFS(const std::vector<int>& candidates, std::vector<int>& path, std::vector<std::vector<int>>& res, int start, int end, int sum, int target) {
	for (int index = start; index < end; index++) {
		int finalSum = sum + candidates.at(index);
		path.push_back(candidates.at(index));
		if (finalSum < target) {
			combinationSumDFS(candidates, path, res, index, end, finalSum, target);
		}
		else if (finalSum > target) {
			path.pop_back();
			return;
		}
		else {
			res.push_back(path);
			path.pop_back();
			return;
		}
		path.pop_back();
	}
}

std::vector<std::vector<int>> lzy::combinationSum(std::vector<int>& candidates, int target) {
	typedef std::vector<int> vecInt;

	std::sort(candidates.begin(), candidates.end());	// ����

	// Ѱ�ҵ�һ������Ŀ�����ļ���������Ϊ��������
	vecInt::const_iterator it = std::find_if(candidates.cbegin(), candidates.cend(), [target](int x)->bool { return x > target; });
	int end = it - candidates.cbegin();

	vecInt path;
	std::vector<vecInt> res;
	combinationSumDFS(candidates, path, res, 0, end, 0, target);

	return res;
}

// 70.��¥��
int lzy::climbStairs(int n) {
	std::vector<int> climbCount;

	climbCount.push_back(1);
	climbCount.push_back(2);

	if (n <= 2) {
		return climbCount.at(n - 1);
	}

	for (int i = 2; i < n; i++) {
		climbCount.push_back(climbCount.at(i - 1) + climbCount.at(i - 2));
	}
	return climbCount.at(n - 1);
}

// 17.�绰�������ĸ���
void letterCombinationsDFS(std::string& digits, int index, std::vector<std::string>& res, std::string& path) {
	if (index == digits.size()) {
		res.push_back(path);
		return;
	}

	int num = digits.at(index) - '0';	// ��ȡ��ǰ����

	// ��ȡҪ��������ĸ��ʼ����
	int wordIndex = 0;
	if (num < 7) {
		wordIndex = (num - 2) * 3;
	}
	else if (num == 7) {
		wordIndex = 'p' - 'a';
	}
	else if (num == 8) {
		wordIndex = 't' - 'a';
	}
	else {
		wordIndex = 'w' - 'a';
	}

	for (int start = 0; start < (num == 9 || num == 7 ? 4 : 3); start++) {
		char word = 'a' + wordIndex + start;
		path.push_back(word);
		letterCombinationsDFS(digits, index + 1, res, path);
		path.pop_back();
	}

}

std::vector<std::string> lzy::letterCombinations(std::string digits) {
	std::string path;				// ����·��
	std::vector<std::string> res;	// ������

	if (digits.size() == 0) {
		return res;
	}

	letterCombinationsDFS(digits, 0, res, path);

	return res;
}

// 73.��������
void lzy::setZeroes(std::vector<std::vector<int>>& matrix) {
	std::unordered_set<int> colSet;
	std::unordered_set<int> rowSet;

	for (int col = 0; col < matrix.size(); col++) {
		for (int row = 0; row < matrix[0].size(); row++) {
			if (matrix[col][row] == 0) {
				colSet.insert(col);
				rowSet.insert(row);
			}
		}
	}

	if (colSet.empty()) {
		return;
	}

	for (auto col : colSet) {
		for (int row = 0; row < matrix[0].size(); row++) {
			matrix[col][row] = 0;
		}
	}

	for (auto row : rowSet) {
		for (int col = 0; col < matrix.size(); col++) {
			matrix[col][row] = 0;
		}
	}
}

