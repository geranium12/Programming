import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;

public class ImagePanel extends JPanel {
    BufferedImage bufferedImage;
    ImagePanel(BufferedImage buffIm) {
        bufferedImage = buffIm;
        repaint();
    }

    @Override
    protected void paintComponent(Graphics g) {
        g.drawImage(bufferedImage, 0, 0, null);
    }
}
