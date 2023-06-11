#include <vector>
#include "iostream"
#include "opencv4/opencv2/imgcodecs.hpp"
#include "opencv4/opencv2/highgui.hpp"
#include "opencv4/opencv2/imgproc.hpp"
#include "opencv4/opencv2/objdetect.hpp"
#include "opencv4/opencv2/opencv.hpp"

int main() {
    cv::VideoCapture video(-1);
    cv::CascadeClassifier faceDetector;
    cv::Mat img;
    std::string path;
    printf("Enter the path to the xml file: ");
    std::cin >> path;
    faceDetector.load(path);

    while(1){
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
