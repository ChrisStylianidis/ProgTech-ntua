/*
6 9
5 3 10
1 2 11
4 3 4
5 2 8
2 3 16
5 0 7
3 0 7
4 0 10
1 4 1
5
1 2 17
4 5 1
2 3 14
4 2 7
1 5 7

 */
#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    struct pair{
        int first,second;
        pair(int a,int b):first(a),second(b){};
    };
    vector<pair> *grafos;
    int N;
public:
    Graph(int V) {
        N=V;
        grafos = new vector<pair>[N];
    }
    ~Graph() {
        delete [] grafos;
    }
    vector<pair> edges(int u)const{
        return grafos[u];}
    void addEdge(int u, int v, int l) {
        grafos[u].push_back(pair(v,l));
        grafos[v].push_back(pair(u,l));
    }
    void support(int u, vector<bool> &status, int B, int &C, vector<int> &path,bool &found, vector<int> &trip)  {
        status[u] = 1;
        for (auto v: edges(u)) {
            if (v.second <= C){
            if (status[v.first] == 0) {
                if (B != v.first){
                    path.push_back(v.first);
                    trip.push_back(v.second);
                    support(v.first,status, B, C,path,found,trip);
                    if (found) return;
                }
                else {
                    path.push_back(v.first);
                    trip.push_back(v.second);
                    found = true;
                    return;
                }
            }
        }}
        status[u] = 1;
        path.pop_back();
        trip.pop_back();
    }
    void run_me(const int &A,const int &B,int capacity) {
        vector<int> path;
        vector<bool> status(N);
        for (int u = 0; u < N; ++u) {
            status[u] = 0;
        }
        bool found(false);
        int fills = 1,tank = capacity;
        vector<int> trip;
        path.push_back(A);
        support(A,status, B, capacity,path, found, trip);
        if (found) {
            for (int i = 0; i < trip.size(); i++){
                if (capacity < trip[i]) {//gemizo to tank me venzini
                    ++fills;
                    capacity = tank;
                }
                capacity -= trip[i];

            }
            cout << "POSSIBLE: " << fills << " fill(s),";
            for (int i = 0; i < path.size(); i++)
                if(path[i]!=-1)
                    cout<<" "<<path[i];
            cout<<endl;
        }
        else
            cout << "IMPOSSIBLE" << endl;

    }
};

int main() {
    int N, M, U, V, L, Q;
    cin >> N >> M;
    Graph graf(N);
    for (int i = 0; i < M; ++i) {
        cin >> U >> V >> L;
        graf.addEdge(U,V,L);
    }
    vector<int> p;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int A,B,C;
        cin >> A;
        cin >> B;
        cin >> C;
        graf.run_me(A, B, C);
    }
}