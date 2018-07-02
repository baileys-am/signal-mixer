#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include "sinusoid.hpp"

BOOST_AUTO_TEST_SUITE(sinusoidTestSuite)

BOOST_AUTO_TEST_CASE(firstSampleIs1With0Offset) {
    // Arrange
    const int sampleCount = 1000;
    auto sinusoid = Sinusoid(40, 1e3, 0);
    double* samples = new double[sampleCount];

    // Act
    sinusoid.Generate(sampleCount, samples);

    // Assert
    BOOST_CHECK_EQUAL(samples[0], 1);

    // Clean up
    delete samples;
}

BOOST_AUTO_TEST_CASE(halfSampleIs0With0Offset) {
    // Arrange
    const int sampleCount = 40000;
    auto sinusoid = Sinusoid(20e3, 40e3, 0);
    double* samples = new double[sampleCount];

    // Act
    sinusoid.Generate(sampleCount, samples);

    // Assert
    BOOST_CHECK_EQUAL(samples[19999], 0);

    // Clean up
    delete samples;
}

BOOST_AUTO_TEST_CASE(lastSampleIsNeg1With0Offset) {
    // Arrange
    const int sampleCount = 40000;
    auto sinusoid = Sinusoid(20e3, 40e3, 0);
    double* samples = new double[sampleCount];

    // Act
    sinusoid.Generate(sampleCount, samples);

    // Assert
    BOOST_CHECK_EQUAL(samples[39999], -1);

    // Clean up
    delete samples;
}

BOOST_AUTO_TEST_SUITE_END()