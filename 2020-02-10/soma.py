'''
Faça uma função recursiva que calcule a soma dos dígitos de um inteiro positivo n
def sd(n): # sd(123) = 6 = 1 + 2 + 3
'''

def sd(n):
    if n <= 9: return n #só um digito
    return n % 10 + sd(n // 10)

print(sd(123))