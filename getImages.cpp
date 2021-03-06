#include <opencv2/opencv.hpp>
#include <stdlib.h>
using namespace std;
using namespace cv;

vector<string> filenames;
string imagelistfn = "stereo_calib.txt";

int main()
{

    Mat img_left, img_right;
    string sSavePath = "../pic";
    string sLeft = "left";
    string sRight = "right";
    string sJpg = ".jpg";
    ofstream ofsImageList(sSavePath+'/'+imagelistfn);
    string sSaveString_left,sSaveString_Right;

    int i = 0;

    cv::VideoCapture camera0(1);
    if (!camera0.isOpened()) return 1;
    camera0.set(CV_CAP_PROP_FOURCC, CV_FOURCC('M', 'J', 'P', 'G'));//设置为MJPG格式
    camera0.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
    camera0.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    cout << "CV_CAP_PROP_FPS: " << camera0.get(CV_CAP_PROP_FPS) << endl;

    while (true)
    {
        cv::Mat frame;
        camera0 >> frame;
        cv::Mat frame_left;
        cv::Mat frame_right;
        frame_left = frame(Rect(0, 0, 640, 480));
        frame_right = frame(Rect(640, 0, 640, 480));

        cv::imshow(sLeft, frame_left);
        cv::imshow(sRight, frame_right);

        int c = waitKey(1);
        if (' ' == char(c))
        {
            i++;
            ostringstream osSaveString_left, osSaveString_right;
            osSaveString_left << sSavePath << '/' << sLeft << '/' << i << sJpg ;
            osSaveString_right << sSavePath << '/' << sRight << '/' << i << sJpg;
            sSaveString_left = osSaveString_left.str();
            sSaveString_Right = osSaveString_right.str();
            ofsImageList << sSaveString_left << endl << sSaveString_Right << endl;
            osSaveString_left << '\0';
            osSaveString_right << '\0';
            sSaveString_left = osSaveString_left.str();
            sSaveString_Right = osSaveString_right.str();
            cv::imwrite(sSaveString_left, frame_left);
            cv::imwrite(sSaveString_Right, frame_right);
            cout << sSaveString_left << endl;
            cout << sSaveString_Right << endl;
        }
        if ('q' == char(c)) break;
    }
    camera0.release();
    ofsImageList.close();
    return 0;

}

