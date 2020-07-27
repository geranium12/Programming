import equipment.*;
import org.w3c.dom.Document;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.File;
import java.io.IOException;

public class Dom {

    public static Motorcyclist readFromXmlFile(File file) throws ParserConfigurationException, SAXException,
            IOException {
        String brand;
        Gender gender;
        Size size;
        UseType useType;
        Color color;
        double weight;

        HelmetType helmetType;
        HelmetMaterialType helmetMaterialType;
        FabricType fabricType;
        SeasonType seasonType;
        boolean isWaterproof;
        BootsMaterialType bootsMaterialType;
        StyleType styleType;

        Motorcyclist motorcyclist = null;
        Helmet helmet = null;
        Jacket jacket = null;
        Gloves gloves = null;
        Boots boots = null;
        Pants pants = null;

        DocumentBuilder documentBuilder = DocumentBuilderFactory.newInstance().newDocumentBuilder();
        Document document = documentBuilder.parse(file);

        Node root = document.getDocumentElement();

        NodeList motorcycl = root.getChildNodes();
        for (int i = 0; i < motorcycl.getLength(); i++) {
            Node item = motorcycl.item(i);
            if (item.getNodeType() != Node.TEXT_NODE) {
                NamedNodeMap attributes = item.getAttributes();
                brand = attributes.item(0).getNodeValue();
                color = Color.valueOf(attributes.item(1).getNodeValue());
                gender = Gender.valueOf(attributes.item(2).getNodeValue());
                size = Size.valueOf(attributes.item(3).getNodeValue());
                useType = UseType.valueOf(attributes.item(4).getNodeValue());
                weight = Double.valueOf(attributes.item(5).getNodeValue());
                NodeList tags = item.getChildNodes();
                int j = incJ(0, tags);

                switch (item.getNodeName()) {
                    case ("helmet"): {
                        helmetType = HelmetType.valueOf(tags.item(j).getChildNodes().item(0).getNodeValue());
                        j = incJ(j + 1, tags);
                        helmetMaterialType = HelmetMaterialType.valueOf(tags.item(j).getChildNodes().item(0).getNodeValue());
                        helmet = new Helmet(brand, gender, size, useType, color, weight, helmetType, helmetMaterialType);
                        break;
                    }
                    case ("jacket"): {
                        fabricType = FabricType.valueOf(tags.item(j).getChildNodes().item(0).getNodeValue());
                        j = incJ(j + 1, tags);
                        seasonType = SeasonType.valueOf(tags.item(j).getChildNodes().item(0).getNodeValue());
                        jacket = new Jacket(brand, gender, size, useType, color, weight, fabricType, seasonType);
                        break;
                    }
                    case ("gloves"): {
                        fabricType = FabricType.valueOf(tags.item(j).getChildNodes().item(0).getNodeValue());
                        j = incJ(j + 1, tags);
                        seasonType = SeasonType.valueOf(tags.item(j).getChildNodes().item(0).getNodeValue());
                        j = incJ(j + 1, tags);
                        isWaterproof = Boolean.valueOf(tags.item(j).getChildNodes().item(0).getNodeValue());
                        gloves = new Gloves(brand, gender, size, useType, color, weight, fabricType, seasonType,
                                isWaterproof);
                        break;
                    }
                    case ("boots"): {
                        seasonType = SeasonType.valueOf(tags.item(j).getChildNodes().item(0).getNodeValue());
                        j = incJ(j + 1, tags);
                        bootsMaterialType = BootsMaterialType.valueOf(tags.item(j).getChildNodes().item(0).
                                getNodeValue());
                        boots = new Boots(brand, gender, size, useType, color, weight, seasonType, bootsMaterialType);
                        break;
                    }
                    case ("pants"): {
                        fabricType = FabricType.valueOf(tags.item(j).getChildNodes().item(0).getNodeValue());
                        j = incJ(j + 1, tags);
                        seasonType = SeasonType.valueOf(tags.item(j).getChildNodes().item(0).getNodeValue());
                        j = incJ(j + 1, tags);
                        styleType = StyleType.valueOf(tags.item(j).getChildNodes().item(0).getNodeValue());
                        pants = new Pants(brand, gender, size, useType, color, weight, fabricType, seasonType,
                                styleType);
                    }
                }

            }
        }
        motorcyclist = new Motorcyclist(helmet, jacket, gloves, boots, pants);
        return motorcyclist;
    }

    private static int incJ(int j, NodeList tags) {
        while (tags.item(j).getNodeType() == Node.TEXT_NODE) {
            j++;
        }
        return j;
    }
}