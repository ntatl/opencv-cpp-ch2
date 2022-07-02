#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main() {

    string path = "C:\\Users\\davdk\\Desktop\\OpenCV C++\\Chapter 2\\Resources\\cards.jpg";
    Mat img = imread(path);
    Mat imgGray, imgBlur, imgCanny, imgDilation, imgErode;
    resize(img,img,Size(), 0.50, 0.50);

    //    Color An Image    //
    cvtColor(img,imgGray,COLOR_BGR2GRAY);
    //    Blur An Image    //
    GaussianBlur(img,imgBlur,Size(7, 7), 1);
    //    Edges On Image    //
    Canny(imgBlur,imgCanny,50,150);
    //    Dilate Edges On Image    //
    Mat kernel_dilate = getStructuringElement(MORPH_RECT, Size (5,5)); // İf You Give Highter Element You Will Dilate More //
    dilate(imgCanny,imgDilation,kernel_dilate);
    //    Erode Edges On Image    //
    Mat kernel_erode = getStructuringElement(MORPH_RECT, Size(5,5));
    erode(imgDilation,imgErode,kernel_erode);


    imshow("Image", img);
    imshow("Image Gray", imgGray);
    imshow("Image Blur", imgBlur);
    imshow("Image Canny", imgCanny);
    imshow("Image Dilate", imgDilation);
    imshow("Image Erode", imgErode);
    waitKey(0);

}
