#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <stack>

bool is_even(const int x)
{
	return x % 2 == 0;
}

void print_vector(const std::vector<int>& v)
{
	printf("%i", v[0]);
	for (int i = 1; i < v.size(); ++i)
		printf(", %i", v[i]);
}

// a refaire avec les bornes
// a refaire avec le step
int find_index(const std::vector<int>& nums, const int value)
{
	if (nums.size() <= 0 || value > nums[nums.size() - 1])
		return -1;

	int step = nums.size() / 4;
	step += step == 0 ? 1 : 0;
	int index = nums.size() / 2;
	while (step >= 0)
	{
		printf("-");

		if (nums[index] == value)
		{
			return index;
		}
		else
		{
			index += step * (nums[index] < value ? 1 : -1);
			step = (step / 2) + is_even(step / 2) ? 1 : 0;
		}
	}

	return -1;
}

// a refaire avec un seul parcours de tableau (et un seul tableau)
int remove_duplicates(std::vector<int>& nums)
{
	if (nums.size() <= 0)
		return -1;

	std::vector<int> temp(nums.size());
	int x = std::numeric_limits<int>::min();
	int uniqueCount = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		printf("-");

		if (x != nums[i])
		{
			temp[uniqueCount] = nums[i];
			x = temp[uniqueCount];
			++uniqueCount;
		}
	}

	nums.assign(&temp[0], &temp[0] + temp.size());
	return uniqueCount;
}

// a refaire avec une map
std::vector<int> two_sum(const std::vector<int>& nums, const int target)
{
	int x = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		x = nums[i];
		if (x >= target)
			continue;
		int y = target - x;
		int index = find_index(nums, y);
		if (index != -1)
			return { x, y };
	}

	return { -1, -1 };
}

bool is_string_valid(const std::string& str)
{
	std::stack<char> stack;
	std::string_view view = str;
	for (int i = 0; i < view.size(); ++i)
	{
		if (view[i] == '(' || view[i] == '[' || view[i] == '{')
		{
			stack.push(view[i]);
		}
		else
		{
			if (stack.empty())
				return false;

			if (view[i] == ')' && stack.top() == '(')
				stack.pop();
			else if (view[i] == ']' && stack.top() == '[')
				stack.pop();
			else if (view[i] == '}' && stack.top() == '{')
				stack.pop();
		}

	}

	return stack.empty();
}

struct ListNode
{

};

ListNode* merge_two_lists()
{
	throw;
}

int length_of_longest_substring()
{
	throw;
}

void quick_sort_rotate(std::vector<int>& arr)
{
	int last = arr.size() - 1;
	int pivotIndex = last;
	int pivot = arr[pivotIndex];

	for (int i = 0; i < last; ++i)
	{
		if (arr[i] > pivot)
		{
			std::rotate(arr.begin() + i, arr.begin() + i + 1, arr.end());
			--i;
			--pivotIndex;
			--last;
		}
	}

	// TODO : recursive
}

void quick_sort(std::vector<int>& arr, int begin = -1, int end = -1)
{
	int last = end < 0 ? arr.size() - 1 : end - 1;

	int p = last;
	int pivot = arr[p];
	int j = begin < 0 ? 0 : begin;
	for (int i = begin < 0 ? 0 : begin; i < last; ++i)
	{
		if (arr[i] <= pivot)
			std::swap(arr[j++], arr[i]);
	}
	std::swap(arr[p], arr[j]);
	p = j;

	if (p == last)
		return;

	if (p > 0)
		quick_sort(arr, 0, p);
	if (p > 0 || last > 0)
		quick_sort(arr, p + 1, last + 1);
}

int vector_elements_sum(std::vector<int>& v)
{
	int result = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		result += v[i];
	}
	return result;
}

std::vector<int> merge_array(std::vector<int>& arr1, std::vector<int>& arr2)
{
	std::vector<int> out;
	out.resize(arr1.size() + arr2.size());

	int i = 0, j = 0, k = 0;
	while (i < arr1.size() && j < arr2.size())
	{
		out[k++] = std::min(arr1[i], arr2[j]);
	}
	while (i < arr1.size())
	{
		out[k++] = arr1[i];
	}
	while (j < arr2.size())
	{
		out[k++] = arr2[j];
	}

	return out;
}

void merge_sort(std::vector<int>& arr, int start = -1, int end = -1)
{
	start = start < 0 ? 0 : start;
	end = end < 0 ? arr.size() : end;
	if (start < end)
	{
		int half = (start + end) / 2;
		merge_sort(arr, start, half);
		merge_sort(arr, half + 1, end);
		std::vector<int>::iterator it1 = arr.begin() + start;
		std::vector<int>::iterator it2 = arr.begin() + end;
		std::vector<int> left, right;
		left.assign(it1, it1 + half);
		right.assign(it1 + half, it2);
		auto out = merge_array(left, right);

		for (int i = 0; i < out.size(); ++i)
		{
			arr[start + i] = out[i];
		}
	}
}

float closest_distance()
{
	throw;
}

void quick_hull()
{

}

int main()
{
	//{
	//	std::vector<int> nums = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	//	std::cout << find_index(nums, 0) << std::endl;
	//	std::cout << find_index(nums, 1) << std::endl;
	//	std::cout << find_index(nums, 2) << std::endl;
	//	std::cout << find_index(nums, 3) << std::endl;
	//	std::cout << find_index(nums, 4) << std::endl;
	//	std::cout << find_index(nums, 5) << std::endl;
	//	std::cout << find_index(nums, 6) << std::endl;
	//	std::cout << find_index(nums, 7) << std::endl;
	//	std::cout << find_index(nums, 8) << std::endl;
	//	std::cout << find_index(nums, 9) << std::endl;
	//	std::cout << find_index(nums, 10) << std::endl;
	//	std::cout << find_index(nums, 11) << std::endl;
	//	std::cout << find_index(nums, 12) << std::endl;
	//	std::cout << find_index(nums, 13) << std::endl;
	//	std::cout << find_index(nums, 14) << std::endl;
	//	std::cout << find_index(nums, 15) << std::endl;
	//}
	//{
	//	std::vector<int> nums = { 0,0,1,1,1,2,3,4,5,5,6 };
	//	std::cout << remove_duplicates(nums) << std::endl;
	//}
	//{
	//	std::vector<int> nums = { 1, 5, 2, 7, 11, 15 };
	//	print_vector(two_sum(nums, 9));
	//}
	//{
	//	std::cout << is_string_valid("()()()()") << std::endl;
	//}
	{
		std::vector<int> nums = { 7, -2, 4, 1, 6, 5, 0, -4, 2 };
		//quick_sort(nums);
		merge_sort(nums);
	}

	return 0;
}