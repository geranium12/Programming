import javax.swing.*;

import java.awt.*;

public class Application extends JFrame {
    Application() {
        TimerPanel panel = new TimerPanel();
        add(panel);
        setPreferredSize(new Dimension(620, 640));
        setResizable(false);
        setVisible(true);
        pack();
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        Application app = new Application();
    }
}
