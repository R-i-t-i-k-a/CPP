#include <bits/stdc++.h>
using namespace std;

int populateResultUtil(int empIndex, vector<int>& empManager, unordered_map<int, vector<int>>& empManagerMap, map<int, int>& result)
{
    int count = 0;
    if (empManagerMap.find(empIndex) == empManagerMap.end()) {
        result.insert({ empIndex, 0 });
        return 0;
    }

    else if (result.find(empIndex) != result.end()) {
        count = result[empIndex];
    } else {
        vector<int> directReportEmpList = empManagerMap[empIndex];
        count = directReportEmpList.size();
        for (int i = 0; i < directReportEmpList.size(); i++) {
            count += populateResultUtil(directReportEmpList[i], empManager, empManagerMap, result);
        }
        result.insert({ empIndex, count });
    }
    return count;
}

void populateResult(int N, vector<int>& empManager)
{

    map<int, int> result;

    unordered_map<int, vector<int>> empManagerMap;

    for (int i = 2; i <= N; i++) {
        int emp = i;
        int mngr = empManager[i - 2];

        // If 'emp' is the first employee under 'mngr'
        if (empManagerMap.find(mngr) == empManagerMap.end()) {
            vector<int> directReportList;
            directReportList.push_back(emp);
            empManagerMap[mngr] = directReportList;
        } else {
            empManagerMap[mngr].push_back(emp);
        }
    }
    for (int i = 1; i <= N; i++) {
        populateResultUtil(i, empManager, empManagerMap, result);
    }

    map<int, int>::iterator itr;
    auto end = result.end();
    end--; // end to second last;

    for (itr = result.begin(); itr != end; itr++) {
        cout << itr->second << " ";
    }
    cout << itr->second;
}

int main()
{
    int N; // Number of employees
    cin>>N;
    vector<int> empManager;// Boss of each employee
    
    for(int i=0;i<N-1;i++){
        int val;
        cin>>val;
        empManager.push_back(val);
    }

    populateResult(N, empManager);

    return 0;
}
