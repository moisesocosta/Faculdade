package Entidades;

import java.util.Scanner;

public class Cliente extends Pessoa {
    private static String ComprovanteDeRenda;
    private double totalCompras;
    private int TotalComprasRealizadas;

    public void setComprovanteDeRenda(String ComprovanteDeRenda) {
        Cliente.ComprovanteDeRenda = ComprovanteDeRenda;
    }
    public void setTotalCompras(double totalCompras) {
        this.totalCompras = totalCompras;
    }
    public void setTotalComprasRealizadas(int TotalComprasRealizadas){
        this.TotalComprasRealizadas = TotalComprasRealizadas;
    }

    public static String getComprovanteDeRenda() {
        return ComprovanteDeRenda;
    }
    public double getTotalCompras() {
        return totalCompras;
    }
    public int getTotalComprasRealizadas(){
        return TotalComprasRealizadas;
    }



    public void realizarPagamento() {
        Scanner entrada = new Scanner(System.in);
        Pagamentos pag = new Pagamentos();

        int op;
        do {
            if (totalCompras == 0) {
                System.out.println("Compra finalizada");
                op = 1;
            }
            else {
                System.out.println("Forma de pagamento:");
                System.out.println("1 - Cartão de crédito.");
                System.out.println("2 - Cartão de débito.");
                System.out.println("3 - Dinheiro");
                op = entrada.nextInt();
                switch (op) {
                    case 1 -> {
                        System.out.println("Pagamento em forma de crédito selecionado.");
                        pag.credito(totalCompras);
                    }
                    case 2 -> {
                        System.out.println("Pagamento em forma de débito selecionado.");
                        pag.debito(totalCompras);
                    }
                    case 3 -> {
                        System.out.println("Pagamento em forma de dinheiro selecionado.");
                        pag.Dinheiro(totalCompras);
                    }
                    default -> System.out.println("Opção inválida!");
                }
            }
        }while (op < 0 || op > 3);
    }
}


