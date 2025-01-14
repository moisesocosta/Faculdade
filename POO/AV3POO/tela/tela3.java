package tela;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

import logica.logica;


public class tela3 {

    JFrame frame = new JFrame("Vizualisando lista");

    private JPanel painelArrayList = new JPanel();
    private JLabel jlArrayList = new JLabel();

    private JPanel painelBotao = new JPanel();
    private JButton jbSair = new JButton("Sair");
    
    public void montaJanela3(){
        preparaPainel();
        preparaJFrame();
        preparaBoteos();
    }
    public void preparaPainel(){
        logica log = new logica();
        painelArrayList.setLayout(new FlowLayout());
      

        painelBotao.add(jbSair);
        frame.add(painelBotao);
    }   
    public void preparaJFrame(){
        frame.setLayout(new FlowLayout());
        frame.add(painelArrayList);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setSize(300,300);
        frame.setVisible(true);
    }
    public void preparaBoteos(){
        jbSair.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                frame.dispose();
            }
        });
        // jbView.addActionListener(new ActionListener(){
        //     
        //     @Override
        //     public void actionPerformed(ActionEvent e) {
        //         jlArrayList.setText(log.resultado());
        //     }
        // }
        
    }
}
    
