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

void m_show(Mat,String);
void m_Blur(Mat,float);
void m_Blur_5(Mat,float);
Mat m_Shar(Mat,float,float,float);
void m_Nois_M(Mat);
void m_Nois_A(Mat,float);
void m_Edge(Mat);

int main()
{
    winNum = 1;
    Mat img = imread(GAUSI,CV_LOAD_IMAGE_GRAYSCALE);
    Mat img2 = imread(test,CV_LOAD_IMAGE_GRAYSCALE);
    Mat img3 = imread(test,CV_LOAD_IMAGE_COLOR);
    Mat img4 = imread(test,CV_LOAD_IMAGE_GRAYSCALE);
    m_show(img4,SAVE);

    Mat st = cvCreateMat(img4.rows,img4.cols,CV_8UC1);

    m_Edge(img4);
    waitKey(0);
    destroyAllWindows;
    return 0;
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
void m_Edge(Mat img){

    Mat st = cvCreateMat(img.rows,img.cols,CV_8UC1);

    float maskX[]={-1,0,1,
                   -2,0,2,
                   -1,0,1};
    float maskY[]={-1,-2,-1,
                    0,0,0,
                    1,2,1};
    Vec3b color;
    int sumX,sumY,cnt;

        for(int y=1;y<img.rows-1;y++){
            for(int x=1;x<img.cols-1;x++)
            {
                sumX = 0;
                sumY = 0;
                cnt = 0;

                for(int h=y-1;h<=y+1;h++){

                    for(int w=x-1;w<=x+1;w++){
                    sumX += img.at<uchar>(h,w)*maskY[cnt];
                    //sumY += img.at<uchar>(h,w)*maskY[cnt];
                    cnt++;
                    }

                }
                st.at<uchar>(y,x) = abs(sumX);
        }
    }

    m_show(st,SAVE+"_EDGE_");
}



void m_Blur(Mat img,float A){

    Mat st = cvCreateMat(img.rows,img.cols,CV_8UC3);

    float mask[]={A,A,A,A,A,A,A,A,A};
    Vec3b color;
    int sum[3];
    int cnt;

    for(int y=1;y<img.rows-1;y++){
        for(int x=1;x<img.cols-1;x++){
            for(int c=0;c<3;c++)
                sum[c]=0;
            cnt =0;

            for(int h=y-1;h<=y+1;h++){
                for(int w=x-1;w<=x+1;w++){
                    color = img.at<Vec3b>(h,w);
                    sum[0]+= color[0]*mask[cnt];
                    sum[1]+= color[1]*mask[cnt];
                    sum[2]+= color[2]*mask[cnt];
                    cnt++;
                }
            }
            for(int c=0;c<3;c++){
                if(sum[c]<0)
                    sum[c]=0;
                else if(sum[c]>255)
                    sum[c]=255;
                st.at<Vec3b>(y,x)[c]=sum[c];
            }
        }
    }
    char size[3];
    itoa((int)A,size,10);
    m_show(st,SAVE+"_BLUR_"+size);
}
void m_Blur_5(Mat img, float A){
    Mat st = cvCreateMat(img.rows,img.cols,CV_8UC3);

    float mask[]={A,A,A,A,A,
                  A,A,A,A,A,
                  A,A,A,A,A,
                  A,A,A,A,A,
                  A,A,A,A,A};
    Vec3b color;
    int sum[3];
    int cnt;

    int Num =2;
    for(int y=Num;y<img.rows-Num;y++){
        for(int x=Num;x<img.cols-Num;x++){
            for(int c=0;c<3;c++)
                sum[c]=0;
            cnt =0;

            for(int h=y-Num;h<=y+Num;h++){
                for(int w=x-Num;w<=x+Num;w++){
                    color = img.at<Vec3b>(h,w);
                    sum[0]+= color[0]*mask[cnt];
                    sum[1]+= color[1]*mask[cnt];
                    sum[2]+= color[2]*mask[cnt];
                    cnt++;
                }
            }
            for(int c=0;c<3;c++){
                if(sum[c]<0)
                    sum[c]=0;
                else if(sum[c]>255)
                    sum[c]=255;
                st.at<Vec3b>(y,x)[c]=sum[c];
            }
        }
    }
    char size[3];
    itoa((int)A,size,10);
    m_show(st,SAVE+"_BLUR5_"+size);
}
Mat m_Shar(Mat img,float A,float B,float C){

    Mat st = cvCreateMat(img.rows,img.cols,CV_8UC3);

    float mask[] = {A,B,A,
                    B,C,B,
                    A,B,A};
    Vec3b color;
    int sum[3];
    int cnt;

    for(int y=1;y<img.rows-1;y++){
        for(int x=1;x<img.cols-1;x++){
            for(int c=0;c<3;c++)
                sum[c]=0;
            cnt =0;

            for(int h=y-1;h<=y+1;h++){
                for(int w=x-1;w<=x+1;w++){
                    color = img.at<Vec3b>(h,w);
                    sum[0]+= color[0]*mask[cnt];
                    sum[1]+= color[1]*mask[cnt];
                    sum[2]+= color[2]*mask[cnt];
                    cnt++;
                }
            }
            for(int c=0;c<3;c++){
                if(sum[c]<0)
                    sum[c]=0;
                else if(sum[c]>255)
                    sum[c]=255;
                st.at<Vec3b>(y,x)[c]=sum[c];
            }
        }
    }
    char size[3];
    itoa((int)A,size,10);
    m_show(st,SAVE+"_Shar"+size);
    return st;
}
void m_Nois_M(Mat img){
    Mat st = cvCreateMat(img.rows,img.cols,CV_8UC1);
    int sort_array[9];
    int cnt=0;

        for(int y=1;y<img.rows-1;y++){
            for(int x=1;x<img.cols-1;x++)
            {
                cnt = 0;
                for(int h=y-1;h<=y+1;h++){
                    for(int w=x-1;w<=x+1;w++){
                    sort_array[cnt]= img.at<uchar>(h,w);
                    cnt++;
                    }

                }

                vector<int>myvector(sort_array,sort_array+9);
                sort(myvector.begin(),myvector.end());
                st.at<uchar>(y,x) = myvector.at(4);
        }

    }
    m_show(st,SAVE+"_Med");
}

void m_Nois_A(Mat img, float A){
    Mat st = cvCreateMat(img.rows,img.cols,CV_8UC1);

    float mask[]={A,A,A,A,A,A,A,A,A};

    Vec3b color;
    int sum,cnt;

        for(int y=1;y<img.rows-1;y++){
            for(int x=1;x<img.cols-1;x++)
            {
                sum = 0;
                cnt = 0;

                for(int h=y-1;h<=y+1;h++){

                    for(int w=x-1;w<=x+1;w++){
                    sum += img.at<uchar>(h,w)*mask[cnt];
                    cnt++;
                    }

                }
                st.at<uchar>(y,x) = sum;
        }
    }
    m_show(st,SAVE+"_Ave");
}

