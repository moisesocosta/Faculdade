function experienciaProfissional(anosExperiencia){
    if (anosExperiencia > 0 && anosExperiencia <= 1)
        return "Profissional Iniciante!";
    if (anosExperiencia >= 1 && anosExperiencia <= 3)
        return "Profissional Intermediário!";
    if (anosExperiencia >= 3 && anosExperiencia <= 6)
        return "Profissional Avançado!";
    if (anosExperiencia > 7)
        return "Profissional Master!";
}

var anosTrabalho = 3;
console.log(experienciaProfissional(anosTrabalho));