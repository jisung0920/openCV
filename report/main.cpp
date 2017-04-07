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
    String COLCUBE="D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw1\\RGB_Colorcube_Corner_White.bmp";
    String P1 = "D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw1\\p1.jpg";
    String LOGO = "D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw1\\logo.PNG";
    String P2 = "D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw1\\p2.jpg";
    String P3 = "D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw1\\p3.jpg";
    String LENA = "D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\hw1\\Lena.jpg";

int winNum;
int saveNum=0;


void m_invert(Mat);
void m_stretching(Mat,float);
void m_equalization(Mat);
void m_thresholding(Mat,int);
void m_Add(Mat,Mat,float,float);
void m_Sub(Mat,Mat,float,float);
void m_sum(Mat,Mat);
void m_show(Mat,String);

int main()
{
    winNum=0;

    Mat Logo = imread(LOGO,CV_LOAD_IMAGE_GRAYSCALE);


    m_show(Logo,SAVE);
    m_thresholding(Logo,150);


    waitKey(0);
    destroyAllWindows;
/*
    m_show(p1,SAVE);
    m_show(p1,SAVE);

    m_Add(p1,p1,1,1);
*/

    return 0;//RGB color divide
}
void m_sum(Mat p1,Mat p2){

    m_show(p1,SAVE);
    m_show(p2,SAVE);

    m_Add(p1,p2,1,1);


}
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

void m_invert(Mat img){
    Mat Output(img.rows,img.cols,CV_8UC1);
    Mat invImg[3];
    split(img,invImg);//3차원 배열인 img를 3개로 분리한다.
    for(int i=0;i<3;i++)
        invImg[i]=255-invImg[i];//영상의 RGB 값을 각각 255에서 뺀다.
    merge(invImg,3,Output);//합친다.
    m_show(Output,SAVE+"_Invert");
}

void m_stretching(Mat img,float rate){
    Mat st = cvCreateMat(img.rows,img.cols,CV_8UC1);
    int x,y;
    int min =257, max = -1;
    int MN = (img.rows *img.cols);
    float slope = 0;

    int hist[256] = {0},sum_1 = 0, sum_2 = 0;

    for(y=0;y<img.rows;y++){
        for(x=0;x<img.cols;x++){
            hist[(int)img.at<uchar>(y,x)]++;
        }
    }//hisotogram
    for(int i=0;i<256;i++){
        sum_1 += hist[i];
        if(sum_1>MN*rate)//전체의 5%에 최소값
        {
            min = i;
            break;
        }
    }
    for(int i=255;i>=0;i--){
        sum_2 +=hist[i];
        if(sum_2>MN*rate){
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

    m_show(st,SAVE+"_Stretching");
}
void m_equalization(Mat img){
    Mat eq = cvCreateMat(img.rows,img.cols,0);

    int x,y,i;
    int acc_hist =0;
    float N = (img.rows*img.cols)/256;
    int hist[256] = {0},sum[256]={0};

    for(y=0;y<img.rows;y++)
        for(x=0;x<img.cols;x++)
            hist[(int)img.at<uchar>(y,x)]++;


    for(i=0;i<256;i++){
        acc_hist+=hist[i];
        sum[i] = ((int)acc_hist/N);
    }

    for(y=0;y<img.rows;y++)
       for(x=0;x<img.cols;x++)
           eq.at<uchar>(y,x) = sum[img.at<uchar>(y,x)];

    m_show(eq,SAVE+"_Eql");

}

void m_thresholding(Mat img,int threshold_value){
    Mat thresh_img = cvCreateMat(img.rows,img.cols,CV_8UC1);
    int x,y;
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
    m_show(thresh_img,SAVE+"_Threshold");
}

void m_Add(Mat img1,Mat img2,float alpha,float beta){
    Mat img = cvCreateMat(img1.rows,img1.cols,CV_8UC1);
    img = img1*alpha +img2*beta;
    m_show(img,SAVE+"_Add");
}

void m_Sub(Mat img1,Mat img2, float alpha,float beta){
    Mat minus = cvCreateMat(img1.rows,img1.cols,CV_8UC1);
    minus = img1*alpha - img2*beta;
    m_show(minus,SAVE+"_Sub");
}
