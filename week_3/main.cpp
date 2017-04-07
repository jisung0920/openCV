#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;
int main()
/*{
    Mat img = imread("D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\install_Week1\\Lena.jpg",CV_LOAD_IMAGE_COLOR);

    if(!img.data){
            cout<<"not find image"<<std::endl;
             //return -1;

    }
    Mat gray;
    cvtColor(img,gray,CV_RGB2GRAY);
    namedWindow("Lena",CV_WINDOW_AUTOSIZE);
    imshow("Lena",img);
    namedWindow("Lena2",CV_WINDOW_AUTOSIZE);
    imshow("Lena2",gray);
    waitKey(0);

    return 0;for (y=0; y<img.rows;y++)
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
}*/
/*{
    Mat img = imread("D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\install_Week1\\Lena.jpg",CV_32FC3);
    Mat gray;
    Mat Output(img.rows,img.cols,CV_8UC1);

    if(!img.data){
            cout<<"not image"<<std::endl;
        return -1;
    }
    for(int i=0;i<img.rows;i++){
        for(int j=0;j<img.cols;j++){
            Vec3b intensity = img.at<Vec3b>(i,j);

            int blue = intensity.val[0];
            int green = intensity.val[1];
            int red = intensity.val[2];

            Output.at<uchar>(i,j) = blue*0.0722 + green*0.7152 + red*0.2126;
        }
    }
    return 0;
}*/
{
    Mat img = imread("D:\\backup\\hanyang_17_01\\멀티미디어정보처리\\실습자료\\install_Week1\\Lena.jpg",CV_32FC3);
    Mat Output(img.rows,img.cols,CV_8UC1);
    Mat imgC[3];
    Mat Mat_z[3];
    Mat Mat_b[3];
    Mat Mat_c[3];

    split(img,Mat_z);
    split(img,Mat_b);
    split(img,Mat_c);
    if(!img.data){
            cout<<"not image"<<std::endl;
        return -1;
    }
    namedWindow("Lena",CV_WINDOW_AUTOSIZE);
    imshow("Lena",img);
        Mat_z[0]=255;
        merge(Mat_z,3,imgC[0]);
        Mat_b[1]=255;
        merge(Mat_b,3,imgC[1]);
        Mat_c[2]=255;
        merge(Mat_c,3,imgC[2]);


    for(int i=0;i<3;i++){
        namedWindow("Lena2"+i,CV_WINDOW_AUTOSIZE);
        imshow("Lena2"+i,imgC[i]);
    }

    waitKey(0);
    return 0;//RGB color divide
}
