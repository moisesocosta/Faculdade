function temHabilidade(linguagem){
    var resultado = habilidades.indexOf("Javascript");
    if(resultado >= 0)
        return true;
    else
        return false
}

var habilidades = ["Javascript", "ReactJS", "React Native"];
console.log(temHabilidade(habilidades));