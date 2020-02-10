#Faça uma função anagrama, que verifique se duas palavras são anagramas. ex. aberto e rebato

def anagrama(p1, p2):
    return sorted(p1) == sorted(p2)

print(anagrama('aberto', 'rebato'))
print(anagrama('casa', 'asa'))