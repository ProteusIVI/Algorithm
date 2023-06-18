class Solution {
public:
    bool dfs(int current) {
        if (visited[current] == true) return false;

        if (preMap[current].size() == 0) return true;

        visited.push_back(current);
        for (auto pre : preMap[current]) {
            if (dfs(pre) == false) 
                return false;
        }
        preMap[current].erase(preMap[current].begin(), preMap[current].end());
        visited.pop_back();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() <= 1)
            return true;

        vector<vector<int>> preMap(numberCourses);

        // intialize the adj list
        for (auto pre : prerequisites) {
            // 0: course, 1: prerequisite
            preMap[pre[0]].push_back(pre[1]);
        }

        // visited node/course
        vector<int> visisted;

        for (int i = 0; i < numCourses; ++i) {
            if (dfs(i, preMap, visited) == false)
                return false;
        }

        return true;
    }
}
