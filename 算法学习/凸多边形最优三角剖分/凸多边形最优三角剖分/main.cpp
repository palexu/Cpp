#include <iostream>
#include <math.h>
using namespace std;

const int N = 7;//凸多边形边数+1
double weight[][N]={};//凸多边形的权
int xoy[][N]={{0,2},{1,5},{3,7},{6,6},{7,4},{6,2},{2,1}};
double MinWeightTriangulation(int n,double **t,double **s);
void Traceback(int i,int j,double **s);//构造最优解
double Weight(int a,int b,int c);//权函数
void initWeight();

int main()
{
    initWeight();
    double **s = new double *[N];
    double **t = new double *[N];
    for(int i=0;i<N;i++)
    {
        s[i] = new double[N];
        t[i] = new double[N];
    }
    
    cout<<"此多边形的最优三角剖分值为："<<MinWeightTriangulation(N-1,t,s)<<endl;
    cout<<"最优三角剖分结构为："<<endl;
    Traceback(1,5,s); //s[i][j]记录了Vi-1和Vj构成三角形的第3个顶点的位置
    
    return 0;
}
void initWeight(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            weight[i][j]=sqrt(pow(xoy[i][1]-xoy[j][1],2)+pow(xoy[i][2]-xoy[j][2],2));
//            cout<<i<<":"<<j<<"  "<<weight[i][j]<<endl;
        }
    }
}
double MinWeightTriangulation(int n,double **t,double **s)
{
    for(int i=1; i<=n; i++)
    {
        t[i][i] = 0;
    }
    for(int r=2; r<=n; r++) //r为当前计算的链长（子问题规模）
    {
        for(int i=1; i<=n-r+1; i++)//n-r+1为最后一个r链的前边界
        {
            int j = i+r-1;//计算前边界为r，链长为r的链的后边界
            
            t[i][j] = t[i+1][j] + Weight(i-1,i,j);//将链ij划分为A(i) * ( A[i+1:j] )这里实际上就是k=i
            
            s[i][j] = i;
            
            for(int k=i+1; k<j; k++)
            {
                //将链ij划分为( A[i:k] )* (A[k+1:j])
                double u = t[i][k] + t[k+1][j] + Weight(i-1,k,j);
                if(u<t[i][j])
                {
                    t[i][j] = u;
                    s[i][j] = k;
                }
            }
        }
    }
    return t[1][N-2];
}

void Traceback(int i,int j,double **s)
{
    if(i==j) return;
    Traceback(i,s[i][j],s);
    Traceback(s[i][j]+1,j,s);
    cout<<"三角剖分顶点：V"<<i-1<<",V"<<j<<",V"<<s[i][j]<<endl;
}

double Weight(int a,int b,int c)
{
    return weight[a][b] + weight[b][c] + weight[a][c];
}