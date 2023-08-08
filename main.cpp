#include <vector>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/opencv.hpp"

int main() {
    cv::VideoCapture video(0);
    cv::CascadeClassifier faceDetector;
    cv::Mat img;
    faceDetector.load("haarcascade_frontalface_default.xml");

    while(cv::waitKey(1) != 27) {
        video.read(img);
        std::vector<cv::Rect> faces;
        faceDetector.detectMultiScale(img, faces, 1.3, 5);

        for(int i = 0; i < faces.size(); i++) {
            cv::rectangle(img,
                          faces[i].tl(),
                          faces[i].br(),
                          cv::Scalar(255, 0, 0),
                          2
                          );

            cv::rectangle(img,
                          cv::Point(faces[i].tl().x, faces[i].tl().y - 20),
                          cv::Point(faces[i].br().x, faces[i].tl().y),
                          cv::Scalar(255, 0, 0),
                          -1
                          );

            cv::putText(img,
                        "Face",
                        cv::Point(faces[i].tl().x + 6, faces[i].tl().y - 5),
                        cv::FONT_HERSHEY_COMPLEX,
                        0.5,
                        cv::Scalar(255, 255, 255),
                        1
                        );
        }
        cv::imshow("Image", img);
        if(cv::waitKey(1) == 27){
            break;
        }
    }
}
