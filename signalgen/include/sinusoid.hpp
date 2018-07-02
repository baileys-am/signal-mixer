/*
    Generates a sinusoid for a given frequency and sample rate.

    @author Steven Cantrell
    @version 1.0.04122018
*/

class Sinusoid
{
    private:
        const double _PI = 3.141592653589793238463;
        double _frequency;
        double _sampleRate;
        double _phase;
        int _currentSample;

    public:
        Sinusoid(double frequency, double sampleRate, double phase);
        void Generate(int sampleCount, double* samples);
};