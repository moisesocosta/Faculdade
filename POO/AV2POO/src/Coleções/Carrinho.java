package Coleções;

import Entidades.Produto;
import Operações.Operacoes;
import jdk.swing.interop.SwingInterOpUtils;

import java.util.ArrayList;
import java.util.List;

public class Carrinho implements Operacoes {
    private static Produto produto;
    private static final List<Produto> carrinho = new ArrayList<Produto>();

    public Carrinho(Produto produto){
        Carrinho.produto = produto;
    }

    public static void adicionarProduto(Produto produto){
        carrinho.add(produto);
    }
    public static void removerProduto(int index){
        carrinho.remove(index);
    }
    public int tamanhoCarrinho(){
        return carrinho.size();
    }

    public static Produto getProduto(int index){
        return carrinho.get(index);

    }

    public static int Num(){
        return carrinho.indexOf(produto);
    }

    public static void listarCarrinho() {
        for (Produto produto: carrinho) {
            System.out.println("Nome: " + produto.getNome());
            System.out.println("Quantidade: " + produto.getQuantidade());
            System.out.println("Preço: " + produto.getPreco() + "R$");
            System.out.println();

        }
    }

        @Override
        public void inserir() {
            System.out.println("Produto inserido!");
        }

        @Override
        public void excluir() {
            System.out.println("Produto removido!");
        }

        @Override
        public void localizar() {
            System.out.println("Produto localizado!");
        }

}
