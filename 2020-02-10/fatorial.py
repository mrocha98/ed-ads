'''
até agora, fizemos repetições com while e for
como repetir sem usar while e for?

faça uma função fat(n) que devolva o fatorial de um inteiro positivo n
'''

def fat(n):
    if n <= 1:
        return 1
    return n * fat(n-1)


for k in range(11):
    print(f'{k}! == {fat(k)}\n')


'''
programa recursivo é aquele que se chama a si próprio
se o dado é simples devolta a resposta, caso contrário, reduza a instância e faça
a conta usando o retorno da função
uma hora a instância cai no caso simples
'''