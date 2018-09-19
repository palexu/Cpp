#include <iostream>
#include<fstream>
using namespace std;

class Work
{
public:
    Work();
    void solve();
private:
    void Backtrack(int t);
    int n;
    int cw,
        bestw=INT_MAX;
    int **w;
    int *x;
};
void Work::Backtrack(int t)
{
    if(t>=n){
        if(cw<bestw){
            bestw=cw;
            return;
        }
    }
    if(cw<bestw){
        for(int i=0;i<n;i++){
            if(x[i]==0){
                x[i]=1;
                cw+=w[t][i];
                Backtrack(t+1);
                x[i]=0;
                cw-=w[t][i];
            }
        }
    }
}
Work::Work(){
    fstream file("/Users/xj/code/c++/工作分配问题-回溯法/工作分配问题-回溯法/input.txt");
    if(!file.is_open()){
        cout<<"Error opening file";
        exit(1);
    }
    file>>n;
    
    w=new int*[n];
    x=new int[n];
    for(int i=0;i<n;i++){
        w[i]=new int[n];
        x[i]=0;
    }
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            file>>w[i][j];
        }
}
void Work::solve(){
    Backtrack(0);
    cout<<"best:"<<bestw<<endl;
}




int main()
{
    Work M;
    M.solve();
    return 0;
}