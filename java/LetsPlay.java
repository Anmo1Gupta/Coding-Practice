import java.util.Random;
import java.util.Scanner;

public class LetsPlay{

    private String computer;
    private String user;

    // public LetsPlay() {
    public LetsPlay() {
		this.user = "";
		this.computer = "";
	}

    public void runComputer(){
        Random rand = new Random(); 
        int randNum = rand.nextInt(5);

        switch(randNum){
            case 0: setComputer("Red"); break;
            case 1: setComputer("Green"); break;
            case 2: setComputer("Blue"); break;
            case 3: setComputer("Orange"); break;
            case 4: setComputer("Yellow"); break;
            default: System.out.println("Try next time");
        }
    }

    public void setUserChoice(){
        Scanner s = new Scanner(System.in);
        Boolean condition = false;
        String user_input = "";

        while(condition == false){
            System.out.println("Please guess the random color - ");
            user_input = s.nextLine();
            setUser(user_input);
            condition = isValid(user);
        }       
        // s.close(); 
    }

    public Boolean isValid(String user){
        if(user.equalsIgnoreCase("Red") || user.equalsIgnoreCase("Green") || user.equalsIgnoreCase("Blue") || 
            user.equalsIgnoreCase("Orange") || user.equalsIgnoreCase("Yellow")){
            return true;
        }
        else{
            return false;
        }
    }

    public String whoWins(String computer, String user){
        
        String winner = "Computer";

        if(user.equalsIgnoreCase(computer)){
            winner = "User";
        }
        
        return winner;
    }

    public String getComputer() {
		return this.computer;
	}

	public void setComputer(String computer) {
		this.computer = computer;
	}

	public String getUser() {
		return this.user;
	}

	public void setUser(String user) {
		this.user = user;
	}
    

    public static void main(String[] args){
        int userWinCount = 0, compWinCount = 0;
        LetsPlay c = new LetsPlay();

        for(int i=0;i<10;i++){
            c.runComputer();
            c.setUserChoice();
            if (c.whoWins(c.getComputer(), c.getUser()) == "User"){
                userWinCount+=1;
            }
            else{
                compWinCount+=1;
            }
        }

        if(userWinCount > compWinCount){
            System.out.println("User is the Grand Winner with "+ userWinCount + " wins!");
        }
        else if (userWinCount < compWinCount){
            System.out.println("Computer is the Grand Winner with "+ compWinCount + " wins!");
        }
        else{
            System.out.println("Both User and Computer have the same number of wins!");
        }
    }
}