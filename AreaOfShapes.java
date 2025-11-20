abstract class Shape {
    abstract double calculateArea();

    void displayArea() {
        System.out.println("The area is: " + calculateArea());
    }
}

class Circle extends Shape {
    private double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    @Override
    double calculateArea() {
        return Math.PI * radius * radius;
    }
}

class Rectangle extends Shape {
    private double length;
    private double width;

    Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    double calculateArea() {
        return length * width;
    }
}

class Triangle extends Shape {
    private double base;
    private double height;

    Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    @Override
    double calculateArea() {
        return 0.5 * base * height;
    }
}

public class AreaOfShapes {
    public static void main(String[] args) {
        Shape circle = new Circle(5.0);
        System.out.println("Circle:");
        circle.displayArea();

        Shape rectangle = new Rectangle(4.0, 6.0);
        System.out.println("Rectangle:");
        rectangle.displayArea();

        Shape triangle = new Triangle(4.0, 3.0);
        System.out.println("Triangle:");
        triangle.displayArea();
    }
}
