from TrabalhoDeLogica2Q2 import criaTabela, mostraTabela, resolvetabela, veriSub, verificalinha

# # # Função que identifica as colunas das formulas digitadas e retorna o resultado
def resolveconsequencialogica(formulas, tabelageral, conjuntoForm_Entrada, aForm_entrada):

    conjuntoForm = conjuntoForm_Entrada.split(",",conjuntoForm_Entrada.count(','))
    #print(conjuntoForm) (a&b)#c),(a#c),-(b>c)

    id_formulas = []
    for formula in conjuntoForm:
        id_formulas.append(verificalinha(formula, formulas))
    #print(id_formulas)  |  [7, 4, 6]

    id_A = verificalinha(aForm_entrada, formulas)
    #print(id_A)  |  8

    for j in range(len(tabelageral[0])): ## verifica linha por linha das colunas abaixo
        contVerdade = 0
        for i in id_formulas: ## colunas referente a lista de subformulas [7, 4, 6] 
            #print("esse é o i",i)
            if tabelageral[i][j] == True:
                contVerdade = contVerdade + 1

        #print(contVerdade)
        if contVerdade == len(id_formulas) and tabelageral[id_A][j] == False:
            return ">>> NÃO É CONSEQUÊNCIA LÓGICA <<<\n"

    return ">>> É CONSEQUÊNCIA LÓGICA <<<\n"

# # # Função para gerar uma formula conjunta para poder resolver
def organizaconjntoformulas(conjuntoForm_Entrada,aForm_entrada):
    
    #gerar subconjunto de A
    aForm_Subaux = sorted((veriSub(aForm_entrada)), key = len)

    aForm_Subf = []
    for i in aForm_Subaux:
        if not i.isalpha():
            aForm_Subf.append(i)

    #separar o conjunto das formulas
    conjuntoForm = conjuntoForm_Entrada.split(",",conjuntoForm_Entrada.count(','))
    #print(conjuntoForm)

    #gerar os subconjunto das formulas
    conjuntoForm_Subaux = []
    for i in range(len(conjuntoForm)):
        conjuntoForm_Subaux = conjuntoForm_Subaux + veriSub(conjuntoForm[i])

    #organiza os subconjuntos
    conjuntoForm_Subaux = sorted((conjuntoForm_Subaux), key = len)
    
    #tira os atomos repetidos
    conjuntoForm_Subf = []
    for i in range(len(conjuntoForm_Subaux)):
        if not conjuntoForm_Subaux[i].isalpha():
            conjuntoForm_Subf.append(conjuntoForm_Subaux[i])

    return (conjuntoForm_Subf + aForm_Subf)

# # # Função principal
def main():

    print("#"*36)
    print(" Verificador de Consequência Lógica  ")
    print("#"*36)
    print()

    print("As formulas devem ter o seguinte formato:")
    print('Símbolos Átomicos -> {\033[1;32ma, b, c, ..., x, y, z\033[m}')
    print('Símbolos auxiliares -> {\033[1;32m( )\033[m}')
    print('{\033[1;32m-\033[m} significando negação')
    print('{\033[1;32m&\033[m} significando conjução')
    print('{\033[1;32m#\033[m} significando disjunção')
    print('{\033[1;32m>\033[m} significando implicação')

    print("Exemplo:\033[1;32m (-(a#b)>(a&b)) \033[m")
    print()

    print("O conjunto de fórmulas Γ deve ter o seguinte formato:")
    print('{\033[1;32m(formula),(formula),...,(formula)\033[m} tendo uma {\033[1;32m,\033[m} virgula entre cada formula')
    print("Exemplo:\033[1;32m (a#b),(b&c),(c>a) \033[m")
    print()

    #entradas
    #ex. de formato de entrada: (a&b),((a#c)&b),-(b&c)
    conjuntoForm_Entrada = input("Digite o conjunto de fórmulas Γ no formato acima: ")
    
    #ex. de formato de entrada: (a>b)
    aForm_entrada = input("Agora digite a formula A à ser comparada: ")
    

    #achar os atomos
    aux = conjuntoForm_Entrada + aForm_entrada

    atomos = []
    for i in range(len(aux)):
        if aux[i].isalpha() and aux[i] not in atomos:
            atomos.append(aux[i])

    #gerar a tabela dos atomos
    tabelaAtomos = criaTabela(atomos)
    #print(tabelaAtomos)


    formula = atomos + organizaconjntoformulas(conjuntoForm_Entrada, aForm_entrada)
    #print(formula)

    tabelageral = resolvetabela(formula, tabelaAtomos, len(atomos))

    mostraTabela(formula, tabelageral, len(atomos))
    
    print(resolveconsequencialogica(formula, tabelageral, conjuntoForm_Entrada, aForm_entrada))

main()
