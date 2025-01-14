const empresa = {
    nome: 'UFC',
    endereco: {
        cidade: 'Russas',
        estado: 'CE',
    }
};

const { nome, endereco: { cidade, estado} } = empresa;

console.log(nome);
console.log(cidade);
console.log(estado);

function exibeInfo({ nome, idade}){
    return `${nome} tem ${idade} anos.`;
}

exibeInfo({ nome: 'Rodrigo', idade: 37})