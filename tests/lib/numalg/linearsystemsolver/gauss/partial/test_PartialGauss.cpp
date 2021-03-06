#include <gtest/gtest.h>
#include <linearsystem/LinearSystem.hpp>
#include <linearsystem/size/LinearSystemSize.hpp>
#include <numalg/linearsystemsolver/gauss/partial/PartialGauss.hpp>
#include <matrix/dense/DenseMatrix.hpp>
#include <matrix/size/MatrixSize.hpp>

#define MAX_ERROR 0.0000001


TEST(Numalg_PartialGauss, 1_equation_and_1_variable) {
	LinearSystem<double> system(
		LinearSystemSize(1, 1),
		DenseMatrix<double>(MatrixSize(1, 1), new double[1]{2.5}),
		new double[1]{5.0}
	);
	double* solution = new double[1];
	const Numalg::PartialGauss<double> solver;
	solver.solve(system, solution);
	EXPECT_NEAR(solution[0], 2.0, MAX_ERROR);
}

TEST(Numalg_PartialGauss, 2_equations_and_2_variables) {
	LinearSystem<double> system(
		LinearSystemSize(2, 2),
		// new double[4]{
		// 	-2.0, 1.0,
		// 	5.0, 3.0
		// },
		DenseMatrix<double>(MatrixSize(2, 2), new double[4]{
			-2.0, 1.0,
			5.0, 3.0
		}),
		new double[2]{
			-10.0, 3.0
		}
	);
	double* solution = new double[2];
	const Numalg::PartialGauss<double> solver;
	solver.solve(system, solution);
	EXPECT_NEAR(solution[0], 3.0, MAX_ERROR);
	EXPECT_NEAR(solution[1], -4.0, MAX_ERROR);
}

TEST(Numalg_PartialGauss, 3_equations_and_3_variables) {
	LinearSystem<double> system(
		LinearSystemSize(3, 3),
		// new double[9]{
		// 	-2.0, 3.5, -1.0,
		// 	4.0, 6.0, -10.0,
		// 	3.5, -1.0, 7.5
		// },
		DenseMatrix<double>(MatrixSize(3, 3), new double[9]{
			-2.0, 3.5, -1.0,
			4.0, 6.0, -10.0,
			3.5, -1.0, 7.5
		}),
		new double[3]{
			-28.5, -97.0, 78.25
		}
	);
	double* solution = new double[3];
	// partialGauss(system, solution);
	const Numalg::PartialGauss<double> solver;
	solver.solve(system, solution);
	EXPECT_NEAR(solution[0], 3.0, MAX_ERROR);
	EXPECT_NEAR(solution[1], -4.0, MAX_ERROR);
	EXPECT_NEAR(solution[2], 8.5, MAX_ERROR);
}

TEST(Numalg_PartialGauss, 4_equations_and_4_variables) {
	LinearSystem<double> system(
		LinearSystemSize(4, 4),
		DenseMatrix<double>(MatrixSize(4, 4), new double[16]{
			1.0, 1.0, 3.0, 1.0,
			-5.0, 3.0, -4.0, 1.0,
			1.0, 0.0, 2.0, -1.0,
			1.0, 2.0, 0.0, 0.0
		}),
		new double[4]{2.0, 0.0, 1.0, 12.0}
	);
	double* solution = new double[4];
	const Numalg::PartialGauss<double> solver;
	solver.solve(system, solution);
	EXPECT_NEAR(solution[0], 26.0/7.0, MAX_ERROR);
	EXPECT_NEAR(solution[1], 29.0/7.0, MAX_ERROR);
	EXPECT_NEAR(solution[2], -12.0/7.0, MAX_ERROR);
	EXPECT_NEAR(solution[3], -5.0/7.0, MAX_ERROR);
}
