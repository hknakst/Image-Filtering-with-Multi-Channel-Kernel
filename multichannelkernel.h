#ifndef MULTICHANNELKERNEL_H
#define MULTICHANNELKERNEL_H
#include <iostream>
using namespace std;

typedef unsigned char BYTE;

class MultiChannelKernel
{
private:
    unsigned int kernelSize=3;
    double *redKernel;
    double *greenKernel;
    double *blueKernel;
    double redKernelCoefficient;
    double greenKernelCoefficient;
    double blueKernelCoefficient;
public:
    MultiChannelKernel();
    ~MultiChannelKernel();
    MultiChannelKernel(double *redKernel, double *greenKernel, double *blueKernel);
    void setMultiChannelKernel( double *redKernel, double *greenKernel, double *blueKernel);
    void setKernelCoefficients(double redKernelCoefficient,double greenKernelCoefficient,double blueKernelCoefficient);
    BYTE* convolution(BYTE *inputImg, unsigned int width, unsigned height);


};



#endif // MULTICHANNELKERNEL_H
