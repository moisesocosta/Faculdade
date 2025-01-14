package logica;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;

public class logica {

    private String  ID, preco;
    private String nome;
    private int valor;

    ArrayList<String> Lista = new ArrayList();

    public ArrayList<String> cadastra(String nome, String ID, String preco){

        this.nome = nome;
        this.ID = ID;
        this.preco = preco;
        String adicionar = "Nome: " + nome + " , " + "ID: "+ ID + " , " + " Preço: " + preco;
        Lista.add(adicionar);
        
        return Lista;
    }
    public void remover(int valor){
        this.valor=valor;
        Lista.remove(valor);

        int n = Lista.size();
        int i;
        System.out.println("REMOVE");
        for (i=0; i<n; i++) {
            System.out.println( "\n"+"Item("+i+") "+Lista.get(i));
        }
    }
  
    public String[] resultado(){
        String[] input = new String[Lista.size()];

        // array tem o tamanho da lista, ele é modificado dentro do método
        Lista.toArray(input);
        for (String s : input) {
            System.out.println(input + s); // imprime os 3 nomes
        }
        return input;
        
        // int n = Lista.size();
        // int i;
        // for (i=0; i<n; i++) {
        //     System.out.println( "\n"+"Item("+i+") "+Lista.get(i));
        // }
       
    }
   
}