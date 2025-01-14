def hornsat(C):

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
            if len(C[i]) == 1 and C[i][0] > 0:
                fato = C[i][0]
                x += 1
        
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

            return hornsat(Clinha)

def main():

    #Mostrar o menu
    print("#"*36)
    print("       Verificador Hornsat ")
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
            
    print("Essas são as suas calusulas: ",Cinteiro)
    print()
    
    x = hornsat(Cinteiro)
    if x == [[]]:
        print("Não satisfazivel")
    else:
        print("Satisfazivel")
        print("Valoração: ",x)
        

if __name__ == "__main__":
    main() 
