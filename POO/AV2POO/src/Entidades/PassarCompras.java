package Entidades;

import Coleções.Carrinho;
import Coleções.Notafiscal;

import java.util.Scanner;

public class PassarCompras {

    public static double passarCompras() throws InterruptedException{
        Scanner entrada = new Scanner(System.in);

        int resp, quantidade;
        double total = 0.0;
        String resp2 = "";
        do{
            Produto prod = new Produto();
            Carrinho car = new Carrinho(prod);
            System.out.println("Para encerrrar a compra digite 0");
            Produtos.Mostrarprodutos();
            System.out.println("Digite o código de barras do produto:");
            resp = entrada.nextInt();
            switch (resp){
                case 8554 -> {
                    System.out.println("Arroz - 5,00 R$");
                    System.out.println("Quantidade");
                    prod.setQuantidade(entrada.nextInt());
                    total += prod.getQuantidade() * 5.0;
                    prod.setNome("Arroz");
                    prod.setPreco(5.00);
                    Carrinho.adicionarProduto(prod);
                    car.inserir();
                    Notafiscal.adicionarProduto(prod);
                }
                case 8566 -> {
                    System.out.println("Feijão - 8,00 R$");
                    System.out.println("Quantidade:");
                    prod.setQuantidade(entrada.nextInt());
                    total += prod.getQuantidade() * 8.0;
                    prod.setNome("Feijão");
                    prod.setPreco(8.00);
                    Carrinho.adicionarProduto(prod);
                    car.inserir();
                    Notafiscal.adicionarProduto(prod);
                }
                case 8422 -> {
                    System.out.println("Macarão - 9,00 R$");
                    System.out.println("Quantidade:");
                    prod.setQuantidade(entrada.nextInt());
                    total += prod.getQuantidade() * 9.0;
                    prod.setNome("Macarão");
                    prod.setPreco(9.00);
                    Carrinho.adicionarProduto(prod);
                    car.inserir();
                    Notafiscal.adicionarProduto(prod);
                }
                case 1245 -> {
                    System.out.println("Coca-cola - 5,50 R$");
                    System.out.println("Quantidade:");
                    prod.setQuantidade(entrada.nextInt());
                    total += prod.getQuantidade() * 5.50;
                    prod.setNome("Coca-cola");
                    prod.setPreco(5.50);
                    Carrinho.adicionarProduto(prod);
                    car.inserir();
                    Notafiscal.adicionarProduto(prod);
                }
                case 6398 -> {
                    System.out.println("Leite - 11,00 R$");
                    System.out.println("Quantidade:");
                    prod.setQuantidade(entrada.nextInt());
                    total += prod.getQuantidade() * 11.00;
                    prod.setNome("Leite");
                    prod.setPreco(11.00);
                    Carrinho.adicionarProduto(prod);
                    car.inserir();
                    Notafiscal.adicionarProduto(prod);
                }
                case 2345 -> {
                    System.out.println("Sabonete - 4,25 R$");
                    System.out.println("Quantidade:");
                    prod.setQuantidade(entrada.nextInt());
                    total += prod.getQuantidade() * 4.25;
                    prod.setNome("Sabonete");
                    prod.setPreco(4.25);
                    Carrinho.adicionarProduto(prod);
                    car.inserir();
                    Notafiscal.adicionarProduto(prod);
                }
                case 0 -> {
                    System.out.println("FECHANDO A COMPRA...");
                    Thread.sleep(2000);
                }
                default -> {
                    System.out.println("Codigo do produto inválido!");
                    Thread.sleep(2000);
                }
            }
            System.out.println("Carrinho de compras:");
            Carrinho.listarCarrinho();
            Thread.sleep(1000);
        }while(resp != 0);
        return total;
    }
}
