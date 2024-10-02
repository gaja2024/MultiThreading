#include "PerformanceData.h"

PerformanceData::PerformanceData()
{

}

PerformanceData::PerformanceData(unsigned int nMatrixFirstRow, unsigned int m_nMatrixFirstCol, unsigned int nMatrixSecondCol,
	std::chrono::duration<double> dDuration):
	m_nMatrixFirstRow(nMatrixFirstRow), m_nMatrixFirstCol(m_nMatrixFirstCol), m_nMatrixSecondCol(nMatrixSecondCol), m_dDuration(dDuration)
{
}


PerformanceData::~PerformanceData()
{
}

