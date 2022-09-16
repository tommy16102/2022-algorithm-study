const nickname = { }
const str = [];

function enter(id, name) {
    setNickname(id, name);
    str.push({
        id,
        text: "님이 들어왔습니다.",
    })
}

function leave(id) {
    str.push({
        id,
        text: "님이 나갔습니다.",
    })
}

function setNickname(id, name) {
    nickname[id] = name;
}

function splitStr(arr) {
    const [ kind, id, name ] = arr.split(' ');
    if (kind === 'Enter') enter(id, name);
    else if (kind === 'Leave') leave(id);
    else if (kind === 'Change') setNickname(id, name);
}

function solution(record) {
    for (let i = 0; i < record.length; i++) splitStr(record[i]);
    return str.map(obj => {
        return `${nickname[obj.id]}${obj.text}`;
    })
}