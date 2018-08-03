vector <int> lis(vector <int> &v) {
    vector <int> lisVec;
    vector <int> ans;
    vector <int> sol(v.size(), -1);
    for(int i = 0; i < v.size(); ++i) {
        int pos = lower_bound(lisVec.begin(), lisVec.end(), i, [&](int x, int y) { return v[x] < v[y]; }) - lisVec.begin(); //strictly increasing
        //int pos = lower_bound(lisVec.begin(), lisVec.end(), i, [&](int x, int y) { return v[x] <= v[y]; }) - lisVec.begin(); //non-decreasing
        //int pos = lower_bound(lisVec.begin(), lisVec.end(), i, [&](int x, int y) { return v[x] > v[y]; }) - lisVec.begin(); //strictly decreasing
        //int pos = lower_bound(lisVec.begin(), lisVec.end(), i, [&](int x, int y) { return v[x] >= v[y]; }) - lisVec.begin(); //non-increasing
        if(pos == lisVec.size()) {
            if(lisVec.size() > 0) sol[i] = lisVec.back();
            lisVec.push_back(i);
        } else {
            if(pos > 0) sol[i] = lisVec[pos - 1];
            lisVec[pos] = i;
        }
    }
    int idx = lisVec.back();
    while(idx != -1) {
        ans.push_back(v[idx]);
        idx = sol[idx];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
