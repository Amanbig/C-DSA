#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int ar[4][4]={
    0,1,1,1,
    1,0,1,0,
    1,1,0,0,
    1,0,0,0
};
class vertex{
    public:
    int id=0;
    string color="WHITE";
    int d=-1;
    vertex *p=NULL;
};
vector<vertex> v;
void bfs(int a){
    queue<vertex> q;
    vertex c;
    for(int i=0;i<4;i++){
        c.id=i;
        v.push_back(c);
    }
    v[a].color="GREY";
    v[a].d=0;
    q.push(v[a]);
    cout<<v[a].id<<v[a].d<<endl;
    while(!q.empty()){
        vertex u=q.front();
        q.pop();
        int e=u.id;
        for(int i=0;i<4;i++){
           if(ar[e][i]!=0){
                if(v[i].color=="WHITE"){
                    v[i].d=u.d+1;
                    v[i].color="GREY";
                    v[i].p=&u;
                    q.push(v[i]);
                    cout<<v[i].id<<v[i].d<<endl;
                }
           }
        }
        u.color="BLACK";
    }
}
int main(){
    bfs(1);
    return 0;
}
