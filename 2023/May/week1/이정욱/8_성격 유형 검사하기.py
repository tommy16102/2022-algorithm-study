def solution(survey, choices):
    answer = ''
    
    MBTI = {
        'R': 0,
        'T': 0,
        'C': 0,
        'F': 0,
        'J': 0,
        'M': 0,
        'A': 0,
        'N': 0,
    }
    for i in range(len(survey)):
        a,b = survey[i]
        
        if choices[i] == 4:
            continue
        if choices[i] > 4:
            MBTI[b] += choices[i] - 4
        else:
            MBTI[a] += 4 - choices[i]
    
    if MBTI['R'] >= MBTI['T']:
        answer += 'R'
    else:
        answer += 'T'
    
    if MBTI['C'] >= MBTI['F']:
        answer += 'C'
    else:
        answer += 'F'
        
    if MBTI['J'] >= MBTI['M']:
        answer += 'J'
    else:
        answer += 'M'
        
    if MBTI['A'] >= MBTI['N']:
        answer += 'A'
    else:
        answer += 'N'
    
    return answer