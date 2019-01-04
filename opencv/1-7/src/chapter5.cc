#include <iostream>
#include <vector>
#include <string>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/photo.hpp"

using namespace std;

int main( int argc, char** argv )
{
    /************************   1    ***************************\
    cv::Mat m1( 100, 100, CV_8UC3, cv::Scalar( 0, 0, 0 ) );
    cv::Point center( 50, 50 );
    cv::Scalar color( 125, 0, 130 );
    cv::circle( m1, center, 20, color );
    imshow( "circle", m1 );
    cv::waitKey( 0 );
    /************************   2    ***************************\
    cv::Mat m2( 100, 100, CV_8UC3, cv::Scalar( 0, 0, 0 ) );
    for( int i = 20; i <= 40; i++ )
    {
        m2.at<cv::Vec3b>( i, 5  )[1] = 255;
        m2.at<cv::Vec3b>( i, 20 )[1] = 255;
    }
    for( int i = 5; i <= 20; i++ )
    {
        m2.at<cv::Vec3b>( 20, i )[1] = 255;
        m2.at<cv::Vec3b>( 40, i )[1] = 255;
    }
    imshow( "rectangular" , m2 );
    cv::waitKey( 0 );
    /************************   3    ***************************\
    cv::Mat m3( 100, 100, CV_8UC3, cv::Scalar( 0, 0, 0 ) );
    uchar* lu = m3.ptr<uchar>( 20 );
    uchar* ld = m3.ptr<uchar>( 40 );
    for( int i = 5; i <= 20; i++ )
    {
        uchar* up = lu + i * m3.channels();
        uchar* down = ld + i * m3.channels();
        up[1] = 255;
        down[1] = 255;
    }
    for( int i = 20; i <= 40; i++ )
    {
        uchar* l = m3.ptr<uchar>( i );
        uchar* l1 = l + 5 * m3.channels();
        uchar* l2 = l + 20 * m3.channels();
        l1[1] = 255;
        l2[1] = 255;
    }
    imshow( "ptr_rect", m3 );
    cv::waitKey( 0 );
    /************************   4    **************************\
    cv::Mat m4( 210, 210, CV_8U, cv::Scalar( 0 ) );
    for( int i = 0; i <= 100; i=i+10 )
    {
        int j = 2 * i;
        m4( cv::Rect(i,i,210-j,210-j) ).setTo( i );
    }
    imshow( "pyramid", m4 );
    cv::waitKey(0);
    /************************  read  **************************/
    cv::Mat m5 = cv::imread( "satomi.jpeg", -1 );
    if( !m5.data )
        cout << "read image failed" << endl;
    /************************   5    **************************\
    cv::Mat ROI1 = m5( cv::Rect(5,10,20,30) );
    cv::Mat ROI2 = m5( cv::Rect(50,60,20,30) );
    cv::bitwise_not( ROI1, ROI1 );
    cv::bitwise_not( ROI2, ROI2 ); 
    imshow( "石原さとみ", m5 );
    cv::waitKey( 0 );
    /************************   6    **************************/
    vector<cv::Mat> channels;
    double minVal, maxVal;
    int minIdx, maxIdx;
    cv::split( m5, channels );
    imshow( "green", channels[1] );
    cv::waitKey( 0 );
    cv::Mat clone1, clone2;
    channels[1].copyTo( clone1 );
    channels[1].copyTo( clone2 );
    cv::minMaxIdx( channels[1], &minVal, &maxVal, &minIdx, &maxIdx );
    cout << "minVal: " << minVal << endl
         << "maxVal: " << maxVal << endl
         << "minIdx: " << minIdx << endl
         << "maxIdx: " << maxIdx << endl;
    int thresh = ( maxVal - minVal ) / 2;
    clone1.setTo( thresh );
    clone2.setTo( 0 );
    cv::compare( channels[1], clone1, clone2, cv::CMP_GE );
    cv::subtract( channels[1], thresh/2, channels[1], clone2 );
    imshow( "last", channels[1] );
    cv::waitKey( 0 );
    /***********************  end    **************************/
}
