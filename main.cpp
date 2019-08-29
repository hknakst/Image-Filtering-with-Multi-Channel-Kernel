#include <iostream>
#include "multichannelkernel.h"

int main(int argc, char *argv[])
{

    MultiChannelKernel mKernel;
    double red[9]={1,1,1,
                   1,1,1,
                   1,1,1};
    double green[9]={1,2,1,
                     2,4,2,
                     1,2,1};
    double blue[9]={1,0,-1,
                    2,0,-2,
                    1,0,-1};
    BYTE img[61] = {1,2,3,  4,5,6,  7,8,9, 10,11,12, 13,14,15,
                    16,17,18,  19,20,21,   22,23,24,  25,26,27, 28,29,30,
                    31,32,33,   34,35,36,  37,38,39,  40,41,42,  43,44,45,
                    46,47,48,  49,50,51,   52,53,54,  55,56,57,   58,59,60};
    mKernel.setMultiChannelKernel(red,green,blue);
    double redKernelCoefficient = (double)1/9;
    double greenKernelCoefficient = (double)1/16;
    double blueKernelCoefficient = (double)1;
    mKernel.setKernelCoefficients(redKernelCoefficient,greenKernelCoefficient,blueKernelCoefficient);
    mKernel.convolution(img,5,4);
    return 0;
}
