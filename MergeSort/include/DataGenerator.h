#pragma once
#include <vector>
#include <cstdlib>
#include <string>
class DataGenerator
{
public:
	DataGenerator();
	std::vector<std::vector<int>> GetDataList();
private:
	std::vector<std::vector<int>>m_DataList;
	void GenerateData(std::vector<int>& data, const unsigned int nSize, std::string strDataFile);
};

