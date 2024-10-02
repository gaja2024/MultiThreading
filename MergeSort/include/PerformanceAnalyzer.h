#pragma once
#include <vector>
#include "PerformanceData.h"
class PerformanceAnalyser
{
public:
	PerformanceAnalyser(const std::vector<PerformanceData>&performanceDataSingleThreaded,
		const std::vector<PerformanceData>&performanceDataMultiThreaded);
};
