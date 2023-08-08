#include<iostream>
#include<vector>
using namespace std;
vector<bool> visited;
int ar[100][100];
int ver=0;
void dfs(int v){
    visited[v]=true;
    cout<<v<<" ";
    for(int i=0;i<ver;i++){
        if(ar[v][i]!=0){
            if(!visited[i]){
                dfs(i);
            }
        }
    }
}
int main(){
    int a,b;
    cout<<"Enter number of vertices\n";
    cin>>a;
    ver=a;
    int choice;
    visited.resize(ver, false);
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            ar[i][j]=0;
        }
    }
    while(choice!=0){
        int c,d;
        cout<<"Enter 1 - input edge\n";
        cout<<"Enter 0 - execute bfs\n";
        cin>>choice;
        if(choice==1){
            cout<<"Enter initial vertex\n";
            cin>>c;
            while(c>=ver){
                cout<<"Enter initial vertex again\n";
                cin>>c;
            }
            cout<<"Enter final vertex\n";
            cin>>d;
            while(d>=ver){
                cout<<"Enter final vertex again\n";
                cin>>d;
            }
            ar[c][d]=1;
        }
        else if(choice==0){
            break;
        }
        else{
            cout<<"Not valid choice\n";
        }
    }
    cout<<"Enter initial vertex\n";
    cin>>b;
    dfs(b);
    return 0;
}