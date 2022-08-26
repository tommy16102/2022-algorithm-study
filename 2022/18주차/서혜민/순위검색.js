/*
  filter로 요소 개수, sort 2번 사용 -> 효율성 테스트 시간 초과
  sort 1번, 이진 탐색 사용해야 통과..
*/

function sortInfoObj(obj) {
    for(let key in obj) {
        obj[key].sort((a, b) => a - b);
    }
    return obj;
}

function makeInfoObj(info) {
    const obj = {};
    info.forEach(elem => {
        const elemArr = elem.split(' ');
        const key = elemArr[0] + elemArr[1] + elemArr[2] + elemArr[3];
        if (key in obj) obj[key].push(+elemArr[4]);
        else obj[key] = [+elemArr[4]];
    })
    return sortInfoObj(obj);
}

function makeQueryArr(query) {
    const arr = [];
    query.forEach(elem => {
        const elemArr = elem.split(' ');
        const [lang,, end,, work,, food, cnt] = elemArr;       
        arr.push({lang, end, work, food, cnt});
    }) 
    return arr;
}

function compare(elem, infoObj) {
    let count = 0;
    for (let infoKey in infoObj) {
        const infoValue = infoObj[infoKey];
        const {lang, end, work, food, cnt} = elem; 
        if ((lang === '-' ? true : infoKey.includes(lang)) && (end === '-' ? true : infoKey.includes(end)) && (work === '-' ? true : infoKey.includes(work))
            && (food === '-' ? true : infoKey.includes(food))) count += search(cnt, infoValue);
    }
    return count;
}

function search(count, infoArr) {
    let start = 0;
    let end = infoArr.length;
    while(start < end) {
        let mid = Math.floor((start + end) / 2);
        if (infoArr[mid] < count) start = mid + 1;
        else end = mid;
    }
    return infoArr.length - end;
}

function findInfoObj(query, infoObj) {
    const ans = [];
    const queryArr = makeQueryArr(query);
    queryArr.forEach(elem => {
        ans.push(compare(elem, infoObj));
    })
    return ans;
}

function solution(info, query) {
    const infoObj = makeInfoObj(info);
    return findInfoObj(query, infoObj);
}
