#pragma once
#include <chrono>
class PerformanceData
{
public:
	PerformanceData(size_t nDataSize,std::chrono::duration<double> dDuration);
	PerformanceData();
	size_t GetDataSize() const { return m_nDataSize; }
	std::chrono::duration<double> GetTimeDuration() const { return m_dDuration; }
private:
	size_t m_nDataSize;
	std::chrono::duration<double> m_dDuration;
};
