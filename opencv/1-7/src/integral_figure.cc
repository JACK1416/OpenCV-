#include <string>
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

using namespace std;

float sum( cv::Mat1f f_mat, int i, int j, int a, int b )
{
    return f_mat( i, j ) + f_mat( i+a, j+b ) - f_mat( i+a, j ) - f_mat( i, j+b );
}

float sumRotated( cv::Mat1f f_mat, cv::RotatedRect rr )
{
    int a = rr.size.width / sqrt(2);
    return 2 * sum( f_mat, rr.center.x - a, rr.center.y - a, a, a );
}

int main( int argc, char** argv )
{
    cv::Mat1b u_mat( 100, 200 );
    cv::Mat1f f_mat( 100, 200 );
    f_mat = cv::Mat::zeros( 100, 200, CV_32F );

    cv::randu( u_mat, 0, 255 );

    f_mat( 0, 0 ) = u_mat( 0, 0 );
    for( int i = 1; i < 100; i++ )
        f_mat( i, 0 ) = f_mat( i-1, 0 ) + u_mat( i, 0 );

    for( int j = 1; j < 200; j++ )
        f_mat( 0, j ) = f_mat( 0, j-1 ) + u_mat( 0, j );

    for( int i = 1; i < 100; i++ )
        for ( int j = 1; j < 200; j++ )
            f_mat( i, j ) = u_mat( i , j ) + f_mat( i-1, j ) + 
                            f_mat( i, j-1 ) - f_mat( i-1, j-1 );

    float summ = sum( f_mat, 2, 2, 10, 10 );
}
