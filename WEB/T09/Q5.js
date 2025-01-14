const arr = [1, 2, 3, 4, 5, 6];
const [x, ...y] = arr;
function soma(...params){
    return params.reduce((a, b) => a + b);
}

const usuario1 = {
    nome: 'Rodrigo',
    idade: '37',
    endereco: {
        cidade: 'Mossoró',
        uf: 'PB',
        pais: 'Brasil',
    }
};
const usuario2 = {...usuario, nome: "João"};
const usuario3 = {...usuario, endereco: {...usuario.endereco, cidade: "Russas"}};