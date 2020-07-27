package classes;

import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

public class DomExample {

    public static void readFromXmlFile(File file, ArrayList<Student>  arrayList) throws ParserConfigurationException, SAXException,
            IOException {
        arrayList.clear();
        int recordBook = 0, course = 0, group = 0;
        String surname = null;

        DocumentBuilder documentBuilder = DocumentBuilderFactory.newInstance().newDocumentBuilder();
        Document document = documentBuilder.parse(file);

        Node root = document.getDocumentElement();

        NodeList students = root.getChildNodes();
        for (int i = 0; i < students.getLength(); i++) {
            Node student = students.item(i);
            if (student.getNodeType() != Node.TEXT_NODE) {
                int countProps = 0;
                recordBook = Integer.parseInt(student.getAttributes().getNamedItem("recordBook").getNodeValue());
                NodeList studentProps = student.getChildNodes();
                int j = 0;
                while (countProps < 3) {
                    Node studentProp = studentProps.item(j);
                    j++;
                    if (studentProp.getNodeType() != Node.TEXT_NODE) {
                        switch (studentProp.getNodeName()) {
                            case ("surname"): {
                                surname = studentProp.getChildNodes().item(0).getTextContent();
                                countProps++;
                                break;
                            }
                            case ("course"): {
                                course = Integer.parseInt(studentProp.getChildNodes().item(0).getNodeValue());
                                countProps++;
                                break;
                            }
                            case ("group"): {
                                group = Integer.parseInt(studentProp.getChildNodes().item(0).getNodeValue());
                                countProps++;
                            }
                        }
                    }
                }
                if (countProps == 3) {
                    arrayList.add(new Student(recordBook, surname, course, group));
                }
            }
        }
    }

    /*
    public static void writeToXmlFile(File file, TreeMap<Integer, Student> treeMap) throws
            TransformerFactoryConfigurationError, DOMException, ParserConfigurationException {
        Document document = DocumentBuilderFactory.newInstance().newDocumentBuilder().newDocument();
        Element students = document.createElement("students");

        Iterator itr = treeMap.entrySet().iterator();
        while (itr.hasNext()) {
            Map.Entry<Integer, Student> element = (Map.Entry<Integer, Student>) itr.next();
            Element student = document.createElement("student");

            Element surname = document.createElement("surname");
            surname.setTextContent(element.getValue().getSurname());

            Element course = document.createElement("course");
            course.setTextContent(Integer.toString(element.getValue().getCourse()));

            Element group = document.createElement("group");
            group.setTextContent(Integer.toString(element.getValue().getGroup()));

            student.setAttribute("recordBook", Integer.toString(element.getKey()));

            student.appendChild(surname);
            student.appendChild(course);
            student.appendChild(group);

            students.appendChild(student);
        }

        document.appendChild(students);
        writeDocument(document);
    }

    private static void writeDocument(Document document) throws TransformerFactoryConfigurationError {
        try {
            Transformer tr = TransformerFactory.newInstance().newTransformer();
            DOMSource source = new DOMSource(document);
            FileOutputStream fos = new FileOutputStream("output.xml");
            StreamResult result = new StreamResult(fos);
            tr.transform(source, result);
        } catch (TransformerException | IOException e) {
            e.printStackTrace(System.out);
        }
    }
    */
}