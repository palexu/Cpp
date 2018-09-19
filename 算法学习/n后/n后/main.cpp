//
//  main.cpp
//  n后
//  回溯法
//  Created by   　　xj on 16/5/9.
//  Copyright © 2016年 xujunyu. All rights reserved.
//

#include <iostream>
#include <ctime>
using namespace std;
class Queen{
    friend int nQueen(int);
private:
    bool Place(int k);
    void Backtrack(int);
    int n,
    *x;
    long sum;
};
bool Queen::Place(int k){
    for(int j=1;j<k;j++){
        if((abs(k-j)==abs(x[j]-x[k]))||
           (x[j]==x[k]))
            return false;
    }
    return true;//void non-end loop
}
int nQueen(int n){
    Queen Q;
    Q.n=n;//ppt上的代码少了这一行，所以无法运行
    int *p=new int[n+1];
    for(int i=0;i<=n;i++){
        p[i]=0;
    }
    Q.x=p;
    Q.Backtrack(1);
    delete[]p;
    return Q.sum;
}
void Queen::Backtrack(int t){
    if(t>n){
        sum++;
    }else{
        for(int i=1;i<=n;i++){
            x[t]=i;
            if(Place(t))
                Backtrack(t+1);
        }
    }
}
//void Queen::Backtrack(int xyz){
//    x[1]=0;
//    int k=1;
//    while(k>0){
//        x[k]+=1;
//        while((x[k]<=n)&&!(Place(k)))
//            x[k]+=1;
//        if(x[k]<=n){
//            if(k==n){
//                sum++;
//            }else{
//                k++;
//                x[k]=0;
//            }
//        }else
//            k--;
//    }
//}
int main(int argc, const char * argv[]) {
    
    // insert code here...
    for(int i=0;i<15;i++){
        cout<<"n:"<<i<<"  解有";
        time_t start,end,time;
        start=clock();
       
        cout <<nQueen(i);
        end=clock();
        cout<<" time:"<<end-start<<endl;
        
    }
    return 0;
}
