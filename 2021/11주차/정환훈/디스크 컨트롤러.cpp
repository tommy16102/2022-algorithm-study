int solution(vector<vector<int>> jobs) {
    int answer = 0; 
    sort(jobs.begin(), jobs.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    int idx = 0, time = 0;
    while (idx < jobs.size() || !pq.empty()) { // 모든 일을 다 안봤거나 도착한 일이 있으면 계속
        while (idx < jobs.size() && time >= jobs[idx][0]) {  // 도착한 일들
            pq.push(make_pair(jobs[idx][1], jobs[idx][0])); // 소요 시간으로 sort해서 waiting 큐에 넣기
            idx++;
        } 
        if (!pq.empty()) { // 모든 일을 다 봤고, 도착한 일들이 있다
            time += pq.top().first; // 완료된 시간 
            answer += time - pq.top().second; // 기다린 시간 더해줌
            pq.pop(); 
        } 
        else { // 모든 일을 다 봤는데 현재 도착한 일이 없다 
            time = jobs[idx][0]; 
        } 
    } 
    return answer / jobs.size(); 
}