/*
    @author Steven Cantrell
    @version 1.0.04122018
*/

#include "sinusoid.hpp"
#include <math.h>

Sinusoid::Sinusoid(double frequency, double sampleRate, double phase)
{
    this->_frequency = frequency;
    this->_sampleRate = sampleRate;
    this->_phase = phase;

    this->_currentSample = 0;
}

void Sinusoid::Generate(int sampleCount, double* samples)
{
    for (int i = 0; i < sampleCount; i = i + 1) {
        if (this->_currentSample >= this->_sampleRate)
        {
            this->_currentSample = 0;
        }

        // Generate sample
        samples[i] = cos(2 * this->_PI * this->_frequency * this->_currentSample / this->_sampleRate + this->_phase);

        // Increment running sample
        this->_currentSample++;
    }
}