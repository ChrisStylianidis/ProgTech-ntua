#include <iostream>
#include <vector>
using namespace std;

void issessoso(vector<int> &A,int N){
    int i,j,temp;

    for(i=0; i<N; i++){
        temp=A[i];
        j=i-1;
        while(j>=0&&A[j]<temp){
            A[j+1]=A[j];
            j--;}
        A[j+1]=temp;}}

enum state{ UN , SE , VI };//Unvisited Seen Visited
class Graph{
public:
    Graph(int n): grafos(n),status(n){};
    ~Graph(){grafos.clear();};
    void addEdge(int u,int v){
        grafos[u].push_back(v);
        status[u].push_back(UN);
    };


    const vector<int> & edge(int u) const{
                return grafos[u];}

    bool cycle(vector<int> &path) {
        dfs();
        //for(int i: ans){cout<<i<<" ";} cout<<'\n';
        vector<int> testme;
        int here;
        for(int x: ans){
            if(x!=-1)
                testme.push_back(x);
            else{
                if(testme.size()!=1 && testme.size()!=2 && check(testme,here)){

                    for(int i=here;i<testme.size();++i){
                        path.push_back(testme[i]);
                    }
                    return true;}
                testme.clear();
            }
        }
        return false;
    };

    void dfs_help(int u,int v){

        status[u][v]=SE;
        int value=grafos[u][v];
        ans.push_back(value);
        //cout<<value<<" ";
        for(int x=0; x<grafos[value].size();++x){
            if(status[value][x]==UN){
                dfs_help(value,x);
            }else{   //cout<<endl;
                if(ans.back()!=-1)
                    ans.push_back(-1);}
        }
        //cout<<endl;
        if(ans.back()!=-1)
            ans.push_back(-1);
        status[u][v]=VI;
    };
    void dfs( ) {
        for(int u=0;u<grafos.size();++u)
            for (int v = 0; v < edge(u).size(); ++v) {
                if(status[u][v]==UN){
                    //cout<<x<<" ";
                    dfs_help(u,v);}  }

        //cout<<"ans"<<endl;
        //for(int i=0;i<ans.size();++i)cout<<ans[i]<<" ";
        //cout<<endl;
    };

    bool check(const vector<int> &a,int &position) const {
        //for(int x: a)  cout<<x<<" ";
        int end=a.back();
        vector<int> b=edge(end);
        issessoso(b,b.size());
        for(int i=a.size()-3;i>=0;--i){
            for(int x: b){
                //cout<<"a[i]:"<<a[i]<<"  x:"<<x<<endl;
                if(a[i]==x){
                    position=i;
                    //if(check_loop(a,position)){return true;}
                    return true;
                }
            }
        }
        //cout<<end<<endl;
        return false;

    }
    void print() {
        cout<<endl;
        for(int i=0;i<grafos.size();++i) {
            cout<<i<<": ";
            for(int x=0;x<grafos[i].size();++x) {
                cout<<" "<<grafos[i][x]<<" "<<"     ";
            }//<<status[i][x]
            cout<<endl;
        }
    }

private:
    vector<int> ans;
    vector<vector<int>> grafos;
    vector<vector<state>> status;

};
#ifndef CONTEST
int main() {
    int V, E;
    cin >> V >> E;
    Graph g(V);
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    vector<int> path;
    bool c = g.cycle(path);


if (c) {
    cout << "CYCLE: ";
    for (int i = 0; i < path.size(); ++i)
        cout << path[i] << (i == path.size()-1 ? "\n" : " ");
} else {
cout << "NO CYCLE" << endl;
 }
g.print();
 }
#endif
 /*
  *
7 9
0 1
0 2
1 2
2 3
3 4
4 0
4 6
1 5
5 6


   10 20
   7 0
   2 5
   0 6
   8 1
   1 0
   3 7
   6 0
   7 8
   0 8
   2 8
   4 5
   0 4
   2 0
   1 5
   6 1
   5 4
   8 7
   6 9
   3 1
   4 1


  10 20
  0 1
  6 2
  0 6
  3 1
  4 6
  4 5
  5 1
  7 1
  9 2
  5 6
  8 9
  8 3
  0 3
  7 4
  8 6
  7 3
  3 4
  0 4
  5 9
  3 5


4 5
0 1
0 2
1 3
2 3
0 3

6 5
0 1
0 2
3 4
4 5
5 3

  * */