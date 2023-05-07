def getDate(day):
    day = list(map(int,day.split('.')))
    return day[0] * 12 * 28 + day[1] * 28 + day[2]

def solution(today, terms, privacies):
    answer = []
    _terms = {}
    today = getDate(today)
    # print(f"today : {today}")
    
    for i in range(len(terms)):
        e = terms[i].split()
        _terms[e[0]] = int(e[1]) * 28
    
    for i in range(len(privacies)):
        e = privacies[i].split()
        p = getDate(e[0]) + _terms[e[1]]
        
        if p <= today:
            answer.append(i+1)
    return answer