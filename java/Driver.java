import java.util.Scanner;

class Wheels{
    private static String facingDirection;
    private static String frontWheels;
    private static String rearWheels;
    public static String getfacingDirection()
    {
        return Wheels.facingDirection;
    }
    public static void setfacingDirection(String direction)
    {
        Wheels.facingDirection = direction;
    }
    public static String getfrontWheels()
    {
        return Wheels.frontWheels;
    }
    public static void setfrontWheels( String direction)
    {
        Wheels.frontWheels = direction;
    }
    public static String getrearWheels()
    {
        return Wheels.rearWheels;
    }
    public static void setrearWheels( String direction)
    {
        Wheels.rearWheels = direction;
    }
    public Wheels() {
        facingDirection = "";
        frontWheels = "";
        rearWheels = "";
    }
    static void turningDirection( String direction){
        setrearWheels(direction);
        setfrontWheels(direction);
        setfacingDirection(direction);
        System.out.println("Turned " + direction);
    }
}

class Steering_Wheel{

    private static String turnDirection;
    
    public static String getAcceleration()
    {
        return Steering_Wheel.turnDirection;
    }
    public static void setAcceleration( String direction)
    {
        Steering_Wheel.turnDirection = direction;
    }

    public static String getturnDirection()
    {
        return Steering_Wheel.turnDirection;
    }
    public static void setturnDirection(String direction)
    {
        Steering_Wheel.turnDirection = direction;
    }

    static void Honk_Horn(){
        System.out.println("Car Horn is honked.");
    }
}
class Engine{
    private static boolean isRunning;
    private static int acceleration;

    public static boolean getIsRunning()
    {
        return Engine.isRunning;
    }
    public static void setIsRunning()
    {
        Engine.isRunning = !Engine.isRunning ;
    }

    public static int getAcceleration()
    {
        return Engine.acceleration;
    }
    public static void setAcceleration( int a)
    {
        Engine.acceleration = a;
    }
    public Engine(){
        isRunning = false;
        acceleration = 5;
    }
    static void changeAcceleration(){
        System.out.println("The acceleration is set at - " + Engine.getAcceleration());
        Car.setCurrentSpeed(Engine.getAcceleration());
    }
}
class Car{
    String interiorColors;
    String exteriorColors;
    private static float currentSpeed;

    public static float getCurrentSpeed()
    {
        return Car.currentSpeed;
    }
    public static void setCurrentSpeed(int acceleration)
    {
        Car.currentSpeed = 65/acceleration;
    }

    public Car(){
        interiorColors = "";
        exteriorColors = "";
        currentSpeed = 65/5;
    }

}

class Driver {       
    static void turn(String direction){
        Steering_Wheel.setturnDirection(direction);
        Wheels.turningDirection(Steering_Wheel.getturnDirection());
    }
    
    static void honkhorn() {
        Steering_Wheel.Honk_Horn();
    }

    static void ignition(){
        Engine.setIsRunning();
        Engine.getIsRunning();
        if(Engine.getIsRunning() == true){
            System.out.println("Started Ignition. Car is now running.");
        }
        else{
            System.out.println("Turned Off Ignition.");
        }
    }
    static void accelerate( int a){
        Engine.setAcceleration(a);
        Engine.changeAcceleration();
    }

    public static void main(String[] args) {
        int d = 0;
        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("Menu");
            System.out.println("1. Honk Horn");
            System.out.println("2. Turn Left/Right");
            System.out.println("3. Start/Stop Ignition");
            System.out.println("4. Speed Up/Slow Down");
            System.out.println("5. Exit");
            System.out.println("Choose an Option - ");
            d = sc.nextInt();
            switch (d) {
            case 1:
                honkhorn(); break;
            case 2: 
                System.out.println("Which Direction do you want to turn in?(Left/Right)");
                String direction = sc.next();
                turn(direction); break;
            case 3: 
                ignition(); break;
            case 4: 
                System.out.println("Please enter the new acceleration - ");
                int acceleration = sc.nextInt();
                accelerate(acceleration); break;
            case 5: 
                System.exit(0);
            }
        }while(d!=5);
        sc.close();
    }
    
}