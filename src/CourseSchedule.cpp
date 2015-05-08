#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 拓扑排序方法判断图是否有环
class Solution1 {
public:
	// (u,v)表示从u->v的边
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
		int count[numCourses];
		vector<int> points;
		// edge[i]存放所有从i出发与i相连的顶点
		std::map<int, vector<int> > edge;
		memset(count, 0, sizeof(count));
        for (int i = 0 ; i < prerequisites.size(); i++) {
			vector<int> pair  = prerequisites[i];
			int u = pair[0];
			int v = pair[1];
			count[v]++;
			if (edge.find(u) == edge.end()) {
				edge[u] = vector<int>();
			}
			edge[u].push_back(v);
		}
		
		for (int i = 0; i < numCourses; i++) {
			if (count[i] == 0) {
				points.push_back(i);
			}
		}
		
		while (points.size()) {
			int u = points.back();
			points.pop_back();
	        for (int v : edge[u]) {
				count[v]--;
				if (count[v] == 0) {
					points.push_back(v);
				}
			}
		}
		
		for (int i = 0; i < numCourses; i++) {
			if (count[i] != 0) {
				return false;
			}
		}
		return true;
    }
};

// DFS判断图是否有环
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
		// edge[i]临接表形式存放所有从i出发与i相连的顶点
		std::map<int, vector<int> > edge;

        for (int i = 0 ; i < prerequisites.size(); i++) {
			vector<int> pair  = prerequisites[i];
			int u = pair[0];
			int v = pair[1];
			if (edge.find(u) == edge.end()) {
				edge[u] = vector<int>();
			}
			edge[u].push_back(v);
		}
		bool visit[numCourses];
		bool handled[numCourses];
		memset(visit, 0, sizeof(visit));
		memset(handled, 0, sizeof(handled));
		bool hasLoop = false;

		// 对每一个入度为0的点进行dfs，判断是否有环, handled表示之前dfs处理过的点不再处理
		for (int i = 0; i < numCourses; i++) {
			if (!handled[i]) {
				hasLoop |= dfs(i, edge, visit, handled);
				if (hasLoop) {
					break;
				}
			}
		}
		
		return !hasLoop;
    }
	// 对图进行深度遍历，如果一条链中有环，就会出现遍历的点已经遍历过
	bool dfs(int start, const std::map<int, vector<int> > &edge, bool visit[], bool handled[]) {
		if (visit[start]) {
			return true;
		}
		if (edge.find(start) == edge.end()) 
			return false;
			
		visit[start] = true;
		handled[start] = true;
		bool hasLoop = false;
		for (int i = 0; i < edge.at(start).size(); i++) {
			hasLoop |= dfs(edge.at(start)[i], edge, visit, handled);
			if (hasLoop) {
			    break;
			}
		}
		visit[start] = false;
		return hasLoop;
	}
};
int main(int argc, char *argv[]) {
	Solution s;
	vector<vector<int> > v;
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(0);
	vector<int> v2;
	v2.push_back(0);
	v2.push_back(1);
	v.push_back(v1);
	v.push_back(v2);
	s.canFinish(2, v);
}