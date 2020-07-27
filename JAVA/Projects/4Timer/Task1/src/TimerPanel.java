import javax.swing.*;
import java.awt.*;
import java.awt.geom.Ellipse2D;

public class TimerPanel extends JPanel {
    private Timer timer;
    private int delay = 1000;
    private int angle = 0;

    private int side = 600;

    TimerPanel() {
        timer = new Timer(delay, e -> {
            repaint();
            angle %= 360;
            angle += 6;
        });
        timer.start();
    }

    @Override
    protected void paintComponent(Graphics g) {
        int margin = 30;

        double angleInRad = Math.toRadians(angle);
        int centerXY = (side) / 2;
        int radius = (side - 2 * margin) / 2;
        int x2 = (int) (centerXY - (radius * Math.sin(-angleInRad)));
        int y2 = (int) (centerXY - (radius * Math.cos(-angleInRad)));

        g.clearRect(0, 0, 640, 640);
        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(3));
        g2.drawLine(centerXY, centerXY, x2, y2);
        g2.draw(new Ellipse2D.Double(centerXY - radius, centerXY - radius, 2.0 * radius, 2.0 * radius));
    }
}