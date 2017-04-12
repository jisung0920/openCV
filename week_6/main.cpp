#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdlib.h>
#include <math.h>

using namespace cv;
using namespace std;

String GAUSI ="D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw2\\lena(GausiaanNoise).bmp";
String IMPUL1 = "D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw2\\lena-impulsenoise1.BMP";
String IMPUL2 = "D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw2\\lena-impulsenoise2.BMP";
String IMPUL3 ="D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw2\\lena-impulsenoise3.BMP";
String SAVE = "D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw2\\saveImg\\save";
String LENA = "D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw1\\Lena.jpg";
String FRUIT = "D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw1\\FRUIT.BMP";
String test ="D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw2\\21.jpg";//5,7
int winNum;
int saveNum=0;
Mat src,src_gray;
int thresh = 200;
int max_thresh = 255;
char* source_window = "Source image";
char* corners_window = "Corners detected";

void cornerHarris_demo(int,void*);


void m_show(Mat img,String save){
    winNum++;
    namedWindow(winNum+"  Window",CV_WINDOW_AUTOSIZE);
    imshow(winNum+"  Window",img);
    char num[3];
    itoa(saveNum,num,10);
    String locate = save+"("+num+")"+".jpg";
    imwrite(locate, img);
    saveNum++;
}

int main(){
    src = imread(LENA,1);
    cvtColor(src,src_gray,CV_BGR2GRAY);

    namedWindow(source_window,CV_WINDOW_AUTOSIZE);
    createTrackbar("Threshold:",source_window,&thresh,max_thresh,cornerHarris_demo);
    cornerHarris_demo(0,0);
    waitKey(0);

    return 0;

    }
    /*
{
    Mat img = imread(test,CV_LOAD_IMAGE_GRAYSCALE);
    m_show(img,SAVE);

    Mat st = cvCreateMat(img.rows,img.cols,CV_8UC1);

    int maskX[]={-1,0,1,
                   -2,0,2,
                   -1,0,1};
    int maskY[]={-1,-2,-1,
                    0,0,0,
                    1,2,1};
    float sumX,sumY;
    int cnt;

        for(int y=1;y<img.rows-1;y++){
            for(int x=1;x<img.cols-1;x++)
            {
                sumX = 0;
                sumY = 0;
                cnt = 0;

                for(int h=y-1;h<=y+1;h++){

                    for(int w=x-1;w<=x+1;w++){
                    sumX += img.at<uchar>(h,w)*maskY[cnt];
                    sumY += img.at<uchar>(h,w)*maskY[cnt];
                    cnt++;
                    }

                }
                st.at<uchar>(y,x) = sqrt(sumX*sumX + sumY*sumY);
        }
    }
    m_show(st,SAVE);
    waitKey(0);
    destroyAllWindows;
    return 0;
}
*/
void cornerHarris_demo(int,void*){
    Mat dst, dst_norm, dst_norm_scaled;
    dst = Mat::zeros(src.size(),CV_32FC1);

    int blockSize =2;
    int apertureSize =3;
    double k = 0.04;

    cornerHarris(src_gray,dst,blockSize,apertureSize,k,BORDER_DEFAULT);

    normalize(dst,dst_norm,0,255,NORM_MINMAX,CV_32FC1,Mat());
    convertScaleAbs(dst_norm,dst_norm_scaled);
    for(int j=0;j<dst_norm.rows;j++){
        for(int i=0;i<dst_norm.cols;i++){
            if((int)dst_norm.at<float>(j,i)>thresh){
                circle(dst_norm_scaled,Point(i,j),5,Scalar(0),2,8,0);
            }
        }
    }

    namedWindow(corners_window,CV_WINDOW_AUTOSIZE);
    imshow(corners_window,dst_norm_scaled);
}
