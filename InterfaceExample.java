interface Vehicle {
    void start();
    void stop();
    void accelerate();
}

class Car implements Vehicle {
    public void start() {
        System.out.println("Car is starting...");
    }

    public void stop() {
        System.out.println("Car is stopping...");
    }

    public void accelerate() {
        System.out.println("Car is accelerating...");
    }
}

class Bike implements Vehicle {
    public void start() {
        System.out.println("Bike is starting...");
    }

    public void stop() {
        System.out.println("Bike is stopping...");
    }

    public void accelerate() {
        System.out.println("Bike is accelerating...");
    }
}

public class InterfaceExample {
    public static void main(String[] args) {
        Vehicle myCar = new Car();
        Vehicle myBike = new Bike();

        myCar.start();
        myCar.accelerate();
        myCar.stop();

        System.out.println(); 
        myBike.start();
        myBike.accelerate();
        myBike.stop();
    }
}
