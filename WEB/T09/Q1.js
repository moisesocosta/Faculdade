class Usuario{
    constructor(email, senha){
        this.email = email;
        this.senha = senha;
    }
    isAdmin(){
        return this.admin === true;
    }
}

class Admin extends Usuario{
    admin = true;
}

const User1 = new Usuario('email@teste.com', 'senha123');
const Adm1 = new Admin('email@teste.com', 'senha123');