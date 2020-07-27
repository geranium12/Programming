import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.border.CompoundBorder;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;
import java.awt.*;
import java.awt.event.*;

public class Application extends JFrame {
    private JFrame frame;
    private JPanel panel;
    private JButton button;
    private JLabel statusBar;
    private MouseAdapter mouseMotionListener;
    private MouseAdapter mouseListener;
    private MouseAdapter mouseMotionListenerButton;
    private KeyListener keyListener;

    public Application() {

        frame = new JFrame("App1");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        Dimension dimension = toolkit.getScreenSize();
        frame.setBounds(dimension.width / 2 - 320, dimension.height / 2 - 240, 640, 480);

        panel = new JPanel();
        panel.setBounds(0, 0, frame.getWidth(), frame.getHeight());
        panel.setLayout(null);
        frame.add(panel);


        button = new JButton("Bla-bla-bla");
        button.setBounds(50, 100, 200, 100);

        Font defaultFont = new Font("Gill Sans MT", Font.BOLD, 14);
        Color textColor = Color.decode("#000000");
        Color backgroundColor = Color.decode("#ccffff");
        Color hoverColor = Color.decode("#00aced");

        button.setFocusPainted(false);
        button.setBorder(null);
        button.setForeground(textColor);
        button.setBackground(backgroundColor);
        Border line = new LineBorder(Color.BLACK, 5);
        Border margin = new EmptyBorder(5, 15, 5, 15);
        Border compound = new CompoundBorder(line, margin);
        button.setBorder(compound);
        button.setFont(defaultFont);
        button.setOpaque(true);

        panel.add(button);
        button.setVisible(true);

        int x = MouseInfo.getPointerInfo().getLocation().x;
        int y = MouseInfo.getPointerInfo().getLocation().y;

        statusBar = new JLabel("x: " + x + " y: " + y);
        statusBar.setBounds(10, 0, 1000, 30);
        panel.add(statusBar);
        statusBar.setVisible(true);

        mouseMotionListener = new MouseAdapter() {
            @Override
            public void mouseMoved(MouseEvent e) {
                statusBar.setText("x: " + e.getX() + " y: " + e.getY());
            }

            @Override
            public void mouseDragged(MouseEvent e) {
                statusBar.setText("x: " + e.getX() + " y: " + e.getY());
            }
        };

        mouseListener = new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                button.setLocation(e.getX(), e.getY());
            }
        };

        mouseMotionListenerButton = new MouseAdapter() {
            private int x, y;

            @Override
            public void mouseDragged(MouseEvent e) {
                if (e.isControlDown()) {
                    statusBar.setText("x: " + (e.getX() - x + button.getX()) + " y: " + (e.getY() - y + button.getY()));
                    button.setLocation(e.getX() - x + button.getX(), e.getY() - y + button.getY());
                } else {
                    statusBar.setText("x: " + (e.getX() + button.getX()) + " y: " + (e.getY() + button.getY()));
                }
            }

            @Override
            public void mousePressed(MouseEvent e) {
                x = e.getX();
                y = e.getY();
            }

            @Override
            public void mouseMoved(MouseEvent e) {
                statusBar.setText("x: " + (e.getX() + button.getX()) + " y: " + (e.getY() + button.getY()));
            }
        };

        keyListener = new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                if (e.getKeyChar() == KeyEvent.VK_BACK_SPACE) {
                    if (button.getText().length() > 0) {
                        StringBuilder str = new StringBuilder(button.getText());
                        str.deleteCharAt(str.length() - 1);
                        button.setText(str.toString());
                    }
                } else {
                    button.setText(button.getText() + e.getKeyChar());
                }
            }
        };

        button.addMouseMotionListener(mouseMotionListenerButton);
        button.addMouseListener(mouseMotionListenerButton);

        button.addKeyListener(keyListener);

        panel.addMouseListener(mouseListener);
        panel.addMouseMotionListener(mouseMotionListener);

        frame.setVisible(true);
    }


    public static void main(String[] args) {
        Application app = new Application();
    }
}
