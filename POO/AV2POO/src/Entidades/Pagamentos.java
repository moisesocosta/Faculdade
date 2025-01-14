package Entidades;

import Enuns.Pagamento;
import Enuns.StatusPagamento;

import java.util.Date;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Pagamentos {
    Scanner entrada = new Scanner(System.in);

    private double valor;
    private double totalCompras;

    public void setValor(double valor){
        this.valor = valor;
    }
    public void setTotalCompras(double totalCompras){
        this.totalCompras = totalCompras;
    }
    private double getValor(){
        return valor;
    }
    private double getTotalCompras(){
        return totalCompras;
    }

    public void credito(double totalCompras){
        try {
            while (true) {
                int marca;
                System.out.println("Qual a marca do seu cartão:");
                System.out.println("1 - MASTERCARD");
                System.out.println("2 - VISA");
                System.out.println("3 - ELO");
                marca = entrada.nextInt();
                if (marca >= 1 && marca <= 3) {
                    break;
                }
                else {
                    System.out.println("Opção inválida. Tente novamente!");
                }
            }
            int parcelas;
            System.out.println("Em quantas parcelas deseja fazer o seu pedido: (Em até 10x sem juros)");
            while(true){
                parcelas = entrada.nextInt();
                if(parcelas <= 10){
                    break;
                }
                else{
                    System.out.println("Número de parcelas inválido, tente novamente:");
                }
            }
            if(parcelas == 0){
                System.out.println("Total da compra : " + totalCompras + "R$");
            }
            else {
                double valorParcelado = totalCompras / parcelas;
                System.out.println("Compra parcelada em " + parcelas + "X " + " de " + valorParcelado + "R$");
            }
        }catch(InputMismatchException e){
            System.out.println("Foi digitado um valor incorreto");
            System.out.println("Informações do erro: " + e.toString());
            System.out.println();
        }
    }
    public void debito(double totalCompras){
        while (true) {
            int marca;
            System.out.println("Qual a marca do seu cartão:");
            System.out.println("1 - MASTERCARD");
            System.out.println("2 - VISA");
            System.out.println("3 - ELO");
            marca = entrada.nextInt();
            if (marca >= 1 && marca <= 3) {
                break;
            }
            else {
                System.out.println("Opção inválida. Tente novamente:");

            }
        }
        System.out.println("Pagamento realizado, foi debitado " + totalCompras+ "R$ do seu cartão");
    }

    public void Dinheiro(double totalCompras){
        System.out.println("Informe o valor dado pelo cliente em Reais: ");
        do{
            valor = entrada.nextDouble();
            if(valor < totalCompras){
                System.out.println("Valor Menor que o total da Compra!");
                System.out.println("Solicite um valor: ");
            }
        }while(valor < totalCompras);
        double troco = valor - totalCompras;
        System.out.println("Troco do cliente: " + troco);
    }



}
