//
//  main.cpp
//  算法分析题2-3[二分搜索改]
//
//  Created by   　　xj on 16/3/25.
//  Copyright © 2016年 xujunyu. All rights reserved.
//

#include <iostream>
using namespace std;
template<class Type>
int myBinarySearch(Type a[],const Type& x,int n);
int main(int argc, const char * argv[]) {
    int a[100];
    for(int i=0;i<100;i++){
        a[i]=i*2+1;
        if(i==45)
            a[i]=i*2;
    }
    
    int find=11;
    myBinarySearch(a, find, 100);
    for(int i=find-5;i<find+5;i++)
        cout<<i<<":"<<a[i]<<endl;
    
}
template<class Type>
int myBinarySearch(Type a[],const Type& x,int n)
{
    //在a[0]<=a[1]<=...<=a[n-1]中搜索x
    //找到时返回其在数组中的位置，否则返回-1
    int left=0;
    int right=n-1;
    
    while(left<=right){
        int middle=(left+right)/2;
        if(x==a[middle]){
            cout<<"大于"<<x<<"的最小值的位置"<<middle<<endl
            <<"小于"<<x<<"的最大值的位置"<<middle<<endl;

            return middle;
        }
        if(x>a[middle]){
            left=middle+1;
        }
        else{
            right=middle-1;
        }
    }
    cout<<"大于"<<x<<"的最小值的位置"<<left<<endl
        <<"小于"<<x<<"的最大值的位置"<<right<<endl;
    return -1;//未找到
    
}