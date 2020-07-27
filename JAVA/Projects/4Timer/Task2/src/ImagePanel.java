import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;

public class ImagePanel extends JPanel {
    private BufferedImage image;
    private Application parent;
    private double angle = 0;
    private int radius = 1;

    ImagePanel(Application parent) {
        this.parent = parent;
        int size = Application.SIZE;
        setPreferredSize(new Dimension(size, size));

        int delay = 1;
        Timer timer = new Timer(delay, e -> {
            repaint();
            int speed = parent.getSpeed();
            boolean isClockwise = parent.isClockwise();
            double changeAngle = (speed * 10.) / radius;
            angle += isClockwise ? changeAngle : -changeAngle;
            if (angle >= 360) {
                angle = 0;
            }
        });
        timer.start();
    }

    @Override
    protected void paintComponent(Graphics g) {
        int width = parent.getSize().width;
        int height = parent.getSize().height;
        g.clearRect(0, 0, width, height);

        if (image != null) {
            double angleInRad = Math.toRadians(angle);
            int margin = Math.max(image.getWidth(), image.getHeight()) / 2;
            int side = Math.min(width, height);
            radius = (side - 2 * margin) / 2;
            int centerX = (side - image.getWidth()) / 2;
            int centerY = (side - image.getHeight()) / 2;
            int xImage = (int) (centerX - (radius * Math.sin(-angleInRad)));
            int yImage = (int) (centerY - (radius * Math.cos(-angleInRad)));
            g.drawImage(image, xImage, yImage, null);
        }
    }

    public void setImage(BufferedImage image) {
        this.image = image;
    }
}