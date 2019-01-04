#include <iostream>
#include <vector>
#include "../include/cursor.h"

const int w = 10, h = 20; // 方块的左上点和宽高
//Cursor_<float> cursor( w, h );
cv::Mat1f T1 = (cv::Mat_<float>( h, w ) <<
        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
        0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
        0, 1, 1, 0, 1, 1, 0, 0, 0, 0,
        1, 1, 0, 0, 1, 1, 0, 0, 0, 0,
        1, 1, 0, 0, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 0
        );

//Cursor_<cv::Vec3f> cursor( w, h );
//cv::Mat3f COLOR_T1( h, w );
Cursor_<float> cursor( w, h );

void load( const int num )
{
    switch( num )
    {
        case    -1: cursor.flash(       );  break;
        case    13: cursor.enter(       );  break;
        case    49: cursor.write( T1 );  break;
        case   127: cursor.del  (       );  break;
        case 63232: cursor.up   (       );  break;
        case 63233: cursor.down (       );  break;
        case 63234: cursor.left (       );  break;
        case 63235: cursor.right(       );  break;
        default: break;
    }
}

int main( int argc, char** argv)
{
    /*****************    a      ********************/
    std::string window_name = "ASCII";
    cv::namedWindow( window_name, cv::WINDOW_AUTOSIZE );
    cv::Mat m3( 500, 500, CV_32FC3, cv::Scalar( 0.f, 0.f, 0.f) );
    std::vector<cv::Mat> v;

    int num;
    while( 1 )
    {
        num = cvWaitKey(600);
        if( num == 27 ) break;
        load( num );
        cv::cvtColor( cursor.m, m3, cv::COLOR_GRAY2BGR );
        cv::split( m3, v );
        v[1] = cv::Mat::zeros( 500, 500, CV_32F );
        cv::merge( v, m3 );
        cv::imshow( window_name, m3 );
        if( num == -1 )
        {
            load( num );
            num = cvWaitKey(200);
            cv::cvtColor( cursor.m, m3, cv::COLOR_GRAY2BGR );
            cv::split( m3, v );
            v[1] = cv::Mat::zeros( 500, 500, CV_32F );
            cv::merge( v, m3 );
            cv::imshow( window_name, m3 );
        }
    }
    return 0;
}
