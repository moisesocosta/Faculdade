package Entidades;

public class DadosSupermercado {
    private static int cpnj;
    private static int telefone;
    private static String endereco;

    public DadosSupermercado(/*int cnpj, int telefone, String endereco*/){
        //this.cpnj = cnpj;
        //this.endereco = endereco;
        //this.telefone = telefone;
    }
    public static void setCpnj(int cpnj){
        DadosSupermercado.cpnj = cpnj;
    }
    public static void setTelefone(int telefone){
        DadosSupermercado.telefone = telefone;
    }
    public static void setEndereco(String endereco){
        DadosSupermercado.endereco = endereco;
    }

    public static int getCpnj(){
        return cpnj;
    }
    public static int getTelefone(){
        return telefone;
    }
    public static String getEndereco(){
        return endereco;
    }

}
