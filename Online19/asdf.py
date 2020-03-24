t = int(input())
for _ in range(t):
    n = int(input())
    sum = 0
    ddd = dict()
    for i in range(n):
        windex = input().split(' ')
        word,ind = windex[0],int(windex[1])
        ddd[word] = ddd.get(word, [0,0])
        ddd[word][ind] += 1
    for word in ddd.keys():
        sum += max(ddd[word][0],ddd[word][1])
    print(sum)