package Supermercado;

import Coleções.Notafiscal;
import Entidades.*;
import Enuns.Pagamento;
import Enuns.StatusPagamento;

import java.util.Date;
import java.util.Scanner;


public class Bompreco {
    public static void cls(){
        for(int i = 0; i < 50; i++)
            System.out.println("");
    }

    public static void main(String[] args) throws InterruptedException {
        Cliente cliente = new Cliente();
        Scanner entrada = new Scanner(System.in);
        Pagamento pedido = new Pagamento(new Date(), StatusPagamento.PAGAMENTO_EM_ANDAMENTO);

        String resposta = "";
        //String resp2 = "S";
        cliente.setNome("Nathan");
        cliente.setSexo("Masculino");
        cliente.setIdade(33);
        cliente.setCpf("84548453");
        cliente.setComprovanteDeRenda("R$ 5000");
        cliente.setTotalComprasRealizadas(2000);
        DadosSupermercado.setCpnj(123456);
        DadosSupermercado.setEndereco("Rua Coronel Nathan Vidal");
        DadosSupermercado.setTelefone(881335488);
            do {
                    System.out.println("Bem vindo ao supermercado Bom preço:");
                    Menu.mostrarMenu();
                    resposta = entrada.nextLine();
                    switch (resposta) {
                        case "1" -> {
                            System.out.println("Caixa aberto");
                            System.out.println("Passando produtos...");
                            Thread.sleep(2000);
                            cliente.setTotalCompras(PassarCompras.passarCompras());
                            System.out.println("Total a pagar:" + cliente.getTotalCompras());
                            System.out.println(pedido);
                            cliente.realizarPagamento();
                            System.out.println("");
                            pedido.setStatus(StatusPagamento.valueOf("PAGAMENTO_CONCLUIDO"));
                            System.out.println(pedido);
                            Thread.sleep(5000);
                            cls();
                        }
                        case "2" -> {
                            Notafiscal.CupomFiscal();
                            Notafiscal.listarCarrinho();
                        }
                        case "0" -> {
                            System.out.println("Obrigado pela preferência, tenha um bom dia");
                            System.out.println("Atenciosamente equipe bom preço");
                        }
                    }
            } while (!resposta.equals("0"));
        }
    }
