#Khai bao.
mode = """Chon phuong thuc nhap:
1: Ma tran ke.
2: Danh sach ke.
"""
print(mode)
n, k = 0, 0
ke = list()
mode = input()
mx = """Do thi vo huong hay co huong?
1: Do thi vo huong.
2: Do thi co huong."""
print(mx); mx = input()
print("Nhap dau vao:")
if   mode == '1':
    n = int(input())
    ke = [[] for _ in range(n+1)]
    mtk = list()
    for _ in range(n):
        mtk.append(list(map(int, input().split())))
    for i in range(n):
        for j in range(n): 
            if mtk[i][j] == 1: ke[i+1].append(j+1)
elif mode == '2':
    n = int(input())
    dsk = list()
    for i in range(n):
        lst = list(map(int, input().split()))
        dsk.append(lst[1::])
    ke = dsk.copy()
# - DFS su dung de quy.
def dequy(u, ke = ke, xet = None):
    if xet is None: xet = list()
    xet.append(u)
    for v in ke[u]: 
        if v not in xet: dequy(v, ke, xet)
    return xet

# DFS su dung stack.
def stack(u, ke = ke):
    st = list(); st.append(u)
    kq = list(); kq.append(u)
    while(len(st) > 0):
        s = st.pop()
        for i in ke[s]:
            if i not in kq: 
                st.append(s)
                st.append(i)
                kq.append(i)
                break
    return kq

# BFS su dung queue.
def queue(u, m = 1, ke = ke):
    qu = list(); qu.append(u)
    kq = list(); kq.append(u)
    truoc = [0]*(n+1)
    while(len(qu) > 0):
        s = qu.pop(0)
        for i in ke[s]: 
            if i not in kq: 
                truoc[i] = s
                qu.append(i)
                kq.append(i)
    if m == 0: return truoc
    return kq

# Chuc nang
bt = """
1 - DFS su dung de quy.
2 - DFS su dung stack.
3  - BFS su dung queue."""

print(bt); bt = input()
if   bt == '1':
    print("Chon dinh: ", end='')
    x = int(input()); 
    print("Ket qua DFS theo de quy tu dinh {}: ".format(x))
    print(dequy(x))
elif bt == '2':
    print("Chon dinh: ", end='')
    x = int(input()); 
    print("Ket qua DFS theo stack tu dinh {}: ".format(x))
    print(stack(x))
elif bt == '3' :
    print("Chon dinh: ", end='')
    x = int(input()); 
    print("Ket qua BFS theo queue tu dinh {}: ".format(x))
    print(queue(x))
