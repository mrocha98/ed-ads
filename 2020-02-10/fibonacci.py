'''
calcule fibonacci de um inteiro n
def fib(n): #fib(4) = 3
'''

def fib(n):
    print(n)
    if n <= 2: return 1
    return fib(n-1) + fib(n-2)

#for k in range(1, 11):
#    print(f'{k}: {fib(k)}')

print(fib(10))