### FUNÇÃO PARA VERIFICAR SE É UMA FORMULA OU NÃO
def principal(a):

    if a.count("(") != a.count(")"):
        return "FALSO"

    if len(a) == 1 and a.islower() and a.isalpha():  
        return "x"

    elif "-" in a:

        x = a.find("-")

        if x == len(a)-1:
            return "FALSO"

        if a[x+1].isalpha() or a[x+1] == "(":

            a = a[0:x]+a[x+1:]
            return "-" + principal(a)

        else:
            return "FALSO"
            
    else:

        if "(" not in a and ")" not in a:
            return "FALSO"

        elif a[0] == "(" and a[-1] == ")":

            a = a[1:-1]

            aux = 0
            i = 0
            while i < len(a)+1:
                    if a[i] == "(":
                        aux += 1

                    if a[i] == ")":
                        aux -= 1
                    
                    if aux <= 0:
                        x = i
                        i = len(a)

                    i += 1
            
            parte1 = a[0:x+1]
            parte2 = a[x+2:len(a)]
            
            if x == len(a)-1:
                return "FALSO"

            elif a[x+1] in CONECTIVOS:
                return principal(parte1) + a[x+1] + principal(parte2)

        return "FALSO"


### FUNÇÕES PARA VERIFICAR AS SUBFORMULAS
def veriRepe(a, sub):
    if a not in sub:
        return sub.append(a)
    else:
        return sub


def veriSub(a):
    sub = []
    i = 0

    while i < len(a):   

        if a[i].isalpha():
            veriRepe(a[i], sub)
        
        if a[i] == "-":
            if a[i+1].isalpha():
                veriRepe(a[i]+a[i+1], sub)

            if a[i+1] == "(":
                
                j = i+2
                aux = 1
                while j < len(a):
                    if a[j] == "(":
                        aux += 1
                    if a[j] == ")":
                        aux -= 1
                    if aux == 0:
                        aux = j
                        j = len(a)

                    j += 1

                veriRepe(a[i:aux+1], sub)
            
        if a[i] == "(":
                
                j = i+1
                aux = 1
                while j < len(a):
                    if a[j] == "(":
                        aux += 1
                    if a[j] == ")":
                        aux -= 1
                    if aux == 0:
                        aux = j
                        j = len(a)

                    j += 1

                veriRepe(a[i:aux+1], sub)
        i += 1

    return(sub)

def main():

    print("#"*33)
    print("  Verificador de Fórmula Lógica  ")
    print("#"*33)
    print()

    print('Símbolos Átomicos -> {\033[1;32ma, b, c, ..., x, y, z\033[m}')
    print('Símbolos auxiliares -> {\033[1;32m( )\033[m}')
    print('{\033[1;32m-\033[m} significando negação')
    print('{\033[1;32m&\033[m} significando conjução')
    print('{\033[1;32m#\033[m} significando disjunção')
    print('{\033[1;32m>\033[m} significando implicação')

    print("Exemplo:\033[1;32m (-(a#b)>(a&b)) \033[m")
    print()

    formula = input("digite uma formula com ou sem espaços entre os caracteres: ")

    semespaco = ""
    for i in range(len(formula)):
        if formula[i] != " ":
            semespaco = semespaco + formula[i]

    resultado = principal(semespaco)

    if "FALSO" in resultado:
        print("\n>>> NÃO É FORMULA")

    else:

        listOrdem = sorted(veriSub(semespaco), key=len)
        print("\n>>> É FORMULA")
        print(">>> As subformulas são:", listOrdem)
        print(">>> A complexidade é:", len(resultado))

CONECTIVOS = [">" , "&", "#"]
main()
