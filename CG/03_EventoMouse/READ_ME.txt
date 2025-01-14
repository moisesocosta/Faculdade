Programa controlado pelo mouse:

- A cada clique com o botão esquerdo do mouse, um ponto azul é inserido sobre o local do clique
- A janela pode ser redimensionada para aumentar ou diminuir a área de inserção de pontos

OBS: Converter a coordenada de janela (retornada pelo mouse) em coordenada de mundo (usada pelo OpenGL) não é uma tarefa fácil. Neste programa, estou tornando a coordenada de mundo igual a coordenada de janela para que essa conversão torne-se simples, mas não é possível usar essa estratégia em qualquer aplicação.

OBS2: Esse programa usa duas bibliotecas que podem ser de grande ajuda.

Biblioteca <vector>. Classe C++ contida na STL (Standard Template Library) que implementa arrays sem se preocupar com tamanho máximo do array (diferente do array padrão da linguagem C/C++)

Biblioteca <glm>. Conjunto de classes OpenGL Mathematics. Insere uma grande quantidade de classes que auxilia em ferramentas matemáticas muito comuns a serem usados em programas gráficos. Foi criada usando como inspiração a linguagem de shaders da OpenGL. Por isso, ao usar a biblioteca, está indiretamente estudando a linguagem usada na construção de shaders. Para instalar, você pode baixar o código diretamente na internet no link: https://github.com/g-truc/glm/releases/tag/0.9.9.8
Baixe o código fonte e faça o include do arquivo diretamente no seu código. No meu caso, eu coloquei a pasta contendo todas as classes GLM dentro da pasta contendo todas as bibliotecas do meu computador (onde estão localizadas as bibliotecas stdio.h, etc.)
