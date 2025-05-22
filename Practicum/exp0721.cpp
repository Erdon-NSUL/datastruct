#include<bits/stdc++.h>
using namespace std;

//cd "e:\datastruct\Practicum\" ; if ($?) { g++ exp0721.cpp -o exp0721.exe } ; if ($?) { .\exp0721.exe }

//����������ô˵��������ÿ����·����վ��
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
	cout << "��������·������"<<endl;
	cin >> m;
	cout << "��������·��Ϣ��ֻ��Ҫ��վ�㰴˳��ÿһ��д�����м�ո�ֿ���"<<endl;
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

	/*��ӡ���
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
	
	// ��ʼ��
    visited[start] = true;
    route.push_back(start);

	int i = 1;
    while (!route.empty()) {
		//��ǰ·����
        string current = route.front();
        route.pop_front();
		cout << "#" <<i<<" --- current:"<<current<<endl;

		// �����ǰ������Ŀ�궥�㣬����·��������
        if (current == end) {
			cout <<"���ҵ����·����"<<endl;
            for(string p = end; p != start; p = previous[p]){
				path.push_back(p);
			}
			path.push_back(start);
			reverse(path.begin(),path.end());
			return true;
        }


		// ������ǰ����������ڽӶ���
        for (string neighbor : ciallo.at(current)) {//at()�Ƿ���map��ֵ����
            if(!visited[neighbor]){
				visited[neighbor] = true;
				previous[neighbor] = current;
				route.push_front(neighbor);
			}
        }
		i++;
    }

    // ���û���ҵ�·�������ؿ�
	cout << "δ�ҵ����·����";
    return false;

}

int main(){
	//��һ�������ڽӱ�
	unordered_map<string, vector<string>> ciallo = query();
	
	cout << "���������վ���յ�վ�� "<< endl;
	string start_s,end_s;
	cin >> start_s >> end_s;

	//��һ����bfs�����������·��
	vector<string> path ;
	if(bfs(ciallo,start_s,end_s,path)){
		for(auto i:path){
			cout << i << " " ;
		}
		cout << endl << "·������Ϊ�� " << path.size();
	}
	
	return 0;
}
