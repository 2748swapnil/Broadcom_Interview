#include <iostream>
#include <sstream>
#include <vector>

std::vector<int> splitVersion(const std::string& version)
{
	std::vector<int> result;
	std::stringstream ss(version);
	std::string segment;

	while (std::getline(ss, segment, '.'))
	{
		result.push_back(std::stoi(segment));
	}
	return result;
}

int compareVersion(const std::string& version1, const std::string& version2)
{
	std::vector<int>v1 = splitVersion(version1);
	std::vector<int>v2 = splitVersion(version2);
	
	for (int i = 0; i < std::min(v1.size(), v2.size()); ++i)
	{
		if (v1[i] < v2[i]) return -1;
		if (v1[i] > v2[i]) return 1;
	}

	if (v1.size() < v2.size())
	{
		for (int j = v1.size(); j < v2.size(); ++j)
		{
			if (v2[j] != 0) {
				return -1;
			}
		}
		return 0;
	}
	if (v1.size() > v2.size()) 
	{
		for (int j = v2.size(); j < v1.size(); ++j)
		{
			if (v1[j] != 0) {
				return -1;
			}
		}
		return 0;
	}
	return 0;
}

int main()
{
	std::string version1 = "1.0.1";
	std::string version2 = "1.0.0";

	int result = compareVersion(version1, version2);

	std::cout << "Result : " << result << std::endl;

}