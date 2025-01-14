var endereco = { 
    rua: "Sto Antonio",
    numero: 120,
    bairro: "São José",
    cidade: "Patos-PB"
};

function mensagem(){
    return ("Moisés reside em "  +
        endereco.cidade + ", no bairro " +
        endereco.bairro + ", na rua " +
        endereco.rua + " com o número " +
        endereco.numero
    );
}

console.log(mensagem());