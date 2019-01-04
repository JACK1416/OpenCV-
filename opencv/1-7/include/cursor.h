#ifndef CURSOR__H_
#define CURSOR__H_
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/photo.hpp"
#include <string>

#define IN_VOID inline void

template<typename _Tp>
class Cursor_
{
    public:
        /* 构造函数 */
        Cursor_();
        Cursor_( int w, int h );
        Cursor_( int w, int h, int _M, int _N );
        ~Cursor_();
        
        /* 在游标位置写数字, 并向后一步 */
        // void write( cv::Mat_<_Tp>& m, const cv::Mat_<_Tp>& T );
        void write( const cv::Mat_<_Tp>& T );
        /* 退格键 */
        // void del  ( cv::Mat_<_Tp>& m, const cv::Mat_<_Tp>& T );
        void del  ();
        /* 回车 */
        void enter();
        /* 方向键 */
        void up();
        void down();
        void left();
        void right();
        /* 显示游标 */
        void flash();

        cv::Mat_<_Tp> m = cv::Mat::zeros( 500, 500, cv::DataType<_Tp>::type );
        int i = 0, j = 0, width = 10, height = 20; // 确定游标位置

    private:
        cv::Mat_<_Tp> ONES = cv::Mat::ones( height, width, cv::DataType<_Tp>::type );
        cv::Mat_<_Tp> ZEROS = cv::Mat::zeros( height, width, cv::DataType<_Tp>::type );
        int ai, aj; // i, j 的绝对位置
        int M, N; // 所处窗口行列能包含游标的数目
        int *length; // 每行的长度
};

template<typename _Tp>
Cursor_<_Tp>::Cursor_() :
    width(10), height(20), M(25), N(50)
{
    length = new int[M];
    bzero( length, sizeof(int) * M );
}

template<typename _Tp>
Cursor_<_Tp>::Cursor_( int w, int h ) :
    width(w), height(h), M(25), N(50)
{
    length = new int[M];
    bzero( length, sizeof(int) * M );
    ONES = cv::Mat::ones( height, width, cv::DataType<_Tp>::type );
    ZEROS = cv::Mat::zeros( height, width, cv::DataType<_Tp>::type );
}

template<typename _Tp>
Cursor_<_Tp>::Cursor_( int w, int h, int _M, int _N ) :
    width(w), height(h), M(_M), N(_N)
{
    length = new int[M];
    bzero( length, sizeof(int) * M );
    m = cv::Mat::zeros( M * height, N * width, cv::DataType<_Tp>::type );
    ONES = cv::Mat::ones( height, width, cv::DataType<_Tp>::type );
    ZEROS = cv::Mat::zeros( height, width, cv::DataType<_Tp>::type );
}

template<typename _Tp>
Cursor_<_Tp>::~Cursor_()
{
    delete length;
}

template<typename _Tp>
void Cursor_<_Tp>::write( const cv::Mat_<_Tp>& T)
{
    ai = i * width, aj = j * height;
    T.copyTo( m( cv::Rect(ai,aj,width,height) ) );
    length[j] = ( length[j] > i ? length[j] : i );
    right();
}

template<typename _Tp>
void Cursor_<_Tp>::del  ()
{
    left();
    ai = i * width, aj = j * height;
    ZEROS.copyTo( m( cv::Rect(ai,aj,width,height) ) );
    length[j] = length[j] - 1 >= 0 ? length[j] - 1 : 0;;
}

template<typename _Tp>
IN_VOID Cursor_<_Tp>::enter()
{
    if( j < M-1 )
    {
        i = 0;
        j++;
    }
}

template<typename _Tp>
IN_VOID Cursor_<_Tp>::up()
{
    j = ( j-1 <  0 ? 0   : j-1 );
}

template<typename _Tp>
IN_VOID Cursor_<_Tp>::down()
{
    j = ( j+1 >= M ? M-1 : j+1 );
}

template<typename _Tp>
IN_VOID Cursor_<_Tp>::left()
{
    if(i == 0)
    {
        j = ( j-1 < 0 ? 0 : j-1 );
        i = length[j];
    }
    else i--;

}

template<typename _Tp>
IN_VOID Cursor_<_Tp>::right()
{
    if(i == N-1) enter();
    else i++;
}

template<typename _Tp>
IN_VOID Cursor_<_Tp>::flash()
{
    ai = i * width, aj = j * height;
    cv::bitwise_xor( m( cv::Rect(ai,aj,width,height) ), ONES, m( cv::Rect(ai,aj,width,height) ) );
}

#endif
