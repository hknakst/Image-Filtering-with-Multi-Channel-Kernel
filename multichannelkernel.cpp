#include "multichannelkernel.h"


MultiChannelKernel::MultiChannelKernel()
{
    redKernel = nullptr;
    greenKernel = nullptr;
    blueKernel = nullptr;
    redKernelCoefficient = 1;
    greenKernelCoefficient = 1;
    blueKernelCoefficient = 1;


}

MultiChannelKernel::~MultiChannelKernel()
{
//    delete []redKernel;
//    delete []greenKernel;
//    delete []blueKernel;
}

MultiChannelKernel::MultiChannelKernel(double *redKernel, double *greenKernel, double *blueKernel)
{
    this->redKernel = redKernel;
    this->greenKernel = greenKernel;
    this->blueKernel = blueKernel;
}

void MultiChannelKernel::setMultiChannelKernel(double *redKernel, double *greenKernel, double *blueKernel)
{
    this->redKernel = redKernel;
    this->greenKernel = greenKernel;
    this->blueKernel = blueKernel;
}

void MultiChannelKernel::setKernelCoefficients(double redKernelCoefficient, double greenKernelCoefficient, double blueKernelCoefficient)
{
    this->redKernelCoefficient = redKernelCoefficient;
    this->greenKernelCoefficient = greenKernelCoefficient;
    this->blueKernelCoefficient = blueKernelCoefficient;
}

BYTE* MultiChannelKernel::convolution(BYTE *inputImg, unsigned int width, unsigned height)
{
    unsigned int center;
    BYTE *result = new BYTE[(width)*(height)*3]{0};
    int red=0,green=0,blue=0;

    for (unsigned int i = 0; i < 3*(height-kernelSize+1); i+=3)
        {
            for (unsigned int j = 0; j < 3*(width-kernelSize+1); j+=3)
            {
                for(unsigned int k = 0; k< kernelSize; k++)
                {
                    for(unsigned int h = 0; h< kernelSize; h++)
                    {
                        red   +=   inputImg[(i * width + j) + (3 * k * width +(3*h))] * redKernel[k * kernelSize +h];
                        green +=   inputImg[(i * width + j) + (3 * k * width +(3*h)) + 1] * greenKernel[k * kernelSize +h];
                        blue  +=   inputImg[(i * width + j) + (3 * k * width +(3*h)) + 2] * blueKernel[k * kernelSize +h];
                        if(k==1 && h==1)
                            center = (i * width + j) + (3*k * width +(3*h));
                    }
                }
                result[center] = redKernelCoefficient * red;
                result[center + 1] = greenKernelCoefficient * green;
                result[center + 2] = blueKernelCoefficient * blue;
                red=0; green=0; blue=0;

            }
        }

//    for(int i=0; i<3*height; i+=3)
//    {
//        for(int j=0; j<3*(width); j+=3)
//        {
//            center = (i*(width)+j);
//            result[center] = 255;
//            result[center + 1] = 0;
//            result[center + 2] = 0;
//        }

//}
    return result;

}





//                center = (i*width + j);
//                result[center] = (inputImg[(center - width -1)] + inputImg[(center - width)] + inputImg[(center - width +1)]
//                         + inputImg[(center - 1)] + inputImg[center] + inputImg[(center + 1)]
//                         + inputImg[(center + width - 1)] + inputImg[(center + width)] + inputImg[(center + width + 1)]);





