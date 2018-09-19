//
//  main.cpp
//  RlE行程编码
//
//  Created by   　　xj on 16/3/11.
//  Copyright © 2016年 xujunyu. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int go=1;
    while(go==1)
    {
        string in;
        cout<<"get input:";
        cin>>in;
        
        int times=1;
        char previous=in[0];
        for(int i=1;i<in.length();i++)
        {
            if(in[i]==previous)//same ++  || end
            {
                times++;//same ++
            }
            else if(in[i]!=previous)//diff
            {
                cout<<previous;
                cout<<times;
                previous=in[i];
                times=1;
            }
            if(i==in.length()-1)//at end,cout
            {
                
                cout<<previous;
                cout<<times;
            }

        }
        
        go=0;
        cout<<"\nagain?press 1 and enter\n";
        cin>>go;
    }
    
    
}
