package Entidades;

public class Produto{
    private String nome;
    private  double preco;
    private  int quantidade;
    private  int CodigoDeBarras;


    public  void setNome(String nome) {
       this.nome = nome;
    }
    public  void setPreco(double preco){
        this.preco = preco;
    }
    public  void setQuantidade(int quantidade){
        this.quantidade = quantidade;
    }
    public  void setCodigoDeBarras(int CodigoDeBarras){
        this.CodigoDeBarras = CodigoDeBarras;
    }

    public   String getNome(){
        return nome;
    }
    public double getPreco(){
        return preco;
    }
    public  int getQuantidade(){
        return quantidade;
    }
    public  int getCodigoDeBarras(){
        return CodigoDeBarras;
    }
}