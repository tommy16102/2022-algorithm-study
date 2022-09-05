function chunk(size, s) {
  return s.match(new RegExp(".{1," + size + "}", "g"));
}

function check(size, s) {
  let ret = 0;
  let cnt = 1;
  let last = "";
  const chunks = chunk(size, s);

  for (let i = 0; i < chunks.length; i++) {
    if (i === chunks.length - 1) {
      if (last !== chunks[i]) ret += chunks[i].length;
      else ret += String(++cnt).length;
      break;
    }

    if (chunks[i] === chunks[i + 1]) {
      if (last != chunks[i]) {
        last = chunks[i];
        ret += size;
      } else cnt++;
    } else {
      if (last == chunks[i]) ret += String(++cnt).length;
      else {
        if (cnt > 1) ret += String(cnt).length;
        ret += size;
      }
      cnt = 1;
    }
  }
  return ret;
}

function solution(s) {
  var answer = s.length;
  for (let i = 1; i <= s.length / 2 + 1; i++)
    answer = Math.min(answer, check(i, s));
  return answer;
}
