
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdlib.h>

using namespace cv;
using namespace std;

String BABOON ="D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw1\\Baboon.BMP";
String COLORBAR = "D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw1\\color bar.bmp";
String FRUIT = "D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw1\\FRUIT.BMP";
String LYALC ="D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw1\\lya-lc.bmp";
String LYALC_B ="D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw1\\lya-lc-bright.bmp";
String LYALC_D = "D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw1\\lya-lc-dark.bmp";
String LYALC_X = "D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw1\\lya-lc-안되는예.bmp";
String TEST = "D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw1\\test.jpg";
String FIG = "D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw1\\지문-gray.bmp";
String SAVE = "D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw1\\saveImg\\save";

int winNum;
int saveNum=0;


void m_invert(Mat);
void m_stretching(Mat,float);
void m_equalization(Mat);
void m_thresholding(Mat,int);
void m_Add(Mat,Mat,float,float);
void m_Sub(Mat,Mat,float,float);

void m_show(Mat,String);
