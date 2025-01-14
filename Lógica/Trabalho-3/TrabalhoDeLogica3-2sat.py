def simplifica(C):

    #caso c for um conjunto vazio
    if C == [[]]: 
        return C
    if C == []:
        return C

    else:
        #Lema clausula unitaria positiva
        x = 0
        for i in range(len(C)):

            #procura por fatos veridicos
            if len(C[i]) == 1:
                fato = C[i][0]
                x = 1
                break
        
        #se C não contem fatos (Lema 1)
        if x == 0:
            return C

        #se C tem fatos então fazer operações (Lema 2)
        else:

            Clinha = []

            for clausula in C: 
                if (fato*-1) in clausula:
                    clausula.remove(fato*-1)
                    Clinha.append(clausula)

                elif fato not in clausula:
                    Clinha.append(clausula)
            
            
            return simplifica(Clinha)

def _2sat(C):

    novoC = simplifica(C)

    while [] not in novoC and len(novoC) != 0:

        p = novoC[0][0]
        if p < 0:
            p = p * -1
        
        auxC = novoC
        auxC.append([p])

        novoClinha = simplifica(auxC)
        
        if  novoClinha == [[]] :
            auxC = novoC
            auxC.append([-1*p])
            novoC = simplifica(auxC)
        else:
            novoC = novoClinha 

    #caso c for um conjunto vazio
    return novoC

def main():
    #Mostrar o menu
    print("#"*36)
    print("       Verificador 2Sat ")
    print("#"*36)
    print()

    #Usuário vai digitar a quantidade de cláusulas
    numClausula = int(input("Digite quantas clausulas deseja verificar: "))
    print("Digite uma clausula por vez e a seguir pressione enter para adicionar:\n\n EXEMPLO:\n\n 1\n 2,1,4\n-3,1,-2\n-1,3,-2\n\n")

    c = []
    for i in range(numClausula):
        c.append(input("digite a clausula no formato esperado: "))

    print()
    Cinteiro = []
    for i in range(len(c)):
        Cinteiro.append(list(map(int, c[i].split(","))))
            
    print("Essas são as suas clausulas: ",Cinteiro)
    print()
    
    x = _2sat(Cinteiro)
    if [] in x:
        print("Não satisfazivel")
        print("Valoração: ",x)
    else:
        print("Satisfazivel")
        print("Valoração: ",x)

if __name__ == "__main__":
    main()
