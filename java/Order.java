import java.util.Scanner;

class Order {

    public static void main(String[] args){
        String item="";
        int shipping=0, price=0;
        float tax=0, total_bill=0;
        Scanner reader = new Scanner(System.in);
        
        System.out.println("Items");
        System.out.println("1. Alexa $100");
        System.out.println("2. Charger $20");
        System.out.println("3. Kindle $80");
        System.out.println("4. Earphone $30");
        System.out.println("5. USB Drive $10");
        System.out.println("Enter your choice :: ");
        int userChoice = reader.nextInt();
        
        switch(userChoice){
            case 1: item = "Alexa $100"; price = 100; tax = (price*10)/100; shipping = 5; break;
            case 2: item = "Charger $20"; price = 20; tax = (price*10)/100; shipping = 0; break;
            case 3: item = "Kindle $80"; price = 80; tax = (price*10)/100; shipping = 5; break;
            case 4: item = "Earphone $30"; price = 30; tax = (price*10)/100; shipping = 0; break;
            case 5: item = "USB Drive $10"; price = 10; tax = (price*10)/100; shipping = 0; break;
            default: System.out.println("Please Enter a valid choice!"); break;
        }
        total_bill = price+tax+shipping;
        if(item!= null){
            System.out.println("Thank you for your order!!");
            System.out.println(item);
            System.out.println("Tax = $"+tax);
            System.out.println("Shipping = $"+shipping);
            System.out.println("Total Bill = $"+total_bill);
        }

        reader.close();
    }
}