#include <iostream>
#include <string>
#include "opencv2/core.hpp"

using namespace std;

int main()
{
    cv::Mat A = (cv::Mat1f( 3, 2 ) <<
                 1.f, 1.f,
                 0.f, 1.f,
                -1.f, 1.f
                );
    cv::Mat B = A.t() * A;
    cv::Mat values;
    cv::Mat vecs;
    cv::eigen( B, values, vecs );
    cv::Mat sigma;
    cv::sqrt( values, sigma );
    cv::Mat tmp1 = (1/sigma);
    cv::Mat tmp2 = A * vecs;
    cv::Mat tmp3;
    cv::repeat( tmp1, 1, 3, tmp3 );
    cv::Mat u = tmp3.t().mul( tmp2 );
    cv::Mat C = (cv::Mat1f( 2, 2 ) <<
                 sigma.at<float>(0), 0,
                 0, sigma.at<float>(1)
                 );
    cv::Mat res = u * C * vecs;
    for( int i = 0; i < res.size[0]; i++ )
    {
        for( int j = 0; j < res.size[1]; j++ )
        {
            cout << res.at<float>(i ,j) << " ";
        }
    }
}
