def solution(commands):
    answer = []
    
    arr = [[None for _ in range(51)] for _ in range(51)]
    cells = {}
    merge_track = {}
    
    def tofs(r,c):
        r = int(r)
        c = int(c)
        return f"{r},{c}"
    
    def torc(fs):
        r,c = map(int,fs.split(","))
        return [r,c]
    
    for i in range(1,51):
        for j in range(1,51):
            fs = tofs(i,j)
            cells[fs] = fs
            merge_track[fs] = []
    
    def find(r,c):
        _fs = tofs(r,c)
        if _fs == cells[_fs]:
            return cells[_fs]
        else:
            _r,_c = torc(cells[_fs])
            cells[_fs] = find(_r,_c)
            return cells[_fs]
    
    def merge(r1,c1,r2,c2):
        fs1 = find(r1,c1)
        fs2 = find(r2,c2)
        r1,c1 = torc(fs1)
        r2,c2 = torc(fs2)
        
        if r1 == r2 and c1 == c2: return
        
        if not arr[r1][c1] and arr[r2][c2]:
            arr[r1][c1] = None
            cells[fs1] = fs2
            if merge_track[fs1]:
                merge_track[fs2] += merge_track[fs1]
                merge_track[fs1] = []
            merge_track[fs2].append(fs1)
        else: 
            arr[r2][c2] = None
            cells[fs2] = fs1
            if merge_track[fs2]:
                merge_track[fs1] += merge_track[fs2]
                merge_track[fs2] = []
            merge_track[fs1].append(fs2)

    def unmerge(r,c):
        origin_fs = find(r,c)
        merged = merge_track[origin_fs]
        print(merged)
        o_r,o_c = torc(cells[origin_fs])
        origin_value = arr[o_r][o_c]
        merged.append(origin_fs)
        for fs in merged:
            _r,_c = torc(fs)
            if _r == r and _c == c:
                arr[_r][_c] = origin_value
                cells[fs] = fs
            else:
                arr[_r][_c] = None
                cells[fs] = fs
        merge_track[origin_fs] = []
                
    def update1(r,c,value):
        _r,_c = torc(find(r,c))
        arr[_r][_c] = value
        
    def update2(value1,value2):
        u = []
        for i in range(1,51):
            for j in range(1,51):
                if arr[i][j] == value1: u.append([i,j])
                
        for r,c in u:
            _r,_c = torc(find(r,c))
            arr[_r][_c] = value2
        
    def print_arr(r,c):
        r,c = torc(find(r,c))
        res = arr[r][c]
        if not res: answer.append('EMPTY')
        else: answer.append(res)
        
    for e in commands:
        cmd = list(e.split())
        
        if cmd[0] == 'UPDATE':
            if len(cmd) == 4: update1(int(cmd[1]),int(cmd[2]),cmd[3])
            else: update2(cmd[1],cmd[2])
        elif cmd[0] == 'MERGE':
            merge(int(cmd[1]),int(cmd[2]),int(cmd[3]),int(cmd[4]))
        elif cmd[0] == 'UNMERGE':
            unmerge(int(cmd[1]),int(cmd[2]))
        elif cmd[0] == 'PRINT':
            print_arr(int(cmd[1]),int(cmd[2]))
            
    return answer