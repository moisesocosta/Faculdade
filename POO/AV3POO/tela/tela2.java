package tela;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import logica.logica;

public class tela2 {

    JFrame frame = new JFrame("Excluindo Itens");

    private JPanel painelID = new JPanel();
    private JPanel painelBotoes = new JPanel();

    private JLabel jlID = new JLabel("Item(?) : ");

    private JTextField txtID = new JTextField(15);

    private JButton jbexit = new JButton("Sair");
    private JButton jbExcluir = new JButton("Excluir");
    

    public void montaJanela2(){
        preparaPainel();
        preparaJFrame();
        preparaBoteos();
    }
    public void preparaPainel(){

        painelID.setLayout(new FlowLayout());
        painelID.add(jlID);
        painelID.add(txtID);

        painelBotoes.setLayout(new FlowLayout());
        painelBotoes.add(jbExcluir);
        painelBotoes.add(jbexit);

    }   
    public void preparaJFrame(){
        frame.setLayout(new FlowLayout());
        frame.add(painelID);
        frame.add(painelBotoes);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setSize(300,170);
        frame.setVisible(true);
    }
    public void preparaBoteos(){
        jbExcluir.addActionListener(new ActionListener(){
            logica log = new logica();
            @Override
            public void actionPerformed(ActionEvent e) {

                String valor = txtID.getText();
           
                log.remover(Integer.parseInt(valor));
            }
        });
        
        jbexit.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                frame.dispose();
            }
        });
    }
}
