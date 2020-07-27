import com.sun.j3d.utils.geometry.*;

import com.sun.j3d.utils.universe.*;

import javax.media.j3d.*;

import javax.swing.*;
import javax.vecmath.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class Application extends JFrame {
    private final static Color3f E_COLOR = new Color3f(0.0f, 0.0f, 0.0f);
    private final static Color3f S_COLOR = new Color3f(1.0f, 1.0f, 1.0f);
    private final static Color3f OBJECT_COLOR = new Color3f(0.6f, 0.6f, 0.6f);
    private final static Color3f LIGHT_COLOR = new Color3f(1.0f, 0.0f, 0.0f);
    private final static Color3f AL_COLOR = new Color3f(0.2f, 0.2f, 0.2f);
    private final static Color3f BACKGROUND_COLOR = new Color3f(0.05f, 0.05f, 0.2f);
    private final static BoundingSphere BOUNDS = new BoundingSphere(new Point3d(0.0, 0.0, 0.0),
            1000.0);
    private final static Vector3d SPHERE_POS_UP = new Vector3d(0.0, 0.8, 2.0);
    private final static Vector3d SPHERE_POS_DOWN = new Vector3d(0.0, -0.6, 2.0);
    private final static Vector3d SPHERE_POS_LEFT = new Vector3d(-1.5, 0.0, 2.0);
    private final static Vector3d SPHERE_POS_RIGHT = new Vector3d(1.5, 0.0, 2.0);

    private Text3D text3D;
    private PointLight light;
    private AmbientLight ambientLight;
    private Vector3d spherePos;
    private ColoringAttributes coloringAttributes;
    private Transform3D transform3DSphere;
    private TransformGroup transformGroupSphere;

    public Application() {
        Canvas3D canvas3D = createCanvas3D();
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        SimpleUniverse universe = new SimpleUniverse(canvas3D);

        // Create the root of the branch graph
        BranchGroup objectRoot = new BranchGroup();
        // Create a TransformGroup to scale all objects so they
        // appear in the scene.
        TransformGroup objectScale = new TransformGroup();
        Transform3D transform3D1 = new Transform3D();
        transform3D1.setScale(0.4);
        objectScale.setTransform(transform3D1);
        objectRoot.addChild(objectScale);
        // Set up the background
        Background background = new Background(BACKGROUND_COLOR);
        background.setApplicationBounds(BOUNDS);
        objectScale.addChild(background);

        // Create the objects
        TransformGroup transformGroupText = createText3D();
        transformGroupSphere = createSphere();
        objectScale.addChild(transformGroupText);
        objectScale.addChild(transformGroupSphere);
        createLight();
        objectScale.addChild(ambientLight);
        objectRoot.compile();
        universe.getViewingPlatform().setNominalViewingTransform();
        // add the group of objects to the Universe
        universe.addBranchGraph(objectRoot);
    }

    private Canvas3D createCanvas3D() {
        GraphicsConfiguration config = SimpleUniverse.getPreferredConfiguration();
        Canvas3D canvas3D = new Canvas3D(config);
        setSize(1366, 768);
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());
        panel.add(canvas3D, BorderLayout.CENTER);
        panel.setVisible(true);
        setContentPane(panel);

        canvas3D.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getExtendedKeyCode() == KeyEvent.VK_BACK_SPACE) {
                    if (text3D.getString().length() != 0) {
                        String newText = text3D.getString().substring(0, text3D.getString().length() - 1);
                        text3D.setString(newText);
                    }
                } else if (e.getExtendedKeyCode() == KeyEvent.VK_ENTER) {
                    Color color = JColorChooser.showDialog(null, "Choose color!", Color.black);
                    if (color != null) {
                        light.setColor(new Color3f(color));
                        coloringAttributes.setColor(new Color3f(color));
                    }
                } else if(e.getExtendedKeyCode() == KeyEvent.VK_DOWN){
                    spherePos = SPHERE_POS_DOWN;

                } else if(e.getExtendedKeyCode() == KeyEvent.VK_UP){
                    spherePos = SPHERE_POS_UP;
                }
                else if(e.getExtendedKeyCode() == KeyEvent.VK_LEFT){
                    spherePos = SPHERE_POS_LEFT;
                }
                else if(e.getExtendedKeyCode() == KeyEvent.VK_RIGHT) {
                    spherePos = SPHERE_POS_RIGHT;
                }
                transform3DSphere.setTranslation(spherePos);
                transformGroupSphere.setTransform(transform3DSphere);
            }

            @Override
            public void keyTyped(KeyEvent e) {
                if (e.getKeyChar() != KeyEvent.VK_BACK_SPACE) {
                    String newText = String.valueOf(e.getKeyChar());
                    text3D.setString(text3D.getString() + newText);
                }
            }
        });
        return canvas3D;
    }

    // Create a Text3D object
    private TransformGroup createText3D() {
        Material material = new Material(OBJECT_COLOR, E_COLOR, OBJECT_COLOR, S_COLOR, 100.0f);
        Appearance appearance = new Appearance();
        material.setLightingEnable(true);
        appearance.setMaterial(material);
        Font3D font3D = new Font3D(new Font("Helvetica", Font.PLAIN, 1),
                new FontExtrusion());

        text3D = new Text3D(font3D, new String("Blabla"), new Point3f(
                -2.0f, 0.0f, 0.0f));
        text3D.setCapability(Text3D.ALLOW_STRING_WRITE);
        text3D.setCapability(Text3D.ALLOW_STRING_READ);
        Shape3D shape3D = new Shape3D();
        shape3D.setGeometry(text3D);
        shape3D.setAppearance(appearance);

        TransformGroup transformGroup = new TransformGroup();
        transformGroup.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
        transformGroup.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
        transformGroup.setCapability(TransformGroup.ENABLE_PICK_REPORTING);
        transformGroup.addChild(shape3D);
        return transformGroup;
    }

    // Create a Sphere
    private TransformGroup createSphere() {
        coloringAttributes = new ColoringAttributes();
        coloringAttributes.setCapability(ColoringAttributes.ALLOW_COLOR_WRITE);
        coloringAttributes.setColor(LIGHT_COLOR);
        Appearance appearance = new Appearance();
        appearance.setColoringAttributes(coloringAttributes);

        spherePos = new Vector3d(0.0, -0.7, 2.0);
        transform3DSphere = new Transform3D();
        transform3DSphere.set(spherePos);
        transformGroupSphere = new TransformGroup(transform3DSphere);
        transformGroupSphere.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
        transformGroupSphere.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
        transformGroupSphere.setCapability(TransformGroup.ENABLE_PICK_REPORTING);

        transformGroupSphere.addChild(new Sphere(0.05f, appearance));
        return transformGroupSphere;
    }

    // Create an AmbientLight
    private void createLight() {
        ambientLight = new AmbientLight(AL_COLOR);
        ambientLight.setInfluencingBounds(BOUNDS);

        Point3f lPoint = new Point3f(0.0f, 0.0f, 0.0f);
        Point3f attenuation = new Point3f(1.0f, 0.0f, 0.0f);
        light = new PointLight(LIGHT_COLOR, lPoint, attenuation);

        light.setInfluencingBounds(BOUNDS);
        light.setCapability(PointLight.ALLOW_COLOR_WRITE);
        light.setCapability(PointLight.ALLOW_COLOR_READ);
        light.setCapability(PointLight.ALLOW_POSITION_WRITE);
        transformGroupSphere.addChild(light);
    }

    public static void main(String[] args) {
        new Application();
    }
}