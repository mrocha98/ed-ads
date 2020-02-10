'''
calcule fibonacci de um inteiro n
def fib(n): #fib(4) = 3
'''

'''
f = {}
def fib(n):
    if n <= 2: return 1
    if n not in f:
        f[n] = fib(n-1) + fib(n-2)
    return f[n]
'''

from functools import lru_cache
@lru_cache(maxsize=None)
def fib(n):
    if n <= 2: return 1
    return fib(n-1) + fib(n-2)


print(fib(100))