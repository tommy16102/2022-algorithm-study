/*
  start ~ end 영역 매번 1 더해준 뒤, 누적합 -> 시간초과
  start +1, end -1 한 뒤, 누적합 2번 해줘야 통과..
*/

const MIN = 60;
const MAX = (99 * MIN * MIN) + (MIN * 60) + 60;
let timeArr;

function makeTimeSecs(hour, min, sec) {
    return (hour * MIN * MIN) + (MIN * min) + sec;
}

function initTimeArr(play_time) {
    const playTimeArr = play_time.split(':');
    const end = makeTimeSecs(+playTimeArr[0], +playTimeArr[1], +playTimeArr[2]);
    timeArr = new Array(end + 1).fill(0);
}

function makeSecTime(sec) {
    let h = '00', m = '00';
    if (sec >= (MIN * MIN)) {
        h = parseInt(sec / (MIN * MIN));
        sec -= h * MIN * MIN;
        if (h < 10) h = '0' + h;
    }
    if (sec >= MIN) {
        m = parseInt(sec / MIN);
        sec -= m * MIN;
        if (m < 10) m = '0' + m;
    }
    s = sec;
    if (s < 10) s = '0' + s;
    return [h, m, s].join(":");   
}

function addTimeArr(logs) {
    logs.forEach(log => {
        const logArr = log.split('-');
        const startArr = logArr[0].split(':');
        const endArr = logArr[1].split(':');
        const start = makeTimeSecs(+startArr[0], +startArr[1], +startArr[2]);
        const end = makeTimeSecs(+endArr[0], +endArr[1], +endArr[2]);
        timeArr[start]++;
        timeArr[end]--;
    })
}

function updateTimeArr(play_time) {
    const playTimeArr = play_time.split(':');
    const end = makeTimeSecs(+playTimeArr[0], +playTimeArr[1], +playTimeArr[2]);
    for (let i = 1; i <= end; i++) timeArr[i] += timeArr[i-1];
    for (let i = 1; i <= end; i++) timeArr[i] += timeArr[i-1];
}

function findTime(play_time, adv_time) {
    const playTimeArr = play_time.split(':');
    const advTimeArr = adv_time.split(':');
    const end = makeTimeSecs(+playTimeArr[0], +playTimeArr[1], +playTimeArr[2]);
    const advTime = makeTimeSecs(+advTimeArr[0], +advTimeArr[1], +advTimeArr[2]);
    return makeSecTime(calc(end, advTime));
}

function calc(end, advTime) {
    let cnt = -1, startAns = 0;
    let startTime = 0;
    while (startTime + advTime <= end) {
        let endTime = startTime + advTime;
        let cntSum = timeArr[endTime-1] - (startTime == 0 ? 0 : timeArr[startTime - 1]);
        if (cntSum > cnt) {
            cnt = cntSum;
            startAns = startTime;
        }
        startTime++;
    }
    return startAns;
}

function solution(play_time, adv_time, logs) {
    initTimeArr(play_time);
    addTimeArr(logs);
    updateTimeArr(play_time);
    return findTime(play_time, adv_time);
}
