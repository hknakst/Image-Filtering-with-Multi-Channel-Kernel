#include <iostream>
#include "multichannelkernel.h"
#include <QtGui/QImage>

int main()
{



    double red[9]={1,1,1,
                   1,1,1,
                   1,1,1};
    double green[9]={1,2,1,
                     2,4,2,
                     1,2,1};
    double blue[9]={1,0,-1,
                    2,0,-2,
                    1,0,-1};

    double redKernelCoefficient = (double)1/9;
    double greenKernelCoefficient = (double)1/16;
    double blueKernelCoefficient = (double)1;

    MultiChannelKernel mKernel;
    mKernel.setMultiChannelKernel(red,green,blue);
    mKernel.setKernelCoefficients(redKernelCoefficient,greenKernelCoefficient,blueKernelCoefficient);

    QString fileName = "image_for_part_2.jpg";
    QImage img(fileName);
    img = img.convertToFormat(QImage::Format_RGB888);

    QImage image(mKernel.convolution(img.bits(),img.width(),img.height()), img.width(), img.height(), QImage::Format_RGB888);
    image.save("output.jpg");

    return 0;
}
