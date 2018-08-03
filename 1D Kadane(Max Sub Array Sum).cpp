int maxSubArraySum(vector <int> &v) {
    int localMax = 0;
    int globalMax = v[0];
    for(int i = 0; i < v.size(); ++i) {
        localMax += v[i];
        globalMax = max(globalMax, localMax);
        if(localMax < 0) localMax = 0;
    }
    return globalMax;
}
