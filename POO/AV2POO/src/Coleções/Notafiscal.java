package Coleções;

import Entidades.Cliente;
import Entidades.DadosSupermercado;
import Entidades.Produto;

import java.util.ArrayList;
import java.util.List;

public class Notafiscal extends Cliente {
    private static final List<Produto> notaFiscal = new ArrayList<Produto>();
    private static Produto produto;

    public Notafiscal(Produto produto){
        Notafiscal.produto = produto;
    }

    public static void adicionarProduto(Produto produto){
        notaFiscal.add(produto);
    }

    public static void listarCarrinho() {
        for (Produto produto: notaFiscal) {
            System.out.println("Nome: " + produto.getNome());
            System.out.println("Preço: " + produto.getPreco() + "R$" );
            System.out.println("-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        }
    }

    public static void CupomFiscal(){
        System.out.println("SUPERMERCADO BOM PREÇO");
        System.out.println("Cnpj: " + DadosSupermercado.getCpnj());
        System.out.println("Endereço: " + DadosSupermercado.getEndereco());
        System.out.println("Telefone: " + DadosSupermercado.getTelefone());
        System.out.println("-=-=-=-=-=-=-=-=-=-=-=-=-=");
        System.out.println("CUPOM FISCAL");
        System.out.println("Dados do Cliente:");
        System.out.println("Nome: " + getNome());
        System.out.println("Idade: " + getIdade());
        System.out.println("Sexo: " + getSexo());
        System.out.println("Cpf: " + getCpf());
        System.out.println("Comprovante de renda: " + getComprovanteDeRenda());
        System.out.println("-=-=-=-=-=-=-=-=-=-=-=-=-=-");
        System.out.println("Compras");

    }
}
