#faça uma função recursiva que calcule o mdc de dois inteiros a e b
#ex? mdc(21, 15) == 3

def mdc(a, b):
    if a % b == 0: return b
    return mdc(b, a%b)

print(mdc(21, 15))
print(mdc(15, 21)) 