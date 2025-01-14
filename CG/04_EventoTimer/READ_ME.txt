Programa básico para realizar animações na GLUT
 
Dois pontos (um vermelho e um azul) andam para esquerda e direita em velocidades diferentes na tela.

Animações são feitas ao modificar as características de um objeto e então redesenhar a tela periodicamente. Você pode redesenhar a uma taxa de tempo fixa com a função glutTimerFunc ou redesenhar a todo momento possível que o seu computador permitir com a função glutIdleFunc.

O programa possui uma classe Objeto que mantém sua posição, a direção atual de movimento e sua cor. A classe também recalcula sua posição e desenha o objeto na tela. É uma boa prática de programação criar classes para cada objeto da sua aplicação. A biblioteca GLM pode auxiliar bastante nas características do objeto.
