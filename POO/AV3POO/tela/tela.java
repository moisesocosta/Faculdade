package tela;


import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.nio.file.ProviderMismatchException;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

import logica.logica;

public class tela{

    JFrame frame = new JFrame("Cadastro");

    private JPanel painelNome = new JPanel();
    private JPanel painelID = new JPanel();
    private JPanel painelvalor = new JPanel();
    private JPanel painelResultado = new JPanel();
    private JPanel painelBotaoCadastrar = new JPanel();
    
    private JPanel painelBotoes = new JPanel();
    //n sei se deveria colocar resultado.

    private JLabel jlnome = new JLabel("NOME : ");
    private JLabel jlID = new JLabel("ID        : ");
    private JLabel jlvalor = new JLabel("VALOR: ");
    private JLabel jlResultado = new JLabel();

    private JTextField txtnome = new JTextField(15);
    private JTextField txtID = new JTextField(15);
    private JTextField txtvalor = new JTextField(15);

    private JButton jbCadastrar = new JButton("Cadastrar");
    private JButton jbExcluir = new JButton("Excluir");
    private JButton jbSair = new JButton("Sair");
    private JButton jbView = new JButton("Ver Lista");
    private JButton jbLimpar = new JButton("Limpar");
    

    public void montaJanela(){
        preparaPainel();
        preparaJFrame();
        preparaBoteos();
    }
    public void preparaPainel(){
        painelNome.setLayout(new FlowLayout());
        painelNome.add(jlnome);
        painelNome.add(txtnome);

        painelID.setLayout(new FlowLayout());
        painelID.add(jlID);
        painelID.add(txtID);

        painelvalor.setLayout(new FlowLayout());
        painelvalor.add(jlvalor);
        painelvalor.add(txtvalor);

        painelBotaoCadastrar.setLayout(new FlowLayout());
        painelBotaoCadastrar.add(jbCadastrar);
        painelBotaoCadastrar.add(jbLimpar);

        painelBotoes.setLayout(new FlowLayout());
        painelBotoes.add(jbView);
        painelBotoes.add(jbExcluir);
        painelBotoes.add(jbSair);

        painelResultado.setLayout(new FlowLayout());
        painelResultado.add(jlResultado);
    }   
    public void preparaJFrame(){
        frame.setLayout(new FlowLayout());
        frame.add(painelNome);
        frame.add(painelID);
        frame.add(painelvalor);
        frame.add(painelBotaoCadastrar);
        frame.add(painelBotoes);
        frame.add(painelResultado);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setSize(300,300);
        frame.setVisible(true);
    }
    public void preparaBoteos(){
        jbCadastrar.addActionListener(new ActionListener(){
            logica log = new logica();
            @Override
            public void actionPerformed(ActionEvent e) {
                
                    String nome = txtnome.getText();
                    String id = txtID.getText();    
                    String valor = txtvalor.getText();
                    
                    log.cadastra(nome, id, valor);
                    log.resultado();
                    JOptionPane.showMessageDialog(null, "Cadastro Efetuado.", "Cadastro", 3);
            }
            
        });
        
        jbExcluir.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                new tela2().montaJanela2();
            }
        });

        jbLimpar.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                txtID.setText("");
                txtnome.setText("");
                txtvalor.setText("");
            }
        });
        jbView.addActionListener(new ActionListener(){
            logica log = new logica();
            @Override
            public void actionPerformed(ActionEvent e) {
                new tela3().montaJanela3();
                
            }
        });
        jbSair.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                frame.dispose();
            }
        });
    }
    //n sei se deveria colocar resultado.
}
