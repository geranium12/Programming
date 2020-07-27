import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class Application extends JFrame {
    GamePanel gamePanel;
    ImagePanel imagePanel;
    BufferedImage bufferedImage;

    Application() {
        setTitle("Пятнашки");
        setLayout(new GridLayout(1, 2));
        setResizable(false);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        try {
            bufferedImage = ImageIO.read(new File("src\\4.jpg"));
        } catch (IOException ex) {
            JOptionPane.showMessageDialog(null, "There is no such file!");
        }

        imagePanel = new ImagePanel(bufferedImage);
        gamePanel = new GamePanel(bufferedImage);

        imagePanel.setPreferredSize(new Dimension(bufferedImage.getWidth(), bufferedImage.getHeight()));
        gamePanel.setPreferredSize(new Dimension(bufferedImage.getWidth(), bufferedImage.getHeight()));

        add(imagePanel);
        add(gamePanel);
        pack();
    }

    public static void main(String[] args) {
        Application app = new Application();
    }
}
