package logica;

public class produto {
    
    private String nome;
    private String valor;
    private String CodigoDeBarras;


    public  void setNome(String nome) {
        this.nome = nome;
    }
    public  void setPreco(String valor){
        this.valor = valor;
    }
    public  void setCodigoDeBarras(String CodigoDeBarras){
        this.CodigoDeBarras = CodigoDeBarras;
    }

    public   String getNome(){
        return nome;
    }
    public String getPreco(){
        return valor;
    }
    public  String getCodigoDeBarras(){
        return CodigoDeBarras;
    }

}
