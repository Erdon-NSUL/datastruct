#include<bits/stdc++.h>
using namespace std;


bool flag = 0;

int Find(vector<vector<int>> r){
    for (size_t i = 0;i < r.size();++i){
        int minn = 1e6;
        int maxx = -1e6;
        int x,y;
        for(size_t j = 0;j<r[i].size();++j){
            if(r[i][j]<minn){
                minn = r[i][j];
                x = i;
            }
            if(r[j][i]>maxx){
                maxx = r[j][i];
                y = j;
            }
        }
        if (minn == maxx){
            cout << "找到一个鞍点: (" << x << "," << y << ")  "<<"值为:"<< maxx <<endl;
            flag = 1;
        }
    }
    return 0;
}
int PRint(vector<vector<int>> m){
    for(auto i:m){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
int main(){
    cout << "输入n,m表示矩阵的行列数:"<< endl;
    int n,m;
    cin >> n >> m;
    vector<vector<int>> _Mat;
    _Mat.resize(n,vector<int>(m));

    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            cin >>_Mat[i][j];
        }
    }
    Find(_Mat);
    if(!flag){
        cout << "没找到";
    }
    return 0;
}
