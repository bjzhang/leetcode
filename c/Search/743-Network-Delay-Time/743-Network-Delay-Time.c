int findSignalTime(int **times, int timesRowSize, int timesColSize, int src, int dst, int *trace)
{
    int i, j;

    for ( i = 0; i < timesRowSize; i++ ) {
        if ( src == times[i][0] ){
            if (dst == times[i][1]) {
                return times[i][2];
            } else if (trace[i] == 1)
                continue;
            trace[times[i][1]] = 1;
            return findSignalTime(times, timesRowSize, timesColSize, times[i][1], dst, trace) + times[i][2];
        }
    }
    return -1;
}

int networkDelayTime(int** times, int timesRowSize, int timesColSize, int N, int K) {
    #define numOfNode 100

    int result[numOfNode];
    int trace[numOfNode];
    int maxTime = 0;
    int curTime;
    int i;

    memset(result, 0, sizeof(result));
    for (i = 0; i < N; i++) {
        memset(trace, 0, sizeof(trace));
        trace[i]=1;
        trace[K]=1;
        curTime = findSignalTime(times, timesRowSize, timesColSize, K, i, trace);
        if ( maxTime < curTime)
            maxTime = curTime;
    }
    return maxTime;
}
