#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;
int main()
{
    Mat img = imread("D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\install_Week1/Lena.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    Mat img1 = imread("D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\install_Week1/Lena.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    Mat img2 = imread("D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\install_Week1/Lena.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    Mat img3 = imread("D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\install_Week1/Lena.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    Mat img4 = imread("D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\install_Week1/Lena.jpg",CV_LOAD_IMAGE_GRAYSCALE);

    namedWindow("Lena",CV_WINDOW_AUTOSIZE);
    imshow("Lena",img);


    img1 = img1/500;
    img2 = img1*500;
    img3 = img3*3;
    img4 = img4/3;

    namedWindow("Lena+100",CV_WINDOW_AUTOSIZE);
    imshow("Lena+100",img1);

    namedWindow("Lena-100",CV_WINDOW_AUTOSIZE);
    imshow("Lena-100",img2);

    namedWindow("Lena x 3",CV_WINDOW_AUTOSIZE);
    imshow("Lena x 3",img3);

    namedWindow("Lena / 3",CV_WINDOW_AUTOSIZE);
    imshow("Lena / 3",img4);


    waitKey(0);
    destroyWindow("Lena");
    destroyWindow("Lena+100");
    destroyWindow("Lena-100");
    destroyWindow("Lena x 3");
    destroyWindow("Lena / 3");
    return 0;
}
