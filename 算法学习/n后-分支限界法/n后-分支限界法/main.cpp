//
//  main.cpp
//  n后
//  回溯法
//  Created by   　　xj on 16/5/9.
//  Copyright © 2016年 xujunyu. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <queue>
using namespace std;
#define NUM 8
class QNode{
    friend void EnQueue(queue<QNode *> &,int *x);
    QNode(int *location,int ct){
        for(int i=0;i<NUM;i++){
            x[i]=location[i];
            t=ct;
        }
    }
    int *x;//存放当前各皇后位置
    int t;
};
void EnQueue(queue<QNode *>& q,int*x,int ct){
    QNode node(x,ct);
    q.push(&node);
}

class Queen{
    friend int nQueen(int);
private:
    bool Place(int k);
    void Backtrack(void);
    int *x,n;
    queue <QNode> open;
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
    Q.n=NUM;
    int *p=new int[n+1];
    for(int i=0;i<=n;i++){
        p[i]=0;
    }
    Q.x=p;
    Q.Backtrack();
    delete[]p;
    return 0;
}

//迭代
void Queen::Backtrack(){
    x[1]=0;
    int k=1;
    while(k>0){
        x[k]+=1;
        while((x[k]<=n)&&!(Place(k)))//不合要求
            x[k]+=1;
        if(x[k]<=n){
            if(k==n){//得到解
//                sum++;
            }else{//还有皇后未放置，继续
                k++;
                x[k]=0;
            }
        }else
            k--;
    }
}
int main(int argc, const char * argv[]) {
    
    // insert code here...
        time_t start,end;
        start=clock();
        nQueen(NUM);
        end=clock();
        cout<<" time:"<<end-start<<endl;
    
    return 0;
}
