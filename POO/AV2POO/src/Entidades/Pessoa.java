package Entidades;

public class Pessoa {
    private static String nome;
    private static String sexo;
    private static int idade;
    private static String cpf;

    public Pessoa(/*String nome, String sexo, int cpf*/) {
        /*this.nome = nome;
        this.sexo = sexo;
        this.cpf = cpf;*/
    }

    public void setNome(String nome) {
        Pessoa.nome = nome;
    }
    public void setSexo(String sexo) {
        Pessoa.sexo = sexo;
    }
    public void setIdade(int idade){
        Pessoa.idade = idade;
    }
    public void setCpf(String cpf){
        Pessoa.cpf = cpf;
    }

    public static String getNome(){
        return nome;
    }
    public static String getSexo(){
        return sexo;
    }
    public static int getIdade(){
        return idade;
    }
    public static String getCpf(){
        return cpf;
    }
}
