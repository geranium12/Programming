import app.Application;

import java.awt.*;

public class Main {
    public static void main(String[] args) {
        Application app = new Application();
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        Dimension dimension = toolkit.getScreenSize();
        app.setBounds(dimension.width / 2 - 320, dimension.height / 2 - 240, 1000, 480);
    }
}
