#include "mImage.h"

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
    int max_hist = 0;
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

    int x,y,i,k;
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
    Mat plus = cvCreateMat(img1.rows,img1.cols,CV_8UC1);
    plus = img1*alpha +img2*beta;
    m_show(plus,SAVE+"_Add");
}

void m_Sub(Mat img1,Mat img2, float alpha,float beta){
    Mat minus = cvCreateMat(img1.rows,img1.cols,CV_8UC1);
    minus = img1*alpha - img2*beta;
    m_show(minus,SAVE+"_Sub");
}
