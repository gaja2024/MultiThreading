#include "PerformanceData.h"

PerformanceData::PerformanceData()
{

}

PerformanceData::PerformanceData(size_t nDataSize, std::chrono::duration<double> dDuration) :
	m_nDataSize(nDataSize), m_dDuration(dDuration)
{
}

