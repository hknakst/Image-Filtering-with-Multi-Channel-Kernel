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
    mKernel.setMultiChannelKernel(red,green,blue);
    mKernel.setKernelCoefficients(1/9,1/16,1);
    return 0;
}
