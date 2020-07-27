import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.Random;

public class Application extends JFrame {
    private JFrame frame;
    private JPanel panel;
    private JLabel labelQuestion;
    private JButton buttonYes;
    private JButton buttonNo;
    private MouseAdapter mouseAdapterYes;
    private MouseAdapter mouseAdapterNo;

    public Application() {

        Font defaultFont = new Font("Gill Sans MT",Font.BOLD,14);
        Color textColor = Color.decode("#000000");
        Color backgroundColor = Color.decode("#ccffff");
        Border line, margin, compound;

        frame = new JFrame("App1");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        Dimension dimension = toolkit.getScreenSize();
        frame.setBounds(dimension.width / 2 - 320, dimension.height / 2 - 240, 640, 480);
        frame.setResizable(false);
        frame.setVisible(true);

        panel = new JPanel();
        panel.setBounds(0, 0, frame.getWidth(), frame.getHeight());
        panel.setLayout(null);
        panel.setBorder(BorderFactory.createLoweredBevelBorder());
        frame.add(panel);
        panel.setVisible(true);

        labelQuestion = new JLabel("Will Sakovich V. Yu. accept your lab work?");
        labelQuestion.setBounds(panel.getWidth() / 4, 20, 300, 50);
        labelQuestion.setFont(defaultFont);
        labelQuestion.setBackground(Color.RED);

        panel.add(labelQuestion);
        labelQuestion.setVisible(true);

        buttonYes = new JButton("Yes");
        buttonYes.setBounds(panel.getWidth() / 6, 90, 100, 100);

        buttonYes.setFocusPainted(false);
        buttonYes.setBorder(null);
        buttonYes.setForeground(textColor);
        buttonYes.setBackground(backgroundColor);
        line = new LineBorder(Color.BLACK, 5);
        margin = new EmptyBorder(5, 15, 5, 15);
        compound = new CompoundBorder(line, margin);
        buttonYes.setBorder(compound);
        buttonYes.setFont(defaultFont);
        buttonYes.setOpaque(true);

        panel.add(buttonYes);
        buttonYes.setVisible(true);

        buttonNo = new JButton("No");
        buttonNo.setBounds(panel.getWidth() / 6 * 4, 90, 100, 100);

        backgroundColor = Color.decode("#ffccff");
        buttonNo.setFocusPainted(false);
        buttonNo.setBorder(null);
        buttonNo.setForeground(textColor);
        buttonNo.setBackground(backgroundColor);
        line = new LineBorder(Color.BLACK, 5);
        margin = new EmptyBorder(0, 0, 0, 0);
        compound = new CompoundBorder(line, margin);
        buttonNo.setBorder(compound);

        panel.add(buttonNo);
        buttonNo.setVisible(true);

        mouseAdapterYes = new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                JOptionPane.showMessageDialog(null, "Undoubtedly!");
            }
        };

        mouseAdapterNo = new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                int x = panel.getWidth();
                if (buttonNo.getLocation().x < panel.getWidth() / 2) {
                    x *= getCoeff(0.6, 0.9);
                } else {
                    x *= getCoeff(0.1, 0.4);
                    while (Math.abs(x - buttonYes.getLocation().x) < 10) {
                        x *= getCoeff(0.1, 0.4);
                    }
                }
                int y = panel.getHeight();
                y *= getCoeff(0.1, 0.9);
                buttonNo.setLocation(x, y);
            }
        };

        buttonYes.addMouseListener(mouseAdapterYes);
        buttonNo.addMouseListener(mouseAdapterNo);
    }


    public static void main(String[] args) {
        Application app = new Application();
    }

    private double getCoeff(double a, double b) {
        Random random = new Random();
        double c = 1;
        while (c > b || c < a) {
            c = random.nextDouble();
        }
        return c;
    }
}
