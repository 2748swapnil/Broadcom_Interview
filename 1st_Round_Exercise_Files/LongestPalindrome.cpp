#include <iostream>
#include <string>

std::string findLongestPalindrome(const std::string& stream)
{
	if (stream.empty())
	{
		return "";
	}
	int maxLength = 1;

	int start = 0;

	for (int i = 0; i < stream.size(); ++i)
	{
		int left = i, right = i;
		while (left >= 0 && right < stream.size() && stream[left] == stream[right])
		{
			if (right - left + 1 > maxLength)
			{
				start = left;
				maxLength = right - left + 1;
			}
			--left;
			++right;
		}

		left = i, right = i + 1;
		while (left >= 0 && right < stream.size() && stream[left] == stream[right])
		{
			if (right - left + 1 > maxLength)
			{
				start = left;
				maxLength = right - left + 1;
			}
			--left;
			++right;
		}
	}

	return stream.substr(start, maxLength);
}

int main()
{
	std::string stream = "baab";
	std::string longestPalindrome = findLongestPalindrome(stream);

	std::cout << "Longest Palindrome in stream : " << longestPalindrome << std::endl;
}