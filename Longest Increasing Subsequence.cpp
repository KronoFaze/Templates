vector <int> lis(vector <int> &v) {
    vector <int> lisV;
    vector <int> ret;
    vector <int> sol(v.size(), -1);
    auto cmp = [&](int x, int y) { return v[x] > v[y]; };   //  '>' for strictly increasing
                                                            //  '>=' for non-decreasing
                                                            //  '<' for strictly decreasing
                                                            //  '<=' for non-increasing
    for(int i = v.size() - 1; i >= 0; --i) {
        int pos = lower_bound(lisV.begin(), lisV.end(), i, cmp) - lisV.begin();
        if(pos == lisV.size()) {
            if(pos > 0) sol[i] = lisV.back();
            lisV.push_back(i);
        } else {
            if(pos > 0) sol[i] = lisV[pos - 1];
            lisV[pos] = i;
        }
    }
    int idx = lisV.back();
    while(idx != -1) {
        ret.push_back(v[idx]);
        idx = sol[idx];
    }
    return ret;
}
