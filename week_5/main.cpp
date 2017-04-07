#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdlib.h>


using namespace cv;
using namespace std;

int winNum=0;
void m_show(Mat img){
    winNum++;
    namedWindow(winNum+"  Window",CV_WINDOW_AUTOSIZE);
    imshow(winNum+"  Window",img);

}

String LENA = "D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\Week5\\image\\impulse.png";
/*
int main()
{

    Mat img = imread(LENA,CV_LOAD_IMAGE_GRAYSCALE);
    Mat st = cvCreateMat(img.rows,img.cols,CV_8UC1);

    float mask[] = {1.0/9.0,1.0/9.0,1.0/9.0
        ,1.0/9.0,1.0/9.0,1.0/9.0
        ,1.0/9.0,1.0/9.0,1.0/9.0};

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
    namedWindow("Ori",CV_WINDOW_AUTOSIZE);
    imshow("Ori",img);

    namedWindow("Res",CV_WINDOW_AUTOSIZE);
    imshow("Res",st);
    waitKey();
    destroyAllWindows;


/*
    for(int y=1;y<img.rows-1;y++){
        for(int x=1;x<img.cols-1;x++)
        {
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


    m_show(img);

    m_show(st);
    return 0;
}*/
//gaussian
/*
int main()
{

    Mat img = imread(LENA,CV_LOAD_IMAGE_GRAYSCALE);
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
    namedWindow("Ori",CV_WINDOW_AUTOSIZE);
    imshow("Ori",img);

    namedWindow("Res",CV_WINDOW_AUTOSIZE);
    imshow("Res",st);
    waitKey();
    destroyAllWindows;


    return 0;
}*/
int main()
{

    Mat img = imread(LENA,CV_LOAD_IMAGE_GRAYSCALE);
    Mat st = cvCreateMat(img.rows,img.cols,CV_8UC1);
    Mat sv = cvCreateMat(img.rows,img.cols,CV_8UC1);
    medianBlur(img,sv,3);
    medianBlur(img,st,5);

    namedWindow("Ori",CV_WINDOW_AUTOSIZE);
    imshow("Ori",img);

    namedWindow("Ress",CV_WINDOW_AUTOSIZE);
    imshow("Ress",sv);

    namedWindow("Res",CV_WINDOW_AUTOSIZE);
    imshow("Res",st);
    waitKey();
    destroyAllWindows;


    return 0;
}
