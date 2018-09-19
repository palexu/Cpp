//************************************
//*八数码问题
//************************************
#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<fstream>
using namespace std;

struct P{
    int times=0;
    int d;	//深度g(n)
    int w;	//不在位数h(n)
    int id;	//记录该节点的id，用于输出时找到该节点
    string s;	//状态
    friend bool operator <(const P &a,const P &b){//按f(n)=g(n)+h(n)大小排序
        return a.d+a.w>b.d+b.w;  //最大堆
    }
}p;
const int N=3;	//棋盘大小
//const string t="123456780";	//目标状态
const string t="123804765";
string stack[1000000];		//记录搜索中的节点
string record[1000000];		//从起点开始记录解路径
int father[10000000];		//记录该节点的父节点
int top=0;					//stack的指针
priority_queue<P> pq;		//open表
map<string,bool> mp;		//记录该状态是否已经访问过：1访问过，0没有

int calw6(string s)//计算该状态的不在位数h(n)
{
    int re=0;
    for(int i=0;i<9;i++) if(s[i]!=t[i]) re++;
//    cout<<"w:"<<re<<endl;
    return re;
}

int calw(string s){
    return 0;//h=0;
}

int calw2(string s){//估价函数2:各数码移动到目的位置所需移动的距离的总和
    int re=0;
    char d[3][3]={{'1','2','3'},{'8','0','4'},{'7','6','5'}};
    char c[3][3];
    int x[3][3];//0：未判断
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            c[i][j]=s[i*3+j];
            x[i][j]=0;
        }
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
        if(c[i][j]!=d[i][j])
            for(int k=0;k<3;k++)
            for(int l=0;l<3;l++)
                if(c[i][j]==d[k][l]&&x[i][j]==0&&x[k][l]==0){
                    re+=abs(k-i)+abs(j-l);
                    x[i][j]=1;
                    x[k][l]=1;
                }
    return re*2;
}
int calw1(string s){//估价函数2:各数码移动到目的位置所需移动的距离的总和
    int re=0;
    char d[3][3]={{'1','2','3'},{'8','0','4'},{'7','6','5'}};
    char c[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            c[i][j]=s[i*3+j];
        }
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(c[i][j]!=d[i][j])
                for(int k=0;k<3;k++)
                    for(int l=0;l<3;l++)
                        if(c[i][j]==d[k][l]){
                            re+=abs(k-i)+abs(j-l);
                        }
    return re;
}


class Analyse{
private:
    int *expand;
    int **son;
    int all;
    int before;
    int depthest;
public:
    Analyse(){
        son=new int*[30];
        expand=new int[30];
        for(int i=0;i<30;i++){
            expand[i]=0;
            son[i]=new int[4];
            for(int j=0;j<4;j++)
                son[i][j]=0;
        }
        all=0;
        before=1;
        depthest=1;
    }
    void analyze(int now);
    void show();
};
void Analyse::analyze(int now){
    all++;
    expand[now]++;
    if(now>depthest)
        depthest++;
}
void Analyse::show(){
    cout<<"共产生"<<all<<"个节点"<<endl;
    cout<<"详细:"<<endl;
    for(int i=0;i<depthest;i++)
    {
        cout<<"第"<<i<<"层:"<<expand[i]<<"个子节点"<<endl;
    }
}
    
int solve()	//搜索过程
{
    P cur;
    
    Analyse ana;
    
    while(!pq.empty()){
        cur=pq.top(); //open表
        pq.pop();
        if(cur.s==t){
            ana.show();
            return cur.id;	//达到目标状态，返回当前节点的id
        }
        int x,y;
        int ops=0;
        
        while(cur.s[ops]!='0') ops++;
        x=ops/3,y=ops%3;  //空格所在位置
        
        int r=cur.id;
        if(x>0){          //空格向上移
            p.s=cur.s;
            swap(p.s[ops],p.s[ops-3]);
            if(!mp[p.s]){
                p.d=cur.d+1,p.w=calw(p.s),p.id=top+1;
                cout<<"d:"<<p.d<<endl;ana.analyze(p.d);
                pq.push(p);
                stack[++top]=p.s;
                father[top]=r;
                mp[p.s]=1;
            }
        }
        if(x<2){    //空格向下移
            p.s=cur.s;
            swap(p.s[ops],p.s[ops+3]);
            if(!mp[p.s]){
                p.d=cur.d+1,p.w=calw(p.s),p.id=top+1;
                cout<<"d:"<<p.d<<endl;
                pq.push(p);
                stack[++top]=p.s;
                father[top]=r;
                mp[p.s]=1;
            }
        }
        if(y>0){    //空格向左移
            p.s=cur.s;
            swap(p.s[ops],p.s[ops-1]);
            if(!mp[p.s]){
                p.d=cur.d+1,p.w=calw(p.s),p.id=top+1;
                cout<<"d:"<<p.d<<endl;
                pq.push(p);
                stack[++top]=p.s;
                father[top]=r;
                mp[p.s]=1;
            }
        }
        if(y<2){   //空格向右移
            p.s=cur.s;
            swap(p.s[ops],p.s[ops+1]);
            if(!mp[p.s]){
                p.d=cur.d+1,p.w=calw(p.s),p.id=top+1;
                cout<<"d:"<<p.d<<endl;
                pq.push(p);
                stack[++top]=p.s;
                father[top]=r;
                mp[p.s]=1;
            }
        }
    }
   
    
    return -1;	//搜索失败
}

void print(int x)////从record表中输出当前搜索的节点
{
    int k=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(record[x][k]=='0')
                printf("  ");
            else printf("%c ",record[x][k]);
            k++;
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    
    //	freopen("a.txt","r",stdin);
//    cout<<"测试的组数";
    int tt;	//测试的组数
//    cin>>tt;
    //测试一次
    tt=1;
    for(int k=1;k<=tt;k++){
//        cout<<"Case "<<k<<":\n";
        int i,j;
        char a;
        p.s="";
//        cout<<"从左到右、从上到下输入数码";
        
        fstream file("/Users/xj/code/c++/input.txt");
        
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                file>>a;  //输入0〜8数码
                p.s+=a;
            }
        }
        p.d=0,p.w=calw(p.s),p.id=0;
        father[0]=-1;
        mp[p.s]=1;
        stack[0]=p.s;
        pq.push(p);	//往open表中加入初始状态节点
        int id=solve();//调用搜索过程
        if(id==-1){
            cout<<"无解！\n";
        }else{
            int c=-1;
            while(id>=0){	//把stack中存的节点按次序放入到record中
                record[++c]=stack[id];
                id=father[id];
            }
            cout<<"原图："<<endl;
            print(c); //输出初始节点
            cout<<"移动过程: \n\n";
            for(i=c-1;i>=0;i--){
                cout<<"Step "<<c-i<<":\n";//输出当前搜索步骤
                print(i);//输出当前搜索的节点
            }
            cout<<"移动结束！\n";
        }
        mp.clear();
        while(!pq.empty()) pq.pop();
        top=0;
        cout<<endl;
    }
    system("pause\n");
    return 0;
}
