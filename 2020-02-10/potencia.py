#faça uma função pot(x, n) que faz x elevado a n, onde x é float e n um inteiro positivo
#faça recursivamente e não usando **
#ex: pot(2, 3) == 8

def pot(x, n):
    if n == 0: return 1
    if n == 1: return x
    return x * pot(x, n - 1)

for k in range(16):
    print(f'3 ** {k} == {pot(k, 3)}\n')