class Battery{
    public int charge;

    Battery(int charge){
        //Write code here
    }
}

abstract class Electronic{
    Battery battery;
    
    Electronic(){
        //Write Code here
    }

    public abstract int use();
    
    public Battery replaceBattery(Battery b)
    { 
        Battery temp = battery;
        battery = b;
        b = temp;
        return b;
    }
}

class BoomBox extends Electronic{
    BoomBox(Battery battery_Boombox){
        battery = battery_Boombox;
    }
    public int use(){
        if(battery.charge >= 3){
            battery.charge -= 3;
        }
        return battery.charge;
    }
}

class FlashLight extends Electronic{
    FlashLight(){
        battery = new Battery(5);
    }
    public int use(){
        if (battery.charge >= 1 ){
            battery.charge -= 1;
        }
        return battery.charge;
    }

}
