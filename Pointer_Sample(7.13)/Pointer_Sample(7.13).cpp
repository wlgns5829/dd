#include <stdio.h>                          //표준 헤더 파일
#include <malloc.h>                         //메모리 공간 확보 - heap영역에
                                            //Pointersample 10000 500 : //Command Line 명령어
char buf[2000]; 
void MemoryDump(int start, int length);     //10000 : Start memory 주소
                                         
int main(int argc, char* arge[])            //500   : Dump 할 메모리 크기
{
    int start = 0x09000000;
    int length = 500;

    char c = 'A';
    int i = 1;
    float a = 2.0;
    double d = 3.14;
    void* p = malloc(100); //0x80000000;

    *(double *)p = d;

    MemoryDump((int)buf, length);

    /*printf("c = %8c [0x%8x] \n", c, &c);
    printf("i = %8d [0x%8x] \n", i, &i);
    printf("f = %8f [0x%8x] \n", a, &a);
    printf("d = %8f [0x%8x] \n", d, &d);
    printf("p = %8f [0x%8x] \n", *(double*)p, p);*/

}

void MemoryDump(int start, int length)
{
    char* cp = buf;
    int i = 0;              //index 변수 초기값

    while(i<length)         //수행조건 : i < length
    {
        
        unsigned char c = *((char*)cp + i++);
        printf("%02x  ", c);
    }
}
