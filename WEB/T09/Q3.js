const arr = [1, 2, 3, 4, 5];
const newArr = arr.map(item => item + 10);

const usuario = { nome: 'Rodrigo', idade: 37};
const mostraIdade = usuario => usuario.idade;
mostraIdade(usuario);

const nome = "Rodrigo";
const idade = 37;
function mostraUsuario(nome = 'Rodrigo', idade = 37){
    return { nome, idade };
}
mostraUsuario(nome, idade);
mostraUsuario(nome);

const promise = function(){
    return new Promise(function (resolve, reject){
        return resolve();
    })
}