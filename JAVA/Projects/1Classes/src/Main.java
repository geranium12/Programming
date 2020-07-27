import classes.*;
import enums.DimensionHardDiskDrive;
import enums.InterfaceHardDiskDrive;
import enums.RandomAccessMemoryType;

public class Main {
    public static void main(String[] args) {
        HardDiskDrive hardDiskDrive = new HardDiskDrive(InterfaceHardDiskDrive.SATA, 1024,
                DimensionHardDiskDrive.DIMENSION_25, 8);
        OpticalDiskDrive opticalDiskDrive = new OpticalDiskDrive(30, 24, true);
        RandomAccessMemory randomAccessMemory = new RandomAccessMemory(RandomAccessMemoryType.DDR4, 16,
                3200);
        Processor processor = new Processor("Intel", 8, 4, 8,
                4900);
        Computer computer = new Computer(hardDiskDrive, opticalDiskDrive, randomAccessMemory, processor);

        computer.scan();
        computer.turnOn();
        computer.scan();
        computer.turnOff();
        computer.printHardDiskDriveCapacity();
    }
}
