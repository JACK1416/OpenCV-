#include <iostream>
#include <string>
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/shape.hpp"

using namespace std;

int main( int argc, char** argv )
{
    const int w = 150, h = 150;
    int x = 0, y = 0;
    cv::Scalar color( 128, 128, 128 );
    cv::Rect ROI( x, y, w, h );
    cv::Point center( 75, 75 );
    cv::Mat m( 500, 500, CV_8UC3, cv::Scalar( 0, 0, 0 ) );
    cv::circle( m( ROI ), center, 50, color );
    x += w;
    ROI.x = x;
    cv::ellipse( m( ROI ), center, cv::Size(60,30), 50, 0, 360, color );
    x += w;
    ROI.x = x;
    cv::ellipse( m( ROI ), cv::RotatedRect( center, cv::Size(120,60), 310 ), color );
    vector<cv::Point> pts;
    cv::ellipse2Poly( center, cv::Size(60,30), 50, 0, 360, 1, pts );
    x = 0;
    y += h;
    ROI.x = x;
    ROI.y = y;
    int npts = pts.size();
    cv::Mat m1 = m( ROI );
    cv::fillConvexPoly( m1, &pts[0], npts, color );
    x += w;
    ROI.x = x;
    cv::putText( m( ROI ), "hello", cv::Point(10,10), cv::FONT_HERSHEY_PLAIN, 1.0, cv::Scalar(125,10,255) );

    imshow( "...", m );
    cv::waitKey( 0 );
}
