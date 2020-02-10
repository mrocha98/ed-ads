#faça uma função recursiva que inverta uma string s
#ex: def inv('abacate') == 'etacaba'

def inv(s):
    if len(s) == 0: return s
    return inv(s[1:]) + s[0]
    #return s[-1] + inv(s[:-1])

print(inv('abacate'))