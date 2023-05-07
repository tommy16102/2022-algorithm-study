def get(i,n,arr,res):
    if i == n:
        res.append(arr)
    else:
        get(i+1,n,arr + [10],res)
        get(i+1,n,arr + [20],res)
        get(i+1,n,arr + [30],res)
        get(i+1,n,arr + [40],res)
    
    return res

def solution(users, emoticons):
    answer = []
    go = get(0,len(emoticons),[],[])
    
    for e in go:
        # print(*e)
        plus = 0
        total = 0
        for i in range(len(users)):
            _sum = 0
            for j in range(len(e)):
                if e[j] >= users[i][0]:
                    _sum += int(emoticons[j] * (100 - e[j])/100)
            if _sum >= users[i][1]:
                plus += 1
            else:
                total += _sum
        answer.append([plus,total])
    answer.sort()
    return answer[-1]


