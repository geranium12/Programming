package classes;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Random;

public class Computer {
    private HardDiskDrive hardDiskDrive;
    private OpticalDiskDrive opticalDiskDrive;
    private RandomAccessMemory randomAccessMemory;
    private Processor processor;
    private boolean isOn;
    private ArrayList<String> runningProcesses;

    public Computer(HardDiskDrive hardDiskDrive, OpticalDiskDrive opticalDiskDrive, RandomAccessMemory
            randomAccessMemory, Processor processor) {
        this.hardDiskDrive = hardDiskDrive;
        this.opticalDiskDrive = opticalDiskDrive;
        this.randomAccessMemory = randomAccessMemory;
        this.processor = processor;
        this.isOn = false;
        runningProcesses = new ArrayList<>();
    }

    public void turnOn() {
        if (isOn) {
            System.out.println("The computer has been already turned on!");
            return;
        }
        isOn = true;
        System.out.println("The computer has been turned on!");
        Random random = new Random();
        int n = random.nextInt(10) + 5;
        for (int i = 0; i < n; i++) {
            int x = random.nextInt(15);
            int number = random.nextInt(20);
            switch (x % 5) {
                case 0: {
                    runningProcesses.add("Trojan$%&#@__(" + number + ")");
                    break;
                }
                case 1: {
                    runningProcesses.add("IntelliJ IDEA(" + number + ")");
                    break;
                }
                case 2: {
                    runningProcesses.add("Google Chrome(" + number + ")");
                    break;
                }
                case 3: {
                    runningProcesses.add("File Explorer(" + number + ")");
                    break;
                }
                case 4: {
                    runningProcesses.add("Word 2017(" + number + ")");
                    break;
                }
            }
        }
    }

    public void turnOff() {
        if (!isOn) {
            System.out.println("The computer has been already turned off!");
            return;
        }
        runningProcesses.clear();
        isOn = false;
        System.out.println("The computer has been turned off!");
    }

    public void scan() {
        if (!isOn) {
            System.out.println("Turn on the computer!");
            return;
        }
        String result = scanAlgorithm();
        if (result.equals("")) {
            System.out.println("The antivirus has not found any viruses!");
        } else {
            System.out.println("The antivirus has found viruses!!!");
            System.out.print(result);
        }
    }

    public void printHardDiskDriveCapacity() {
        System.out.println("Hard disk drive capacity is " + hardDiskDrive.getCapacity() + "GB");
    }

    private String scanAlgorithm() {
        String result = new String();
        for (int i = 0; i < runningProcesses.size(); i++) {
            if (runningProcesses.get(i).contains("Trojan")) {
                result += runningProcesses.get(i) + " is a virus!\n";
            }
        }
        return result;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Computer computer = (Computer) o;
        return isOn == computer.isOn &&
                Objects.equals(hardDiskDrive, computer.hardDiskDrive) &&
                Objects.equals(opticalDiskDrive, computer.opticalDiskDrive) &&
                Objects.equals(randomAccessMemory, computer.randomAccessMemory) &&
                Objects.equals(processor, computer.processor) &&
                Objects.equals(runningProcesses, computer.runningProcesses);
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 31 * hash + hardDiskDrive.hashCode();
        hash = 31 * hash + opticalDiskDrive.hashCode();
        hash = 31 * hash + randomAccessMemory.hashCode();
        hash = 31 * hash + processor.hashCode();
        hash = 31 * hash + (isOn ? 1 : 0);
        for (int i = 0; i < runningProcesses.size(); i++) {
            hash = 31 * hash + runningProcesses.get(i).hashCode();
        }
        return hash;
    }

    @Override
    public String toString() {
        return "Computer{" + "\n" +
                "hardDiskDrive=" + hardDiskDrive + "\n" +
                ", opticalDiskDrive=" + opticalDiskDrive + "\n" +
                ", randomAccessMemory=" + randomAccessMemory + "\n" +
                ", processor=" + processor + "\n" +
                ", isOn=" + isOn + "\n" +
                ", runningProcesses=" + runningProcesses + "\n" +
                '}';
    }
}
