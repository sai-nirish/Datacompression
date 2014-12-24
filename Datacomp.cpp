#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "easyzlib.h"
#include <iostream>
#include <string>

const int MAX_DATA_SIZE = 1024;
const int MAX_COMPRESSED_SIZE = EZ_COMPRESSMAXDESTLENGTH(MAX_DATA_SIZE);
//#define _block_size 16

using namespace std;

//char* finalData;

int compress(const char* orig,char* finalData){

    //const char* orig = "hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.hello world.aaaaaaaaaaaaa";

    const unsigned char* sourceData = (unsigned char*)orig;
    long sourceLength = strlen(orig);
    string str = to_string(strlen(orig));
    unsigned char destinationData[MAX_DATA_SIZE];
    long destinationLength = MAX_DATA_SIZE;
    int x;

    x = ezcompress(destinationData, &destinationLength, sourceData, sourceLength);
    std::cout << "Sending compressed data of size: " << destinationLength << " bytes. Original was: " << sourceLength << " bytes." << std::endl;
    cout << x << endl;
    
    for (long l = 0; l < destinationLength; l++){
        finalData[l] = destinationData[l];
        //cout<<finalData[l]<<endl;
    }
    finalData[destinationLength]='_';
    for (long l = destinationLength+1; l < destinationLength+sourceLength; l++){
        finalData[l] = str[l-destinationLength-1];
        //cout<<finalData[l]<<endl;
    }

    return x;

 }


int decompress(const char* received , char* uncomp){
    const unsigned char* sourceData = (unsigned char*)received;
    
    long i = 0;
    while(true){
        if(received[i]=='_') {
            if(received[i+1] == '9' || received[i+1] == '1' || received[i+1] == '2' || received[i+1] == '3' || received[i+1] == '4' || received[i+1] == '5' || received[i+1] == '6' || received[i+1] == '7' || received[i+1] == '8' )
            break;
        }
        i++;
    }
    cout<<"SourceLength: "<<i<<endl;
    long sourceLength = i;
    long destinationLength = 10*(received[i+1]-'0') + (received[i+2]-'0');
    unsigned char destinationData[destinationLength];
    //long destinationLength = MAX_DATA_SIZE;
    int x;
    cout<<destinationLength<<endl;
    x = ezuncompress(destinationData, &destinationLength, sourceData, sourceLength);
    std::cout << "Sending uncompressed data of size: " << destinationLength << " bytes. Original was: " << sourceLength << " bytes." << std::endl;
    cout << x << endl;
    
    for (long l = 0; l < destinationLength; l++)
        uncomp[l] = destinationData[l];
    //cout<<uncomp<<endl;

    return x;

}






int main(){

    const char* a = "\200g`\347\353\205\362I\202\275\327v\277\343\255zd\223\252\362\3502\307&\216\372u̞ȍ\361ƤQ\214ٱ\261\227J\323\245\372\217eW\253U?\246\217\211\253Q\226";
    char b[200];
    char c[200];


    compress(a,b);
    decompress(b,c);

    cout<<a<<endl;
    cout<<c<<endl;
    cout<<strcmp(a,c)<<endl;//returns '0' when both the strings are equal
    
   }

