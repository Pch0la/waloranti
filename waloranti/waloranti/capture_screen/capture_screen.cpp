#include "capture_screen.hpp"
#include "../utilities/config.hpp"

BYTE* screenData = 0;

std::vector< int > capture_screen::get_rgb( int x, int y )
{
    HDC hScreen = GetDC(NULL);
    HBITMAP hBitmap = CreateCompatibleBitmap(hScreen, this->get_width( ), this->get_height( ));
    screenData = (BYTE*)malloc(5 * this->get_width( ) * this->get_height( ));
    HDC hDC = CreateCompatibleDC(hScreen);
    point middle_screen(this->get_width( ) / 2, this->get_height( ) / 2);
    BITMAPINFOHEADER bmi = { 0 };
    bmi.biSize = sizeof(BITMAPINFOHEADER);
    bmi.biPlanes = 1;
    bmi.biBitCount = 32;
    bmi.biWidth = this->get_width( );
    bmi.biHeight = -(this->get_heigth( ));
    bmi.biCompression = BI_RGB;
    bmi.biSizeImage = 0;
    return {
        #define red screenData[ 4 * ( ( y * this->get_width( ) ) + x ) + 2 ]
        #define green screenData[ 4 * ( ( y * this->get_width( ) ) + x ) + 1 ]
        #define blue screenData[ 4 * ( ( y * this->get_width( ) ) + x ) ]
    };
}
