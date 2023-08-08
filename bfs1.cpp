#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int ar[100][100];
int ver=0;
class vertex{
    public:
    int d=-1;
    int id=0;
    string color="WHITE";
    vertex *p=NULL;
};
vector<vertex> v;
void bfs(int a) {
    vertex c;
    for (int i = 0; i < ver; i++) {
        c.id = i;
        v.push_back(c);
    }
    queue<vertex*> q; 
    v[a].d = 0;
    v[a].color = "GREY";
    q.push(&v[a]); 
    cout << v[a].id << " " << v[a].d << endl;
    while (!q.empty()) {
        vertex* u = q.front(); 
        q.pop();
        int e = u->id; 
        for (int i = 0; i < ver; i++) {
            if (ar[e][i] != 0) {
                if (v[i].color == "WHITE") {
                    v[i].color = "GREY";
                    v[i].d = u->d + 1;
                    v[i].p = u;
                    q.push(&v[i]); 
                    cout << v[i].id << " " << v[i].d << endl;
                }
            }
        }
        u->color = "BLACK"; 
    }
}
int main(){
    int a,b;
    cout<<"Enter number of vertices\n";
    cin>>a;
    ver=a;
    int choice;
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
    bfs(b);
    return 0;
}