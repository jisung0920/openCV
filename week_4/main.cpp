#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


using namespace cv;
using namespace std;
/*
int main()
{
    Mat img = imread("D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\install_Week1\\Lena.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    Mat st = cvCreateMat(img.rows,img.cols,CV_8UC1);
    int x,y;
    int min =257, max = -1;
    int MN = (img.rows *img.cols);
    float slope = 0;
    int max_hist = 0;
    int max_hist2 = 0;
    int hist[256] = {0},sum_1 = 0, sum_2 = 0,hist2[256]={0};

    for(y=0;y<img.rows;y++){
        for(x=0;x<img.cols;x++){
            hist[(int)img.at<uchar>(y,x)]++;
        }
    }
    for(int i=0;i<256;i++){
        sum_1 += hist[i];
        if(sum_1>MN*0,05)
        {
            min = i;
            break;
        }
    }
    for(int i=255;i>=0;i--){
        sum_2 +=hist[i];
        if(sum_2>MN*0.05){
            max = i;
            break;
        }
    }
    slope = 255/(max-min);
    for (y=0; y<img.rows;y++)
    {
    for(x=0;x<img.cols;x++)
        {
            int k;
            k=(int)(img.at<uchar>(y,x));

            if(k<min)
                st.at<uchar>(y,x) = 0;
            else if (k>max)
                st.at<uchar>(y,x) = 255;
            else
                st.at<uchar>(y,x) = (k-min)*slope;
        }
    }
    for(y=0;y<img.rows;y++)
    {
       for(x=0;x<img.cols;x++)
       {
           hist2[(int)st.at<uchar>(y,x)]++;
       }
    }
        namedWindow("Lena",CV_WINDOW_AUTOSIZE);
        imshow("Lena",img);
        namedWindow("Lena2",1);
        imshow("Lena2",st);
        waitKey(0);
        destroyAllWindows;


//Histogram stretching
    return 0;
}*/
/*
int main(){
    Mat img = imread("D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\install_Week1\\Lena.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    Mat eq = cvCreateMat(img.rows,img.cols,0);

    namedWindow("Lena",CV_WINDOW_AUTOSIZE);
    imshow("Lena",img);

    int x,y,i,k;
    int acc_hist =0;
    float N = (img.rows*img.cols)/256;
    int hist[256] = {0},sum[256]={0};
    for(y=0;y<img.rows;y++){

        for(x=0;x<img.cols;x++)
            hist[(int)img.at<uchar>(y,x)]++;
    }

    for(i=0;i<256;i++){
        acc_hist = acc_hist + hist[i];
        sum[i] = ((int)acc_hist/N);
    }

    for(y=0;y<img.rows;y++)
    {
       for(x=0;x<img.cols;x++)
       {
           eq.at<uchar>(y,x) = sum[img.at<uchar>(y,x)];
       }
    }
    namedWindow("Lena eq",1);
    imshow("Lena eq",eq);
    waitKey(0);
    destroyAllWindows;
    return 0;
}//histogram equalization
*/
/*
int main(){
    Mat gray =imread("D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\install_Week1\\Lena.jpg",CV_LOAD_IMAGE_GRAYSCALE);

    Mat dst;

    equalizeHist(gray,dst);
    namedWindow("origin",1);
    namedWindow("equalized",1);

    imshow("origin",gray);
    imshow("equalized",dst);

    waitKey(0);
    destroyAllWindows;
}//equal function
*/
/*
int main(){
    Mat img =imread("D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\Week4\\image/finger_print.png",CV_LOAD_IMAGE_GRAYSCALE);
    Mat thresh_img = cvCreateMat(img.rows,img.cols,CV_8UC1);
    int x,y;
    int threshold_value = 120;

    for(y=0;y<img.rows;y++)
    {
       for(x=0;x<img.cols;x++)
       {
            int k=(int)(img.at<uchar>(y,x));
            if(k<=threshold_value)
                thresh_img.at<uchar>(y,x) = 0;
            else
                thresh_img.at<uchar>(y,x) = 255;
       }
    }
    namedWindow("origin img",CV_WINDOW_AUTOSIZE);
    namedWindow("thresholded img",1);

    imshow("origin img",img);
    imshow("thresholded img",thresh_img);

    waitKey(0);
    destroyAllWindows;

}//thresh
*/
/*
int main(){

    Mat gray =imread("D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw1\\test.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    Mat osu;
    Mat adp;

    threshold(gray,osu,0,255,THRESH_BINARY|THRESH_OTSU);
    adaptiveThreshold(gray,adp,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY
                      ,3,1);
    threshold(gray,adp,0,255,THRESH_BINARY|THRESH_OTSU);

    namedWindow("origin img",1);
    namedWindow("ot img",1);
    namedWindow("adp img",1);

    imshow("origin img",gray);
    imshow("ot img",osu);
    imshow("adp img",adp);

    waitKey(0);
    destroyAllWindows;
}*/

int main(){
    Mat img1 = imread("D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\Week4\\image/Lena.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    Mat img2 = imread("D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\Week4\\image/Pattern.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    Mat img3 = imread("D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\Week4\\image/Pattern.jpg",CV_LOAD_IMAGE_GRAYSCALE);

    Mat plus = cvCreateMat(img1.rows,img1.cols,CV_8UC1);
    Mat minus = cvCreateMat(img1.rows,img1.cols,CV_8UC1);

    int x,y;

    float alpha =0.8;
    float beta = 0.2;

    plus = img1*alpha +beta*img2;
    minus = img2 - img3;

    namedWindow("origin img",CV_WINDOW_AUTOSIZE);
    namedWindow("patten 1 img",CV_WINDOW_AUTOSIZE);
    namedWindow("patten 2 img",CV_WINDOW_AUTOSIZE);
    namedWindow("plus img",CV_WINDOW_AUTOSIZE);
    namedWindow("minus img",CV_WINDOW_AUTOSIZE);

    imshow("origin img",img1);
    imshow("patten 1 img",img2);
    imshow("patten 2 img",img3);
    imshow("plus img",plus);
    imshow("minus img",minus);

    waitKey(0);
    destroyAllWindows;
//add&subtract
}
