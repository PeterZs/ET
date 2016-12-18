#ifndef LINEAR_ALG_H
#define LINEAR_ALG_H

#include<iostream>
#include<Eigen/Core>
#include<Eigen/SVD>

namespace util
{

	template<typename _Matrix_Type_>
	_Matrix_Type_ pseudoInverse(const _Matrix_Type_ &a, double epsilon = std::numeric_limits<double>::epsilon())
	{
		Eigen::JacobiSVD< _Matrix_Type_ > svd(a ,Eigen::ComputeThinU | Eigen::ComputeThinV);
		double tolerance = epsilon * std::max(a.cols(), a.rows()) *svd.singularValues().array().abs()(0);
		return svd.matrixV() * (
			svd.singularValues().array().abs() > tolerance
			).select(
			svd.singularValues().array().inverse(), 0
			).matrix().asDiagonal() * svd.matrixU().adjoint();
	}

}
#endif