#include<bits/stdc++.h>
using namespace std;

//cd "e:\datastruct\Practicum\" ; if ($?) { g++ exp0721.cpp -o exp0721.exe } ; if ($?) { .\exp0721.exe }

//反正不管怎么说，先设置每条线路及其站点
unordered_map<int, vector<string>> ciallo =
{
{0, {"A", "B", "C", "D", "E", "F", "G", "H", }},
{1, {"M", "C", "N", "O", "P", "Q", "AA"}},
{2, {"D", "X", "F", "Z", "AA", "BB"}},
{3, {"E", "II", "JJ", "KK", "LL", "MM", "NN", "OO", "H"}},
{4, {"M", "TT", "UU", "VV", "WW", "F"}},
{5, {"S", "Q", "FFF", "O", "HHH", "G", "JJJ", "KKK", "LLL", "MMM", "NNN","XXX", "YYY"}},
{6, {"NNN", "PPP", "QQQ"}},
};


unordered_map<string, vector<string>> query(){
	int m;
	cout << "请输入线路总数："<<endl;
	cin >> m;
	cout << "请输入线路信息（只需要将站点按顺序每一行写出，中间空格分开）"<<endl;
	cin.ignore();
	int i = 0;
	unordered_map<string, set<string>> mujica;
	
	for(i;i<m;++i){
		string line,station,prestation;
		getline(cin,line);
		istringstream TGW(line);
		TGW >> prestation;
		while(TGW>>station){
			mujica[station].insert(prestation);
			mujica[prestation].insert(station);
			prestation = station;
		}
	}

	unordered_map<string, vector<string>> mygo;	
	for(auto i:mujica){
		vector<string>tmpt(i.second.begin(),i.second.end());
		mygo[i.first] =tmpt;
	}

	/*打印检查
	for(auto i:mygo){
			cout << i.first << ": ";
			for(auto j:i.second){
				cout << j << " ";
			}
			cout <<endl;}*/
			
	return mygo;
}
 
bool bfs(unordered_map<string, vector<string>> ciallo,string start,string end,vector<string> &path){
	deque<string> route;
	map<string, bool>visited;
	map<string ,string>previous;
	
	// 初始化
    visited[start] = true;
    route.push_back(start);

	int i = 1;
    while (!route.empty()) {
		//当前路径点
        string current = route.front();
        route.pop_front();
		cout << "#" <<i<<" --- current:"<<current<<endl;

		// 如果当前顶点是目标顶点，构造路径并返回
        if (current == end) {
			cout <<"已找到最短路径！"<<endl;
            for(string p = end; p != start; p = previous[p]){
				path.push_back(p);
			}
			path.push_back(start);
			reverse(path.begin(),path.end());
			return true;
        }


		// 遍历当前顶点的所有邻接顶点
        for (string neighbor : ciallo.at(current)) {//at()是访问map的值方法
            if(!visited[neighbor]){
				visited[neighbor] = true;
				previous[neighbor] = current;
				route.push_front(neighbor);
			}
        }
		i++;
    }

    // 如果没有找到路径，返回空
	cout << "未找到最短路径！";
    return false;

}

int main(){
	//这一步构建邻接表
	unordered_map<string, vector<string>> ciallo = query();
	
	cout << "请输入起点站与终点站： "<< endl;
	string start_s,end_s;
	cin >> start_s >> end_s;

	//这一步用bfs搜索所有最短路径
	vector<string> path ;
	if(bfs(ciallo,start_s,end_s,path)){
		for(auto i:path){
			cout << i << " " ;
		}
		cout << endl << "路径长度为： " << path.size();
	}
	
	return 0;
}
