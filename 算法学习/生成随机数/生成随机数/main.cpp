//
//  main.cpp
//  生成随机数
//
//  Created by   　　xj on 16/4/18.
//  Copyright © 2016年 xujunyu. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "stdlib.h"
#include "huffman.h"
using namespace std;
#define num 6
#define fileDir "/Users/xj/Downloads/output.dat"
void create();
void huffman();

int main(int argc, const char * argv[]) {
    create();
    huffman();
    
    
    
}

void create()
{
    fstream file;
    file.open(fileDir);
    
    srand((unsigned)time(NULL));
    int a[num];
    int tmp;
    for(int i=0;i<100;i++){
        tmp=(rand()%num);
        if(tmp==0)
            file<<"a"<<endl;
        else if(tmp==1)
            file<<"b"<<endl;
        else if(tmp==2)
            file<<"c"<<endl;
        else if(tmp==3)
            file<<"d"<<endl;
        else if(tmp==4)
            file<<"e"<<endl;
        else if(tmp==5)
            file<<"f"<<endl;
        
        a[tmp]++;
    }
    char b[num]={'a','b','c','d','e','f'};
    for(int i=0;i<num;i++){
        cout<<b[i]<<"   出现次数："<<a[i]<<endl;
    }
    cout<<"size:"<<file.tellg()*8<<"bit"<<endl;//文件指针到末尾
    file.close();
}
void huffman()
{
    fstream file;
    file.open(fileDir);
    string tmp="";
    while(!file.eof()){
        string s="";
        file>>s;
        tmp+=s;
    }
    char* c;
    const int len = tmp.length();
    c = new char[len+1];
    strcpy(c,tmp.c_str());
    run(c);
}

