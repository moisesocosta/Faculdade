const usuarios = [
    { nome: 'Rafael', idade: 37, empresa: 'Google' },
    { nome: 'Pedro', idade: 35, empresa: 'Google' },
    { nome: 'Junior', idade: 23, empresa: 'Facebook' },
];

const idade = usuarios.map(users => users.idade);
const filter = usuarios.filter(users => users.empresa === 'Google' && users.idade > 35);
const find = usuarios.find(users => users.empresa === 'Microsoft');