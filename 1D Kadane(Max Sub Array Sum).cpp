int maxSubArraySum(vector <int> &v) {
    int localMax = v[0];
    int globalMax = v[0];
    for(int i = 1; i < v.size(); ++i) {
        localMax = max(v[i], localMax + v[i]);
        globalMax = max(globalMax, localMax);
    }
    return globalMax;
}
