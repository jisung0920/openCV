#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>

using namespace cv;
using namespace std;

int main()
/*{

    Mat image;
    image = imread("D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\install_Week1/Lena.jpg",0);
    namedWindow("Display window",CV_WINDOW_AUTOSIZE);
    imshow("Display window",image);
    waitKey(0);
    return 0;
}*/
/*
{
    Mat img(200,200,CV_8UC3,Scalar(5,200,0));
    namedWindow("MyWindow",CV_WINDOW_AUTOSIZE);
    imshow("MyWindow",img);
    waitKey(0);
    destroyWindow("MyWindow");

}*/
/*
{
    Mat img = imread("D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\install_Week1/Lena.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    namedWindow("Lena",CV_WINDOW_AUTOSIZE);
    imshow("Lena",img);
    img = img/2;
    namedWindow("Lena/2",CV_WINDOW_AUTOSIZE);
    imshow("Lena/2",img);
    waitKey(0);
    destroyWindow("Lena/2");

}
*/

{
    Mat img = imread("D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\install_Week1/Lena.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    namedWindow("Lena",CV_WINDOW_AUTOSIZE);
    imshow("Lena",img);

    img =255-img;

    namedWindow("Lena/2",CV_WINDOW_AUTOSIZE);
    imshow("Lena/2",img);
    waitKey(0);
    destroyWindow("Lena");
    destroyWindow("Lena/2");

}


