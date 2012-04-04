#include <iostream>
#include <stdio.h>
#include "md5.h"

using namespace std;
using namespace CryptoPP;

int main()
{
    byte message[6];
byte m[16];
message[0]='1';
message[1]='2';
message[2]='3';
message[3]='4';
message[4]='5';
message[5]='6';
MD5 md5;
md5.Update(message,6);
md5.Final(m);
std:;cout<<"Algorithm Name:"<<md5.AlgorithmName()<<endl;
for(int i=0;i<16;i++)
{
printf("%02x",m[i]);
}
printf("/n");
return 0;
}
