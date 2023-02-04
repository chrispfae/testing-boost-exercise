#define BOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include <matrixIO.hpp>

using namespace std;
using namespace Eigen;

struct MatrixFixture {
  MatrixFixture()
  {
    A = MatrixXd(3, 3);
    A << 0.680375, 0.59688, -0.329554,
        -0.211234, 0.823295, 0.536459,
        0.566198, -0.604897, -0.444451;
  }

  MatrixXd A;
};

BOOST_FIXTURE_TEST_SUITE(MatrixIOTests, MatrixFixture, *boost::unit_test::tolerance(1e-12))

BOOST_AUTO_TEST_CASE(openData)
{
  string   filename    = "../data/m3.csv";
  int      matrix_size = 3;
  MatrixXd M           = matrixIO::openData(filename, matrix_size);
  BOOST_TEST(M(0, 0) == A(0, 0));
  BOOST_TEST(M(0, 1) == A(0, 1));
  BOOST_TEST(M(0, 2) == A(0, 2));
  BOOST_TEST(M(1, 0) == A(1, 0));
  BOOST_TEST(M(1, 1) == A(1, 1));
  BOOST_TEST(M(1, 2) == A(1, 2));
  BOOST_TEST(M(2, 0) == A(2, 0));
  BOOST_TEST(M(2, 1) == A(2, 1));
  BOOST_TEST(M(2, 2) == A(2, 2));
}

BOOST_AUTO_TEST_SUITE_END()
