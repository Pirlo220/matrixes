#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ULARGE_INTEGER p1, p2, p3;
    GetDiskFreeSpaceEx(".", &p1, &p2, &p3);
    printf("%llu %llu %llu\n", p1, p2, p3);
    
    long double byte;
    long double kilobyte;
    long double megabyte;
    long double gigabyte;
	    
    kilobyte = p1.QuadPart / 1024;
    megabyte = kilobyte / 1024;
    gigabyte = megabyte /  1024;

    
    cout <<  " lpFreeBytesAvailable Equal to  " << gigabyte << " Gigabyte's "<<"\n";
    
    kilobyte = p2.QuadPart / 1024;
    megabyte = kilobyte / 1024;
    gigabyte = megabyte /  1024;

    
    cout <<  " lpTotalNumberOfBytes Equal to  " << gigabyte << " Gigabyte's "<<"\n";
    
    kilobyte = p3.QuadPart / 1024;
    megabyte = kilobyte / 1024;
    gigabyte = megabyte /  1024;

    
    cout <<  " lpTotalNumberOfFreeBytes Equal to  " << gigabyte << " Gigabyte's "<<"\n";
    
  
    system("pause");
    return 0;
}
